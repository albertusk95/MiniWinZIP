#pragma once
#include <atlstr.h>
#include <iostream>
#include <fstream>
#include <math.h>
using System::Runtime::InteropServices::Marshal;
using namespace System;
using namespace System::Text;
using namespace System::IO;
class FileCompressor
{
public:
	FileCompressor();
	virtual ~FileCompressor();
	void compress(array<String^>^ sourcefiles, System::String^ outpath, 
		int nfile, float *nisbah, float *entropi, float* rata_bit, System::Windows::Forms::ListView^ LV, System::Windows::Forms::ListView^ LV2, System::Windows::Forms::Label^ labelnisbah, System::Windows::Forms::Label^ lt, System::Windows::Forms::ProgressBar^ PB, System::Windows::Forms::Label^ _filein_size, System::Windows::Forms::Label^ _fileout_size, System::Windows::Forms::Button^  _buttonCom);
	void decompress(System::String^ pathfilezipx, System::String^ pathfileout, System::Windows::Forms::ListView^ lv3, System::Windows::Forms::Label^ LTD, System::Windows::Forms::ProgressBar^ PBD, System::Windows::Forms::Button^  _buttonDec);
	int getProgress();

private:
	int progress;
	int long TabFileComp[256];
};