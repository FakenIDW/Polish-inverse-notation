#pragma once
#include <string>
using namespace std;

class entry
{
private:
	string Name;
	double value;
public:
	// ����������� ������ entry � ����������� �� ���������.
	entry(string _Name = "", double _value = 0.0)
	{
		Name = _Name;
		value = _value;
	}
	// �������-����, ������������ �������� ���������� ����� Name.
	string poluchim_imya()
	{
		return Name;
	}
	// �������-����, ������������ �������� ���������� ����� value.
	double poluchim_znachenie()
	{
		return value;
	}
	// �������-����, ��������������� �������� ���������� ����� value.
	void postavim_novoe_znachenie(double _value)
	{
		value = _value;
	}
};