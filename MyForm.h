#pragma once
#include <atlstr.h>
#include <iostream>
#include <fstream>
#include "BinTree.h"
#include "FileCompressor.h"

using namespace System;
using namespace System::Text;
using namespace System::IO;
#include <msclr/marshal.h>
#include <msclr/marshal_cppstd.h>

using namespace msclr::interop;
using namespace System;
using System::Runtime::InteropServices::Marshal;


namespace HuffmanCoding01 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace std;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
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
		/*HuffmanCompression(void)
		{

		}

		HuffmanDecompression(void)
		{

		}*/

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
	private: System::Windows::Forms::TabPage^  tabPage1;
	private: System::Windows::Forms::Button^  buttonCompress;
	private: System::Windows::Forms::Button^  buttonDecompress;

	private: System::Windows::Forms::Panel^  panel1;
	private: System::Windows::Forms::Button^  buttonBrowseCompress;
	private: System::Windows::Forms::TabPage^  tabPage2;
	private: System::Windows::Forms::ProgressBar^  progressBarDecompress;
	private: System::Windows::Forms::Panel^  panel2;
	private: System::Windows::Forms::Button^  buttonBrowseDecompress;
	private: System::Windows::Forms::TextBox^  textFileDecompress;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::OpenFileDialog^  openFileDialog1;
	private: System::Windows::Forms::FolderBrowserDialog^  folderBrowserDialog1;
	private: System::Windows::Forms::Panel^  panel3;
	private: System::Windows::Forms::TextBox^  textFileCompressOut;



	private: System::Windows::Forms::Label^  label3;


	private: System::Windows::Forms::Timer^  timer1;
	private: System::Windows::Forms::Panel^  panel4;
	private: System::Windows::Forms::Button^  buttonBrowCompress;
	private: System::Windows::Forms::Button^  buttonBrowDecompress;


	private: System::Windows::Forms::TextBox^  textFileDecompressOut;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::ProgressBar^  progressBarCompress;
	private: System::Windows::Forms::Label^  labelDataFile;
	private: System::Windows::Forms::ListBox^  listBoxFile;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Button^  buttonRemove;
	private: System::Windows::Forms::ListView^  listView1;
	private: System::Windows::Forms::ColumnHeader^  columnHeader1;
	private: System::Windows::Forms::ColumnHeader^  columnHeader2;
	private: System::Windows::Forms::ColumnHeader^  columnHeader3;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::ListView^  listView2;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::ColumnHeader^  columnHeader4;
	private: System::Windows::Forms::ColumnHeader^  columnHeader5;
	private: System::Windows::Forms::ColumnHeader^  columnHeader6;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::ListView^  listView3;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::ColumnHeader^  columnHeader7;
	private: System::Windows::Forms::ColumnHeader^  columnHeader8;
	private: System::Windows::Forms::ColumnHeader^  columnHeader9;
	private: System::Windows::Forms::Label^  label9;
	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::Label^  label10;
	private: System::Windows::Forms::Label^  label11;
	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^  fileToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  exitToolStripMenuItem;


	private: System::Windows::Forms::ToolStripMenuItem^  helpToolStripMenuItem1;
	private: System::Windows::Forms::ToolStripMenuItem^  aboutToolStripMenuItem1;
	private: System::Windows::Forms::Label^  label12;
	private: System::Windows::Forms::Label^  label13;




	private: System::ComponentModel::IContainer^  components;


	private:
		/// <summary>
		/// Required designer variable.
		// </summary>
		
		// OK
		ref class CallHuffman {
		public:
			FileCompressor* file;
			float *nisbah;
			float *entropi;
			float *rata_bit;
			bool busy = true;
			array<String^>^ filepaths_in;		// menyimpan daftar path file input ke dalam array
			System::String^ filepath_in;		
			System::String^ filepath_out;
			
			System::Windows::Forms::ProgressBar^ pb;
			System::Windows::Forms::ProgressBar^ pbd;
			System::Windows::Forms::ListView^ lv;
			System::Windows::Forms::ListView^ lv2;
			System::Windows::Forms::ListView^ lv3;
			System::Windows::Forms::Label^ ln;
			System::Windows::Forms::Label^ lt;
			System::Windows::Forms::Label^ ltd;
			System::Windows::Forms::Label^ filein_size;
			System::Windows::Forms::Label^ fileout_size;
			System::Windows::Forms::Button^  buttonCom;
			System::Windows::Forms::Button^  buttonDec;

			int n;								// menyimpan jumlah file input

			CallHuffman(array<String^>^ namainput, System::String^ namaoutput, int i, System::Windows::Forms::ListView^ LV, System::Windows::Forms::ListView^ LV2, System::Windows::Forms::Label^ lnis, System::Windows::Forms::Label^ LT, System::Windows::Forms::ProgressBar^ PB, System::Windows::Forms::Label^ _filein_size, System::Windows::Forms::Label^ _fileout_size, System::Windows::Forms::Button^  _buttonCom){
				nisbah = new float[0];
				entropi = new float[i];
				rata_bit = new float[i];
				n = i;
				file = new FileCompressor();
				filepaths_in = namainput;
				filepath_out = namaoutput;
				lv = LV;
				lv2 = LV2;
				ln = lnis;
				pb = PB;
				lt = LT;
				filein_size = _filein_size;
				fileout_size = _fileout_size;
				buttonCom = _buttonCom;
			}

			CallHuffman(System::String^ namainput, System::String^ namaoutput, System::Windows::Forms::ListView^ LV3, System::Windows::Forms::Label^ LTD, System::Windows::Forms::ProgressBar^ PBD, System::Windows::Forms::Button^  _buttonDec){
				file = new FileCompressor();
				filepath_in = namainput;
				filepath_out = namaoutput;
				lv3 = LV3;
				ltd = LTD;
				pbd = PBD;
				buttonDec = _buttonDec;
			}
			~CallHuffman() {
				delete file;
			}

			void startCompression() {
				busy = true;
				file->compress(filepaths_in, filepath_out, n, nisbah, entropi, rata_bit, lv, lv2, ln, lt, pb, filein_size, fileout_size, buttonCom);
				busy = false;
			}

			void startDecompression() {
				busy = true;
				file->decompress(filepath_in, filepath_out, lv3, ltd, pbd, buttonDec);
				busy = false;
			}
			

			int checkProgress() {
				return file->getProgress();
			}

			bool isBusy() {
				return busy;
			}

		};

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
			this->tabPage1 = (gcnew System::Windows::Forms::TabPage());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->listView2 = (gcnew System::Windows::Forms::ListView());
			this->columnHeader4 = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader5 = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader6 = (gcnew System::Windows::Forms::ColumnHeader());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->listView1 = (gcnew System::Windows::Forms::ListView());
			this->columnHeader1 = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader2 = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader3 = (gcnew System::Windows::Forms::ColumnHeader());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->progressBarCompress = (gcnew System::Windows::Forms::ProgressBar());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->buttonBrowCompress = (gcnew System::Windows::Forms::Button());
			this->textFileCompressOut = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->buttonCompress = (gcnew System::Windows::Forms::Button());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->buttonRemove = (gcnew System::Windows::Forms::Button());
			this->labelDataFile = (gcnew System::Windows::Forms::Label());
			this->listBoxFile = (gcnew System::Windows::Forms::ListBox());
			this->buttonBrowseCompress = (gcnew System::Windows::Forms::Button());
			this->tabPage2 = (gcnew System::Windows::Forms::TabPage());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->listView3 = (gcnew System::Windows::Forms::ListView());
			this->columnHeader7 = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader8 = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader9 = (gcnew System::Windows::Forms::ColumnHeader());
			this->panel4 = (gcnew System::Windows::Forms::Panel());
			this->buttonBrowDecompress = (gcnew System::Windows::Forms::Button());
			this->textFileDecompressOut = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->buttonDecompress = (gcnew System::Windows::Forms::Button());
			this->progressBarDecompress = (gcnew System::Windows::Forms::ProgressBar());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->buttonBrowseDecompress = (gcnew System::Windows::Forms::Button());
			this->textFileDecompress = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->folderBrowserDialog1 = (gcnew System::Windows::Forms::FolderBrowserDialog());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->fileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->exitToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->helpToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->aboutToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->tabControl1->SuspendLayout();
			this->tabPage1->SuspendLayout();
			this->panel3->SuspendLayout();
			this->panel1->SuspendLayout();
			this->tabPage2->SuspendLayout();
			this->panel4->SuspendLayout();
			this->panel2->SuspendLayout();
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// tabControl1
			// 
			this->tabControl1->Controls->Add(this->tabPage1);
			this->tabControl1->Controls->Add(this->tabPage2);
			this->tabControl1->Location = System::Drawing::Point(4, 29);
			this->tabControl1->Name = L"tabControl1";
			this->tabControl1->SelectedIndex = 0;
			this->tabControl1->Size = System::Drawing::Size(815, 436);
			this->tabControl1->SizeMode = System::Windows::Forms::TabSizeMode::FillToRight;
			this->tabControl1->TabIndex = 0;
			// 
			// tabPage1
			// 
			this->tabPage1->Controls->Add(this->label13);
			this->tabPage1->Controls->Add(this->label12);
			this->tabPage1->Controls->Add(this->label10);
			this->tabPage1->Controls->Add(this->label9);
			this->tabPage1->Controls->Add(this->label6);
			this->tabPage1->Controls->Add(this->listView2);
			this->tabPage1->Controls->Add(this->label5);
			this->tabPage1->Controls->Add(this->listView1);
			this->tabPage1->Controls->Add(this->label1);
			this->tabPage1->Controls->Add(this->progressBarCompress);
			this->tabPage1->Controls->Add(this->panel3);
			this->tabPage1->Controls->Add(this->buttonCompress);
			this->tabPage1->Controls->Add(this->panel1);
			this->tabPage1->Location = System::Drawing::Point(4, 22);
			this->tabPage1->Name = L"tabPage1";
			this->tabPage1->Padding = System::Windows::Forms::Padding(3);
			this->tabPage1->Size = System::Drawing::Size(807, 410);
			this->tabPage1->TabIndex = 0;
			this->tabPage1->Text = L"Compress";
			this->tabPage1->UseVisualStyleBackColor = true;
			this->tabPage1->Click += gcnew System::EventHandler(this, &MyForm::tabPage1_Click);
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(151, 336);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(0, 13);
			this->label10->TabIndex = 15;
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(150, 336);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(0, 13);
			this->label9->TabIndex = 14;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Enabled = false;
			this->label6->Location = System::Drawing::Point(151, 323);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(0, 13);
			this->label6->TabIndex = 13;
			this->label6->Click += gcnew System::EventHandler(this, &MyForm::label6_Click);
			// 
			// listView2
			// 
			this->listView2->Columns->AddRange(gcnew cli::array< System::Windows::Forms::ColumnHeader^  >(3) {
				this->columnHeader4, this->columnHeader5,
					this->columnHeader6
			});
			this->listView2->Location = System::Drawing::Point(506, 307);
			this->listView2->Name = L"listView2";
			this->listView2->Size = System::Drawing::Size(280, 97);
			this->listView2->TabIndex = 12;
			this->listView2->UseCompatibleStateImageBehavior = false;
			this->listView2->View = System::Windows::Forms::View::Details;
			// 
			// columnHeader4
			// 
			this->columnHeader4->Text = L"ID";
			this->columnHeader4->Width = 50;
			// 
			// columnHeader5
			// 
			this->columnHeader5->Text = L"Entropi";
			this->columnHeader5->Width = 120;
			// 
			// columnHeader6
			// 
			this->columnHeader6->Text = L"Rata-rata bit";
			this->columnHeader6->Width = 120;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(507, 291);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(52, 13);
			this->label5->TabIndex = 11;
			this->label5->Text = L"Kalkulasi:";
			// 
			// listView1
			// 
			this->listView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::ColumnHeader^  >(3) {
				this->columnHeader1, this->columnHeader2,
					this->columnHeader3
			});
			this->listView1->Location = System::Drawing::Point(506, 28);
			this->listView1->Name = L"listView1";
			this->listView1->Size = System::Drawing::Size(295, 253);
			this->listView1->TabIndex = 10;
			this->listView1->UseCompatibleStateImageBehavior = false;
			this->listView1->View = System::Windows::Forms::View::Details;
			// 
			// columnHeader1
			// 
			this->columnHeader1->Text = L"ID";
			this->columnHeader1->Width = 50;
			// 
			// columnHeader2
			// 
			this->columnHeader2->Text = L"Proses";
			this->columnHeader2->Width = 200;
			// 
			// columnHeader3
			// 
			this->columnHeader3->Text = L"Status";
			this->columnHeader3->Width = 50;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(507, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(113, 13);
			this->label1->TabIndex = 9;
			this->label1->Text = L"Compression progress:";
			// 
			// progressBarCompress
			// 
			this->progressBarCompress->Location = System::Drawing::Point(3, 245);
			this->progressBarCompress->Name = L"progressBarCompress";
			this->progressBarCompress->Size = System::Drawing::Size(497, 18);
			this->progressBarCompress->TabIndex = 8;
			// 
			// panel3
			// 
			this->panel3->Controls->Add(this->buttonBrowCompress);
			this->panel3->Controls->Add(this->textFileCompressOut);
			this->panel3->Controls->Add(this->label3);
			this->panel3->Location = System::Drawing::Point(6, 143);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(489, 53);
			this->panel3->TabIndex = 7;
			this->panel3->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::panel3_Paint);
			// 
			// buttonBrowCompress
			// 
			this->buttonBrowCompress->Location = System::Drawing::Point(388, 18);
			this->buttonBrowCompress->Name = L"buttonBrowCompress";
			this->buttonBrowCompress->Size = System::Drawing::Size(80, 20);
			this->buttonBrowCompress->TabIndex = 3;
			this->buttonBrowCompress->Text = L"Browse";
			this->buttonBrowCompress->UseVisualStyleBackColor = true;
			this->buttonBrowCompress->Click += gcnew System::EventHandler(this, &MyForm::buttonBrowCompress_Click);
			// 
			// textFileCompressOut
			// 
			this->textFileCompressOut->Location = System::Drawing::Point(75, 18);
			this->textFileCompressOut->Name = L"textFileCompressOut";
			this->textFileCompressOut->Size = System::Drawing::Size(295, 20);
			this->textFileCompressOut->TabIndex = 1;
			this->textFileCompressOut->TextChanged += gcnew System::EventHandler(this, &MyForm::textFileCompressOut_TextChanged);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(11, 18);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(66, 13);
			this->label3->TabIndex = 0;
			this->label3->Text = L"Destination :";
			// 
			// buttonCompress
			// 
			this->buttonCompress->Enabled = false;
			this->buttonCompress->Location = System::Drawing::Point(153, 291);
			this->buttonCompress->Name = L"buttonCompress";
			this->buttonCompress->Size = System::Drawing::Size(170, 30);
			this->buttonCompress->TabIndex = 6;
			this->buttonCompress->Text = L"Compress";
			this->buttonCompress->UseVisualStyleBackColor = true;
			this->buttonCompress->Click += gcnew System::EventHandler(this, &MyForm::buttonCompress_Click_1);
			// 
			// panel1
			// 
			this->panel1->Controls->Add(this->button2);
			this->panel1->Controls->Add(this->buttonRemove);
			this->panel1->Controls->Add(this->labelDataFile);
			this->panel1->Controls->Add(this->listBoxFile);
			this->panel1->Controls->Add(this->buttonBrowseCompress);
			this->panel1->Location = System::Drawing::Point(5, 6);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(490, 131);
			this->panel1->TabIndex = 0;
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(398, 79);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(80, 22);
			this->button2->TabIndex = 4;
			this->button2->Text = L"Remove all";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// buttonRemove
			// 
			this->buttonRemove->Location = System::Drawing::Point(398, 53);
			this->buttonRemove->Name = L"buttonRemove";
			this->buttonRemove->Size = System::Drawing::Size(80, 20);
			this->buttonRemove->TabIndex = 3;
			this->buttonRemove->Text = L"Remove";
			this->buttonRemove->UseVisualStyleBackColor = true;
			this->buttonRemove->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// labelDataFile
			// 
			this->labelDataFile->AutoSize = true;
			this->labelDataFile->Location = System::Drawing::Point(3, 11);
			this->labelDataFile->Name = L"labelDataFile";
			this->labelDataFile->Size = System::Drawing::Size(55, 13);
			this->labelDataFile->TabIndex = 1;
			this->labelDataFile->Text = L"Daftar file:";
			// 
			// listBoxFile
			// 
			this->listBoxFile->FormattingEnabled = true;
			this->listBoxFile->Location = System::Drawing::Point(3, 27);
			this->listBoxFile->Name = L"listBoxFile";
			this->listBoxFile->Size = System::Drawing::Size(389, 95);
			this->listBoxFile->TabIndex = 2;
//			this->listBoxFile->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::listBoxFile_SelectedIndexChanged);
			// 
			// buttonBrowseCompress
			// 
			this->buttonBrowseCompress->Location = System::Drawing::Point(398, 27);
			this->buttonBrowseCompress->Name = L"buttonBrowseCompress";
			this->buttonBrowseCompress->Size = System::Drawing::Size(80, 20);
			this->buttonBrowseCompress->TabIndex = 2;
			this->buttonBrowseCompress->Text = L"Add...";
			this->buttonBrowseCompress->UseVisualStyleBackColor = true;
			this->buttonBrowseCompress->Click += gcnew System::EventHandler(this, &MyForm::buttonBrowseCompress_Click);
			// 
			// tabPage2
			// 
			this->tabPage2->Controls->Add(this->label11);
			this->tabPage2->Controls->Add(this->label8);
			this->tabPage2->Controls->Add(this->label7);
			this->tabPage2->Controls->Add(this->listView3);
			this->tabPage2->Controls->Add(this->panel4);
			this->tabPage2->Controls->Add(this->buttonDecompress);
			this->tabPage2->Controls->Add(this->progressBarDecompress);
			this->tabPage2->Controls->Add(this->panel2);
			this->tabPage2->Location = System::Drawing::Point(4, 22);
			this->tabPage2->Name = L"tabPage2";
			this->tabPage2->Padding = System::Windows::Forms::Padding(3);
			this->tabPage2->Size = System::Drawing::Size(807, 410);
			this->tabPage2->TabIndex = 1;
			this->tabPage2->Text = L"Decompress";
			this->tabPage2->UseVisualStyleBackColor = true;
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Location = System::Drawing::Point(160, 218);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(0, 13);
			this->label11->TabIndex = 10;
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(157, 192);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(0, 13);
			this->label8->TabIndex = 9;
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(507, 9);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(126, 13);
			this->label7->TabIndex = 8;
			this->label7->Text = L"Decompression progress:";
			// 
			// listView3
			// 
			this->listView3->Columns->AddRange(gcnew cli::array< System::Windows::Forms::ColumnHeader^  >(3) {
				this->columnHeader7, this->columnHeader8,
					this->columnHeader9
			});
			this->listView3->Location = System::Drawing::Point(506, 28);
			this->listView3->Name = L"listView3";
			this->listView3->Size = System::Drawing::Size(298, 376);
			this->listView3->TabIndex = 7;
			this->listView3->UseCompatibleStateImageBehavior = false;
			this->listView3->View = System::Windows::Forms::View::Details;
			// 
			// columnHeader7
			// 
			this->columnHeader7->Text = L"ID";
			this->columnHeader7->Width = 50;
			// 
			// columnHeader8
			// 
			this->columnHeader8->Text = L"Proses";
			this->columnHeader8->Width = 200;
			// 
			// columnHeader9
			// 
			this->columnHeader9->Text = L"Status";
			// 
			// panel4
			// 
			this->panel4->Controls->Add(this->buttonBrowDecompress);
			this->panel4->Controls->Add(this->textFileDecompressOut);
			this->panel4->Controls->Add(this->label4);
			this->panel4->Location = System::Drawing::Point(5, 66);
			this->panel4->Name = L"panel4";
			this->panel4->Size = System::Drawing::Size(480, 52);
			this->panel4->TabIndex = 3;
			// 
			// buttonBrowDecompress
			// 
			this->buttonBrowDecompress->Location = System::Drawing::Point(388, 18);
			this->buttonBrowDecompress->Name = L"buttonBrowDecompress";
			this->buttonBrowDecompress->Size = System::Drawing::Size(80, 20);
			this->buttonBrowDecompress->TabIndex = 5;
			this->buttonBrowDecompress->Text = L"Browse";
			this->buttonBrowDecompress->UseVisualStyleBackColor = true;
			this->buttonBrowDecompress->Click += gcnew System::EventHandler(this, &MyForm::buttonBrowDecompress_Click);
			// 
			// textFileDecompressOut
			// 
			this->textFileDecompressOut->Location = System::Drawing::Point(75, 18);
			this->textFileDecompressOut->Name = L"textFileDecompressOut";
			this->textFileDecompressOut->Size = System::Drawing::Size(295, 20);
			this->textFileDecompressOut->TabIndex = 4;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(11, 18);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(63, 13);
			this->label4->TabIndex = 3;
			this->label4->Text = L"Destination:";
			// 
			// buttonDecompress
			// 
			this->buttonDecompress->Enabled = false;
			this->buttonDecompress->Location = System::Drawing::Point(160, 159);
			this->buttonDecompress->Name = L"buttonDecompress";
			this->buttonDecompress->Size = System::Drawing::Size(170, 30);
			this->buttonDecompress->TabIndex = 6;
			this->buttonDecompress->Text = L"Decompress";
			this->buttonDecompress->UseVisualStyleBackColor = true;
			this->buttonDecompress->Click += gcnew System::EventHandler(this, &MyForm::buttonDecompress_Click);
			// 
			// progressBarDecompress
			// 
			this->progressBarDecompress->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->progressBarDecompress->Location = System::Drawing::Point(3, 123);
			this->progressBarDecompress->Name = L"progressBarDecompress";
			this->progressBarDecompress->Size = System::Drawing::Size(497, 18);
			this->progressBarDecompress->TabIndex = 5;
			this->progressBarDecompress->Click += gcnew System::EventHandler(this, &MyForm::progressBarDecompress_Click);
			// 
			// panel2
			// 
			this->panel2->Controls->Add(this->buttonBrowseDecompress);
			this->panel2->Controls->Add(this->textFileDecompress);
			this->panel2->Controls->Add(this->label2);
			this->panel2->Location = System::Drawing::Point(5, 6);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(480, 57);
			this->panel2->TabIndex = 0;
			// 
			// buttonBrowseDecompress
			// 
			this->buttonBrowseDecompress->Location = System::Drawing::Point(388, 19);
			this->buttonBrowseDecompress->Name = L"buttonBrowseDecompress";
			this->buttonBrowseDecompress->Size = System::Drawing::Size(80, 20);
			this->buttonBrowseDecompress->TabIndex = 2;
			this->buttonBrowseDecompress->Text = L"Browse";
			this->buttonBrowseDecompress->UseVisualStyleBackColor = true;
			this->buttonBrowseDecompress->Click += gcnew System::EventHandler(this, &MyForm::buttonBrowseDecompress_Click);
			// 
			// textFileDecompress
			// 
			this->textFileDecompress->Location = System::Drawing::Point(75, 19);
			this->textFileDecompress->Name = L"textFileDecompress";
			this->textFileDecompress->Size = System::Drawing::Size(295, 20);
			this->textFileDecompress->TabIndex = 1;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(11, 21);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(50, 13);
			this->label2->TabIndex = 0;
			this->label2->Text = L"File path:";
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			// 
			// folderBrowserDialog1
			// 
			this->folderBrowserDialog1->HelpRequest += gcnew System::EventHandler(this, &MyForm::folderBrowserDialog1_HelpRequest);
			// 
			// menuStrip1
			// 
			this->menuStrip1->BackColor = System::Drawing::SystemColors::MenuBar;
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->fileToolStripMenuItem,
					this->helpToolStripMenuItem1
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(819, 24);
			this->menuStrip1->TabIndex = 1;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// fileToolStripMenuItem
			// 
			this->fileToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->exitToolStripMenuItem });
			this->fileToolStripMenuItem->Name = L"fileToolStripMenuItem";
			this->fileToolStripMenuItem->Size = System::Drawing::Size(37, 20);
			this->fileToolStripMenuItem->Text = L"File";
			// 
			// exitToolStripMenuItem
			// 
			this->exitToolStripMenuItem->Name = L"exitToolStripMenuItem";
			this->exitToolStripMenuItem->Size = System::Drawing::Size(92, 22);
			this->exitToolStripMenuItem->Text = L"Exit";
			this->exitToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::exitToolStripMenuItem_Click);
			// 
			// helpToolStripMenuItem1
			// 
			this->helpToolStripMenuItem1->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->aboutToolStripMenuItem1 });
			this->helpToolStripMenuItem1->Name = L"helpToolStripMenuItem1";
			this->helpToolStripMenuItem1->Size = System::Drawing::Size(44, 20);
			this->helpToolStripMenuItem1->Text = L"Help";
			// 
			// aboutToolStripMenuItem1
			// 
			this->aboutToolStripMenuItem1->Name = L"aboutToolStripMenuItem1";
			this->aboutToolStripMenuItem1->Size = System::Drawing::Size(107, 22);
			this->aboutToolStripMenuItem1->Text = L"About";
			this->aboutToolStripMenuItem1->Click += gcnew System::EventHandler(this, &MyForm::aboutToolStripMenuItem1_Click);
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Location = System::Drawing::Point(151, 369);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(90, 13);
			this->label12->TabIndex = 16;
			this->label12->Text = L"Input File(s) Size: ";
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Location = System::Drawing::Point(151, 386);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(84, 13);
			this->label13->TabIndex = 17;
			this->label13->Text = L"Ouput File Size: ";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(819, 469);
			this->Controls->Add(this->tabControl1);
			this->Controls->Add(this->menuStrip1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"MyForm";
			this->Text = L"miniZIPXX";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->tabControl1->ResumeLayout(false);
			this->tabPage1->ResumeLayout(false);
			this->tabPage1->PerformLayout();
			this->panel3->ResumeLayout(false);
			this->panel3->PerformLayout();
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->tabPage2->ResumeLayout(false);
			this->tabPage2->PerformLayout();
			this->panel4->ResumeLayout(false);
			this->panel4->PerformLayout();
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	// OK
	private: System::Void buttonBrowseCompress_Click(System::Object^  sender, System::EventArgs^  e) {
		
		// USING LIST BOX

		// menampilkan OpenFileDialog untuk memilih file yang akan dicompress
		openFileDialog1->Filter = "Any File|*.*";			// jenis ekstensi file
		openFileDialog1->Title = "File to compress";		// judul kotak dialog
		openFileDialog1->Multiselect = true;				// bisa memilih banyak file

		//Kalau sudah milih file (sudah klik OK) maka path filenya muncul di list box
		if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		{
			// membandingkan setiap file input dengan semua file di listbox -> jika listbox tidak kosong
			int index;

			if (listBoxFile->Items->Count != 0) {
				//MessageBox::Show("count: " + listBoxFile->Items->Count);
				for each (String^ temp_file in openFileDialog1->FileNames) {
					index = listBoxFile->FindString(temp_file);
					if (index == -1) {
						// tidak ada file di listbox yang sama dengan file yg akan diadd
						listBoxFile->Items->Add(temp_file);
					}
					else {
						// ada file di listbox yang sama dengan file yg akan diadd
						// do nothing
					}
				}
			}
			else {
				for each (String^ temp_file in openFileDialog1->FileNames) {
					listBoxFile->Items->Add(temp_file);
				}
			}
			
			System::String^ path_in = openFileDialog1->FileNames[0];
			path_in = path_in->Replace(Path::GetExtension(path_in), ".zipxx");
			this->textFileCompressOut->Text = path_in;

			// enable compress button
			this->buttonCompress->Enabled = true;
		}
	
	}
	
	private: System::Void buttonBrowseDecompress_Click(System::Object^  sender, System::EventArgs^  e) {
		// menampilkan OpenFileDialog untuk memilih file yang akan di decompress
		openFileDialog1->Filter = "Zipxx File|*.zipxx";		// jenis file yang akan didecompress 
		openFileDialog1->Title = "File to decompress";					// judul kotak dialog

		// jika user sudah memilih satu file dan mengklik OK, maka keluar dari
		// kotak dialog dan menampilkan absolute path nya ke textbox
		if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		{
			this->textFileDecompress->Text = openFileDialog1->FileName;
		}

		// cek path kosong atau tidak
		if (this->textFileDecompress->Text == "") {
			this->buttonDecompress->Enabled = false;
		}
		else {
			if (this->textFileDecompressOut->Text == "") {
				this->buttonDecompress->Enabled = false;
			}
			else {
				this->buttonDecompress->Enabled = true;
			}
		}
	}

private: System::Void progressBarDecompress_Click(System::Object^  sender, System::EventArgs^  e) {
}

private: System::Void panel3_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
}

	// OK
	private: void changeCursor(bool isWaiting) {
		Cursor->Current = isWaiting ? Cursors::WaitCursor : Cursors::Default;
		Application::DoEvents();
	}

	// OK
	private: System::Void buttonCompress_Click_1(System::Object^  sender, System::EventArgs^  e) {
		int j;
		// Ambil path dari textbox
		// System::String^ path_in = this->openFileDialog1->FileNames[0];
		
		if (listBoxFile->Items->Count != 0 && this->textFileCompressOut->Text != "") {
			// path_out menyimpan path tujuan untuk file ZIPXX
			System::String^ path_out = this->textFileCompressOut->Text;

			array<String^>^ paths_in = gcnew array<String^>(listBoxFile->Items->Count);

			for (int n = 0; n < listBoxFile->Items->Count; n++) {
				//MessageBox::Show("ix" + n);
				listBoxFile->SetSelected(n, true);
				paths_in->SetValue(listBoxFile->SelectedItem->ToString(), n);
				listBoxFile->SetSelected(n, false);
			}

			// ganti "\" milik path semua file input dengan "\\" karena harus begitu di fstream
			for (j = 0; j < listBoxFile->Items->Count; j++) {
				paths_in[j] = paths_in[j]->Replace("\\", "\\\\");
			}

			// ganti "\" milik path tujuan ZIPXX dengan "\\" karena harus begitu di fstream
			path_out = path_out->Replace("\\", "\\\\");

			// inisialisasi nilai properties pada progress bar
			progressBarCompress->Maximum = 100;
			progressBarCompress->Step = 1;
			progressBarCompress->Value = 0;		// nilai awal PB = 0 (kosong)

			// menghapus semua item yang ada pada listview
			listView1->Items->Clear();
			listView2->Items->Clear();
			this->label6->Text = "";
			this->label10->Text = "";
			this->label12->Text = "Input File(s) Size: ";
			this->label13->Text = "Ouput File Size: ";
			this->buttonCompress->Enabled = false;

			// memulai THREAD untuk proses kompresi 
			CallHuffman^ compress = gcnew CallHuffman(paths_in, path_out, listBoxFile->Items->Count, listView1, listView2, label6, label10, progressBarCompress, label12, label13, buttonCompress);
			System::Threading::ThreadStart^ startingPoint = gcnew System::Threading::ThreadStart(compress, &CallHuffman::startCompression);
			System::Threading::Thread^ compressionThread = gcnew System::Threading::Thread(startingPoint);
			compressionThread->Start();

			progressBarCompress->Value = 0;
		}
		else {
			MessageBox::Show("Path file belum ditentukan");
		}
	}

private: System::Void buttonDecompress_Click(System::Object^  sender, System::EventArgs^  e) {
	
	if (this->textFileDecompress->Text != "" && this->textFileDecompressOut->Text != "") {

		//Ambil path dari textbox
		System::String^ path_in = openFileDialog1->FileName;
		System::String^ path_out = this->textFileDecompressOut->Text; //FileName (dengan ekstensi)

		// inisialisasi nilai properties pada progress bar
		progressBarDecompress->Maximum = 100;
		progressBarDecompress->Step = 1;
		progressBarDecompress->Value = 0;		// nilai awal PB = 0 (kosong)

		listView3->Items->Clear();
		this->label11->Text = "";
		this->buttonDecompress->Enabled = false;

		//ambil path
		CallHuffman^ decompress = gcnew CallHuffman(path_in, path_out, listView3, label11, progressBarDecompress, buttonDecompress);
		System::Threading::ThreadStart^ startingPoint = gcnew System::Threading::ThreadStart(decompress, &CallHuffman::startDecompression);
		System::Threading::Thread^ decompressionThread = gcnew System::Threading::Thread(startingPoint);
		decompressionThread->Start();

		progressBarDecompress->Value = 0;
	}
	else {
		MessageBox::Show("Path file belum ditentukan");
	}
}
/*public: HuffmanCompression() {


public: HuffmanDecompression() {

}*/

// OK
private: System::Void buttonBrowCompress_Click(System::Object^  sender, System::EventArgs^  e) {
	folderBrowserDialog1->Description = "Pilih direktori yang dituju";
	if (folderBrowserDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
		System::String^ path_out = folderBrowserDialog1->SelectedPath;
		System::String^ temp_path = Path::GetFileNameWithoutExtension(this->listBoxFile->Text);
		System::String^ path_outaddr = path_outaddr->Concat("\\", temp_path->Concat(temp_path, ".zipxx"));
		path_out = path_out->Concat(path_out, path_outaddr);
		this->textFileCompressOut->Text = path_out;
	}
}

private: System::Void buttonBrowDecompress_Click(System::Object^  sender, System::EventArgs^  e) {
	folderBrowserDialog1->Description = "Pilih direktori yang dituju";
	if (folderBrowserDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
		
		this->textFileDecompressOut->Text = folderBrowserDialog1->SelectedPath;
	}

	// cek path kosong atau tidak
	if (this->textFileDecompress->Text == "") {
		this->buttonDecompress->Enabled = false;
	}
	else {
		if (this->textFileDecompressOut->Text == "") {
			this->buttonDecompress->Enabled = false;
		}
		else {
			this->buttonDecompress->Enabled = true;
		}
	}
}
private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {
	
}
private: System::Void folderBrowserDialog1_HelpRequest(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void tabPage1_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
	// REMOVE SELECTED ITEM
	listBoxFile->Items->Remove(listBoxFile->SelectedItem);
	if (listBoxFile->Items->Count == 0) {
		this->buttonCompress->Enabled = false;
	}
	else {
		this->buttonCompress->Enabled = true;
	}
}

private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
	// REMOVE ALL
	listBoxFile->Items->Clear();
	this->buttonCompress->Enabled = false;
}

private: System::Void textFileCompressOut_TextChanged(System::Object^  sender, System::EventArgs^  e) {

}
private: System::Void label6_Click(System::Object^  sender, System::EventArgs^  e) {
	
}
private: System::Void exitToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	Application::Exit();
}

private: System::Void aboutToolStripMenuItem1_Click(System::Object^  sender, System::EventArgs^  e) {
	MessageBox::Show("Copyright © 2016 HAV" + "\n" + "HAWK, AK, VMJ" + "\n" + "Icon Source: http://iconfinder.com");
}
};
}
