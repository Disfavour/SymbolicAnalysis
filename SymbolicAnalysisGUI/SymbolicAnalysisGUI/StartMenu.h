#pragma once
#include "GUI_Localization.h"
#include "GUI_Balancing.h"
#include "GUI_MaxCycle.h"
#include "GUI_ExtremeCycles.h"
#include "GUI_Projective.h"
#include "GUI_Morse.h"


namespace SymbolicAnalysisGUI {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для StartMenu
	/// </summary>
	public ref class StartMenu : public System::Windows::Forms::Form
	{
	public:
		StartMenu(void)
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
		~StartMenu()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::Button^ button5;
	private: System::Windows::Forms::Button^ button6;
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
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(14, 14);
			this->button1->Margin = System::Windows::Forms::Padding(5);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(445, 37);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Локализация цепно-рекуррентного множества";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &StartMenu::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(14, 61);
			this->button2->Margin = System::Windows::Forms::Padding(5);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(445, 37);
			this->button2->TabIndex = 1;
			this->button2->Text = L"Метод балансировки";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &StartMenu::button2_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(14, 108);
			this->button3->Margin = System::Windows::Forms::Padding(5);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(445, 37);
			this->button3->TabIndex = 2;
			this->button3->Text = L"Поиск простого потока максимальной длины";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &StartMenu::button3_Click);
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(14, 155);
			this->button4->Margin = System::Windows::Forms::Padding(5);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(445, 37);
			this->button4->TabIndex = 3;
			this->button4->Text = L"Поиск экстремальных циклов";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &StartMenu::button4_Click);
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(14, 202);
			this->button5->Margin = System::Windows::Forms::Padding(5);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(445, 37);
			this->button5->TabIndex = 4;
			this->button5->Text = L"Локализация в проективном пространстве";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &StartMenu::button5_Click);
			// 
			// button6
			// 
			this->button6->Location = System::Drawing::Point(14, 249);
			this->button6->Margin = System::Windows::Forms::Padding(5);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(445, 37);
			this->button6->TabIndex = 5;
			this->button6->Text = L"Спектр Морса";
			this->button6->UseVisualStyleBackColor = true;
			this->button6->Click += gcnew System::EventHandler(this, &StartMenu::button6_Click);
			// 
			// StartMenu
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(10, 21);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(473, 298);
			this->Controls->Add(this->button6);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Font = (gcnew System::Drawing::Font(L"Times New Roman", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->Margin = System::Windows::Forms::Padding(5);
			this->Name = L"StartMenu";
			this->Text = L"Символический анализ";
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e)
	{
		GUI_Localization^ obj = gcnew GUI_Localization();
		this->Hide();
		obj->Show();
	}

	System::Void Form1_FormClosing(System::Object^ sender, System::EventArgs^ e)
	{
		Application::Exit();
	}
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e)
	{
		GUI_Balancing^ obj = gcnew GUI_Balancing();
		this->Hide();
		obj->Show();
	}
	private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e)
	{
		GUI_MaxCycle^ obj = gcnew GUI_MaxCycle();
		this->Hide();
		obj->Show();
	}
	private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e)
	{
		GUI_ExtremeCycles^ obj = gcnew GUI_ExtremeCycles();
		this->Hide();
		obj->Show();
	}
	private: System::Void button5_Click(System::Object^ sender, System::EventArgs^ e)
	{
		GUI_Projective^ obj = gcnew GUI_Projective();
		this->Hide();
		obj->Show();
	}
	private: System::Void button6_Click(System::Object^ sender, System::EventArgs^ e)
	{
		GUI_Morse^ obj = gcnew GUI_Morse();
		this->Hide();
		obj->Show();
	}
};
}
