#pragma once
#include <string>
using namespace std;

class entry
{
private:
	string Name;
	double value;
public:
	// Конструктор класса entry с параметрами по умолчанию.
	entry(string _Name = "", double _value = 0.0)
	{
		Name = _Name;
		value = _value;
	}
	// Функция-член, возвращающая значение приватного члена Name.
	string poluchim_imya()
	{
		return Name;
	}
	// Функция-член, возвращающая значение приватного члена value.
	double poluchim_znachenie()
	{
		return value;
	}
	// Функция-член, устанавливающая значение приватного члена value.
	void postavim_novoe_znachenie(double _value)
	{
		value = _value;
	}
};