#pragma once
#include <fstream>
#include"TTable.h"
#include"Record.h"
#include"TArrayHashTable.h"
//#include"TArrayTable.h"
//#include"THashTable.h"
#include"TScanTable.h"
#include"TSortTable.h"
#include"TTreeTable.h"
//#include"TTreeNode.h"

namespace CppWinForm1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
		TTable *pTable = NULL;
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::RadioButton^  radioButton1;
	private: System::Windows::Forms::RadioButton^  radioButton2;
	private: System::Windows::Forms::RadioButton^  radioButton3;
	private: System::Windows::Forms::RadioButton^  radioButton4;
	private: System::Windows::Forms::Label^  label3;

	private: System::Windows::Forms::TextBox^  textBox3;
	private: System::Windows::Forms::Label^  label4;

	private: System::Windows::Forms::Button^  button2;


	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::TextBox^  textBox6;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::TextBox^  textBox7;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::Button^  button4;
	private: System::Windows::Forms::Button^  button5;
	private: System::Windows::Forms::DataGridView^  dataGridView1;
	private: System::Windows::Forms::Button^  button6;




	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->radioButton1 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton2 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton3 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton4 = (gcnew System::Windows::Forms::RadioButton());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->textBox6 = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->textBox7 = (gcnew System::Windows::Forms::TextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->button6 = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(786, 64);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(81, 32);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Создать";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(671, 69);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(72, 22);
			this->textBox1->TabIndex = 1;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(522, 69);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(107, 17);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Число записей";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(522, 112);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(127, 17);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Диапазон ключей";
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(672, 112);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(71, 22);
			this->textBox2->TabIndex = 4;
			// 
			// radioButton1
			// 
			this->radioButton1->AutoSize = true;
			this->radioButton1->Location = System::Drawing::Point(297, 75);
			this->radioButton1->Name = L"radioButton1";
			this->radioButton1->Size = System::Drawing::Size(150, 21);
			this->radioButton1->TabIndex = 5;
			this->radioButton1->TabStop = true;
			this->radioButton1->Text = L"Неупорядоченная";
			this->radioButton1->UseVisualStyleBackColor = true;
			// 
			// radioButton2
			// 
			this->radioButton2->AutoSize = true;
			this->radioButton2->Location = System::Drawing::Point(297, 102);
			this->radioButton2->Name = L"radioButton2";
			this->radioButton2->Size = System::Drawing::Size(134, 21);
			this->radioButton2->TabIndex = 6;
			this->radioButton2->TabStop = true;
			this->radioButton2->Text = L"Упорядоченная";
			this->radioButton2->UseVisualStyleBackColor = true;
			// 
			// radioButton3
			// 
			this->radioButton3->AutoSize = true;
			this->radioButton3->Location = System::Drawing::Point(297, 132);
			this->radioButton3->Name = L"radioButton3";
			this->radioButton3->Size = System::Drawing::Size(172, 21);
			this->radioButton3->TabIndex = 7;
			this->radioButton3->TabStop = true;
			this->radioButton3->Text = L"Хэш-таблица(массив)";
			this->radioButton3->UseVisualStyleBackColor = true;
			// 
			// radioButton4
			// 
			this->radioButton4->AutoSize = true;
			this->radioButton4->Location = System::Drawing::Point(297, 159);
			this->radioButton4->Name = L"radioButton4";
			this->radioButton4->Size = System::Drawing::Size(79, 21);
			this->radioButton4->TabIndex = 8;
			this->radioButton4->TabStop = true;
			this->radioButton4->Text = L"Дерево";
			this->radioButton4->UseVisualStyleBackColor = true;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Modern No. 20", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(342, 46);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(81, 20);
			this->label3->TabIndex = 9;
			this->label3->Text = L"Таблицы";
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(84, 408);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(113, 22);
			this->textBox3->TabIndex = 11;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(84, 376);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(113, 17);
			this->label4->TabIndex = 12;
			this->label4->Text = L"Эффективность";
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(12, 51);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(240, 23);
			this->button2->TabIndex = 14;
			this->button2->Text = L"Ключ                  Значение";
			this->button2->UseVisualStyleBackColor = true;
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(786, 159);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(81, 32);
			this->button3->TabIndex = 17;
			this->button3->Text = L"Поиск";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// textBox6
			// 
			this->textBox6->Location = System::Drawing::Point(671, 159);
			this->textBox6->Name = L"textBox6";
			this->textBox6->Size = System::Drawing::Size(71, 22);
			this->textBox6->TabIndex = 18;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(525, 159);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(43, 17);
			this->label5->TabIndex = 19;
			this->label5->Text = L"Ключ";
			// 
			// textBox7
			// 
			this->textBox7->Location = System::Drawing::Point(672, 209);
			this->textBox7->Name = L"textBox7";
			this->textBox7->Size = System::Drawing::Size(72, 22);
			this->textBox7->TabIndex = 20;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(525, 209);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(76, 17);
			this->label6->TabIndex = 21;
			this->label6->Text = L"Результат";
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(786, 204);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(81, 32);
			this->button4->TabIndex = 22;
			this->button4->Text = L"Добавить";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &MyForm::button4_Click);
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(786, 254);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(81, 32);
			this->button5->TabIndex = 23;
			this->button5->Text = L"Удалить";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &MyForm::button5_Click);
			// 
			// dataGridView1
			// 
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Location = System::Drawing::Point(12, 81);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowTemplate->Height = 24;
			this->dataGridView1->Size = System::Drawing::Size(245, 292);
			this->dataGridView1->TabIndex = 24;
			this->dataGridView1->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MyForm::dataGridView1_CellContentClick);
			// 
			// button6
			// 
			this->button6->Location = System::Drawing::Point(786, 112);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(81, 32);
			this->button6->TabIndex = 25;
			this->button6->Text = L"Файл";
			this->button6->UseVisualStyleBackColor = true;
			this->button6->Click += gcnew System::EventHandler(this, &MyForm::button6_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(911, 489);
			this->Controls->Add(this->button6);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->textBox7);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->textBox6);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->radioButton4);
			this->Controls->Add(this->radioButton3);
			this->Controls->Add(this->radioButton2);
			this->Controls->Add(this->radioButton1);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->button1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {

		if (pTable)
		{
			delete pTable;
		}
		TKey Key;
		TValue Val;
		int DataCount = 0, MemSize;
		char Line[100];
		int MaxKeyValue, RetCode;

		DataCount = Convert::ToInt32(textBox1->Text);
		MaxKeyValue = Convert::ToInt32(textBox2->Text);
		MemSize = DataCount + 10;
		if (radioButton1->Checked)
		{
			pTable = new TScanTable(MemSize);
		}
		if (radioButton2->Checked)
		{
			pTable = new TSortTable(MemSize);
		}
		if (radioButton3->Checked)
		{
			pTable = new TArrayHashTable(MemSize);
		}
		if (radioButton4->Checked)
		{
			pTable = new TTreeTable;
		}
		for (int i = 0; i < DataCount; i++)
		{
			int tmp = ((double) rand() / (double)RAND_MAX)*MaxKeyValue;
			sprintf_s(Line, "%d", tmp);
			Key = tmp;
			Val = "*";
			Val += Line;
			Val += "*";
			RetCode=pTable->InsRecord(Key, Val);
			if (RetCode != TabOk)
			{
				String^ message = "RetCode" + Convert::ToString(RetCode);
				if (RetCode == DuplRec)
				{
					message = "Дублированная запись";
				}
				String^ caption = "Внимание!";
				MessageBoxButtons buttons = MessageBoxButtons::OK;
				MessageBox::Show(this, message, caption, buttons);
			}
		}
		textBox3->Text = Convert::ToString(pTable->GetEfficiency());
		pTable->Print(this->dataGridView1);
	}
private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
	pTable->ClearEfficiency();

	int k = Convert::ToInt32(textBox6->Text);
	if (pTable->FindRecord(k))
	{
		textBox7->Text = "Есть";
	}
	else
	{
		textBox7->Text = "Нет";
	}
	textBox3->Text = Convert::ToString(pTable->GetEfficiency());
	
}
private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) {

	TKey Key = Convert::ToInt32(textBox6->Text);
	int tmp = Key;
	char Line[10];
	int RetCode;
	sprintf_s(Line, "%d", tmp);
	TValue Val;
	Val = "*";
	Val += Line;
	Val += "*";
	pTable->ClearEfficiency();
	RetCode=pTable->InsRecord(Key,Val);
	if (RetCode != TabOk)
	{
		if (RetCode == DuplRec)
		{
			textBox7->Text = "Дублированная запись";

		}
		else
		{
			textBox7->Text = "Таблица полна";
		}
	}
	else textBox7->Text = "Добавлена";
	textBox3->Text = Convert::ToString(pTable->GetEfficiency());
	pTable->Print(this->dataGridView1);
}
private: System::Void button5_Click(System::Object^  sender, System::EventArgs^  e) {
	
	TKey Key = Convert::ToInt32(textBox6->Text);
	
	int RetCode;

	pTable->ClearEfficiency();
	RetCode = pTable->DelRecord(Key);
	if (RetCode != TabOk)
	{
		if (RetCode == TabNoRec)
		{
			textBox7->Text = " Нет записи";

		}
		else
		{
			textBox7->Text = "Таблица пуста";
		}
	}
	else textBox7 ->Text= "Удалена";
	textBox3->Text = Convert::ToString(pTable->GetEfficiency());
	pTable->Print(this->dataGridView1);
}
private: System::Void dataGridView1_CellContentClick(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e) {
}
private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void button6_Click(System::Object^  sender, System::EventArgs^  e) {

	ofstream tF;
	tF.open("table.txt");
	pTable->Fprint(tF);

}
};
}
