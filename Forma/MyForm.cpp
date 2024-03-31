//// ТЕСТЕР ДЛЯ КЛАССА STACK
//#include <iostream>
//#include "Stack.h"
//using namespace std;
//
//int main() {
//
//    setlocale(LC_ALL, "rus");
//
//    int size;
//
//    // Ввод размера стека
//    cout << "Введите размер стека: ";
//    cin >> size;
//
//    // Создание стека заданного размера
//    Stec<int> myStack(size);
//
//    // Ввод элементов стека
//    cout << "Введите элементы стека:" << endl;
//    for (int i = 0; i < size; ++i) {
//        int element;
//        cout << "Элемент №" << i + 1 << ": ";
//        cin >> element;
//        myStack.pushback(element);
//    }
//    cout << endl << endl;
//
//    if (myStack.is_full()) { cout << "Стек полон" << endl; } // Проверка полноты
//    if (myStack.is_empty()) { cout << "Стек пуст" << endl; } // Проверка пустоты
//
//
//    Stec<int> mystack2(myStack); // Конструктор копирования
//    while (!mystack2.is_empty())
//    {
//        cout << "Конструктор копирования:" << mystack2.pop() << " " << endl;
//    }
//
//
//    Stec<int> mystack3 = myStack; // Операция присваивания
//    while (!mystack3.is_empty())
//    {
//        cout << "Присваивания: " << mystack3.pop() << " " << endl;
//    }
//
//    // Вывод элементов стека
//    cout << "Элементы стека: ";
//    while (!myStack.is_empty()) {
//        cout << myStack.pop() << " ";
//    }
//    cout << endl;
//
//    return 0;
//    system("pause");
//}
//





//
//
//// ТЕСТЕР ДЛЯ КЛАССА ТАБЛИЦА
//#include <iostream>
//#include "Table.h"
//
//int main() {
//    setlocale(LC_ALL, "rus");
//    int size;
//
//    // Ввод размера таблицы
//    cout << "Введите размер таблицы: ";
//    cin >> size;
//
//    // Создаем объект класса Tabl
//    Table table(size);
//
//
//    // Добавляем элементы с клавиатуры
//    for (int i = 0; i < size; ++i) {
//        string name;
//        double value;
//
//        cout << "Введите название элемента №" << i + 1 << ": ";
//        cin >> name;
//
//        cout << "Введите значение элемента № " << i + 1 << ": ";
//        cin >> value;
//
//        table.add(entry(name, value));
//    }
//
//    // Копирования
//    Table table2(table);
//    cout << endl << "Копирования: " << endl;
//    for (int i = 0; i < table2.kolichestvo_elementov(); i++)
//    {
//        cout << table2[i].poluchim_imya() << " " << table2[i].poluchim_znachenie() << endl;
//    }
//
//
//    // Присваивания
//    Table table3 = table;
//    cout << endl << "Присваивания: " << endl;
//    for (int i = 0; i < table3.kolichestvo_elementov(); i++)
//    {
//        cout << table3[i].poluchim_imya() << " " << table3[i].poluchim_znachenie() << endl;
//    }
//    cout << endl;
//
//
//    // Выводим содержимое массива
//    cout << "Таблица содержит: " << endl;
//    if (table.kolichestvo_elementov() > 0) {
//        for (int i = 0; i < table.kolichestvo_elementov(); ++i) {
//            cout << table[i].poluchim_imya() << " - " << table[i].poluchim_znachenie() << endl;
//        }
//    }
//
//
//
//    // Проверка полноты и пустоты таблицы
//    if (!table.isFull()) { cout << "Таблица не полная." << endl << endl; }
//    else if (table.isEmpty()) { cout << "Таблица пуста" << endl << endl; }
//    else { cout << endl << "Таблица полная" << endl << endl;; }
//
//
// 
//  // Удаляем запись с именем
//    string del;
//    cout << "Введите название строки, чтобы удалить его " << endl;
//    cin >> del;
//    table.del(del);
//
//
//
// // Вывод таблицы с удалённой записью
//    cout << endl << "Таблица с удалённым элементом" << endl;
//    if (table.kolichestvo_elementov() > 0) {
//        for (int i = 0; i < table.kolichestvo_elementov(); ++i) {
//            cout << table[i].poluchim_imya() << " - " << table[i].poluchim_znachenie() << endl;
//        }
//    }
//
//
//// Получаем значение строки по имени
//    cout << endl << "Введите имя строки, чтобы узнать её значение " << endl;
//    string name;
//    cin >> name;
//    double res = table.serchN(name);
//    cout << endl << "Значение строки под названием: " << name << " - " << res << endl;
//
//
//
//// Вывод элемента (имя и значение) таблицы по индексу
//    cout << endl << "Введите введите номер индекса, чтобы получить имя и значение " << endl;
//    int n;
//    cin >> n;
//    entry Index = table[n];
//    cout << "Запись с индексом " << n << ": " << Index.poluchim_imya() << " - " << Index.poluchim_znachenie() << endl;
//
//
//    return 0;
//}
//
//
//
//

















//// Тестер для ПОЛИЗА
//// Выражение из контрольной работы x*y/w^(a-b)^2+25*(x+y)^(a-b)-17
//
//#include "Poliz.h"
//#include <iostream>
//using namespace std;
//int main()
//{
//	setlocale(LC_ALL, "Russian");
//	string expression;
//	cout << "Введите строку: " << endl;
//	cin >> expression;  // Вводим выражение
//	Pol expression2(expression); // Переменная для Польской инверсной записи
//	cout << "Польская инверсная запись: " << expression2.PoluchimPoliZ() << endl; // Переводим в Польскую инвёрсную запись
//	// Выводим информацию о таблице операндов
//	Table Tabliza = *expression2.table_of_operands();
//	for (int i = 0; i < Tabliza.kolichestvo_elementov(); ++i) {
//		entry operands = Tabliza[i];
//		cout << i << ") " << operands.poluchim_imya() << " = " << operands.poluchim_znachenie() << endl;
//	}
//	// Устанавливаем  значения для операндов по индексу (начиная с 0)
//	cout << endl << "Введите индекс и значения операндов" << endl << endl;
//	int number; int znachenie;
//	for(int i = 0; i < Tabliza.kolichestvo_elementov(); ++i){
//		cout << "Введите индекс: ";  cin >> number; cout << endl;
//		cout << "Введите новое значение для операнда данного индекса: ";  cin >> znachenie; cout << endl;
//		expression2.SetVar(number, znachenie);
//	}
//	// Выводим  информацию о таблице операндов с новыми значениями
//	cout << endl << "Обновлённая таблица операндов: " << endl;
//	Tabliza = *expression2.table_of_operands();
//
//	for (int i = 0; i < Tabliza.kolichestvo_elementov(); ++i){
//		entry operands = Tabliza[i];
//		cout << i << ") " << operands.poluchim_imya() << " = " << operands.poluchim_znachenie() << endl;
//	} cout << endl;
//
//
//
//	// Вторая строка для конструктора копирования
//	Pol Poliz2(expression);
//	cout << "Конструктор копирования: " << Poliz2.PoluchimPoliZ() << endl;
//
//
//	// Третья строка для операции присваивания
//	Pol Poliz3;
//	Poliz3 = expression;
//	cout << "Присваивания:            " << Poliz3.PoluchimPoliZ() << endl;
//	return 0;
//}


//
//// Тестер для арифметик
//// Выражение из контрольной работы x*y/w^(a-b)^2+25*(x+y)^(a-b)-17
//
//#include "Arifmetic.h"
//#include <iostream>
//int main()
//{
//	setlocale(LC_ALL, "Russian");
//	string expression;
//	cout << "Введите строку: ";
//	cin >> expression;  // Вводим выражение
//	Pol expression2(expression);
//	cout << endl << "Польская инверсная запись: " << expression2.PoluchimPoliZ() << endl << endl;
//	arifmetic zn(expression);
//	arifmetic zn2(zn);
//	arifmetic zn3 = zn2;
//	cout << "Таблица переменных:" << endl;
//	for (int i = 0; i < zn.vivedem_tablitsy()->kolichestvo_elementov(); i++){
//		cout << i << ") " << zn.vivedem_tablitsy()->operator[](i).poluchim_imya() << " = " << zn.vivedem_tablitsy()->operator[](i).poluchim_znachenie() << endl;
//	}
//	cout << endl << "Введите новые значения в таблицу: " << endl;
//	for (int i = 0; i < zn.vivedem_tablitsy()->kolichestvo_elementov(); i++){
//		cout << i << ") " << zn.vivedem_tablitsy()->operator[](i).poluchim_imya() << " = "; // Вводим новые значения в таблицу
//
//		int temp; cin >> temp;
//		zn.Index(i, temp);
//	}
//	cout << endl << "Таблица переменных с введёнными значениями:" << endl;
//	for (int i = 0; i < zn.vivedem_tablitsy()->kolichestvo_elementov(); i++){
//		cout << i << ") " << zn.vivedem_tablitsy()->operator[](i).poluchim_imya() << " = ";        // Имя элемента
//		cout << zn.vivedem_tablitsy()->operator[](i).poluchim_znachenie() << endl;        // Новое значение элемента
//	}
//	cout << "Результат вычислений: " << zn.poshitaem() << endl;
//	cout << "Результат вычислений конструктора копирования: " << zn2.poshitaem() << endl;
//	cout << "Результат вычислений операции присваивания: " << zn3.poshitaem() << endl;
//	return 0;
//}






#include "MyForm.h"

#include <iostream>
#include "Poliz.h"
#include "Table.h"
#include "Stack.h"
#include "Entry.h"
#include <string>
#include "Arifmetic.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute] // Запускаем функцию ниже в отдельном потоке данных

void main()
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(true);
	Forma::MyForm form;
	Application::Run(% form);
}