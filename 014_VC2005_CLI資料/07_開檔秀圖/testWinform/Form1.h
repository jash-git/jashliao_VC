#pragma once
#include "Int32.h"

namespace testWinform {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Form1 的摘要
	///
	/// 警告: 如果您變更這個類別的名稱，就必須變更與這個類別所依據之所有 .resx 檔案關聯的
	///          Managed 資源編譯器工具的 'Resource File Name' 屬性。
	///          否則，這些設計工具
	///          將無法與這個表單關聯的當地語系化資源
	///          正確互動。
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: 在此加入建構函式程式碼
			//
		}

	protected:
		/// <summary>
		/// 清除任何使用中的資源。
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^  textBox1;
	protected: 
			CInt32 n;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::PictureBox^  pictureBox1;

	private:
		/// <summary>
		/// 設計工具所需的變數。
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// 此為設計工具支援所需的方法 - 請勿使用程式碼編輯器修改這個方法的內容。
		///
		/// </summary>
		void InitializeComponent(void)
		{
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(37, 12);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(102, 22);
			this->textBox1->TabIndex = 0;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(156, 12);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(68, 35);
			this->button1->TabIndex = 1;
			this->button1->Text = L"button1";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(37, 49);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(102, 22);
			this->textBox2->TabIndex = 2;
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(36, 86);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(102, 42);
			this->button2->TabIndex = 3;
			this->button2->Text = L"button2";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Form1::button2_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->Location = System::Drawing::Point(161, 132);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(197, 143);
			this->pictureBox1->TabIndex = 4;
			this->pictureBox1->TabStop = false;
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(477, 437);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox1);
			this->Name = L"Form1";
			this->Text = L"Form1";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
				 String ^s1;
				 CInt32 k;
				 n++;
				 k=n+100;
				 s1=n.Int10toInt2(); 
				 textBox1->Text=s1;
			     textBox2->Text=n.IntToString();
			 }
	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
				OpenFileDialog^ dlg  = gcnew OpenFileDialog;
				dlg->InitialDirectory = "c:\\";
				dlg->Filter = "Image Files|*.BMP;*.GIF;*.JPG;*.JPEG;*.PNG;*.TIF;*.TIFF;*.Exif;*.WMF;*.EMF|All Files|*.*";
				if (dlg->ShowDialog() == ::DialogResult::OK)
				{
					Bitmap ^image = gcnew Bitmap(dlg->FileName);
					pictureBox1->Image = image;
					//image->SetPixel
					//image->GetPixel 
				}
			 }
};
}

