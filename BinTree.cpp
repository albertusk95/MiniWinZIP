#include "BinTree.h"
#include <msclr/marshal.h>
#include <msclr/marshal_cppstd.h>

using namespace msclr::interop;
using namespace System;
using namespace System::Windows::Forms;
using System::Runtime::InteropServices::Marshal;

using namespace std;

Node Tree(Node *L, Node *R)
/* Menghasilkan sebuah pohon biner dari A, L, dan R, jika alokasi berhasil */
/* Menghasilkan pohon kosong (Nil) jika alokasi gagal */
{
	Node P;
	P.Info.namaKar = Akar(L).namaKar + Akar(R).namaKar;
	P.Info.frek = Akar(L).frek + Akar(R).frek;
	P.Left = L;
	P.Right = R;
	return P;
}

/*** Predikat-Predikat Penting ***/
bool IsTreeEmpty(BinTree P)
/* Mengirimkan true jika P adalah pohon biner kosong */
{
	return (P == Nil);
}

/*** Traversal ***/
void PrintTree(BinTree P, int h)
/* I.S. P terdefinisi, h adalah jarak indentasi */
/* F.S. Semua simpul P sudah ditulis dengan indentasi, Nil diganti dengan '.' */
/* Contoh: h=2
a
b
d
.
.
.
c
.
.
*/
{
	//KAMUS
	int i;
	//ALGORITMA
	printf("%c\n", Akar(P));
	
	//Left
	for (i = 1; i <= h; i++) {
		printf(" ");
	}
	if (!IsTreeEmpty(Left(P))) {
		PrintTree(Left(P), h + h);
	}
	else {
		printf(".\n");
	}

	//Right
	for (i = 1; i <= h; i++) {
		printf(" ");
	}
	if (!IsTreeEmpty(Right(P))) {
		PrintTree(Right(P), h + h);
	}
	else {
		printf(".\n");
	}
}

/*** Searching ***/
bool SearchTree(BinTree P, Infotype X)
/* Mengirimkan true jika ada node dari P yang bernilai X */
{
	if (IsTreeEmpty(P)) {
		return false;
	}
	else if (Akar(P).namaKar == X.namaKar){
		return true;
	}
	else {
		return SearchTree(Left(P), X) || SearchTree(Right(P), X);
	}
}

/*** Fungsi-Fungsi Lain ***/
int NbElmt(BinTree P)
/* Mengirimkan banyaknya elemen (node) pohon biner P */
{
	if (IsTreeEmpty(P)) {
		return 0;
	}
	else {
		return 1 + NbElmt(Left(P)) + NbElmt(Right(P));
	}
}

int NbDaun(BinTree P)
/* Mengirimkan banyaknya daun (node) pohon biner P */
{
	if (IsTreeEmpty(P)) {
		return 0;
	}
	else if (Left(P) == Nil && Right(P) == Nil) {
		return 1;
	}
	else {
		return NbDaun(Left(P)) + NbDaun(Right(P));
	}
}

int GetMinFrekLeft(Node Tab[]) {
	ofstream ots("C:\\Users\\AlbertusK95\\Documents\\output2.txt");
	
	string namaChar;
	int nilaiFrek;

	namaChar = Tab[0].Info.namaKar;
	nilaiFrek = Tab[0].Info.frek;

	//ots << "minFrek: " <<namaChar << " " << nilaiFrek << "\n";

	int i = 0;
	while (Tab[i].Info.frek <= 0) {
		i++;
		if (Tab[i].Info.frek > 0) {
			namaChar = Tab[i].Info.namaKar;
			nilaiFrek = Tab[i].Info.frek;
		}
		//ot << "minFrek: " << namaChar << " " << nilaiFrek << "\n";
	}

	int tanda = i;
	while (i < 511) {
		if (nilaiFrek > Tab[i].Info.frek &&  Tab[i].Info.frek > 0) {
			nilaiFrek = Tab[i].Info.frek;
			namaChar = Tab[i].Info.namaKar;
			tanda = i;
		}
		i++;
	}
	//Tab[tanda].Info.namaKar = KarUndef;
	//Tab[tanda].Info.frek = ValUndef;
	
	ots.close();

	return tanda;
}

int GetMinFrekRight(Node Tab[]) {
	ofstream ots("C:\\Users\\AlbertusK95\\Documents\\output2.txt");

	string namaChar;
	int nilaiFrek;

	namaChar = Tab[0].Info.namaKar;
	nilaiFrek = Tab[0].Info.frek;

	//ots << "minFrek: " <<namaChar << " " << nilaiFrek << "\n";

	int i = 0;
	while (Tab[i].Info.frek <= 0) {
		i++;
		if (Tab[i].Info.frek > 0) {
			namaChar = Tab[i].Info.namaKar;
			nilaiFrek = Tab[i].Info.frek;
		}
		//ot << "minFrek: " << namaChar << " " << nilaiFrek << "\n";
	}

	int tanda = i;
	while (i < 511) {
		if (nilaiFrek > Tab[i].Info.frek &&  Tab[i].Info.frek > 0) {
			nilaiFrek = Tab[i].Info.frek;
			namaChar = Tab[i].Info.namaKar;
			tanda = i;
		}
		i++;
	}
	//Tab[tanda].Info.namaKar = KarUndef;
	//Tab[tanda].Info.frek = ValUndef;

	ots.close();

	return tanda;
}

//Membangun Huffman Tree
Node* BuildHuffmanTree(long int Tab[]) {

	Node* TabFrek = NULL;
	TabFrek = new Node[511];

	Node* PP = NULL;

	int i;
	int count = 0;

	// inisialisasi tabel kosong
	for (i = 0; i < 511; i++) {
		TabFrek[i].Info.namaKar = KarUndef;
		TabFrek[i].Info.frek = ValUndef;
		TabFrek[i].Left = Nil;
		TabFrek[i].Right = Nil;
		TabFrek[i].Parents = Nil;
		//TabFrek[i].isChecked = 0;
		//TabFrek[i].myAddr = Nil;
	}

	// inisialisasi isi tabel dengan isi dari Tab[]
	for (i = 0; i < 256; i++) {
		if (Tab[i] > 0) {
			// membuat node daun sebagai pohon dengan L = R = Nil
			TabFrek[count].Info.namaKar = (char)i;
			TabFrek[count].Info.frek = Tab[i];
			TabFrek[count].Left = Nil;
			TabFrek[count].Right = Nil;
			TabFrek[count].Parents = Nil;
			//TabFrek[count].isChecked = 0;
			//TabFrek[i].myAddr = Nil;
			count++;
		}
	}

	if (count > 1) {
		i = count;
		int j, index, index2;
		Node* tempTab;
		Node* tempTab2;
		Node* PL;
		Node* PR;
		while (i < ((2 * count) - 1)) { //Membuat node sampai 2n-1
			// mengambil node dengan frekuensi terkecil pertama
			//Node* tempTab = NULL;
			tempTab = new Node[511];

			for (j = 0; j < 511; j++) {
				tempTab[j].Info.namaKar = TabFrek[j].Info.namaKar;
				tempTab[j].Info.frek = TabFrek[j].Info.frek;
				tempTab[j].Left = TabFrek[j].Left;
				tempTab[j].Right = TabFrek[j].Right;
				tempTab[j].Parents = TabFrek[j].Parents;
				//tempTab[j].isChecked = TabFrek[j].isChecked;
				//tempTab[j].myAddr = TabFrek[i].myAddr;
			}

			index = GetMinFrekLeft(tempTab);
			if (TabFrek[index].Left == Nil && TabFrek[index].Right == Nil) {
				PL = new Node;
				Akar(PL).namaKar = TabFrek[index].Info.namaKar;
				Akar(PL).frek = TabFrek[index].Info.frek;
				Left(PL) = Nil;
				Right(PL) = Nil;
			}
			else {
				PL = Parents(TabFrek[index].Left);
			}

			TabFrek[index].Info.namaKar = KarUndef;
			TabFrek[index].Info.frek = ValUndef;

			delete[] tempTab;

			// mengambil node dengan frekuensi terkecil kedua
			//Node* tempTab2 = NULL;
			tempTab2 = new Node[511];

			for (j = 0; j < 511; j++) {
				tempTab2[j].Info.namaKar = TabFrek[j].Info.namaKar;
				tempTab2[j].Info.frek = TabFrek[j].Info.frek;
				tempTab2[j].Left = TabFrek[j].Left;
				tempTab2[j].Right = TabFrek[j].Right;
				tempTab2[j].Parents = TabFrek[j].Parents;
				//tempTab2[j].isChecked = TabFrek[j].isChecked;
				//tempTab2[j].myAddr = TabFrek[j].myAddr;
			}
			tempTab2[index].Info.namaKar = KarUndef;
			tempTab2[index].Info.frek = ValUndef;

			index2 = GetMinFrekRight(tempTab2);

			if (TabFrek[index2].Left == Nil && TabFrek[index2].Right == Nil) {
				PR = new Node;
				Akar(PR).namaKar = TabFrek[index2].Info.namaKar;
				Akar(PR).frek = TabFrek[index2].Info.frek;
				Left(PR) = Nil;
				Right(PR) = Nil;
			}
			else {
				PR = Parents(TabFrek[index2].Left);
			}

			TabFrek[index2].Info.namaKar = KarUndef;
			TabFrek[index2].Info.frek = ValUndef;

			delete[] tempTab2;


			PP = new Node;
			//TabFrek[i] = Tree(PL, PR);
			Akar(PP).namaKar = Akar(PL).namaKar + Akar(PR).namaKar;
			Akar(PP).frek = Akar(PL).frek + Akar(PR).frek;
			Left(PP) = PL;
			Right(PP) = PR;
			Parents(PL) = PP;
			Parents(PR) = PP;
			TabFrek[i].Info.namaKar = Akar(PP).namaKar;
			TabFrek[i].Info.frek = Akar(PP).frek;
			TabFrek[i].Left = PL;
			TabFrek[i].Right = PR;
			TabFrek[index].Parents = PP;
			TabFrek[index2].Parents = PP;

			//delete PL;
			//delete PR;
			//delete PP;
			i++;
		}
	
	}
	else if (count == 1) {
		PP = new Node;
		Node* PL = new Node;
		Akar(PL).frek = TabFrek[0].Info.frek;
		Akar(PL).namaKar = "a";
		Left(PL) = Nil;
		Right(PL) = Nil;

		Akar(PP).namaKar = Akar(PL).namaKar;
		Akar(PP).frek = Akar(PL).frek;
		Left(PP) = PL;
		Right(PP) = Nil;
		Parents(PP) = Nil;
		Parents(PL) = PP;

	}
	else {
		PP = new Node;
		Akar(PP).namaKar = "";
		Akar(PP).frek = 0;
		Left(PP) = Nil;
		Right(PP) = Nil;
		Parents(PP) = Nil;
	}
	return PP;
}

// Mapcode menerima input sebuah pohon Huffman P, 
//menghasilkan tabel Tab yang berisi kode Huffman untuk setiap karakter.
void MapCode(Node *P, string str, string *Tab) {
	unsigned char inp;

	if (Left(P) == Nil && Right(P) == Nil) {
		inp = Akar(P).namaKar[0];
		Tab[inp] = str;
	}
	else {
		MapCode(Left(P), str + "0", Tab);
		if (Right(P) != Nil){
			MapCode(Right(P), str + "1", Tab);
		}
	}
}


void push(string *in, ofstream &out,char *buffer, int *i) {
	//buffer penuh
	if (*i >= 8) {
		out << *buffer;
		*buffer = 0x0; //reset buffer
		*i = 0;
		push(in, out, buffer, i);
	}
	else if (in->length() > 0) {
		(*buffer) <<= 1; 
		*i = *i +1;
		if ((*in)[0] == '1') {
			*buffer = *buffer | 0x1;
		}
		in->erase(0, 1);
		//kalau masih ada digit, ulangi
		if (in->length() > 0) {
			push(in, out, buffer, i);
		}
	}
}

void test_extract(System::String^ filezipx, System::String^ _namafileasli, System::Windows::Forms::ListView^ LV3, System::Windows::Forms::Label^ LTD, System::Windows::Forms::ProgressBar^ PBD, System::Windows::Forms::Button^  _buttonDec) {
	CString filezipx_(filezipx->Replace("\\", "\\\\"));
	ifstream in(filezipx_, ios::binary | ios::in);
	int idx_lv = 0;
	time_t start, finish;

	string nama_file = "";

	long int *Tab = new long int[256];
	char c;
	int i, l;

	time(&start);

	for (i = 0; i < 256; i++) {
		Tab[i] = 0;
	}
	int x;
	in.get(c);
	//out << c << endl;
	in.get(c); //jumlah filenya
	int y = c;
	for (x = 0; x < y; x++) {// loop sebanyak jumlah filenya
		System::String^ namafileasli = _namafileasli;
		l = 0;
		nama_file = "";

		LV3->BeginUpdate();
		LV3->Items->Add(System::Convert::ToString(x));
		LV3->Items[idx_lv]->SubItems->Add("Baca file ke-" + System::Convert::ToString(x));
		LV3->Items[idx_lv]->SubItems->Add("proses");
		LV3->EndUpdate();
		
		in.get(c); //B	
		if (c != ':'){
			in.get(c); // :
		}
		in.get(c);
		while (c != ':') {
			nama_file = nama_file + c;
			in.get(c);
		}
		//CString file_out = namafileasli->Replace("\\", "\\\\");
		System::String^ fileout_ = gcnew String(nama_file.c_str());
		namafileasli = namafileasli->Concat(namafileasli, "\\");
		namafileasli = namafileasli->Concat(namafileasli, fileout_);
		namafileasli = namafileasli->Replace("\\", "\\\\");
		CString _fileout(namafileasli);

		ofstream out(_fileout, ios::binary | ios::out);
		
		//C
		in.get(c);
		const char * int_buffer2;
		string int_buffer = "";
		while (l < 256) {
			in.get(c);
			if (c == '|') {
				int_buffer2 = int_buffer.c_str();
				Tab[l] = atoi(int_buffer2);
				int_buffer = "";
				l++;
			}
			else {
				int_buffer = int_buffer + c;
			}

		}

		LV3->BeginUpdate();
		LV3->Items->RemoveAt(idx_lv);
		LV3->Items->Add(System::Convert::ToString(x));
		LV3->Items[idx_lv]->SubItems->Add("Baca file ke-" + System::Convert::ToString(x));
		LV3->Items[idx_lv]->SubItems->Add("OK");
		LV3->EndUpdate();

		// UPDATE PROGRESS BAR ---
		if (PBD->Value < ((x + 1)*(100 / y) * 1 / 3)) {
			PBD->Value = (x + 1)*(100 / y) * 1 / 3;
			PBD->Refresh();
		}

		idx_lv++;

		//Buat pohon huffman

		LV3->BeginUpdate();
		LV3->Items->Add(System::Convert::ToString(x));
		LV3->Items[idx_lv]->SubItems->Add("Build huffman tree file ke-" + System::Convert::ToString(x));
		LV3->Items[idx_lv]->SubItems->Add("proses");
		LV3->EndUpdate();

		Node * P = new Node;
		P = BuildHuffmanTree(Tab);

		LV3->BeginUpdate();
		LV3->Items->RemoveAt(idx_lv);
		LV3->Items->Add(System::Convert::ToString(x));
		LV3->Items[idx_lv]->SubItems->Add("Build huffman tree file ke-" + System::Convert::ToString(x));
		LV3->Items[idx_lv]->SubItems->Add("OK");
		LV3->EndUpdate();

		if (PBD->Value < ((x + 1)*(100 / y) * 2 / 3)) {
			PBD->Value = (x + 1)*(100 / y) * 2 / 3;
			PBD->Refresh();
		}
		
		idx_lv++;

		int cmax = Akar(P).frek;

		LV3->BeginUpdate();
		LV3->Items->Add(System::Convert::ToString(x));
		LV3->Items[idx_lv]->SubItems->Add("Dekompresi file ke-" + System::Convert::ToString(x));
		LV3->Items[idx_lv]->SubItems->Add("proses");
		LV3->EndUpdate();

		//Baca buffer 8 bit
		char buffer = 0x0;
		int m = 8;
		Node * PP = new Node;
		PP = P;
		string c_read;
		string str_read = "";
		int count = 0;
		in.get(c);
		in.get(buffer);
		while (count < cmax) {
			pop(&PP, &str_read, &buffer, &m);
			if (str_read != "" && count < cmax){
				out << str_read;
				count++;
				str_read = "";
				PP = P;
			}
			if (m == 0) {
				in.get(buffer);
				m = 8;
			}
		}
		count = 0;
		out.close();

		LV3->BeginUpdate();
		LV3->Items->RemoveAt(idx_lv);
		LV3->Items->Add(System::Convert::ToString(x));
		LV3->Items[idx_lv]->SubItems->Add("Dekompresi file ke-" + System::Convert::ToString(x));
		LV3->Items[idx_lv]->SubItems->Add("OK");
		LV3->EndUpdate();

		if (PBD->Value < ((x + 1)*(100 / y) * 3 / 3)) {
			PBD->Value = (x + 1)*(100 / y) * 3 / 3;
			PBD->Refresh();
		}

		idx_lv++;
	}
	in.close();
	
	time(&finish);
	double durasi = difftime(finish, start);

	LTD->Text = "Time: " + System::Convert::ToString(durasi) + " s";

	MessageBox::Show("Dekompresi selesai!");
	_buttonDec->Enabled = true;
}

void pop(Node **P, string *out, char *buffer, int *i) {
	if (*i > 0) {
		*i = *i - 1;
		if ((*buffer & 0x80) == 0x80) {
			*P = Right(*P);
		}
		else {
			*P = Left(*P);
		}
		(*buffer) <<= 1;
		if (Right(*P) == NULL && Left(*P) == NULL){
			*out = Akar(*P).namaKar;
		}
		else if (*i > 0) {
			pop(P, out, buffer, i);
		}
	}
}