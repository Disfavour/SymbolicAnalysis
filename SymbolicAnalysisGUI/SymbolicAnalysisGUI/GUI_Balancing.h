#pragma once
#include <msclr\marshal_cppstd.h>
#include <stdlib.h>
#include "SA/Visualization.h"


namespace SymbolicAnalysisGUI {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для GUI_Balancing
	/// </summary>
	public ref class GUI_Balancing : public System::Windows::Forms::Form
	{
	public:
		GUI_Balancing(void)
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
		~GUI_Balancing()
		{
			if (components)
			{
				delete components;
			}
			exit(1);
		}
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::Label^ label10;
	private: System::Windows::Forms::Label^ label11;
	private: System::Windows::Forms::Label^ label12;
	private: System::Windows::Forms::Label^ label13;
	private: System::Windows::Forms::Label^ label14;
	private: System::Windows::Forms::Label^ label15;
	private: System::Windows::Forms::Label^ label16;
	private: System::Windows::Forms::Label^ label17;
	private: System::Windows::Forms::Label^ label18;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::TextBox^ textBox4;
	private: System::Windows::Forms::TextBox^ textBox5;
	private: System::Windows::Forms::TextBox^ textBox6;
	private: System::Windows::Forms::Label^ label19;
	private: System::Windows::Forms::Label^ label20;
	private: System::Windows::Forms::Label^ label21;
	private: System::Windows::Forms::Label^ label22;
	private: System::Windows::Forms::Label^ label23;
	private: System::Windows::Forms::TextBox^ textBox7;
	private: System::Windows::Forms::TextBox^ textBox8;
	private: System::Windows::Forms::TextBox^ textBox9;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Label^ label24;
	private: System::Windows::Forms::Label^ label25;
	private: System::Windows::Forms::Label^ label26;
	private: System::Windows::Forms::Label^ label27;
	private: System::Windows::Forms::Label^ label28;

	private: System::Windows::Forms::Label^ label30;
	private: System::Windows::Forms::Label^ label31;

	private: System::Windows::Forms::Label^ label33;
	private: System::Windows::Forms::Label^ label34;
	private: System::Windows::Forms::Label^ label35;
	private: System::Windows::Forms::Label^ label36;
	private: System::Windows::Forms::Label^ label29;
	private: System::Windows::Forms::TextBox^ textBox10;
	private: System::Windows::Forms::Label^ label32;
	private: System::Windows::Forms::Label^ label37;

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
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->label15 = (gcnew System::Windows::Forms::Label());
			this->label16 = (gcnew System::Windows::Forms::Label());
			this->label17 = (gcnew System::Windows::Forms::Label());
			this->label18 = (gcnew System::Windows::Forms::Label());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->textBox6 = (gcnew System::Windows::Forms::TextBox());
			this->label19 = (gcnew System::Windows::Forms::Label());
			this->label20 = (gcnew System::Windows::Forms::Label());
			this->label21 = (gcnew System::Windows::Forms::Label());
			this->label22 = (gcnew System::Windows::Forms::Label());
			this->label23 = (gcnew System::Windows::Forms::Label());
			this->textBox7 = (gcnew System::Windows::Forms::TextBox());
			this->textBox8 = (gcnew System::Windows::Forms::TextBox());
			this->textBox9 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label24 = (gcnew System::Windows::Forms::Label());
			this->label25 = (gcnew System::Windows::Forms::Label());
			this->label26 = (gcnew System::Windows::Forms::Label());
			this->label27 = (gcnew System::Windows::Forms::Label());
			this->label28 = (gcnew System::Windows::Forms::Label());
			this->label30 = (gcnew System::Windows::Forms::Label());
			this->label31 = (gcnew System::Windows::Forms::Label());
			this->label33 = (gcnew System::Windows::Forms::Label());
			this->label34 = (gcnew System::Windows::Forms::Label());
			this->label35 = (gcnew System::Windows::Forms::Label());
			this->label36 = (gcnew System::Windows::Forms::Label());
			this->label29 = (gcnew System::Windows::Forms::Label());
			this->textBox10 = (gcnew System::Windows::Forms::TextBox());
			this->label32 = (gcnew System::Windows::Forms::Label());
			this->label37 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Times New Roman", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(50, 38);
			this->label1->Margin = System::Windows::Forms::Padding(5, 0, 5, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(23, 21);
			this->label1->TabIndex = 0;
			this->label1->Text = L"X";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(67, 45);
			this->label2->Margin = System::Windows::Forms::Padding(5, 0, 5, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(33, 19);
			this->label2->TabIndex = 1;
			this->label2->Text = L"n+1";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(50, 80);
			this->label3->Margin = System::Windows::Forms::Padding(5, 0, 5, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(23, 21);
			this->label3->TabIndex = 2;
			this->label3->Text = L"Y";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label4->Location = System::Drawing::Point(67, 87);
			this->label4->Margin = System::Windows::Forms::Padding(5, 0, 5, 0);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(33, 19);
			this->label4->TabIndex = 3;
			this->label4->Text = L"n+1";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(130, 35);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(1141, 29);
			this->textBox1->TabIndex = 4;
			this->textBox1->Text = L"1 - 0.9 * (x * cos(0.4 - 6.0 / (1 + x * x + y * y)) - y * sin(0.4 - 6.0 / (1 + x "
				L"* x + y * y)))";
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(130, 77);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(1141, 29);
			this->textBox2->TabIndex = 5;
			this->textBox2->Text = L"1.2 * (x * sin(0.4 - 6.0 / (1 + x * x + y * y)) + y * cos(0.4 - 6.0 / (1 + x * x "
				L"+ y * y)))";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(101, 38);
			this->label5->Margin = System::Windows::Forms::Padding(5, 0, 5, 0);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(21, 21);
			this->label5->TabIndex = 6;
			this->label5->Text = L"=";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(101, 80);
			this->label6->Margin = System::Windows::Forms::Padding(5, 0, 5, 0);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(21, 21);
			this->label6->TabIndex = 7;
			this->label6->Text = L"=";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Times New Roman", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label7->Location = System::Drawing::Point(67, 144);
			this->label7->Margin = System::Windows::Forms::Padding(5, 0, 5, 0);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(176, 24);
			this->label7->TabIndex = 8;
			this->label7->Text = L"Границы области";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(14, 194);
			this->label8->Margin = System::Windows::Forms::Padding(5, 0, 5, 0);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(57, 21);
			this->label8->TabIndex = 9;
			this->label8->Text = L"Левая";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(14, 228);
			this->label9->Margin = System::Windows::Forms::Padding(5, 0, 5, 0);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(67, 21);
			this->label9->TabIndex = 10;
			this->label9->Text = L"Правая";
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(14, 265);
			this->label10->Margin = System::Windows::Forms::Padding(5, 0, 5, 0);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(77, 21);
			this->label10->TabIndex = 11;
			this->label10->Text = L"Верхняя";
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Location = System::Drawing::Point(14, 302);
			this->label11->Margin = System::Windows::Forms::Padding(5, 0, 5, 0);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(74, 21);
			this->label11->TabIndex = 12;
			this->label11->Text = L"Нижняя";
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Location = System::Drawing::Point(99, 194);
			this->label12->Margin = System::Windows::Forms::Padding(5, 0, 5, 0);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(21, 21);
			this->label12->TabIndex = 13;
			this->label12->Text = L"=";
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Location = System::Drawing::Point(99, 228);
			this->label13->Margin = System::Windows::Forms::Padding(5, 0, 5, 0);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(21, 21);
			this->label13->TabIndex = 14;
			this->label13->Text = L"=";
			// 
			// label14
			// 
			this->label14->AutoSize = true;
			this->label14->Location = System::Drawing::Point(99, 265);
			this->label14->Margin = System::Windows::Forms::Padding(5, 0, 5, 0);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(21, 21);
			this->label14->TabIndex = 15;
			this->label14->Text = L"=";
			// 
			// label15
			// 
			this->label15->AutoSize = true;
			this->label15->Location = System::Drawing::Point(98, 302);
			this->label15->Margin = System::Windows::Forms::Padding(5, 0, 5, 0);
			this->label15->Name = L"label15";
			this->label15->Size = System::Drawing::Size(21, 21);
			this->label15->TabIndex = 16;
			this->label15->Text = L"=";
			// 
			// label16
			// 
			this->label16->AutoSize = true;
			this->label16->Location = System::Drawing::Point(336, 124);
			this->label16->Margin = System::Windows::Forms::Padding(5, 0, 5, 0);
			this->label16->Name = L"label16";
			this->label16->Size = System::Drawing::Size(184, 21);
			this->label16->TabIndex = 17;
			this->label16->Text = L"Количество итераций";
			// 
			// label17
			// 
			this->label17->AutoSize = true;
			this->label17->Location = System::Drawing::Point(14, 375);
			this->label17->Margin = System::Windows::Forms::Padding(5, 0, 5, 0);
			this->label17->Name = L"label17";
			this->label17->Size = System::Drawing::Size(717, 21);
			this->label17->TabIndex = 18;
			this->label17->Text = L"Коэффициент точности - это корень из количества бросаемых точек из каждой ячейки."
				L"";
			// 
			// label18
			// 
			this->label18->AutoSize = true;
			this->label18->Location = System::Drawing::Point(14, 407);
			this->label18->Margin = System::Windows::Forms::Padding(5, 0, 5, 0);
			this->label18->Name = L"label18";
			this->label18->Size = System::Drawing::Size(933, 21);
			this->label18->TabIndex = 19;
			this->label18->Text = L"Коэффициент дробления - это корень из количества частей, на которые разбивается я"
				L"чейка при каждой итерации.";
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(130, 191);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(124, 29);
			this->textBox3->TabIndex = 20;
			this->textBox3->Text = L"-2";
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(130, 225);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(124, 29);
			this->textBox4->TabIndex = 21;
			this->textBox4->Text = L"3,5";
			// 
			// textBox5
			// 
			this->textBox5->Location = System::Drawing::Point(130, 262);
			this->textBox5->Name = L"textBox5";
			this->textBox5->Size = System::Drawing::Size(124, 29);
			this->textBox5->TabIndex = 22;
			this->textBox5->Text = L"2,5";
			// 
			// textBox6
			// 
			this->textBox6->Location = System::Drawing::Point(130, 299);
			this->textBox6->Name = L"textBox6";
			this->textBox6->Size = System::Drawing::Size(124, 29);
			this->textBox6->TabIndex = 23;
			this->textBox6->Text = L"-2,5";
			// 
			// label19
			// 
			this->label19->AutoSize = true;
			this->label19->Location = System::Drawing::Point(336, 177);
			this->label19->Margin = System::Windows::Forms::Padding(5, 0, 5, 0);
			this->label19->Name = L"label19";
			this->label19->Size = System::Drawing::Size(200, 21);
			this->label19->TabIndex = 24;
			this->label19->Text = L"Коэффициент точности";
			// 
			// label20
			// 
			this->label20->AutoSize = true;
			this->label20->Location = System::Drawing::Point(336, 232);
			this->label20->Margin = System::Windows::Forms::Padding(5, 0, 5, 0);
			this->label20->Name = L"label20";
			this->label20->Size = System::Drawing::Size(211, 21);
			this->label20->TabIndex = 25;
			this->label20->Text = L"Коэффициент дробления";
			// 
			// label21
			// 
			this->label21->AutoSize = true;
			this->label21->Location = System::Drawing::Point(557, 124);
			this->label21->Margin = System::Windows::Forms::Padding(5, 0, 5, 0);
			this->label21->Name = L"label21";
			this->label21->Size = System::Drawing::Size(21, 21);
			this->label21->TabIndex = 26;
			this->label21->Text = L"=";
			// 
			// label22
			// 
			this->label22->AutoSize = true;
			this->label22->Location = System::Drawing::Point(557, 180);
			this->label22->Margin = System::Windows::Forms::Padding(5, 0, 5, 0);
			this->label22->Name = L"label22";
			this->label22->Size = System::Drawing::Size(21, 21);
			this->label22->TabIndex = 27;
			this->label22->Text = L"=";
			// 
			// label23
			// 
			this->label23->AutoSize = true;
			this->label23->Location = System::Drawing::Point(557, 232);
			this->label23->Margin = System::Windows::Forms::Padding(5, 0, 5, 0);
			this->label23->Name = L"label23";
			this->label23->Size = System::Drawing::Size(21, 21);
			this->label23->TabIndex = 28;
			this->label23->Text = L"=";
			// 
			// textBox7
			// 
			this->textBox7->Location = System::Drawing::Point(586, 121);
			this->textBox7->Name = L"textBox7";
			this->textBox7->Size = System::Drawing::Size(124, 29);
			this->textBox7->TabIndex = 29;
			this->textBox7->Text = L"12";
			// 
			// textBox8
			// 
			this->textBox8->Location = System::Drawing::Point(586, 177);
			this->textBox8->Name = L"textBox8";
			this->textBox8->Size = System::Drawing::Size(124, 29);
			this->textBox8->TabIndex = 30;
			this->textBox8->Text = L"4";
			// 
			// textBox9
			// 
			this->textBox9->Location = System::Drawing::Point(586, 229);
			this->textBox9->Name = L"textBox9";
			this->textBox9->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->textBox9->Size = System::Drawing::Size(124, 29);
			this->textBox9->TabIndex = 31;
			this->textBox9->Text = L"2";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(444, 308);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(163, 48);
			this->button1->TabIndex = 33;
			this->button1->Text = L"Вычислить";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &GUI_Balancing::button1_Click);
			// 
			// label24
			// 
			this->label24->AutoSize = true;
			this->label24->Location = System::Drawing::Point(763, 172);
			this->label24->Margin = System::Windows::Forms::Padding(5, 0, 5, 0);
			this->label24->Name = L"label24";
			this->label24->Size = System::Drawing::Size(270, 21);
			this->label24->TabIndex = 34;
			this->label24->Text = L"Количество возвратных вершин";
			this->label24->Visible = false;
			// 
			// label25
			// 
			this->label25->AutoSize = true;
			this->label25->Font = (gcnew System::Drawing::Font(L"Times New Roman", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label25->Location = System::Drawing::Point(935, 121);
			this->label25->Margin = System::Windows::Forms::Padding(5, 0, 5, 0);
			this->label25->Name = L"label25";
			this->label25->Size = System::Drawing::Size(117, 24);
			this->label25->TabIndex = 35;
			this->label25->Text = L"Результаты";
			this->label25->Visible = false;
			// 
			// label26
			// 
			this->label26->AutoSize = true;
			this->label26->Location = System::Drawing::Point(882, 276);
			this->label26->Margin = System::Windows::Forms::Padding(5, 0, 5, 0);
			this->label26->Name = L"label26";
			this->label26->Size = System::Drawing::Size(140, 21);
			this->label26->TabIndex = 36;
			this->label26->Text = L"Диаметр ячейки";
			this->label26->Visible = false;
			// 
			// label27
			// 
			this->label27->AutoSize = true;
			this->label27->Location = System::Drawing::Point(731, 202);
			this->label27->Margin = System::Windows::Forms::Padding(5, 0, 5, 0);
			this->label27->Name = L"label27";
			this->label27->Size = System::Drawing::Size(444, 21);
			this->label27->TabIndex = 37;
			this->label27->Text = L"Количество и размеры компонент сильной связности";
			this->label27->Visible = false;
			// 
			// label28
			// 
			this->label28->AutoSize = true;
			this->label28->Location = System::Drawing::Point(1053, 171);
			this->label28->Margin = System::Windows::Forms::Padding(5, 0, 5, 0);
			this->label28->Name = L"label28";
			this->label28->Size = System::Drawing::Size(21, 21);
			this->label28->TabIndex = 38;
			this->label28->Text = L"=";
			this->label28->Visible = false;
			// 
			// label30
			// 
			this->label30->AutoSize = true;
			this->label30->Location = System::Drawing::Point(1053, 276);
			this->label30->Margin = System::Windows::Forms::Padding(5, 0, 5, 0);
			this->label30->Name = L"label30";
			this->label30->Size = System::Drawing::Size(21, 21);
			this->label30->TabIndex = 40;
			this->label30->Text = L"=";
			this->label30->Visible = false;
			// 
			// label31
			// 
			this->label31->AutoSize = true;
			this->label31->Location = System::Drawing::Point(1084, 171);
			this->label31->Margin = System::Windows::Forms::Padding(5, 0, 5, 0);
			this->label31->Name = L"label31";
			this->label31->Size = System::Drawing::Size(19, 21);
			this->label31->TabIndex = 41;
			this->label31->Text = L"0";
			this->label31->Visible = false;
			// 
			// label33
			// 
			this->label33->AutoSize = true;
			this->label33->Location = System::Drawing::Point(1084, 276);
			this->label33->Margin = System::Windows::Forms::Padding(5, 0, 5, 0);
			this->label33->Name = L"label33";
			this->label33->Size = System::Drawing::Size(19, 21);
			this->label33->TabIndex = 43;
			this->label33->Text = L"0";
			this->label33->Visible = false;
			// 
			// label34
			// 
			this->label34->AutoSize = true;
			this->label34->Location = System::Drawing::Point(860, 322);
			this->label34->Margin = System::Windows::Forms::Padding(5, 0, 5, 0);
			this->label34->Name = L"label34";
			this->label34->Size = System::Drawing::Size(162, 21);
			this->label34->TabIndex = 44;
			this->label34->Text = L"Затраченное время";
			this->label34->Visible = false;
			// 
			// label35
			// 
			this->label35->AutoSize = true;
			this->label35->Location = System::Drawing::Point(1053, 322);
			this->label35->Margin = System::Windows::Forms::Padding(5, 0, 5, 0);
			this->label35->Name = L"label35";
			this->label35->Size = System::Drawing::Size(21, 21);
			this->label35->TabIndex = 45;
			this->label35->Text = L"=";
			this->label35->Visible = false;
			// 
			// label36
			// 
			this->label36->AutoSize = true;
			this->label36->Location = System::Drawing::Point(1084, 322);
			this->label36->Margin = System::Windows::Forms::Padding(5, 0, 5, 0);
			this->label36->Name = L"label36";
			this->label36->Size = System::Drawing::Size(19, 21);
			this->label36->TabIndex = 46;
			this->label36->Text = L"0";
			this->label36->Visible = false;
			// 
			// label29
			// 
			this->label29->AutoSize = true;
			this->label29->Location = System::Drawing::Point(731, 239);
			this->label29->Margin = System::Windows::Forms::Padding(5, 0, 5, 0);
			this->label29->Name = L"label29";
			this->label29->Size = System::Drawing::Size(109, 21);
			this->label29->TabIndex = 47;
			this->label29->Text = L"компоненты";
			this->label29->Visible = false;
			// 
			// textBox10
			// 
			this->textBox10->Location = System::Drawing::Point(586, 273);
			this->textBox10->Name = L"textBox10";
			this->textBox10->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->textBox10->Size = System::Drawing::Size(124, 29);
			this->textBox10->TabIndex = 50;
			this->textBox10->Text = L"0,001";
			// 
			// label32
			// 
			this->label32->AutoSize = true;
			this->label32->Location = System::Drawing::Point(557, 276);
			this->label32->Margin = System::Windows::Forms::Padding(5, 0, 5, 0);
			this->label32->Name = L"label32";
			this->label32->Size = System::Drawing::Size(21, 21);
			this->label32->TabIndex = 49;
			this->label32->Text = L"=";
			// 
			// label37
			// 
			this->label37->AutoSize = true;
			this->label37->Location = System::Drawing::Point(400, 276);
			this->label37->Margin = System::Windows::Forms::Padding(5, 0, 5, 0);
			this->label37->Name = L"label37";
			this->label37->Size = System::Drawing::Size(81, 21);
			this->label37->TabIndex = 48;
			this->label37->Text = L"Эпсилон";
			// 
			// GUI_Balancing
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(10, 21);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1283, 436);
			this->Controls->Add(this->textBox10);
			this->Controls->Add(this->label32);
			this->Controls->Add(this->label37);
			this->Controls->Add(this->label29);
			this->Controls->Add(this->label36);
			this->Controls->Add(this->label35);
			this->Controls->Add(this->label34);
			this->Controls->Add(this->label33);
			this->Controls->Add(this->label31);
			this->Controls->Add(this->label30);
			this->Controls->Add(this->label28);
			this->Controls->Add(this->label27);
			this->Controls->Add(this->label26);
			this->Controls->Add(this->label25);
			this->Controls->Add(this->label24);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox9);
			this->Controls->Add(this->textBox8);
			this->Controls->Add(this->textBox7);
			this->Controls->Add(this->label23);
			this->Controls->Add(this->label22);
			this->Controls->Add(this->label21);
			this->Controls->Add(this->label20);
			this->Controls->Add(this->label19);
			this->Controls->Add(this->textBox6);
			this->Controls->Add(this->textBox5);
			this->Controls->Add(this->textBox4);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->label18);
			this->Controls->Add(this->label17);
			this->Controls->Add(this->label16);
			this->Controls->Add(this->label15);
			this->Controls->Add(this->label14);
			this->Controls->Add(this->label13);
			this->Controls->Add(this->label12);
			this->Controls->Add(this->label11);
			this->Controls->Add(this->label10);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Font = (gcnew System::Drawing::Font(L"Times New Roman", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->Margin = System::Windows::Forms::Padding(5);
			this->Name = L"GUI_Balancing";
			this->Text = L"Метод балансировки";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e)
	{
		label24->Hide();
		label25->Hide();
		label26->Hide();
		label27->Hide();
		label28->Hide();
		label29->Hide();
		label30->Hide();
		label31->Hide();
		label33->Hide();
		label34->Hide();
		label35->Hide();
		label36->Hide();

		button1->Hide();

		string
			formulaX = msclr::interop::marshal_as<std::string>(textBox1->Text),
			formulaY = msclr::interop::marshal_as<std::string>(textBox2->Text);

		float
			left = System::Convert::ToDouble(textBox3->Text),
			right = System::Convert::ToDouble(textBox4->Text),
			top = System::Convert::ToDouble(textBox5->Text),
			bot = System::Convert::ToDouble(textBox6->Text);

		int
			maxIter = System::Convert::ToInt32(textBox7->Text),
			dotsPerCell = System::Convert::ToInt32(textBox8->Text),
			splitNum = System::Convert::ToInt32(textBox9->Text);

		const float eps = System::Convert::ToDouble(textBox10->Text);

		//Visualization a(left, right, top, bot, formulaX, formulaY, "0", "0", "0", maxIter, dotsPerCell, splitNum, 0, 0);
		Visualization a(left, right, top, bot, formulaX, formulaY, maxIter, dotsPerCell, splitNum, eps, "0", "0", 0, 0, "0");
		a.BalancingMethod();

		unordered_map<string, vector<string>> info = a.getInfo();

		label31->Text = gcnew String(info["v"][0].c_str());

		string SC = info["sc"][0] + ": ";

		for (int i = 0; i < info["scALL"].size() - 1; i++)
		{
			SC += info["scALL"][i] + ", ";
		}
		SC += info["scALL"][info["scALL"].size() - 1];


		label29->Text = gcnew String(SC.c_str());

		label33->Text = gcnew String(info["d"][0].c_str());

		label36->Text = gcnew String(info["t"][0].c_str());

		label24->Show();
		label25->Show();
		label26->Show();
		label27->Show();
		label28->Show();
		label29->Show();
		label30->Show();
		label31->Show();
		label33->Show();
		label34->Show();
		label35->Show();
		label36->Show();

		button1->Show();
	}
};
}
