//MyForm.cpp : file UTAMA yang akan memulai keseluruhan program

#include "MyForm.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
int main(array<System::String ^> ^args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	// menjalankan program
	HuffmanCoding01::MyForm form;
	Application::Run(%form);
	return 0;
}