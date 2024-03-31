#include <string>
#include "Entry.h"
#pragma once
class Table {
private:
	entry* mem;      // Указатель на массив объектов класса zapis
	int size, count;  // Размер массива и текущее количество элементов в массиве

public:
	// Функция для поиска индекса элемента по имени (ключу)
	int serchN(string key)
	{
		int i = 0;
		int res = -1;

		// Проход по массиву и сравнение ключа с именем элемента
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

	// Конструктор класса Tabl с параметром по умолчанию
	Table(int _size = 0)
	{
		size = _size;
		count = 0;
		mem = new entry[size];  // Выделение памяти под массив объектов класса zapis

		// Инициализация массива объектов класса zapis
		for (int i = 0; i < size; i++)
		{
			mem[i] = entry("", 0);
		}
	}

	// Деструктор класса Tabl, освобождает выделенную память
	~Table()
	{
		delete[] mem;
	}

	// Конструктор копирования класса Tabl
	Table(const Table& tmp)
	{
		size = tmp.size;
		count = tmp.count;
		mem = new entry[size];

		// Копирование элементов массива
		for (int i = 0; i < size; i++)
		{
			mem[i] = tmp.mem[i];
		}
	}

	// Метод, возвращающий количество элементов в таблице
	int kolichestvo_elementov()
	{
		return count;
	}

	// Перегрузка оператора присваивания для класса Tabl
	Table& operator =(Table tmp)
	{
		// Проверка размера массива
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

		// Копирование элементов массива
		for (int i = 0; i < size; i++)
		{
			mem[i] = tmp.mem[i];
		}
		return *this;
	}

	// Добавление элемента в массив
	void add(entry tmp)
	{
		int l = serchN(tmp.poluchim_imya());

		// Если элемент с таким именем уже существует, заменяем его
		if (l > -1)
		{
			mem[l] = tmp;
		}
		// Иначе добавляем новый элемент в конец массива
		else
		{
			mem[count++] = tmp;
		}
	}

	// Удаление элемента из массива по ключу (имени)
	void del(string key)
	{
		int c = serchN(key);
		if (c > -1)
		{
			mem[c] = mem[--count];
		}
	}

	// Проверка, пуст ли массив
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

	// Проверка, полон ли массив
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

	// Поиск значения элемента по ключу и возвращение значения
	double searchI(string key)
	{
		int l = -1, i = 0;
		double res = 0;

		// Поиск элемента по ключу
		while ((l == -1) && (i <= count)) {
			if (key == mem[i].poluchim_imya()) {
				l = i;
			}
			i++;
		}

		// Если элемент найден, возвращаем его значение, иначе возвращаем -1
		if (l > -1) {
			return mem[l].poluchim_znachenie();
		}
		return -1;
	}

	// Перегрузка оператора индексации для класса Tabl
	entry operator [](int key)
	{
		entry res;
		if (key > -1 && key <= count)
		{
			res = mem[key];
		}
		return res;
	}

	// Установка значения элемента по индексу
	void setWar(int n, double k)
	{
		if (n >= size) return;
		mem[n].postavim_novoe_znachenie(k);
	}

};