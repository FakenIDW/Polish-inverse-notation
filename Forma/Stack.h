#pragma once
// Объявление шаблонного класса Stec (стек)
template <typename T>
class Stec {
private:
	T* mem;      // Указатель на массив элементов стека
	int size;    // Размер выделенной памяти для стека
	int count;   // Текущее количество элементов в стеке

public:
	// Конструктор класса, инициализирует size, count и выделяет память под стек
	Stec(int _size = 20) {
		size = _size;
		count = 0;
		mem = new T[size];  // Выделение памяти для стека
		for (int i = 0; i < size; i++) {
			mem[i] = T();  // Инициализация элементов значениями по умолчанию
		}
	}

	// Конструктор копирования, копирует значения из другого объекта типа Stec
	Stec(const Stec& tmp) {
		size = tmp.size;
		count = tmp.count;
		mem = new T[size];
		for (int i = 0; i < size; i++) {
			mem[i] = tmp.mem[i];
		}
	}

	// Деструктор, освобождает выделенную память при уничтожении объекта
	~Stec() {
		delete[] mem;
	}

	// Перегруженный оператор присваивания
	Stec& operator =(Stec<T> tmp) {
		if (size != tmp.size) {
			if (size != 0) {
				delete[] mem;
			}
			size = tmp.size;
			mem = new T[size];
		}
		count = tmp.count;
		for (int i = 0; i < size; i++) {
			mem[i] = tmp.mem[i];
		}
		return *this;
	}

	// Добавляет элемент в конец стека
	void pushback(T val) {
		if (count < size) {
			mem[count++] = val;
		}
	}

	// Возвращает верхний элемент стека без удаления
	T top() {
		if (count > 0) {
			return mem[count - 1];
		}
		else {
			T r(0);
			return r;
		}
	}

	// Удаляет верхний элемент стека и возвращает его значение
	T pop() {
		if (count > 0) {
			return mem[--count];
		}
		else {
			T r(0);
			return r;
		}
	}

	// Проверяет, полон ли стек
	int is_full() {
		if (count == size) {
			return 1;
		}
		else {
			return 0;
		}
	}

	// Проверяет, пуст ли стек
	int is_empty() {
		if (count == 0) {
			return 1;
		}
		else {
			return 0;
		}
	}

	// Возвращает текущее количество элементов в стеке
	int Getcount() {
		return count;
	}
};