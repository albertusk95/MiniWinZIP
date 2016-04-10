/* NIM/Nama		:  */
/* Nama file	:  */
/* Topik		:  */
/* Tanggal		:  */
/* Deskripsi	:  */

#ifndef pohon_h
#define pohon_h

/* ADT Pohon Biner */
#include <string>
using namespace std;
#include <fstream>
#include <sstream>
#include <atlstr.h>
#include <time.h>

#include <sys/stat.h>
using namespace System;

/* Modul lain yang digunakan */
//#include "listrekursif.h"
//#include "mesinkar.h"

#define Nil NULL
#define ValUndef -1
#define KarUndef ";."
typedef struct {
	string namaKar;
	long int frek;
}Infotype;
/*** Definisi Type Pohon Biner ***/
typedef struct tNode *AddressTree;
typedef struct tNode {
	Infotype Info;
	AddressTree Left;
	AddressTree Right;
	AddressTree Parents;
	int isChecked;
	AddressTree myAddr;
} Node;
typedef AddressTree BinTree;

/*
BEBERAPA CATATAN
1. Pohon merupakan pohon biner dengan representasi karakter
2. pita karakter merupakan stdin (di-supply dari stdin)
*/

/*** PROTOTYPE ***/
/*** Selektor ***/
#define Akar(P) (P)->Info
/* Mengirimkan nilai Akar pohon biner P */

#define Left(P) (P)->Left
/* Mengirimkan Anak Kiri pohon biner P */

#define Right(P) (P)->Right
/* Mengirimkan Anak Kanan pohon biner P */

#define Parents(P) (P)->Parents

/*** Konstruktor ***/
Node Tree(Node* L, Node* R);
/* Menghasilkan sebuah pohon biner dari A, L, dan R, jika alokasi berhasil */
/* Menghasilkan pohon kosong (Nil) jika alokasi gagal */

/*** Predikat-Predikat Penting ***/
bool IsTreeEmpty(BinTree P);
/* Mengirimkan true jika P adalah pohon biner kosong */

/*** Traversal ***/
void PrintTree(BinTree P, int h);
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

/*** Searching ***/
bool SearchTree(BinTree P, Infotype X);
/* Mengirimkan true jika ada node dari P yang bernilai X */

/*** Fungsi-Fungsi Lain ***/
int NbElmt(BinTree P);
/* Mengirimkan banyaknya elemen (node) pohon biner P */

int NbDaun(BinTree P);
/* Mengirimkan banyaknya daun (node) pohon biner P */


/*** Operasi lain ***/
void AddDaunTerkiri(BinTree *P, Infotype X);
/* I.S. P boleh kosong */
/* F.S. P bertambah simpulnya, dengan X sebagai simpul daun terkiri */

void AddDaun(BinTree *P, Infotype X, Infotype Y, bool Kiri);
/* I.S. P tidak kosong, X adalah salah satu daun Pohon Biner P */
/* F.S. P bertambah simpulnya, dengan Y sebagai anak kiri X (jika Kiri = true), atau
sebagai anak k@anan X (jika Kiri = false) */

void DelDaunTerkiri(BinTree *P, Infotype *X);
/* I.S. P tidak kosong */
/* F.S. P dihapus daun terkirinya, dan didealokasi, dengan X adalah info yang semula
disimpan pada daun terkiri yang dihapus */

void DelDaun(BinTree *P, Infotype X);
/* I.S. P tidak kosong, X adalah salah satu daun */
/* F.S. Semua daun bernilai X dihapus dari P */

int GetMinFrek(Node Tab[]);

void test_extract(System::String^ filezipx, System::String^ _namafileasli, System::Windows::Forms::ListView^ LV3, System::Windows::Forms::Label^ LTD, System::Windows::Forms::ProgressBar^ PBD, System::Windows::Forms::Button^  _buttonDec);
Node* BuildHuffmanTree(long int Tab[]);
void push(string *in, ofstream &out, char *buffer, int *i);
void pop(Node **P, string *out, char *buffer, int *i);
void MapCode(Node *P, string str, string *Tab);


#endif
