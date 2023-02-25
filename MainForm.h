#pragma once
#include "AmApi.h"
#include <string>
#include <msclr\marshal_cppstd.h>
namespace Project5 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	using namespace System;
	using namespace System::Drawing;
	using namespace System::Drawing::Imaging;
	using namespace System::Media;
	using namespace System::IO;

	std::string base_img, cmp_img;
	std::string output_str = "output.bmp";

	const char* conf_path = "configuration.csv";
	am::AmApi am_api(conf_path);
	std::atomic_bool is_active = true;
	int base_height, base_width;
	//class MainForm;

	/// <summary>
	/// Summary for MainForm
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{
	public:
		MainForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			button3->Enabled = false;
		}
		void doJob()
		{

		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::OpenFileDialog^ openFileDialog1;
	private: System::Windows::Forms::OpenFileDialog^ openFileDialog2;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::Button^ button3;	   
	private: System::String^ output_bmp = "output.bmp";
	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::GroupBox^ groupBox2;
	private: System::Windows::Forms::Button^ button5;
	private: System::Windows::Forms::Button^ button4;

	private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel2;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::CheckBox^ checkBox1;
	public: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::FolderBrowserDialog^ folderBrowserDialog1;

	private: System::Windows::Forms::Button^ button6;
	private: System::Windows::Forms::OpenFileDialog^ openFileDialog3;

	private: System::ComponentModel::IContainer^ components;
	protected: DateTime base_img_creation;
	protected: String^ output_str_ = "output.bmp";
	protected: String^ base_img_;
	protected:		 System::Threading::Thread^ thread;
	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->openFileDialog2 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->tableLayoutPanel2 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
			this->folderBrowserDialog1 = (gcnew System::Windows::Forms::FolderBrowserDialog());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->openFileDialog3 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->tableLayoutPanel1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->groupBox1->SuspendLayout();
			this->groupBox2->SuspendLayout();
			this->tableLayoutPanel2->SuspendLayout();
			this->SuspendLayout();
			// 
			// tableLayoutPanel1
			// 
			this->tableLayoutPanel1->ColumnCount = 2;
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tableLayoutPanel1->Controls->Add(this->button2, 1, 0);
			this->tableLayoutPanel1->Controls->Add(this->button1, 0, 0);
			this->tableLayoutPanel1->Location = System::Drawing::Point(6, 34);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			this->tableLayoutPanel1->RowCount = 1;
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 52)));
			this->tableLayoutPanel1->Size = System::Drawing::Size(256, 52);
			this->tableLayoutPanel1->TabIndex = 0;
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(131, 3);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(122, 46);
			this->button2->TabIndex = 1;
			this->button2->Text = L"Compare Image";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MainForm::button2_Click);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(3, 3);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(122, 46);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Base Image";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MainForm::button1_Click);
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			this->openFileDialog1->Filter = L"\"bmp files (*.bmp, *.BMP,*.jpg;*.jpeg)|*.bmp;*.BMP;*jpg;*jpeg";
			// 
			// openFileDialog2
			// 
			this->openFileDialog2->FileName = L"openFileDialog2";
			this->openFileDialog2->Filter = L"\"bmp files (*.bmp, *.BMP,*.jpg;*.jpeg)|*.bmp;*.BMP;*jpg;*jpeg";
			// 
			// pictureBox1
			// 
			this->pictureBox1->Location = System::Drawing::Point(9, 13);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(640, 480);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox1->TabIndex = 1;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->LoadCompleted += gcnew System::ComponentModel::AsyncCompletedEventHandler(this, &MainForm::pictureBox1_LoadCompleted);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(6, 109);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(256, 52);
			this->button3->TabIndex = 2;
			this->button3->Text = L"Compare";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MainForm::button3_Click);
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->tableLayoutPanel1);
			this->groupBox1->Controls->Add(this->button3);
			this->groupBox1->Location = System::Drawing::Point(655, 93);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(263, 167);
			this->groupBox1->TabIndex = 3;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Single comparison";
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->button5);
			this->groupBox2->Controls->Add(this->button4);
			this->groupBox2->Location = System::Drawing::Point(661, 284);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(256, 149);
			this->groupBox2->TabIndex = 4;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Continous comparison";
			// 
			// button5
			// 
			this->button5->Enabled = false;
			this->button5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button5->Location = System::Drawing::Point(17, 87);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(225, 44);
			this->button5->TabIndex = 1;
			this->button5->Text = L"Select folder with photos";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &MainForm::button5_Click);
			// 
			// button4
			// 
			this->button4->Enabled = false;
			this->button4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button4->Location = System::Drawing::Point(17, 30);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(225, 42);
			this->button4->TabIndex = 0;
			this->button4->Text = L"Select base image";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &MainForm::button4_Click);
			// 
			// tableLayoutPanel2
			// 
			this->tableLayoutPanel2->ColumnCount = 2;
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tableLayoutPanel2->Controls->Add(this->textBox2, 1, 0);
			this->tableLayoutPanel2->Controls->Add(this->textBox1, 0, 0);
			this->tableLayoutPanel2->Location = System::Drawing::Point(655, 449);
			this->tableLayoutPanel2->Name = L"tableLayoutPanel2";
			this->tableLayoutPanel2->RowCount = 1;
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel2->Size = System::Drawing::Size(269, 32);
			this->tableLayoutPanel2->TabIndex = 7;
			// 
			// textBox2
			// 
			this->textBox2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox2->Location = System::Drawing::Point(137, 3);
			this->textBox2->Name = L"textBox2";
			this->textBox2->ReadOnly = true;
			this->textBox2->Size = System::Drawing::Size(122, 26);
			this->textBox2->TabIndex = 9;
			this->textBox2->Text = L"0";
			this->textBox2->TextChanged += gcnew System::EventHandler(this, &MainForm::textBox2_TextChanged);
			// 
			// textBox1
			// 
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox1->Location = System::Drawing::Point(3, 3);
			this->textBox1->Name = L"textBox1";
			this->textBox1->ReadOnly = true;
			this->textBox1->Size = System::Drawing::Size(128, 26);
			this->textBox1->TabIndex = 8;
			this->textBox1->Text = L"Found objects:";
			// 
			// checkBox1
			// 
			this->checkBox1->AutoSize = true;
			this->checkBox1->Checked = true;
			this->checkBox1->CheckState = System::Windows::Forms::CheckState::Checked;
			this->checkBox1->Location = System::Drawing::Point(667, 13);
			this->checkBox1->Name = L"checkBox1";
			this->checkBox1->Size = System::Drawing::Size(134, 17);
			this->checkBox1->TabIndex = 8;
			this->checkBox1->Text = L"Only single comparison";
			this->checkBox1->UseVisualStyleBackColor = true;
			this->checkBox1->CheckedChanged += gcnew System::EventHandler(this, &MainForm::checkBox1_CheckedChanged_1);
			// 
			// button6
			// 
			this->button6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button6->Location = System::Drawing::Point(658, 36);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(256, 40);
			this->button6->TabIndex = 9;
			this->button6->Text = L"Load configuration ...";
			this->button6->UseVisualStyleBackColor = true;
			this->button6->Click += gcnew System::EventHandler(this, &MainForm::button6_Click);
			// 
			// openFileDialog3
			// 
			this->openFileDialog3->FileName = L"openFileDialog3";
			this->openFileDialog3->Filter = L"CSV Files (*.csv)|*.csv";
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ControlLight;
			this->ClientSize = System::Drawing::Size(934, 511);
			this->Controls->Add(this->button6);
			this->Controls->Add(this->checkBox1);
			this->Controls->Add(this->tableLayoutPanel2);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->pictureBox1);
			this->Name = L"MainForm";
			this->Text = L"Aquamarine Demo";
			this->tableLayoutPanel1->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->groupBox1->ResumeLayout(false);
			this->groupBox2->ResumeLayout(false);
			this->tableLayoutPanel2->ResumeLayout(false);
			this->tableLayoutPanel2->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}

#pragma endregion
		private: 	 static void calculations() {

			for (int i = 0; i < 3; i++)
			{
				System::Media::SystemSounds::Exclamation->Play();
				System::Threading::Thread::Sleep(1000);
				//form->textBox2->Text = i.ToString()
				//this->textBox1->Text = "Hola";
			}
		}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		using namespace System::Windows::Forms;
		System::Windows::Forms::DialogResult dr = this->openFileDialog1->ShowDialog();
		if (dr == System::Windows::Forms::DialogResult::OK) {
			if (this->pictureBox1->Image)
				delete this->pictureBox1->Image;

			this->textBox2->Text = "0";
			this->pictureBox1->Image = gcnew Bitmap(this->openFileDialog1->FileName);

			if (!this->openFileDialog1->FileName->EndsWith(".bmp") && !this->openFileDialog1->FileName->EndsWith(".BMP"))
			{
				base_img = "default_base.bmp";
				this->pictureBox1->Image->Save("default_base.bmp", ImageFormat::Bmp);
			}
			else 
			{
				msclr::interop::marshal_context context;
				base_img = context.marshal_as<std::string>(this->openFileDialog1->FileName);
			}
			if (!cmp_img.empty())
				button3->Enabled = true;
		}
	}
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		System::Windows::Forms::DialogResult dr = this->openFileDialog2->ShowDialog();
		if (dr == System::Windows::Forms::DialogResult::OK) {

			if (this->pictureBox1->Image)
				delete this->pictureBox1->Image;

			this->pictureBox1->Image = gcnew Bitmap(this->openFileDialog2->FileName);

			if (!this->openFileDialog2->FileName->EndsWith(".bmp") && !this->openFileDialog2->FileName->EndsWith(".BMP"))
			{
				cmp_img = "default_cmp.bmp";
				this->pictureBox1->Image->Save("default_cmp.bmp", ImageFormat::Bmp);
			}
			else {
				msclr::interop::marshal_context context;
				cmp_img = context.marshal_as<std::string>(this->openFileDialog2->FileName);
			}
			if (!base_img.empty())
				button3->Enabled = true;
		}
	}
	private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
		if(this->pictureBox1->Image)
			delete this->pictureBox1->Image;

		int objects_count = am_api.compare_and_save_diff_img(base_img, cmp_img, output_str);
		if (objects_count) {
			System::Media::SystemSounds::Exclamation->Play();
		}
		this->pictureBox1->Image = gcnew Bitmap(output_bmp);
		this->textBox2->Text = objects_count.ToString();
	}


	private: System::Void checkBox1_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
		if (this->checkBox1->Checked)
		{
			this->button1->Enabled = true;
			this->button2->Enabled = true;
			this->button4->Enabled = false;
			this->button5->Enabled = false;
		}
		else {
			this->button1->Enabled = false;
			this->button2->Enabled = false;
			this->button4->Enabled = true;
			this->button5->Enabled = false;
		}
	}
private: System::Void checkBox1_CheckedChanged_1(System::Object^ sender, System::EventArgs^ e) {
	if (this->checkBox1->Checked)
	{
		this->button1->Enabled = true;
		this->button2->Enabled = true;
		this->button4->Enabled = false;
		this->button5->Enabled = false;
	}
	else {
		this->button1->Enabled = false;
		this->button2->Enabled = false;
		this->button4->Enabled = true;
		this->button5->Enabled = false;
	}
}
private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
	System::Windows::Forms::DialogResult dr = this->openFileDialog1->ShowDialog();
	if (dr == System::Windows::Forms::DialogResult::OK) {

		if (this->pictureBox1->Image)
			delete this->pictureBox1->Image;

		this->textBox2->Text = "0";
		this->pictureBox1->Image = gcnew Bitmap(this->openFileDialog1->FileName);
		base_img_creation = File::GetLastWriteTime(this->openFileDialog1->FileName);
		base_height = this->pictureBox1->Image->Height;
		base_width = this->pictureBox1->Image->Width;
		
		if (!this->openFileDialog1->FileName->EndsWith(".bmp") && !this->openFileDialog1->FileName->EndsWith(".BMP"))
		{
			base_img = "default_base.bmp";
			this->pictureBox1->Image->Save("default_base.bmp", ImageFormat::Bmp);
			base_img_ = "default_base.bmp";
		}
		else
		{
			msclr::interop::marshal_context context;
			base_img = context.marshal_as<std::string>(this->openFileDialog1->FileName);
			base_img_ = this->openFileDialog1->FileName;
		}
		if (!base_img.empty())
			button5->Enabled = true;
	}
}
private: System::Void button5_Click(System::Object^ sender, System::EventArgs^ e) {
	System::Windows::Forms::DialogResult dr = this->folderBrowserDialog1->ShowDialog();
	if (dr == System::Windows::Forms::DialogResult::OK )
	{
		//while (true) //endless loop, expected that user will monitor all objects during work of app
		//{
			System::Collections::Generic::IEnumerable<System::String^>^ files = System::IO::Directory::EnumerateFiles(this->folderBrowserDialog1->SelectedPath);
			
			for each (System::String ^ item in files)
			{
				
				if (item == output_str_ || item == base_img_)
				{
					continue;
				}
				if (item->EndsWith(".bmp") || item->EndsWith(".BMP") && item != output_str_ && item != "default_cmp.bmp" && item != "default_base.bmp")
				{
					DateTime creation = File::GetLastWriteTime(item);
					System::Drawing::Image^ bmp_file = gcnew Bitmap(item);
					if (System::DateTime::Compare(creation, base_img_creation) > 0 && base_height == bmp_file->Height && base_width == bmp_file->Width)
					{
						delete this->pictureBox1->Image;
						msclr::interop::marshal_context context;
						cmp_img = context.marshal_as<std::string>(item);
						int result = am_api.compare_and_save_diff_img(base_img, cmp_img, output_str);

						if (result)
						{
							System::Media::SystemSounds::Exclamation->Play();
						}

						this->pictureBox1->Image = Image::FromFile(output_str_);// bmp_file;// gcnew Bitmap(output_str_);
						this->textBox2->Text = result.ToString();


						base_img = cmp_img;
						base_img_creation = creation;


						this->textBox2->Refresh();
						this->pictureBox1->Refresh();
						this->Refresh();
					}
					delete bmp_file;
				}
				else if (item->EndsWith(".jpg") || item->EndsWith(".jpeg"))
				{
					DateTime creation = File::GetLastWriteTime(item);
					System::Drawing::Image^ bmp_file =  gcnew Bitmap(item);
					cmp_img = "default_cmp.bmp";

					if (System::DateTime::Compare(creation, base_img_creation) > 0 && base_height == bmp_file->Height && base_width == bmp_file->Width)
					{
						delete this->pictureBox1->Image;
						bmp_file->Save("default_cmp.bmp", ImageFormat::Bmp);
						
						int result = am_api.compare_and_save_diff_img(base_img, "default_cmp.bmp", output_str);
						if (result)
						{
							System::Media::SystemSounds::Exclamation->Play();
						}
						
						this->pictureBox1->Image = gcnew Bitmap(output_str_);
						this->textBox2->Text = result.ToString();

						File::Copy("default_cmp.bmp", "default_base.bmp", true);
						base_img_creation = creation;

						this->textBox2->Refresh();
						this->pictureBox1->Refresh();
					}
					delete bmp_file;
				}
				//this->Refresh();
				System::Threading::Thread::Sleep(3000);
			}
			System::Media::SystemSounds::Hand->Play();
			//System::Threading::Thread::Sleep(15000);
		//}
	}
}
private: System::Void button6_Click(System::Object^ sender, System::EventArgs^ e) {
	System::Windows::Forms::DialogResult dr = this->openFileDialog3->ShowDialog();
	if (dr == System::Windows::Forms::DialogResult::OK) {
		msclr::interop::marshal_context context;
		std::string path  = context.marshal_as<std::string>(this->openFileDialog3->FileName);
		am_api = am::AmApi(path.c_str());
	}
}
private: System::Void textBox2_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void pictureBox1_LoadCompleted(System::Object^ sender, System::ComponentModel::AsyncCompletedEventArgs^ e) {
	this->pictureBox1->Refresh();
	this->Refresh();
}
};
}
