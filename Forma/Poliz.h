#pragma once
#include "Table.h"
#include "Stack.h"
#include "Entry.h"
#include <string>
#include <iostream>
using namespace std;


class Pol {

private:
	// Метод для разделения строки на отдельные лексемы (процесс токенизации)
	void StringToWond(string str, int& k, string* w)
	{

		string zn = "+-*/^()";

		k = 0; // Инициализация счетчика токенов
		str += " ";

		for (int i = 0; i < str.length(); i++)
		{

			int l = zn.find(str[i]); // Поиск текущего символа в строке `zn`
			if (l >= 0 && l < zn.length())
			{
				if (w[k].length() > 0)
				{
					k++; // Если текущий токен не пустой, увеличиваем счетчик токенов
				}
				w[k] = str[i]; // Присваиваем текущему токену значение текущего символа
				w[++k] = ""; // Инициализация нового токена
			}

			else
			{   // Если текущий символ - пробел и текущий токен не пустой, инициализируем новый токен
				if (str[i] == ' ')
				{
					if (w[k].length() > 0)
					{
						w[++k] = "";
					}
				}
				else // Если текущий символ не является знаком операции или пробелом, добавляем его к текущему токену
				{
					w[k] = w[k] + str[i];
				}
			}
		}
	}


	string* lex;
	int sizelex, countlex;


	int count, size;
	string* mem;
	Stec<entry> st;
	Table PriorityTable;
	Table variables;

	// Метод создания таблицы приоритетов операторов и добавления записей
	void madePriorityTable()
	{
		PriorityTable = Table(20);
		PriorityTable.add(entry("+", 1.0));
		PriorityTable.add(entry("-", 1.0));

		PriorityTable.add(entry("*", 2.0));
		PriorityTable.add(entry("/", 2.0));

		PriorityTable.add(entry("^", 3.0));
	}

	// Добавляет открывающую скобку в стек
	void workLeft()
	{
		st.pushback(entry("(", -1.0));
	}


	// Выталкивает операторы из стека в массив ПОЛИЗа до тех пор, пока не встретит открывающую скобку
	void workRight()
	{
		while ((st.is_empty() == 0) && (st.top().poluchim_imya() != "("))
		{
			mem[count++] = st.pop().poluchim_imya();
		}
		if (st.top().poluchim_imya() == "(")
		{
			st.pop();
		}
	}



	// Добавляет операнд в массив ПОЛИЗа и таблицу операндов

	void workOperand(string tmp)
	{
		mem[count++] = tmp;
		if (tmp[0] >= '0' && tmp[0] <= '9')
		{
			variables.add(entry(tmp, stof(tmp)));
		}
		else
		{
			variables.add(entry(tmp, 0.0));
		}
	}




	// Обрабатывает операторы и добавляет их в массив ПОЛИЗа в соответствии с их приоритетами

	void workOperator(string str, int p)
	{
		while ((st.is_empty() == 0) && (st.top().poluchim_znachenie() >= p))
		{
			mem[count++] = st.pop().poluchim_imya();
		}
		st.pushback(entry(str, p));
	}


	// Завершает формирование ПОЛИЗа, выталкивая все операторы из стека в массив ПОЛИЗа
	void workEnd()
	{
		while (st.is_empty() == 0)
		{
			mem[count++] = st.pop().poluchim_imya();
		}
	}



	// Метод сборки полиза
	void madePolis()
	{
		count = 0;
		for (int i = 0; i < countlex; i++)
		{
			if (lex[i] == "(")
			{
				workLeft();
			}

			else
			{
				if (lex[i] == ")")
				{
					workRight();
				}

				else
				{
					int p = PriorityTable.searchI(lex[i]);
					if (p > -1)
					{
						workOperator(lex[i], p);
					}
					else
					{
						workOperand(lex[i]);
					}
				}
			}
		}
		workEnd();
	}



public:
	// Конструктор
	Pol(string str = "")
	{
		size = str.length() + 1;
		variables = Table(size);
		mem = new string[size];

		count = 0;
		sizelex = size + 1;
		lex = new string[sizelex];
		countlex = 0;

		StringToWond(str, countlex, lex);
		madePriorityTable();
		st = Stec<entry>(20);
		madePolis();
	}

	// Конструктор копирования
	Pol(const Pol& tmp)
	{
		size = tmp.size;
		count = tmp.count;
		mem = new string[size];
		for (int i = 0; i < size; i++)
		{
			mem[i] = tmp.mem[i];
		}
		PriorityTable = tmp.PriorityTable;
		st = tmp.st;
		variables = tmp.variables;
	}

	// Деструктор
	~Pol()
	{
		delete[]mem;
	}
	int GetCount()
	{
		return count;
	}


	// Переопределение операции присваивания
	Pol& operator =(Pol tmp)
	{
		if (size != tmp.size)
		{
			if (size != 0)
			{
				delete[]mem;
			}
			size = tmp.size;
			mem = new string[size];
		}
		for (int i = 0; i < size; i++)
		{
			mem[i] = tmp.mem[i];
		}
		count = tmp.count;
		PriorityTable = tmp.PriorityTable;
		st = tmp.st;
		variables = tmp.variables;
		return *this;
	}


	// Метод для доступа к элементам ПОЛИЗа
	string operator[](int R)
	{
		string str = "";

		if (R <= count && R >= 0)
		{
			str = mem[R];
		}

		return str;
	}



	// Можно получить строку, представляющую ПОЛИЗ
	string PoluchimPoliZ()
	{
		string str = "";
		str += mem[0];
		for (int i = 1; i < count; i++)
		{
			str += " " + mem[i];
		}
		return str;
	}



	// Метод для доступа к таблице операндов
	Table table_of_operands()
	{
		return variables;
	}



	// Этот метод возвращает количество элементов в ПОЛИЗе
	int kolichestvo_elementov()
	{
		return count;
	}



	// Этот метод возвращает размер массива ПОЛИЗа
	int getSIZE()
	{
		return size;
	}



	// Метод устанавливает новое числовое значение для записи с индексом n в таблице операндов
	void SetVar(int n, double k)
	{
		variables.setWar(n, k);
	}
};