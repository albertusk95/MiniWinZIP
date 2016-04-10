#include "FileCompressor.h"
#include "BinTree.h"
#include "MyForm.h"
#include <msclr/marshal.h>
#include <msclr/marshal_cppstd.h>
#include <time.h>

using namespace msclr::interop;
using namespace System;
using namespace System::Windows::Forms;

using System::Runtime::InteropServices::Marshal;

FileCompressor::FileCompressor() {
	progress = 0;
	for (int i = 0; i < 256; i++) {
		TabFileComp[i] = 0;
	}
}

FileCompressor::~FileCompressor() { }

void FileCompressor::compress(array<String^>^ sourcefiles, System::String^ outpath,
	int nfile, float *nisbah, float *entropi, float* rata_bit, System::Windows::Forms::ListView^ LV, System::Windows::Forms::ListView^ LV2, System::Windows::Forms::Label^ labelnisbah, System::Windows::Forms::Label^ lt, System::Windows::Forms::ProgressBar^ PB, System::Windows::Forms::Label^ _filein_size, System::Windows::Forms::Label^ _fileout_size, System::Windows::Forms::Button^  _buttonCom)
{
	long int cmax;
	*nisbah = 0;
	float temp2 = 0;
	long int origin_size = 0;
	float temp;
	long int final_size = 0;
	int i = 0, j, idx_lv = 0, idx_lv2 = 0;
	char c;
	unsigned char ch;

	// deklarasi time awal
	time_t start, end;

	//File kompres tujuan (ZIPXX)
	std::string fileout = marshal_as<std::string>(outpath);
	ofstream outfile(fileout, ios::binary | ios::out);

	// inisialisasi nilai awal progress bar = 0
	PB->Value = 0;

	// mulai waktu
	time(&start);

	//A - output jumlah file input
	outfile << 'A';
	outfile << (char)nfile;
	for (j = 0; j < nfile; j++) {
		// ubah path file input sekarang dari system::string ke std::string
		System::String^ current = sourcefiles[j];
		std::string source = marshal_as<std::string>(current);

		// nama logic untuk membaca file input
		ifstream infile(source, ios::binary | ios::in);

		// inisialisasi jumlah frekuensi karakter untuk file ke-j
		for (i = 0; i < 256; i++) {
			TabFileComp[i] = 0;
		}

		// PREPARATION PROCESS -> PROCESS NAME: HITUNG FREKUENSI KARAKTER FILE KE -j -> proses
		LV->BeginUpdate();
		LV->Items->Add(System::Convert::ToString(j));
		LV->Items[idx_lv]->SubItems->Add("Baca file ke-" + System::Convert::ToString(j));
		LV->Items[idx_lv]->SubItems->Add("proses");
		LV->EndUpdate();

		// hitung frekuensi karakter pada file input ke-j
		while (infile.get(c)) {
			ch = c;
			TabFileComp[ch] ++;
		}
		infile.close();

		// PREPARATION PROCESS -> PROCESS NAME: HITUNG FREKUENSI KARAKTER FILE KE -j -> OK
		LV->BeginUpdate();
		LV->Items->RemoveAt(idx_lv);
		LV->Items->Add(System::Convert::ToString(j));
		LV->Items[idx_lv]->SubItems->Add("Baca file ke-" + System::Convert::ToString(j));
		LV->Items[idx_lv]->SubItems->Add("OK");
		LV->EndUpdate();

		// UPDATE PROGRESS BAR ---
		if (PB->Value < ((j + 1)*(100 / nfile) * 1 / 4)) {
			PB->Value = (j + 1)*(100 / nfile) * 1 / 4;
			PB->Refresh();
		}

		////////////////
		idx_lv++;
		////////////////

		// PREPARATION PROCESS -> PROCESS NAME: BUILD HUFFMAN TREE UNTUK FILE KE-j -> proses
		LV->BeginUpdate();
		LV->Items->Add(System::Convert::ToString(j));
		LV->Items[idx_lv]->SubItems->Add("Build huffman tree file ke-" + System::Convert::ToString(j));
		LV->Items[idx_lv]->SubItems->Add("proses");
		LV->EndUpdate();

		// membangun pohon Huffman untuk karakter pada file input ke-j
		Node* P = new Node;
		P = BuildHuffmanTree(TabFileComp);

		// PREPARATION PROCESS -> PROCESS NAME: BUILD HUFFMAN TREE UNTUK FILE KE-j -> OK
		LV->BeginUpdate();
		LV->Items->RemoveAt(idx_lv);
		LV->Items->Add(System::Convert::ToString(j));
		LV->Items[idx_lv]->SubItems->Add("Build huffman tree file ke-" + System::Convert::ToString(j));
		LV->Items[idx_lv]->SubItems->Add("OK");
		LV->EndUpdate();

		// UPDATE PROGRESS BAR ---
		if (PB->Value < ((j + 1)*(100 / nfile) * 2 / 4)) {
			PB->Value = (j + 1)*(100 / nfile) * 2 / 4;
			PB->Refresh();
		}

		////////////////////
		idx_lv++;
		////////////////////

		// inisialisasi kode huffman setiap jenis karakter dengan KarUndef 
		string *Tab = new string[256];
		for (i = 0; i < 256; i++) {
			Tab[i] = KarUndef;
		}

		// PREPARATION PROCESS -> PROCESS NAME: GENERATE HUFFMAN CODE UNTUK FILE KE-j -> proses
		LV->BeginUpdate();
		LV->Items->Add(System::Convert::ToString(j));
		LV->Items[idx_lv]->SubItems->Add("Get huffman code file ke-" + System::Convert::ToString(j));
		LV->Items[idx_lv]->SubItems->Add("proses");
		LV->EndUpdate();

		// mendapatkan kode huffman yang dilihat dari pohon huffman P dan menyimpannya di dalam Tab
		MapCode(P, "", Tab);

		// PREPARATION PROCESS -> PROCESS NAME: GENERATE HUFFMAN CODE UNTUK FILE KE-j -> OK
		LV->BeginUpdate();
		LV->Items->RemoveAt(idx_lv);
		LV->Items->Add(System::Convert::ToString(j));
		LV->Items[idx_lv]->SubItems->Add("Get huffman code file ke-" + System::Convert::ToString(j));
		LV->Items[idx_lv]->SubItems->Add("OK");
		LV->EndUpdate();

		// UPDATE PROGRESS BAR ---
		if (PB->Value < ((j + 1)*(100 / nfile) * 3 / 4)) {
			PB->Value = (j + 1)*(100 / nfile) * 3 / 4;
			PB->Refresh();
		}

		///////////////////////
		idx_lv++;
		///////////////////////

		// PREPARATION PROCESS -> PROCESS NAME: INPUT COMPRESSION CODE UNTUK FILE KE-j -> proses
		LV->BeginUpdate();
		LV->Items->Add(System::Convert::ToString(j));
		LV->Items[idx_lv]->SubItems->Add("Kompresi file ke-" + System::Convert::ToString(j));
		LV->Items[idx_lv]->SubItems->Add("proses");
		LV->EndUpdate();

		// memasukkan kode huffman ke dalam buffer
		char buffer = 0x0;
		string code;
		unsigned char tc;

		//B - output nama file input ke-j
		outfile << 'B';
		outfile << ':';
		int k = source.length() - 1;

		// ambil indeks karakter pertama nama file
		while (source[k] != '\\') {
			k--;
		}

		// memasukkan nama file ke file ZIPXX
		k++;
		while (k < source.length()) {
			outfile << source[k]; k++;
			temp2 += 1;
		}
		outfile << ':';

		//C - mencetak tabel frekuensi setiap karakter ke file ZIPXX
		outfile << 'C';
		string cn;
		for (i = 0; i < 256; i++) {
			outfile << TabFileComp[i] << "|";
			cn = to_string(TabFileComp[i]);
			temp2 += (cn.length());
		}

		//D - mencetak kode huffman ke file kompress
		// Membaca file untuk yang kedua kalinya agar bisa mencetak kode huffman
		outfile << 'D';
		i = 0;
		ifstream infile2(source, ios::binary | ios::in);
		while (infile2.get(c)) {
			tc = c;
			code = Tab[tc];
			push(&code, outfile, &buffer, &i);
		}
		if (i != 0) {
			buffer <<= 8 - i;
			outfile << buffer;
		}

		// PREPARATION PROCESS -> PROCESS NAME: INPUT HUFFMAN CODE UNTUK FILE KE-j -> OK
		LV->BeginUpdate();
		LV->Items->RemoveAt(idx_lv);
		LV->Items->Add(System::Convert::ToString(j));
		LV->Items[idx_lv]->SubItems->Add("Kompresi file ke-" + System::Convert::ToString(j));
		LV->Items[idx_lv]->SubItems->Add("OK");
		LV->EndUpdate();

		// UPDATE PROGRESS BAR ---
		if (PB->Value < ((j + 1)*(100 / nfile)) * 4 / 4) {
			PB->Value = (j + 1)*(100 / nfile) * 4 / 4;
			PB->Refresh();
		}

		/////////////////////
		idx_lv++;
		/////////////////////

		cmax = Akar(P).frek;
		//Menghitung entropi
		temp = 0;
		entropi[j] = 0;
		for (i = 0; i < 256; i++) {

			if (TabFileComp[i] > 0) {
				temp = TabFileComp[i] / (float)cmax;
				entropi[j] -= temp * log(temp);
			}
		}

		//Menghitung rata-rata bit per symbol
		rata_bit[j] = 0;
		temp = 0;
		for (i = 0; i < 256; i++) {
			if (TabFileComp[i] > 0) {
				temp += TabFileComp[i] * Tab[i].length();
			}
		}
		rata_bit[j] = temp / (float)cmax;

		LV2->BeginUpdate();
		LV2->Items->Add(System::Convert::ToString(j));
		LV2->Items[idx_lv2]->SubItems->Add(System::Convert::ToString(entropi[j]));
		LV2->Items[idx_lv2]->SubItems->Add(System::Convert::ToString(rata_bit[j]));
		LV2->EndUpdate();

		//////////////
		idx_lv2++;
		//////////////

		temp2 += 261;
		temp2 += temp / 8;
		temp2 = floor(temp2);
		origin_size += cmax;
		infile2.close();

	}
	temp2 = temp2 + 2;
	nisbah[0] = temp2 / origin_size;
	outfile.close();

	if (PB->Value < 100) {
		PB->Value = 100;
		PB->Refresh();
	}
	temp2 = (double)temp2 / 1024;
	origin_size = (double)origin_size / 1024;
	_filein_size->Text = _filein_size->Text + System::Convert::ToString(origin_size) + " KB";
	_fileout_size->Text = _fileout_size->Text + System::Convert::ToString(temp2) + " KB";
	labelnisbah->Enabled = true;
	labelnisbah->Text = "Nisbah: " + System::Convert::ToString(nisbah[0]);

	// akhir waktu
	time(&end);

	double durasi = difftime(end, start);

	lt->Text = "Time: " + System::Convert::ToString(durasi) + " s";
	MessageBox::Show("Kompresi " + nfile + " file selesai!");
	_buttonCom->Enabled = true;
}

//Menerima sebuah kode Huffman dan menuliskannya ke file output

void FileCompressor::decompress(System::String^ pathfilezipx, System::String^ pathfileout, System::Windows::Forms::ListView^ lv3, System::Windows::Forms::Label^ LTD, System::Windows::Forms::ProgressBar^ PBD, System::Windows::Forms::Button^  _buttonDec) {
	test_extract(pathfilezipx, pathfileout, lv3, LTD, PBD, _buttonDec);
	/*
	ofstream out("C:\\Users\\Verisky\\Desktop\\testdec.txt", ios::binary | ios::out);
	CString path(pathfileout);
	out << path;  -> MALAH KELUAR ADDRESS NYA NIH, BUKAN PATHNYA*/ 
}

int FileCompressor::getProgress() {
	return progress;
}