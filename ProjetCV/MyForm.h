#pragma once
#include "opencv2/opencv.hpp"
#include <iostream>
#include "opencv2/photo.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/core.hpp"
#include <msclr\marshal_cppstd.h>
#include <fstream>
#include "opencv2/imgproc/imgproc.hpp"
#include <stdlib.h>
#include <stdio.h>
#include "Convolution.h"
#include "Header.h"
#include "Morphologie.h"
#include "Video.h"
#include "shapedetector.h"
#include <string>
namespace cv {
	namespace cuda {
		class Stream::Impl {};
	}
}
namespace cv {
	namespace cuda {
		class Event::Impl {};
	}
}
using namespace cv;
using namespace std;

namespace ProjetCV {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	/// <summary>
	/// Summary for MyForm
	/// </summary>
	//Variables
	Mat source, Convolutionsource, MedMoysrc, Morph;
	string location;
	int erosion_type;
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}
		//My Functions
		void DrawCVImage(System::Windows::Forms::Control^ control, cv::Mat& colorImage)
		{
			System::Drawing::Graphics^ graphics = control->CreateGraphics();
			System::IntPtr ptr(colorImage.ptr());
			System::Drawing::Bitmap^ b = gcnew System::Drawing::Bitmap(colorImage.cols, colorImage.rows, colorImage.step, System::Drawing::Imaging::PixelFormat::Format24bppRgb, ptr);
			System::Drawing::RectangleF rect(0, 0, control->Width, control->Height);
			graphics->DrawImage(b, rect); 
			delete graphics;
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
	private: System::Windows::Forms::TabControl^  tabControl1;
	protected:
	private: System::Windows::Forms::TabPage^  Convolution;
	private: System::Windows::Forms::PictureBox^  boxC2;

	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::RadioButton^  radioButton2;
	private: System::Windows::Forms::RadioButton^  laplace;

	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::PictureBox^  boxC1;




















	private: System::Windows::Forms::OpenFileDialog^  ShowPicture;

	private: System::Windows::Forms::TabPage^  tabPage1;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::Button^  button4;
	private: System::Windows::Forms::PictureBox^  DistinMoyenBox;
	private: System::Windows::Forms::GroupBox^  groupBox10;
	private: System::Windows::Forms::RadioButton^  radioButtonMedian;
	private: System::Windows::Forms::RadioButton^  radioButtonMoyen;
	private: System::Windows::Forms::PictureBox^  SourcememoyBox;
	private: System::Windows::Forms::GroupBox^  groupBox11;
	private: System::Windows::Forms::TrackBar^  trackBar15;
	private: System::Windows::Forms::TabPage^  tabPage2;
	private: System::Windows::Forms::GroupBox^  Triangle;




	private: System::Windows::Forms::ColorDialog^  colorselect;



	private: System::Windows::Forms::GroupBox^  circle;



	private: System::Windows::Forms::GroupBox^  rect;



	private: System::Windows::Forms::GroupBox^  bruit;
	private: System::Windows::Forms::Button^  video;

	private: System::Windows::Forms::OpenFileDialog^  selectImage;
	private: System::Windows::Forms::NumericUpDown^  pt;

	private: System::Windows::Forms::NumericUpDown^  c;

	private: System::Windows::Forms::NumericUpDown^  r;

	private: System::Windows::Forms::NumericUpDown^  t;

	private: System::Windows::Forms::Label^  label1;
private: System::Windows::Forms::OpenFileDialog^  medmoyimage;
private: System::Windows::Forms::TabPage^  tabPage3;
private: System::Windows::Forms::Button^  button7;
private: System::Windows::Forms::Button^  button6;

private: System::Windows::Forms::TextBox^  textBox3;
private: System::Windows::Forms::OpenFileDialog^  openFileDialog1;
private: System::Windows::Forms::TabPage^  Morphologique;
private: System::Windows::Forms::GroupBox^  groupBox6;
private: System::Windows::Forms::RadioButton^  radioButton3;
private: System::Windows::Forms::RadioButton^  radioButton1;
private: System::Windows::Forms::RadioButton^  radioButton4;
private: System::Windows::Forms::TextBox^  textBox1;
private: System::Windows::Forms::Button^  file;
private: System::Windows::Forms::PictureBox^  SourceBox;
private: System::Windows::Forms::PictureBox^  DestinationBox;
private: System::Windows::Forms::GroupBox^  groupBox2;
private: System::Windows::Forms::TrackBar^  trackBar1;
private: System::Windows::Forms::GroupBox^  groupBox3;
private: System::Windows::Forms::TrackBar^  trackBar3;
private: System::Windows::Forms::GroupBox^  groupBox4;
private: System::Windows::Forms::TrackBar^  trackBar4;
private: System::Windows::Forms::GroupBox^  groupBox5;
private: System::Windows::Forms::TrackBar^  trackBar5;
private: System::Windows::Forms::GroupBox^  groupBox1;
private: System::Windows::Forms::TrackBar^  trackBar2;
private: System::Windows::Forms::NumericUpDown^  count;


private: System::Windows::Forms::ColorDialog^  colorDialog1;
private: System::Windows::Forms::Button^  button5;
private: System::Windows::Forms::PictureBox^  Distine;

private: System::Windows::Forms::PictureBox^  Orgine;






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
			this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
			this->Convolution = (gcnew System::Windows::Forms::TabPage());
			this->boxC2 = (gcnew System::Windows::Forms::PictureBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->radioButton2 = (gcnew System::Windows::Forms::RadioButton());
			this->laplace = (gcnew System::Windows::Forms::RadioButton());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->boxC1 = (gcnew System::Windows::Forms::PictureBox());
			this->Morphologique = (gcnew System::Windows::Forms::TabPage());
			this->groupBox6 = (gcnew System::Windows::Forms::GroupBox());
			this->radioButton3 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton1 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton4 = (gcnew System::Windows::Forms::RadioButton());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->file = (gcnew System::Windows::Forms::Button());
			this->SourceBox = (gcnew System::Windows::Forms::PictureBox());
			this->DestinationBox = (gcnew System::Windows::Forms::PictureBox());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->trackBar1 = (gcnew System::Windows::Forms::TrackBar());
			this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
			this->trackBar3 = (gcnew System::Windows::Forms::TrackBar());
			this->groupBox4 = (gcnew System::Windows::Forms::GroupBox());
			this->trackBar4 = (gcnew System::Windows::Forms::TrackBar());
			this->groupBox5 = (gcnew System::Windows::Forms::GroupBox());
			this->trackBar5 = (gcnew System::Windows::Forms::TrackBar());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->trackBar2 = (gcnew System::Windows::Forms::TrackBar());
			this->tabPage1 = (gcnew System::Windows::Forms::TabPage());
			this->groupBox11 = (gcnew System::Windows::Forms::GroupBox());
			this->trackBar15 = (gcnew System::Windows::Forms::TrackBar());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->DistinMoyenBox = (gcnew System::Windows::Forms::PictureBox());
			this->groupBox10 = (gcnew System::Windows::Forms::GroupBox());
			this->radioButtonMedian = (gcnew System::Windows::Forms::RadioButton());
			this->radioButtonMoyen = (gcnew System::Windows::Forms::RadioButton());
			this->SourcememoyBox = (gcnew System::Windows::Forms::PictureBox());
			this->tabPage2 = (gcnew System::Windows::Forms::TabPage());
			this->bruit = (gcnew System::Windows::Forms::GroupBox());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->count = (gcnew System::Windows::Forms::NumericUpDown());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->pt = (gcnew System::Windows::Forms::NumericUpDown());
			this->video = (gcnew System::Windows::Forms::Button());
			this->circle = (gcnew System::Windows::Forms::GroupBox());
			this->c = (gcnew System::Windows::Forms::NumericUpDown());
			this->rect = (gcnew System::Windows::Forms::GroupBox());
			this->r = (gcnew System::Windows::Forms::NumericUpDown());
			this->Triangle = (gcnew System::Windows::Forms::GroupBox());
			this->t = (gcnew System::Windows::Forms::NumericUpDown());
			this->tabPage3 = (gcnew System::Windows::Forms::TabPage());
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->ShowPicture = (gcnew System::Windows::Forms::OpenFileDialog());
			this->colorselect = (gcnew System::Windows::Forms::ColorDialog());
			this->selectImage = (gcnew System::Windows::Forms::OpenFileDialog());
			this->medmoyimage = (gcnew System::Windows::Forms::OpenFileDialog());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->colorDialog1 = (gcnew System::Windows::Forms::ColorDialog());
			this->Orgine = (gcnew System::Windows::Forms::PictureBox());
			this->Distine = (gcnew System::Windows::Forms::PictureBox());
			this->tabControl1->SuspendLayout();
			this->Convolution->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->boxC2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->boxC1))->BeginInit();
			this->Morphologique->SuspendLayout();
			this->groupBox6->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->SourceBox))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->DestinationBox))->BeginInit();
			this->groupBox2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar1))->BeginInit();
			this->groupBox3->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar3))->BeginInit();
			this->groupBox4->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar4))->BeginInit();
			this->groupBox5->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar5))->BeginInit();
			this->groupBox1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar2))->BeginInit();
			this->tabPage1->SuspendLayout();
			this->groupBox11->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar15))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->DistinMoyenBox))->BeginInit();
			this->groupBox10->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->SourcememoyBox))->BeginInit();
			this->tabPage2->SuspendLayout();
			this->bruit->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->count))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pt))->BeginInit();
			this->circle->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->c))->BeginInit();
			this->rect->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->r))->BeginInit();
			this->Triangle->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->t))->BeginInit();
			this->tabPage3->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Orgine))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Distine))->BeginInit();
			this->SuspendLayout();
			// 
			// tabControl1
			// 
			this->tabControl1->Controls->Add(this->Convolution);
			this->tabControl1->Controls->Add(this->Morphologique);
			this->tabControl1->Controls->Add(this->tabPage1);
			this->tabControl1->Controls->Add(this->tabPage2);
			this->tabControl1->Controls->Add(this->tabPage3);
			this->tabControl1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->tabControl1->Location = System::Drawing::Point(4, 2);
			this->tabControl1->Name = L"tabControl1";
			this->tabControl1->SelectedIndex = 0;
			this->tabControl1->Size = System::Drawing::Size(856, 528);
			this->tabControl1->TabIndex = 1;
			// 
			// Convolution
			// 
			this->Convolution->Controls->Add(this->boxC2);
			this->Convolution->Controls->Add(this->button2);
			this->Convolution->Controls->Add(this->radioButton2);
			this->Convolution->Controls->Add(this->laplace);
			this->Convolution->Controls->Add(this->button1);
			this->Convolution->Controls->Add(this->boxC1);
			this->Convolution->Location = System::Drawing::Point(4, 22);
			this->Convolution->Name = L"Convolution";
			this->Convolution->Padding = System::Windows::Forms::Padding(3);
			this->Convolution->Size = System::Drawing::Size(848, 502);
			this->Convolution->TabIndex = 0;
			this->Convolution->Text = L"Convolution";
			this->Convolution->UseVisualStyleBackColor = true;
			// 
			// boxC2
			// 
			this->boxC2->Location = System::Drawing::Point(379, 236);
			this->boxC2->Name = L"boxC2";
			this->boxC2->Size = System::Drawing::Size(355, 165);
			this->boxC2->TabIndex = 5;
			this->boxC2->TabStop = false;
			// 
			// button2
			// 
			this->button2->Enabled = false;
			this->button2->Location = System::Drawing::Point(13, 309);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(242, 67);
			this->button2->TabIndex = 4;
			this->button2->Text = L"Show Result";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// radioButton2
			// 
			this->radioButton2->AutoSize = true;
			this->radioButton2->ImageAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->radioButton2->Location = System::Drawing::Point(79, 202);
			this->radioButton2->Name = L"radioButton2";
			this->radioButton2->Size = System::Drawing::Size(101, 17);
			this->radioButton2->TabIndex = 3;
			this->radioButton2->Text = L"Filtre Gaussien";
			this->radioButton2->UseVisualStyleBackColor = true;
			// 
			// laplace
			// 
			this->laplace->Checked = true;
			this->laplace->Location = System::Drawing::Point(79, 167);
			this->laplace->Name = L"laplace";
			this->laplace->Size = System::Drawing::Size(102, 17);
			this->laplace->TabIndex = 2;
			this->laplace->TabStop = true;
			this->laplace->Text = L"Filtre Laplacien";
			this->laplace->UseVisualStyleBackColor = true;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(12, 46);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(243, 67);
			this->button1->TabIndex = 1;
			this->button1->Text = L"Select Image";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// boxC1
			// 
			this->boxC1->Location = System::Drawing::Point(379, 31);
			this->boxC1->Name = L"boxC1";
			this->boxC1->Size = System::Drawing::Size(355, 165);
			this->boxC1->TabIndex = 0;
			this->boxC1->TabStop = false;
			// 
			// Morphologique
			// 
			this->Morphologique->Controls->Add(this->groupBox6);
			this->Morphologique->Controls->Add(this->textBox1);
			this->Morphologique->Controls->Add(this->file);
			this->Morphologique->Controls->Add(this->SourceBox);
			this->Morphologique->Controls->Add(this->DestinationBox);
			this->Morphologique->Controls->Add(this->groupBox2);
			this->Morphologique->Controls->Add(this->groupBox3);
			this->Morphologique->Controls->Add(this->groupBox4);
			this->Morphologique->Controls->Add(this->groupBox5);
			this->Morphologique->Controls->Add(this->groupBox1);
			this->Morphologique->Location = System::Drawing::Point(4, 22);
			this->Morphologique->Name = L"Morphologique";
			this->Morphologique->Padding = System::Windows::Forms::Padding(3);
			this->Morphologique->Size = System::Drawing::Size(848, 502);
			this->Morphologique->TabIndex = 1;
			this->Morphologique->Text = L"Morphologique";
			this->Morphologique->UseVisualStyleBackColor = true;
			// 
			// groupBox6
			// 
			this->groupBox6->Controls->Add(this->radioButton3);
			this->groupBox6->Controls->Add(this->radioButton1);
			this->groupBox6->Controls->Add(this->radioButton4);
			this->groupBox6->Location = System::Drawing::Point(502, 223);
			this->groupBox6->Name = L"groupBox6";
			this->groupBox6->Size = System::Drawing::Size(261, 71);
			this->groupBox6->TabIndex = 17;
			this->groupBox6->TabStop = false;
			this->groupBox6->Text = L"Noyau";
			this->groupBox6->Enter += gcnew System::EventHandler(this, &MyForm::groupBox6_Enter);
			// 
			// radioButton3
			// 
			this->radioButton3->AutoSize = true;
			this->radioButton3->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->radioButton3->Location = System::Drawing::Point(193, 21);
			this->radioButton3->Name = L"radioButton3";
			this->radioButton3->Size = System::Drawing::Size(62, 17);
			this->radioButton3->TabIndex = 2;
			this->radioButton3->Text = L"ELLIPSE";
			this->radioButton3->UseVisualStyleBackColor = true;
			this->radioButton3->CheckedChanged += gcnew System::EventHandler(this, &MyForm::radioButton3_CheckedChanged);
			// 
			// radioButton1
			// 
			this->radioButton1->AutoSize = true;
			this->radioButton1->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->radioButton1->Location = System::Drawing::Point(100, 21);
			this->radioButton1->Name = L"radioButton1";
			this->radioButton1->Size = System::Drawing::Size(60, 17);
			this->radioButton1->TabIndex = 1;
			this->radioButton1->Text = L"CROSS";
			this->radioButton1->UseVisualStyleBackColor = true;
			this->radioButton1->CheckedChanged += gcnew System::EventHandler(this, &MyForm::radioButton1_CheckedChanged);
			// 
			// radioButton4
			// 
			this->radioButton4->AutoSize = true;
			this->radioButton4->Checked = true;
			this->radioButton4->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->radioButton4->Location = System::Drawing::Point(10, 21);
			this->radioButton4->Name = L"radioButton4";
			this->radioButton4->Size = System::Drawing::Size(51, 17);
			this->radioButton4->TabIndex = 0;
			this->radioButton4->TabStop = true;
			this->radioButton4->Text = L"RECT";
			this->radioButton4->UseVisualStyleBackColor = true;
			this->radioButton4->CheckedChanged += gcnew System::EventHandler(this, &MyForm::radioButton4_CheckedChanged);
			// 
			// textBox1
			// 
			this->textBox1->BackColor = System::Drawing::Color::White;
			this->textBox1->Enabled = false;
			this->textBox1->Location = System::Drawing::Point(102, 162);
			this->textBox1->Name = L"textBox1";
			this->textBox1->ReadOnly = true;
			this->textBox1->Size = System::Drawing::Size(296, 22);
			this->textBox1->TabIndex = 15;
			// 
			// file
			// 
			this->file->BackColor = System::Drawing::Color::White;
			this->file->Location = System::Drawing::Point(635, 162);
			this->file->Name = L"file";
			this->file->Size = System::Drawing::Size(82, 22);
			this->file->TabIndex = 14;
			this->file->Text = L"Picture";
			this->file->UseVisualStyleBackColor = false;
			this->file->Click += gcnew System::EventHandler(this, &MyForm::file_Click);
			// 
			// SourceBox
			// 
			this->SourceBox->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->SourceBox->Location = System::Drawing::Point(21, 16);
			this->SourceBox->Name = L"SourceBox";
			this->SourceBox->Size = System::Drawing::Size(326, 121);
			this->SourceBox->TabIndex = 13;
			this->SourceBox->TabStop = false;
			// 
			// DestinationBox
			// 
			this->DestinationBox->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->DestinationBox->Location = System::Drawing::Point(502, 16);
			this->DestinationBox->Name = L"DestinationBox";
			this->DestinationBox->Size = System::Drawing::Size(326, 121);
			this->DestinationBox->TabIndex = 12;
			this->DestinationBox->TabStop = false;
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->trackBar1);
			this->groupBox2->Location = System::Drawing::Point(74, 308);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(261, 80);
			this->groupBox2->TabIndex = 11;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"La dilatation";
			// 
			// trackBar1
			// 
			this->trackBar1->BackColor = System::Drawing::Color::White;
			this->trackBar1->Dock = System::Windows::Forms::DockStyle::Top;
			this->trackBar1->Enabled = false;
			this->trackBar1->Location = System::Drawing::Point(3, 18);
			this->trackBar1->Name = L"trackBar1";
			this->trackBar1->Size = System::Drawing::Size(255, 45);
			this->trackBar1->TabIndex = 2;
			this->trackBar1->Scroll += gcnew System::EventHandler(this, &MyForm::trackBar1_Scroll);
			// 
			// groupBox3
			// 
			this->groupBox3->Controls->Add(this->trackBar3);
			this->groupBox3->Location = System::Drawing::Point(74, 404);
			this->groupBox3->Name = L"groupBox3";
			this->groupBox3->Size = System::Drawing::Size(261, 80);
			this->groupBox3->TabIndex = 11;
			this->groupBox3->TabStop = false;
			this->groupBox3->Text = L"L’ouverture";
			this->groupBox3->Enter += gcnew System::EventHandler(this, &MyForm::groupBox3_Enter);
			// 
			// trackBar3
			// 
			this->trackBar3->BackColor = System::Drawing::Color::White;
			this->trackBar3->Dock = System::Windows::Forms::DockStyle::Top;
			this->trackBar3->Enabled = false;
			this->trackBar3->Location = System::Drawing::Point(3, 18);
			this->trackBar3->Name = L"trackBar3";
			this->trackBar3->Size = System::Drawing::Size(255, 45);
			this->trackBar3->TabIndex = 2;
			this->trackBar3->Scroll += gcnew System::EventHandler(this, &MyForm::trackBar3_Scroll);
			// 
			// groupBox4
			// 
			this->groupBox4->Controls->Add(this->trackBar4);
			this->groupBox4->Location = System::Drawing::Point(502, 404);
			this->groupBox4->Name = L"groupBox4";
			this->groupBox4->Size = System::Drawing::Size(261, 80);
			this->groupBox4->TabIndex = 11;
			this->groupBox4->TabStop = false;
			this->groupBox4->Text = L"Le gradient";
			// 
			// trackBar4
			// 
			this->trackBar4->BackColor = System::Drawing::Color::White;
			this->trackBar4->Dock = System::Windows::Forms::DockStyle::Top;
			this->trackBar4->Enabled = false;
			this->trackBar4->Location = System::Drawing::Point(3, 18);
			this->trackBar4->Name = L"trackBar4";
			this->trackBar4->Size = System::Drawing::Size(255, 45);
			this->trackBar4->TabIndex = 2;
			this->trackBar4->Scroll += gcnew System::EventHandler(this, &MyForm::trackBar4_Scroll);
			// 
			// groupBox5
			// 
			this->groupBox5->Controls->Add(this->trackBar5);
			this->groupBox5->Location = System::Drawing::Point(502, 310);
			this->groupBox5->Name = L"groupBox5";
			this->groupBox5->Size = System::Drawing::Size(261, 80);
			this->groupBox5->TabIndex = 11;
			this->groupBox5->TabStop = false;
			this->groupBox5->Text = L"La fermeture";
			// 
			// trackBar5
			// 
			this->trackBar5->BackColor = System::Drawing::Color::White;
			this->trackBar5->Enabled = false;
			this->trackBar5->Location = System::Drawing::Point(10, 21);
			this->trackBar5->Name = L"trackBar5";
			this->trackBar5->Size = System::Drawing::Size(245, 45);
			this->trackBar5->TabIndex = 2;
			this->trackBar5->Scroll += gcnew System::EventHandler(this, &MyForm::trackBar5_Scroll);
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->trackBar2);
			this->groupBox1->Location = System::Drawing::Point(74, 214);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(261, 80);
			this->groupBox1->TabIndex = 10;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"L’érosion";
			// 
			// trackBar2
			// 
			this->trackBar2->BackColor = System::Drawing::Color::White;
			this->trackBar2->Dock = System::Windows::Forms::DockStyle::Top;
			this->trackBar2->Enabled = false;
			this->trackBar2->Location = System::Drawing::Point(3, 18);
			this->trackBar2->Name = L"trackBar2";
			this->trackBar2->Size = System::Drawing::Size(255, 45);
			this->trackBar2->TabIndex = 2;
			this->trackBar2->Scroll += gcnew System::EventHandler(this, &MyForm::trackBar2_Scroll);
			// 
			// tabPage1
			// 
			this->tabPage1->Controls->Add(this->groupBox11);
			this->tabPage1->Controls->Add(this->button3);
			this->tabPage1->Controls->Add(this->textBox2);
			this->tabPage1->Controls->Add(this->button4);
			this->tabPage1->Controls->Add(this->DistinMoyenBox);
			this->tabPage1->Controls->Add(this->groupBox10);
			this->tabPage1->Controls->Add(this->SourcememoyBox);
			this->tabPage1->Location = System::Drawing::Point(4, 22);
			this->tabPage1->Name = L"tabPage1";
			this->tabPage1->Padding = System::Windows::Forms::Padding(3);
			this->tabPage1->Size = System::Drawing::Size(848, 502);
			this->tabPage1->TabIndex = 2;
			this->tabPage1->Text = L"Moyen-Mediane";
			this->tabPage1->UseVisualStyleBackColor = true;
			this->tabPage1->Click += gcnew System::EventHandler(this, &MyForm::tabPage1_Click);
			// 
			// groupBox11
			// 
			this->groupBox11->Controls->Add(this->trackBar15);
			this->groupBox11->Location = System::Drawing::Point(15, 419);
			this->groupBox11->Name = L"groupBox11";
			this->groupBox11->Size = System::Drawing::Size(811, 75);
			this->groupBox11->TabIndex = 14;
			this->groupBox11->TabStop = false;
			this->groupBox11->Text = L"Taille";
			// 
			// trackBar15
			// 
			this->trackBar15->Enabled = false;
			this->trackBar15->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->trackBar15->LargeChange = 2;
			this->trackBar15->Location = System::Drawing::Point(6, 19);
			this->trackBar15->Maximum = 6;
			this->trackBar15->Minimum = 1;
			this->trackBar15->Name = L"trackBar15";
			this->trackBar15->Size = System::Drawing::Size(799, 45);
			this->trackBar15->SmallChange = 2;
			this->trackBar15->TabIndex = 2;
			this->trackBar15->TickFrequency = 2;
			this->trackBar15->Value = 3;
			this->trackBar15->Scroll += gcnew System::EventHandler(this, &MyForm::trackBar15_Scroll);
			// 
			// button3
			// 
			this->button3->Enabled = false;
			this->button3->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->button3->Location = System::Drawing::Point(659, 394);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(155, 23);
			this->button3->TabIndex = 13;
			this->button3->Text = L"Show image";
			this->button3->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// textBox2
			// 
			this->textBox2->Enabled = false;
			this->textBox2->Location = System::Drawing::Point(15, 350);
			this->textBox2->Name = L"textBox2";
			this->textBox2->ReadOnly = true;
			this->textBox2->Size = System::Drawing::Size(303, 22);
			this->textBox2->TabIndex = 12;
			// 
			// button4
			// 
			this->button4->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->button4->Location = System::Drawing::Point(243, 321);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(75, 23);
			this->button4->TabIndex = 11;
			this->button4->Text = L"Ouvrir";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &MyForm::button4_Click);
			// 
			// DistinMoyenBox
			// 
			this->DistinMoyenBox->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->DistinMoyenBox->Location = System::Drawing::Point(333, 16);
			this->DistinMoyenBox->Name = L"DistinMoyenBox";
			this->DistinMoyenBox->Size = System::Drawing::Size(493, 372);
			this->DistinMoyenBox->TabIndex = 8;
			this->DistinMoyenBox->TabStop = false;
			this->DistinMoyenBox->Click += gcnew System::EventHandler(this, &MyForm::DistinMoyenBox_Click);
			// 
			// groupBox10
			// 
			this->groupBox10->Controls->Add(this->radioButtonMedian);
			this->groupBox10->Controls->Add(this->radioButtonMoyen);
			this->groupBox10->Location = System::Drawing::Point(6, 216);
			this->groupBox10->Name = L"groupBox10";
			this->groupBox10->Size = System::Drawing::Size(312, 81);
			this->groupBox10->TabIndex = 10;
			this->groupBox10->TabStop = false;
			this->groupBox10->Text = L"Filtre Moyen/Médian";
			this->groupBox10->Enter += gcnew System::EventHandler(this, &MyForm::groupBox10_Enter);
			// 
			// radioButtonMedian
			// 
			this->radioButtonMedian->AutoSize = true;
			this->radioButtonMedian->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->radioButtonMedian->Location = System::Drawing::Point(190, 33);
			this->radioButtonMedian->Name = L"radioButtonMedian";
			this->radioButtonMedian->Size = System::Drawing::Size(93, 17);
			this->radioButtonMedian->TabIndex = 4;
			this->radioButtonMedian->Text = L"Filtre Médian";
			this->radioButtonMedian->UseVisualStyleBackColor = true;
			this->radioButtonMedian->CheckedChanged += gcnew System::EventHandler(this, &MyForm::radioButtonMedian_CheckedChanged);
			// 
			// radioButtonMoyen
			// 
			this->radioButtonMoyen->AutoSize = true;
			this->radioButtonMoyen->Checked = true;
			this->radioButtonMoyen->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->radioButtonMoyen->Location = System::Drawing::Point(26, 33);
			this->radioButtonMoyen->Name = L"radioButtonMoyen";
			this->radioButtonMoyen->Size = System::Drawing::Size(89, 17);
			this->radioButtonMoyen->TabIndex = 3;
			this->radioButtonMoyen->TabStop = true;
			this->radioButtonMoyen->Text = L"Filtre Moyen";
			this->radioButtonMoyen->UseVisualStyleBackColor = true;
			this->radioButtonMoyen->CheckedChanged += gcnew System::EventHandler(this, &MyForm::radioButtonMoyen_CheckedChanged);
			// 
			// SourcememoyBox
			// 
			this->SourcememoyBox->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->SourcememoyBox->Location = System::Drawing::Point(15, 16);
			this->SourcememoyBox->Name = L"SourcememoyBox";
			this->SourcememoyBox->Size = System::Drawing::Size(303, 181);
			this->SourcememoyBox->TabIndex = 9;
			this->SourcememoyBox->TabStop = false;
			// 
			// tabPage2
			// 
			this->tabPage2->Controls->Add(this->bruit);
			this->tabPage2->Controls->Add(this->video);
			this->tabPage2->Controls->Add(this->circle);
			this->tabPage2->Controls->Add(this->rect);
			this->tabPage2->Controls->Add(this->Triangle);
			this->tabPage2->Location = System::Drawing::Point(4, 22);
			this->tabPage2->Name = L"tabPage2";
			this->tabPage2->Padding = System::Windows::Forms::Padding(3);
			this->tabPage2->Size = System::Drawing::Size(848, 502);
			this->tabPage2->TabIndex = 3;
			this->tabPage2->Text = L"Create Video";
			this->tabPage2->UseVisualStyleBackColor = true;
			this->tabPage2->Click += gcnew System::EventHandler(this, &MyForm::tabPage2_Click);
			// 
			// bruit
			// 
			this->bruit->Controls->Add(this->button5);
			this->bruit->Controls->Add(this->count);
			this->bruit->Controls->Add(this->label1);
			this->bruit->Controls->Add(this->pt);
			this->bruit->Location = System::Drawing::Point(297, 62);
			this->bruit->Name = L"bruit";
			this->bruit->Size = System::Drawing::Size(229, 162);
			this->bruit->TabIndex = 6;
			this->bruit->TabStop = false;
			this->bruit->Text = L"Bruit";
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(89, 121);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(60, 23);
			this->button5->TabIndex = 3;
			this->button5->Text = L"Color";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &MyForm::button5_Click);
			// 
			// count
			// 
			this->count->Location = System::Drawing::Point(89, 75);
			this->count->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 5, 0, 0, 0 });
			this->count->Name = L"count";
			this->count->Size = System::Drawing::Size(61, 22);
			this->count->TabIndex = 2;
			this->count->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 5, 0, 0, 0 });
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Courier New", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(170, 30);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(21, 21);
			this->label1->TabIndex = 1;
			this->label1->Text = L"T";
			// 
			// pt
			// 
			this->pt->Location = System::Drawing::Point(89, 29);
			this->pt->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 5, 0, 0, 0 });
			this->pt->Name = L"pt";
			this->pt->Size = System::Drawing::Size(61, 22);
			this->pt->TabIndex = 0;
			this->pt->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 5, 0, 0, 0 });
			// 
			// video
			// 
			this->video->Location = System::Drawing::Point(635, 263);
			this->video->Name = L"video";
			this->video->Size = System::Drawing::Size(108, 46);
			this->video->TabIndex = 5;
			this->video->Text = L"Create Video";
			this->video->UseVisualStyleBackColor = true;
			this->video->Click += gcnew System::EventHandler(this, &MyForm::video_Click);
			// 
			// circle
			// 
			this->circle->Controls->Add(this->c);
			this->circle->Location = System::Drawing::Point(69, 295);
			this->circle->Name = L"circle";
			this->circle->Size = System::Drawing::Size(140, 83);
			this->circle->TabIndex = 4;
			this->circle->TabStop = false;
			this->circle->Text = L"Circle";
			// 
			// c
			// 
			this->c->Location = System::Drawing::Point(40, 30);
			this->c->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 5, 0, 0, 0 });
			this->c->Name = L"c";
			this->c->Size = System::Drawing::Size(61, 22);
			this->c->TabIndex = 1;
			this->c->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 5, 0, 0, 0 });
			this->c->ValueChanged += gcnew System::EventHandler(this, &MyForm::c_ValueChanged);
			// 
			// rect
			// 
			this->rect->Controls->Add(this->r);
			this->rect->Location = System::Drawing::Point(69, 172);
			this->rect->Name = L"rect";
			this->rect->Size = System::Drawing::Size(140, 83);
			this->rect->TabIndex = 3;
			this->rect->TabStop = false;
			this->rect->Text = L"Rectangle";
			// 
			// r
			// 
			this->r->Location = System::Drawing::Point(40, 30);
			this->r->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 5, 0, 0, 0 });
			this->r->Name = L"r";
			this->r->Size = System::Drawing::Size(61, 22);
			this->r->TabIndex = 1;
			this->r->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 5, 0, 0, 0 });
			// 
			// Triangle
			// 
			this->Triangle->Controls->Add(this->t);
			this->Triangle->Location = System::Drawing::Point(69, 58);
			this->Triangle->Name = L"Triangle";
			this->Triangle->Size = System::Drawing::Size(140, 83);
			this->Triangle->TabIndex = 0;
			this->Triangle->TabStop = false;
			this->Triangle->Text = L"Triangle";
			this->Triangle->Enter += gcnew System::EventHandler(this, &MyForm::Triangle_Enter);
			// 
			// t
			// 
			this->t->Location = System::Drawing::Point(40, 30);
			this->t->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 5, 0, 0, 0 });
			this->t->Name = L"t";
			this->t->Size = System::Drawing::Size(61, 22);
			this->t->TabIndex = 1;
			this->t->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 5, 0, 0, 0 });
			// 
			// tabPage3
			// 
			this->tabPage3->Controls->Add(this->Distine);
			this->tabPage3->Controls->Add(this->Orgine);
			this->tabPage3->Controls->Add(this->button7);
			this->tabPage3->Controls->Add(this->button6);
			this->tabPage3->Controls->Add(this->textBox3);
			this->tabPage3->Location = System::Drawing::Point(4, 22);
			this->tabPage3->Name = L"tabPage3";
			this->tabPage3->Size = System::Drawing::Size(848, 502);
			this->tabPage3->TabIndex = 4;
			this->tabPage3->Text = L"Detect Object";
			this->tabPage3->UseVisualStyleBackColor = true;
			// 
			// button7
			// 
			this->button7->Enabled = false;
			this->button7->Location = System::Drawing::Point(697, 44);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(100, 23);
			this->button7->TabIndex = 3;
			this->button7->Text = L"Start";
			this->button7->UseVisualStyleBackColor = true;
			this->button7->Click += gcnew System::EventHandler(this, &MyForm::button7_Click);
			// 
			// button6
			// 
			this->button6->Location = System::Drawing::Point(536, 44);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(75, 23);
			this->button6->TabIndex = 2;
			this->button6->Text = L"Load";
			this->button6->UseVisualStyleBackColor = true;
			this->button6->Click += gcnew System::EventHandler(this, &MyForm::button6_Click);
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(33, 46);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(393, 22);
			this->textBox3->TabIndex = 0;
			this->textBox3->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox3_TextChanged);
			// 
			// ShowPicture
			// 
			this->ShowPicture->FileName = L"openFileDialog1";
			this->ShowPicture->FileOk += gcnew System::ComponentModel::CancelEventHandler(this, &MyForm::ShowPicture_FileOk);
			// 
			// selectImage
			// 
			this->selectImage->FileName = L"selectImage";
			this->selectImage->FileOk += gcnew System::ComponentModel::CancelEventHandler(this, &MyForm::selectImage_FileOk);
			// 
			// medmoyimage
			// 
			this->medmoyimage->FileName = L"medmoyimage";
			this->medmoyimage->FileOk += gcnew System::ComponentModel::CancelEventHandler(this, &MyForm::medmoyimage_FileOk);
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			this->openFileDialog1->FileOk += gcnew System::ComponentModel::CancelEventHandler(this, &MyForm::openFileDialog1_FileOk);
			// 
			// Orgine
			// 
			this->Orgine->Location = System::Drawing::Point(4, 131);
			this->Orgine->Name = L"Orgine";
			this->Orgine->Size = System::Drawing::Size(393, 281);
			this->Orgine->TabIndex = 4;
			this->Orgine->TabStop = false;
			// 
			// Distine
			// 
			this->Distine->Location = System::Drawing::Point(448, 131);
			this->Distine->Name = L"Distine";
			this->Distine->Size = System::Drawing::Size(393, 281);
			this->Distine->TabIndex = 5;
			this->Distine->TabStop = false;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::White;
			this->ClientSize = System::Drawing::Size(861, 530);
			this->Controls->Add(this->tabControl1);
			this->Name = L"MyForm";
			this->Text = L"ComputerVision";
			this->tabControl1->ResumeLayout(false);
			this->Convolution->ResumeLayout(false);
			this->Convolution->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->boxC2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->boxC1))->EndInit();
			this->Morphologique->ResumeLayout(false);
			this->Morphologique->PerformLayout();
			this->groupBox6->ResumeLayout(false);
			this->groupBox6->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->SourceBox))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->DestinationBox))->EndInit();
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar1))->EndInit();
			this->groupBox3->ResumeLayout(false);
			this->groupBox3->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar3))->EndInit();
			this->groupBox4->ResumeLayout(false);
			this->groupBox4->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar4))->EndInit();
			this->groupBox5->ResumeLayout(false);
			this->groupBox5->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar5))->EndInit();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar2))->EndInit();
			this->tabPage1->ResumeLayout(false);
			this->tabPage1->PerformLayout();
			this->groupBox11->ResumeLayout(false);
			this->groupBox11->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar15))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->DistinMoyenBox))->EndInit();
			this->groupBox10->ResumeLayout(false);
			this->groupBox10->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->SourcememoyBox))->EndInit();
			this->tabPage2->ResumeLayout(false);
			this->bruit->ResumeLayout(false);
			this->bruit->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->count))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pt))->EndInit();
			this->circle->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->c))->EndInit();
			this->rect->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->r))->EndInit();
			this->Triangle->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->t))->EndInit();
			this->tabPage3->ResumeLayout(false);
			this->tabPage3->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Orgine))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Distine))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
private: System::Void ShowPicture_FileOk(System::Object^  sender, System::ComponentModel::CancelEventArgs^  e) {
			this->Activate();
	std::string filename = msclr::interop::marshal_as<std::string>(ShowPicture->FileName);
	cv::Mat img = cv::imread(filename);
	source = img;
	Morph = img;
	textBox1->Text = ShowPicture->FileName;
	trackBar2->Enabled = true;
	trackBar3->Enabled = true;
	trackBar1->Enabled = true;
	trackBar4->Enabled = true;
	trackBar5->Enabled = true;
	DrawCVImage(SourceBox, img);
	DrawCVImage(DestinationBox, img);
}
private: System::Void trackBar4_Scroll(System::Object^  sender, System::EventArgs^  e) {
	System::Windows::Forms::TrackBar^ myTB;
	myTB = dynamic_cast<System::Windows::Forms::TrackBar^>(sender);

	int erosion_size = trackBar4->Value;
	//applique Fermeture
	Morph = Morphology_Operations(erosion_type, erosion_size, 2, source, 0);
	DrawCVImage(DestinationBox, Morph);

}
private: System::Void trackBar5_Scroll(System::Object^  sender, System::EventArgs^  e) {
	System::Windows::Forms::TrackBar^ myTB;
	myTB = dynamic_cast<System::Windows::Forms::TrackBar^>(sender);

	int erosion_size = trackBar5->Value;
	//applique Gradient
	Morph = Morphology_Operations(erosion_type, erosion_size, 1, source, 0);
	DrawCVImage(DestinationBox, Morph);

}
private: System::Void file_Click(System::Object^  sender, System::EventArgs^  e) {
	ShowPicture->Filter = "Format Fichier (*.jpg*)|*.jpg*";
	ShowPicture->ShowDialog();
}
private: System::Void tabPage1_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void tabPage2_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void comboBox1_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void Triangle_Enter(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void panel1_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
}
private: System::Void color_Click(System::Object^  sender, System::EventArgs^  e) {
	colorselect->ShowDialog();
}
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
	selectImage->Filter = "Format Fichier (*.jpg*)|*.jpg*";
	selectImage->ShowDialog();
}
private: System::Void selectImage_FileOk(System::Object^  sender, System::ComponentModel::CancelEventArgs^  e) {
	//Convolution Filter Image Select
	this->Activate();
	std::string filename = msclr::interop::marshal_as<std::string>(selectImage->FileName);
	cv::Mat img = cv::imread(filename);
	Convolutionsource = img;
	DrawCVImage(boxC1, img);
	this->button2->Enabled = true;
}
private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
	//Convolution Filter  : Apply
	cv::Mat v  = Convolutionsource;
	if (laplace->Checked)
	{
		v= filtroLaplace(Convolutionsource);
	}
	else
	{
		v = filterGussien(Convolutionsource);
	}
	DrawCVImage(boxC2, v);
}
private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) {
	medmoyimage->Filter = "Format Fichier (*.jpg*)|*.jpg*";
	medmoyimage->ShowDialog();
}
private: System::Void medmoyimage_FileOk(System::Object^  sender, System::ComponentModel::CancelEventArgs^  e) {
	this->Activate();
	trackBar15->Enabled = true;
	std::string filename = msclr::interop::marshal_as<std::string>(medmoyimage->FileName);
	cv::Mat img = cv::imread(filename);
	textBox2->Text = medmoyimage->FileName;
	MedMoysrc = img;
	DrawCVImage(SourcememoyBox, img);
	this->button3->Enabled = true;
}
private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
	
	cv::Mat v = MedMoysrc;
	int size = trackBar15->Value*2;

	if (radioButtonMoyen->Checked)
	{
		v = filtreMoyen(MedMoysrc,size);
	}
	else
	{
		v = filtreMediane(MedMoysrc,size);
	}
	DrawCVImage(DistinMoyenBox, v);
}
private: System::Void radioButtonMoyen_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void DistinMoyenBox_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void video_Click(System::Object^  sender, System::EventArgs^  e) {
	int a = (int)t->Value;
	int b = (int)r->Value;
	int f = (int)c->Value;
	int p = (int)pt->Value;
	int ct = (int)count->Value;
	Color clr = colorDialog1->Color;
	create_video(a, b, f, p,ct,clr.R,clr.G,clr.B);
}
private: System::Void button6_Click(System::Object^  sender, System::EventArgs^  e) {
	openFileDialog1->Filter = "Format Fichier (*.avi*)|*.avi*";
	openFileDialog1->ShowDialog();
}
private: System::Void openFileDialog1_FileOk(System::Object^  sender, System::ComponentModel::CancelEventArgs^  e) {
	this->Activate();
	button7->Enabled = true;
	location = msclr::interop::marshal_as<std::string>(openFileDialog1->FileName);
	textBox3->Text = openFileDialog1->FileName;
}
private: System::Void button7_Click(System::Object^  sender, System::EventArgs^  e) {
	detecter_video(location);
}
private: System::Void trackBar2_Scroll(System::Object^  sender, System::EventArgs^  e) {
	System::Windows::Forms::TrackBar^ myTB;
	myTB = dynamic_cast<System::Windows::Forms::TrackBar^>(sender);

	int erosion_size = trackBar2->Value;
	Morph = Erosion(erosion_type,erosion_size, source, 0);
	DrawCVImage(DestinationBox, Morph);
}
private: System::Void radioButton4_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
	erosion_type = 0;
}
private: System::Void radioButton1_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
	erosion_type = 1;
}
private: System::Void groupBox6_Enter(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void radioButton3_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
	erosion_type = 2;
}
private: System::Void trackBar1_Scroll(System::Object^  sender, System::EventArgs^  e) {
	System::Windows::Forms::TrackBar^ myTB;
	myTB = dynamic_cast<System::Windows::Forms::TrackBar^>(sender);
	//Dilation  : Apply

	int erosion_size = trackBar1->Value;
	Morph = Dilation(erosion_type, erosion_size, source, 0);
	DrawCVImage(DestinationBox, Morph);
}
private: System::Void groupBox3_Enter(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void trackBar3_Scroll(System::Object^  sender, System::EventArgs^  e) {
	System::Windows::Forms::TrackBar^ myTB;
	myTB = dynamic_cast<System::Windows::Forms::TrackBar^>(sender);

	int erosion_size = trackBar3->Value;

	Morph = Morphology_Operations(erosion_type, erosion_size,0, source, 0);
	DrawCVImage(DestinationBox, Morph);
}
private: System::Void c_ValueChanged(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void textBox3_TextChanged(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void panel1_Paint_1(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {

}
private: System::Void button5_Click(System::Object^  sender, System::EventArgs^  e) {
	colorDialog1->ShowDialog();
	button5->BackColor = colorDialog1->Color;
}
private: System::Void groupBox10_Enter(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void radioButtonMedian_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void trackBar15_Scroll(System::Object^  sender, System::EventArgs^  e) {
}
int detecter_video(string filename) {

	VideoCapture cap(filename); // recuperer la video "../vision/sourse/vid.mp4"
	if (!cap.isOpened())
		return -1;

	int width = 480;
	int height = 480;
	// changer la taille de l'image
	cap.set(CAP_PROP_FRAME_WIDTH, width);
	cap.set(CAP_PROP_FRAME_HEIGHT, height);

	Mat src,dst;
	Mat gray;
	Mat colored;
	Mat firstframe;
	int tolerance = 10;
	// sauter les premieres capture
	for (int i = 0; i < 10; i++)
		cap >> src;
	// changer la taille de l'image
	resize(src, src, cv::Size(width, height), 0, 0, INTER_CUBIC);
	// convertir niveau du gris
	//cvtColor(frame, frame, COLOR_BGR2GRAY);
	// sauvgarde du background
	//firstframe = frame.clone();
	Mat contoursMat;
	for (;;) {
		cap >> src; // recuperer une image
		Mat out,gray,blurred, thresh;
		if (src.empty()) {
			cap.open(filename);
			cap.set(CAP_PROP_FRAME_WIDTH, width);
			cap.set(CAP_PROP_FRAME_HEIGHT, height);
			cap >> src;
			break;
		}
		cv::cvtColor(src, gray, COLOR_RGB2GRAY);

		// Use Canny instead of threshold to catch squares with gradient shading
		Mat bw;
		Canny(gray, bw, 0, 50, 5);

		// Find contours
		vector<vector<cv::Point> > contours;
		findContours(bw.clone(), contours, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);

		vector<cv::Point> approx;
		Mat dst = src.clone();

		for (int i = 0; i < contours.size(); i++)
		{
			// Approximate contour with accuracy proportional
			// to the contour perimeter
			cv::approxPolyDP(Mat(contours[i]), approx, cv::arcLength(Mat(contours[i]), true)*0.02, true);

			// Skip small or non-convex objects 
			if (std::fabs(cv::contourArea(contours[i])) < 100 || !cv::isContourConvex(approx))
				continue;

			if (approx.size() == 3)
			{
				setLabel(dst, "TRI", contours[i],src);    // Triangles
			}
			else if (approx.size() >= 4 && approx.size() <= 6)
			{
				// Number of vertices of polygonal curve
				int vtc = approx.size();

				// Get the cosines of all corners
				std::vector<double> cos;
				for (int j = 2; j < vtc + 1; j++)
					cos.push_back(angle(approx[j%vtc], approx[j - 2], approx[j - 1]));

				// Sort ascending the cosine values
				std::sort(cos.begin(), cos.end());

				// Get the lowest and the highest cosine
				double mincos = cos.front();
				double maxcos = cos.back();

				// Use the degrees obtained above and the number of vertices
				// to determine the shape of the contour
				if (vtc == 4 && mincos >= -0.1 && maxcos <= 0.3)
					setLabel(dst, "RECT", contours[i], src);
				else if (vtc == 5 && mincos >= -0.34 && maxcos <= -0.27)
					setLabel(dst, "PENTA", contours[i], src);
				else if (vtc == 6 && mincos >= -0.55 && maxcos <= -0.45)
					setLabel(dst, "HEXA", contours[i], src);
			}
			else
			{
				// Detect and label circles
				double area = cv::contourArea(contours[i]);
				cv::Rect r = cv::boundingRect(contours[i]);
				int radius = r.width / 2;

				if (std::abs(1 - ((double)r.width / r.height)) <= 0.2 &&
					std::abs(1 - (area / (CV_PI * std::pow(radius, 2)))) <= 0.2)
					setLabel(dst, "CIR", contours[i], src);
			}
		}
		DrawCVImage(Orgine, src);
		DrawCVImage(Distine, dst);

		if (waitKey(30) == 27) //ESC
			break;
	}
	return 0;

}
vector<cv::Point> grab_contours(vector<vector<cv::Point>> cnts) {
	vector<cv::Point> out ;
	if (sizeof(cnts) == 2)
		out = cnts[0];
	else if (sizeof(cnts) == 3)
		out = cnts[1];
	return out;
}
};
}
