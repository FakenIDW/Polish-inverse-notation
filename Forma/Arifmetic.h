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

	// ����������� � ����������� �� ���������
	arifmetic(string str = "")
	{
		poli = Pol(str);
	}

	// ����������
	~arifmetic() {}

	// ����������� �����������
	arifmetic(const arifmetic& tmp)
	{
		poli = tmp.poli;
		st = tmp.st;
	}

	// �������� ������������
	arifmetic& operator=(arifmetic tmp)
	{
		poli = tmp.poli;
		st = tmp.st;
		return *this;
	}

	// ����� ��������� ���������� ��������������� ���������, ��������������� � ���� ������
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


	// ����� ��������� ������ �������� �� �������
	void Index(int n, float k)
	{
		if (n > -1)
		{
			poli.SetVar(n, k);
		}
	}
	// ����� ���������� ������� ���������
	Table vivedem_tablitsy()
	{
		return poli.table_of_operands();
	}

	// ����� ���������� ������ ������ Poliz, ������� �������� �����
	Pol GetA()
	{
		return poli;
	}
};