#pragma once
#include "Table.h"
#include "Stack.h"
#include "Entry.h"
#include <string>
#include <iostream>
using namespace std;


class Pol {

private:
	// ����� ��� ���������� ������ �� ��������� ������� (������� �����������)
	void StringToWond(string str, int& k, string* w)
	{

		string zn = "+-*/^()";

		k = 0; // ������������� �������� �������
		str += " ";

		for (int i = 0; i < str.length(); i++)
		{

			int l = zn.find(str[i]); // ����� �������� ������� � ������ `zn`
			if (l >= 0 && l < zn.length())
			{
				if (w[k].length() > 0)
				{
					k++; // ���� ������� ����� �� ������, ����������� ������� �������
				}
				w[k] = str[i]; // ����������� �������� ������ �������� �������� �������
				w[++k] = ""; // ������������� ������ ������
			}

			else
			{   // ���� ������� ������ - ������ � ������� ����� �� ������, �������������� ����� �����
				if (str[i] == ' ')
				{
					if (w[k].length() > 0)
					{
						w[++k] = "";
					}
				}
				else // ���� ������� ������ �� �������� ������ �������� ��� ��������, ��������� ��� � �������� ������
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

	// ����� �������� ������� ����������� ���������� � ���������� �������
	void madePriorityTable()
	{
		PriorityTable = Table(20);
		PriorityTable.add(entry("+", 1.0));
		PriorityTable.add(entry("-", 1.0));

		PriorityTable.add(entry("*", 2.0));
		PriorityTable.add(entry("/", 2.0));

		PriorityTable.add(entry("^", 3.0));
	}

	// ��������� ����������� ������ � ����
	void workLeft()
	{
		st.pushback(entry("(", -1.0));
	}


	// ����������� ��������� �� ����� � ������ ������ �� ��� ���, ���� �� �������� ����������� ������
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



	// ��������� ������� � ������ ������ � ������� ���������

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




	// ������������ ��������� � ��������� �� � ������ ������ � ������������ � �� ������������

	void workOperator(string str, int p)
	{
		while ((st.is_empty() == 0) && (st.top().poluchim_znachenie() >= p))
		{
			mem[count++] = st.pop().poluchim_imya();
		}
		st.pushback(entry(str, p));
	}


	// ��������� ������������ ������, ���������� ��� ��������� �� ����� � ������ ������
	void workEnd()
	{
		while (st.is_empty() == 0)
		{
			mem[count++] = st.pop().poluchim_imya();
		}
	}



	// ����� ������ ������
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
	// �����������
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

	// ����������� �����������
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

	// ����������
	~Pol()
	{
		delete[]mem;
	}
	int GetCount()
	{
		return count;
	}


	// ��������������� �������� ������������
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


	// ����� ��� ������� � ��������� ������
	string operator[](int R)
	{
		string str = "";

		if (R <= count && R >= 0)
		{
			str = mem[R];
		}

		return str;
	}



	// ����� �������� ������, �������������� �����
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



	// ����� ��� ������� � ������� ���������
	Table table_of_operands()
	{
		return variables;
	}



	// ���� ����� ���������� ���������� ��������� � ������
	int kolichestvo_elementov()
	{
		return count;
	}



	// ���� ����� ���������� ������ ������� ������
	int getSIZE()
	{
		return size;
	}



	// ����� ������������� ����� �������� �������� ��� ������ � �������� n � ������� ���������
	void SetVar(int n, double k)
	{
		variables.setWar(n, k);
	}
};