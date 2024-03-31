//// ������ ��� ������ STACK
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
//    // ���� ������� �����
//    cout << "������� ������ �����: ";
//    cin >> size;
//
//    // �������� ����� ��������� �������
//    Stec<int> myStack(size);
//
//    // ���� ��������� �����
//    cout << "������� �������� �����:" << endl;
//    for (int i = 0; i < size; ++i) {
//        int element;
//        cout << "������� �" << i + 1 << ": ";
//        cin >> element;
//        myStack.pushback(element);
//    }
//    cout << endl << endl;
//
//    if (myStack.is_full()) { cout << "���� �����" << endl; } // �������� �������
//    if (myStack.is_empty()) { cout << "���� ����" << endl; } // �������� �������
//
//
//    Stec<int> mystack2(myStack); // ����������� �����������
//    while (!mystack2.is_empty())
//    {
//        cout << "����������� �����������:" << mystack2.pop() << " " << endl;
//    }
//
//
//    Stec<int> mystack3 = myStack; // �������� ������������
//    while (!mystack3.is_empty())
//    {
//        cout << "������������: " << mystack3.pop() << " " << endl;
//    }
//
//    // ����� ��������� �����
//    cout << "�������� �����: ";
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
//// ������ ��� ������ �������
//#include <iostream>
//#include "Table.h"
//
//int main() {
//    setlocale(LC_ALL, "rus");
//    int size;
//
//    // ���� ������� �������
//    cout << "������� ������ �������: ";
//    cin >> size;
//
//    // ������� ������ ������ Tabl
//    Table table(size);
//
//
//    // ��������� �������� � ����������
//    for (int i = 0; i < size; ++i) {
//        string name;
//        double value;
//
//        cout << "������� �������� �������� �" << i + 1 << ": ";
//        cin >> name;
//
//        cout << "������� �������� �������� � " << i + 1 << ": ";
//        cin >> value;
//
//        table.add(entry(name, value));
//    }
//
//    // �����������
//    Table table2(table);
//    cout << endl << "�����������: " << endl;
//    for (int i = 0; i < table2.kolichestvo_elementov(); i++)
//    {
//        cout << table2[i].poluchim_imya() << " " << table2[i].poluchim_znachenie() << endl;
//    }
//
//
//    // ������������
//    Table table3 = table;
//    cout << endl << "������������: " << endl;
//    for (int i = 0; i < table3.kolichestvo_elementov(); i++)
//    {
//        cout << table3[i].poluchim_imya() << " " << table3[i].poluchim_znachenie() << endl;
//    }
//    cout << endl;
//
//
//    // ������� ���������� �������
//    cout << "������� ��������: " << endl;
//    if (table.kolichestvo_elementov() > 0) {
//        for (int i = 0; i < table.kolichestvo_elementov(); ++i) {
//            cout << table[i].poluchim_imya() << " - " << table[i].poluchim_znachenie() << endl;
//        }
//    }
//
//
//
//    // �������� ������� � ������� �������
//    if (!table.isFull()) { cout << "������� �� ������." << endl << endl; }
//    else if (table.isEmpty()) { cout << "������� �����" << endl << endl; }
//    else { cout << endl << "������� ������" << endl << endl;; }
//
//
// 
//  // ������� ������ � ������
//    string del;
//    cout << "������� �������� ������, ����� ������� ��� " << endl;
//    cin >> del;
//    table.del(del);
//
//
//
// // ����� ������� � �������� �������
//    cout << endl << "������� � �������� ���������" << endl;
//    if (table.kolichestvo_elementov() > 0) {
//        for (int i = 0; i < table.kolichestvo_elementov(); ++i) {
//            cout << table[i].poluchim_imya() << " - " << table[i].poluchim_znachenie() << endl;
//        }
//    }
//
//
//// �������� �������� ������ �� �����
//    cout << endl << "������� ��� ������, ����� ������ � �������� " << endl;
//    string name;
//    cin >> name;
//    double res = table.serchN(name);
//    cout << endl << "�������� ������ ��� ���������: " << name << " - " << res << endl;
//
//
//
//// ����� �������� (��� � ��������) ������� �� �������
//    cout << endl << "������� ������� ����� �������, ����� �������� ��� � �������� " << endl;
//    int n;
//    cin >> n;
//    entry Index = table[n];
//    cout << "������ � �������� " << n << ": " << Index.poluchim_imya() << " - " << Index.poluchim_znachenie() << endl;
//
//
//    return 0;
//}
//
//
//
//

















//// ������ ��� ������
//// ��������� �� ����������� ������ x*y/w^(a-b)^2+25*(x+y)^(a-b)-17
//
//#include "Poliz.h"
//#include <iostream>
//using namespace std;
//int main()
//{
//	setlocale(LC_ALL, "Russian");
//	string expression;
//	cout << "������� ������: " << endl;
//	cin >> expression;  // ������ ���������
//	Pol expression2(expression); // ���������� ��� �������� ��������� ������
//	cout << "�������� ��������� ������: " << expression2.PoluchimPoliZ() << endl; // ��������� � �������� �������� ������
//	// ������� ���������� � ������� ���������
//	Table Tabliza = *expression2.table_of_operands();
//	for (int i = 0; i < Tabliza.kolichestvo_elementov(); ++i) {
//		entry operands = Tabliza[i];
//		cout << i << ") " << operands.poluchim_imya() << " = " << operands.poluchim_znachenie() << endl;
//	}
//	// �������������  �������� ��� ��������� �� ������� (������� � 0)
//	cout << endl << "������� ������ � �������� ���������" << endl << endl;
//	int number; int znachenie;
//	for(int i = 0; i < Tabliza.kolichestvo_elementov(); ++i){
//		cout << "������� ������: ";  cin >> number; cout << endl;
//		cout << "������� ����� �������� ��� �������� ������� �������: ";  cin >> znachenie; cout << endl;
//		expression2.SetVar(number, znachenie);
//	}
//	// �������  ���������� � ������� ��������� � ������ ����������
//	cout << endl << "���������� ������� ���������: " << endl;
//	Tabliza = *expression2.table_of_operands();
//
//	for (int i = 0; i < Tabliza.kolichestvo_elementov(); ++i){
//		entry operands = Tabliza[i];
//		cout << i << ") " << operands.poluchim_imya() << " = " << operands.poluchim_znachenie() << endl;
//	} cout << endl;
//
//
//
//	// ������ ������ ��� ������������ �����������
//	Pol Poliz2(expression);
//	cout << "����������� �����������: " << Poliz2.PoluchimPoliZ() << endl;
//
//
//	// ������ ������ ��� �������� ������������
//	Pol Poliz3;
//	Poliz3 = expression;
//	cout << "������������:            " << Poliz3.PoluchimPoliZ() << endl;
//	return 0;
//}


//
//// ������ ��� ���������
//// ��������� �� ����������� ������ x*y/w^(a-b)^2+25*(x+y)^(a-b)-17
//
//#include "Arifmetic.h"
//#include <iostream>
//int main()
//{
//	setlocale(LC_ALL, "Russian");
//	string expression;
//	cout << "������� ������: ";
//	cin >> expression;  // ������ ���������
//	Pol expression2(expression);
//	cout << endl << "�������� ��������� ������: " << expression2.PoluchimPoliZ() << endl << endl;
//	arifmetic zn(expression);
//	arifmetic zn2(zn);
//	arifmetic zn3 = zn2;
//	cout << "������� ����������:" << endl;
//	for (int i = 0; i < zn.vivedem_tablitsy()->kolichestvo_elementov(); i++){
//		cout << i << ") " << zn.vivedem_tablitsy()->operator[](i).poluchim_imya() << " = " << zn.vivedem_tablitsy()->operator[](i).poluchim_znachenie() << endl;
//	}
//	cout << endl << "������� ����� �������� � �������: " << endl;
//	for (int i = 0; i < zn.vivedem_tablitsy()->kolichestvo_elementov(); i++){
//		cout << i << ") " << zn.vivedem_tablitsy()->operator[](i).poluchim_imya() << " = "; // ������ ����� �������� � �������
//
//		int temp; cin >> temp;
//		zn.Index(i, temp);
//	}
//	cout << endl << "������� ���������� � ��������� ����������:" << endl;
//	for (int i = 0; i < zn.vivedem_tablitsy()->kolichestvo_elementov(); i++){
//		cout << i << ") " << zn.vivedem_tablitsy()->operator[](i).poluchim_imya() << " = ";        // ��� ��������
//		cout << zn.vivedem_tablitsy()->operator[](i).poluchim_znachenie() << endl;        // ����� �������� ��������
//	}
//	cout << "��������� ����������: " << zn.poshitaem() << endl;
//	cout << "��������� ���������� ������������ �����������: " << zn2.poshitaem() << endl;
//	cout << "��������� ���������� �������� ������������: " << zn3.poshitaem() << endl;
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

[STAThreadAttribute] // ��������� ������� ���� � ��������� ������ ������

void main()
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(true);
	Forma::MyForm form;
	Application::Run(% form);
}