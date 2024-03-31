#pragma once

#include <iostream>
#include <string>
#include <cmath>
#include "Poliz.h"
#include "Entry.h"
class arifmetic
{
private:

	Pol poli;
	Stec <double> st;

public:

	// Конструктор с параметрами по умолчанию
	arifmetic(string str = "")
	{
		poli = Pol(str);
	}

	// Деструктор
	~arifmetic() {}

	// Конструктор копирования
	arifmetic(const arifmetic& tmp)
	{
		poli = tmp.poli;
		st = tmp.st;
	}

	// Оператор присваивания
	arifmetic& operator=(arifmetic tmp)
	{
		poli = tmp.poli;
		st = tmp.st;
		return *this;
	}

	// Метод выполняет вычисление арифметического выражения, представленного в виде ПОЛИЗа
	double poshitaem()
	{
		double right, res, left;
		Table table = poli.table_of_operands();
		Stec <double> st(poli.kolichestvo_elementov());

		for (int i = 0; i < poli.kolichestvo_elementov(); i++)
		{
			res = table.searchI(poli[i]);
			if (res != -1)
			{
				st.pushback(res);
			}

			else
			{
				right = st.pop();
				left = st.pop();
				if (poli[i] == "+")
				{
					st.pushback(left + right);
				}
				if (poli[i] == "-")
				{
					st.pushback(left - right);
				}
				if (poli[i] == "*")
				{
					st.pushback(left * right);
				}
				if (poli[i] == "/")
				{
					st.pushback(left / right);
				}
				if (poli[i] == "^")
				{
					st.pushback(pow(left, right));
				}
			}
		}

		return st.pop();
	}

	void SetVar(string key, float k)
	{
		int n = poli.table_of_operands().serchN(key);
		if (n > -1)
		{
			poli.SetVar(n, k);
		}
	}

	void SetVar(int n, float k)
	{
		if (n > -1)
		{
			poli.SetVar(n, k);
		}
	}


	// Метод установки нового значения по индексу
	void Index(int n, float k)
	{
		if (n > -1)
		{
			poli.SetVar(n, k);
		}
	}
	// Метод возвращает таблицу операндов
	Table vivedem_tablitsy()
	{
		return poli.table_of_operands();
	}

	// Метод возвращает объект класса Poliz, который содержит ПОЛИЗ
	Pol GetA()
	{
		return poli;
	}
};