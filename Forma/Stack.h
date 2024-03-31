#pragma once
// ���������� ���������� ������ Stec (����)
template <typename T>
class Stec {
private:
	T* mem;      // ��������� �� ������ ��������� �����
	int size;    // ������ ���������� ������ ��� �����
	int count;   // ������� ���������� ��������� � �����

public:
	// ����������� ������, �������������� size, count � �������� ������ ��� ����
	Stec(int _size = 20) {
		size = _size;
		count = 0;
		mem = new T[size];  // ��������� ������ ��� �����
		for (int i = 0; i < size; i++) {
			mem[i] = T();  // ������������� ��������� ���������� �� ���������
		}
	}

	// ����������� �����������, �������� �������� �� ������� ������� ���� Stec
	Stec(const Stec& tmp) {
		size = tmp.size;
		count = tmp.count;
		mem = new T[size];
		for (int i = 0; i < size; i++) {
			mem[i] = tmp.mem[i];
		}
	}

	// ����������, ����������� ���������� ������ ��� ����������� �������
	~Stec() {
		delete[] mem;
	}

	// ������������� �������� ������������
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

	// ��������� ������� � ����� �����
	void pushback(T val) {
		if (count < size) {
			mem[count++] = val;
		}
	}

	// ���������� ������� ������� ����� ��� ��������
	T top() {
		if (count > 0) {
			return mem[count - 1];
		}
		else {
			T r(0);
			return r;
		}
	}

	// ������� ������� ������� ����� � ���������� ��� ��������
	T pop() {
		if (count > 0) {
			return mem[--count];
		}
		else {
			T r(0);
			return r;
		}
	}

	// ���������, ����� �� ����
	int is_full() {
		if (count == size) {
			return 1;
		}
		else {
			return 0;
		}
	}

	// ���������, ���� �� ����
	int is_empty() {
		if (count == 0) {
			return 1;
		}
		else {
			return 0;
		}
	}

	// ���������� ������� ���������� ��������� � �����
	int Getcount() {
		return count;
	}
};