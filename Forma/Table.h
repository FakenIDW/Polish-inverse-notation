#include <string>
#include "Entry.h"
#pragma once
class Table {
private:
	entry* mem;      // ��������� �� ������ �������� ������ zapis
	int size, count;  // ������ ������� � ������� ���������� ��������� � �������

public:
	// ������� ��� ������ ������� �������� �� ����� (�����)
	int serchN(string key)
	{
		int i = 0;
		int res = -1;

		// ������ �� ������� � ��������� ����� � ������ ��������
		while (res == -1 && i < count)
		{
			if (key == mem[i].poluchim_imya())
			{
				res = i;
			}
			i++;
		}
		return res;
	}

	// ����������� ������ Tabl � ���������� �� ���������
	Table(int _size = 0)
	{
		size = _size;
		count = 0;
		mem = new entry[size];  // ��������� ������ ��� ������ �������� ������ zapis

		// ������������� ������� �������� ������ zapis
		for (int i = 0; i < size; i++)
		{
			mem[i] = entry("", 0);
		}
	}

	// ���������� ������ Tabl, ����������� ���������� ������
	~Table()
	{
		delete[] mem;
	}

	// ����������� ����������� ������ Tabl
	Table(const Table& tmp)
	{
		size = tmp.size;
		count = tmp.count;
		mem = new entry[size];

		// ����������� ��������� �������
		for (int i = 0; i < size; i++)
		{
			mem[i] = tmp.mem[i];
		}
	}

	// �����, ������������ ���������� ��������� � �������
	int kolichestvo_elementov()
	{
		return count;
	}

	// ���������� ��������� ������������ ��� ������ Tabl
	Table& operator =(Table tmp)
	{
		// �������� ������� �������
		if (size != tmp.size)
		{
			if (size != 0)
			{
				delete[] mem;
			}
			size = tmp.size;
			mem = new entry[size];
		}
		count = tmp.count;

		// ����������� ��������� �������
		for (int i = 0; i < size; i++)
		{
			mem[i] = tmp.mem[i];
		}
		return *this;
	}

	// ���������� �������� � ������
	void add(entry tmp)
	{
		int l = serchN(tmp.poluchim_imya());

		// ���� ������� � ����� ������ ��� ����������, �������� ���
		if (l > -1)
		{
			mem[l] = tmp;
		}
		// ����� ��������� ����� ������� � ����� �������
		else
		{
			mem[count++] = tmp;
		}
	}

	// �������� �������� �� ������� �� ����� (�����)
	void del(string key)
	{
		int c = serchN(key);
		if (c > -1)
		{
			mem[c] = mem[--count];
		}
	}

	// ��������, ���� �� ������
	int isEmpty()
	{
		if (count == 0)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}

	// ��������, ����� �� ������
	int isFull()
	{
		if (count == size)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}

	// ����� �������� �������� �� ����� � ����������� ��������
	double searchI(string key)
	{
		int l = -1, i = 0;
		double res = 0;

		// ����� �������� �� �����
		while ((l == -1) && (i <= count)) {
			if (key == mem[i].poluchim_imya()) {
				l = i;
			}
			i++;
		}

		// ���� ������� ������, ���������� ��� ��������, ����� ���������� -1
		if (l > -1) {
			return mem[l].poluchim_znachenie();
		}
		return -1;
	}

	// ���������� ��������� ���������� ��� ������ Tabl
	entry operator [](int key)
	{
		entry res;
		if (key > -1 && key <= count)
		{
			res = mem[key];
		}
		return res;
	}

	// ��������� �������� �������� �� �������
	void setWar(int n, double k)
	{
		if (n >= size) return;
		mem[n].postavim_novoe_znachenie(k);
	}

};