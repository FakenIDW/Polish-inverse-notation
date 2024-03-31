#pragma once
#include "Arifmetic.h"
#include <string>
#include <msclr\marshal_cppstd.h>
namespace Forma {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace std;


	Table tab;
	string str;
	arifmetic a;


	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^ textBox1;
	protected:
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::DataGridView^ dataGridView1;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;


	protected:

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// textBox1
			// 
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox1->Location = System::Drawing::Point(12, 46);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(612, 29);
			this->textBox1->TabIndex = 1;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(12, 169);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(219, 23);
			this->button1->TabIndex = 3;
			this->button1->Text = L"Таблица";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(27, 36);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(110, 13);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Введите выражение";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(27, 98);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(280, 13);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Полученное выражение в Польско инвёрсной записи";
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(12, 117);
			this->textBox2->Name = L"textBox2";
			this->textBox2->ReadOnly = true;
			this->textBox2->Size = System::Drawing::Size(612, 20);
			this->textBox2->TabIndex = 4;
			// 
			// dataGridView1
			// 
			this->dataGridView1->AllowUserToAddRows = false;
			this->dataGridView1->AllowUserToDeleteRows = false;
			this->dataGridView1->AllowUserToResizeColumns = false;
			this->dataGridView1->AllowUserToResizeRows = false;
			this->dataGridView1->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->dataGridView1->BackgroundColor = System::Drawing::SystemColors::ControlDark;
			this->dataGridView1->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Cursor = System::Windows::Forms::Cursors::Default;
			this->dataGridView1->GridColor = System::Drawing::SystemColors::Desktop;
			this->dataGridView1->Location = System::Drawing::Point(630, 20);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowHeadersVisible = false;
			this->dataGridView1->RowHeadersWidth = 4;
			this->dataGridView1->Size = System::Drawing::Size(284, 278);
			this->dataGridView1->TabIndex = 7;
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(15, 278);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(253, 20);
			this->textBox3->TabIndex = 8;
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(15, 249);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(119, 23);
			this->button2->TabIndex = 4;
			this->button2->Text = L"Посчитать";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(12, 20);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(110, 13);
			this->label3->TabIndex = 9;
			this->label3->Text = L"Введите выражение";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(12, 88);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(280, 13);
			this->label4->TabIndex = 10;
			this->label4->Text = L"Полученное выражение в Польско инвёрсной записи";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(926, 333);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Name = L"MyForm";
			this->Text = L"Полиз";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}

		bool is_num(String^ s) {
			int  i = 0;
			int l;
			if (i == 0 && s[i] == '-') { i = 1; }
			if (s->Length > i) {
				l = 0;
				for (int i = 0; i < s->Length; i++) {
					if (s[i] == ',') {
						if (l == 1) { return false; }
						l = 1;
					}
					else {
						if (!Char::IsNumber(s[i])) {
							return false;
						}
					}

				}
			}
			return true;
		}

		void cleardataGrid() {
			dataGridView1->RowCount = 0;
			dataGridView1->ColumnCount = 0;
		}
		void heightdataGrid(int k) {
			if (k > 0) {
				dataGridView1->RowTemplate->Height = (20);
			}

		}
		void addTable(int k) {
			dataGridView1->RowCount = k;
			dataGridView1->ColumnCount = 2;
		}

#pragma endregion
	private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}

	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e)
	{
		str = msclr::interop::marshal_as<std::string>(textBox1->Text);
		a = arifmetic(str);
		int k = a.vivedem_tablitsy().kolichestvo_elementov();
		cleardataGrid();
		heightdataGrid(k);
		addTable(k);
		for (int i = 0; i < k; i++) {
			string m = a.vivedem_tablitsy()[i].poluchim_imya();
			dataGridView1->Rows[i]->Cells[0]->Value = gcnew String(m.c_str());
			if (m > "0" && m < "9") {
				dataGridView1->Rows[i]->Cells[1]->Value = Convert::ToDouble(dataGridView1->Rows[i]->Cells[0]->Value);
				dataGridView1->Rows[i]->Cells[1]->ReadOnly = true;
			}
		}
		string pol = a.GetA().PoluchimPoliZ();
		textBox2->Text = gcnew String(pol.c_str());
	}

		   private: System::Void dataGridView1_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
			   int i = dataGridView1->CurrentRow->Index;
			   int j = dataGridView1->CurrentCell->ColumnIndex;
			   str = msclr::interop::marshal_as<std::string>(textBox1->Text);
			   a = arifmetic(str);
			   tab = a.vivedem_tablitsy();
			   if (j == 0) { dataGridView1->Rows[i]->Cells[j]->Value = gcnew String(tab[i].poluchim_imya().c_str()); }
			   string m = tab[i].poluchim_imya();
			   if (m[0] > '0' && m[0] < '9') { dataGridView1->Rows[i]->Cells[1]->Value = gcnew String(tab[i].poluchim_imya().c_str()); }
			   if (j == 1) {
				   float k = 0;
				   if (is_num(Convert::ToString(dataGridView1->Rows[i]->Cells[1]->Value))) {
					   k = Convert::ToDouble(dataGridView1->Rows[i]->Cells[1]->Value);
				   }
				   a.SetVar(i, k);
			   }

		   }

	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {

		for (int i = 0; i < dataGridView1->RowCount; i++) {
			float k = 0;
			if (is_num(Convert::ToString(dataGridView1->Rows[i]->Cells[1]->Value))) {
				k = Convert::ToDouble(dataGridView1->Rows[i]->Cells[1]->Value);
			}
			a.SetVar(i, k); 
		}
		float result = a.poshitaem();
		textBox3->Text = Convert::ToString(result);
	}

	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
		 }
};
}