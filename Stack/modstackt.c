/* NIM/Nama : 13517059/Nixon Andhika
Nama file : stackt.c
Topik : ADT Stack
Tanggal : 3 Oktober 2018
Deskripsi : File ini berisi implementasi dari stackt.h*/

#include "modstackt.h"

/* ************ Prototype ************ */
/* *** Konstruktor/Kreator *** */
void CreateEmptyStack (Stack *S)
/* I.S. sembarang; */
/* F.S. Membuat sebuah stack S yang kosong berkapasitas MaxEl */
/* jadi indeksnya antara 1.. MaxEl+1 karena 0 tidak dipakai */
/* Ciri stack kosong : TOP bernilai Nil */
{

  (*S).TOP = Nil;
}

/* ************ Predikat Untuk test keadaan KOLEKSI ************ */
boolean IsEmptyStack (Stack S)
/* Mengirim true jika Stack kosong: lihat definisi di atas */
{
  return (S.TOP) == Nil;
}

boolean IsFullStack (Stack S)
/* Mengirim true jika tabel penampung nilai elemen stack penuh */
{
  return (S.TOP) == MaxEl;
}

/* ************ Menambahkan sebuah elemen ke Stack ************ */
void Push (Stack * S, infotype X)
/* Menambahkan X sebagai elemen Stack S. */
/* I.S. S mungkin kosong, tabel penampung elemen stack TIDAK penuh */
/* F.S. X menjadi TOP yang baru,TOP bertambah 1 */
{
  (*S).TOP++;
  (*S).T[(*S).TOP] = X;
}

/* ************ Menghapus sebuah elemen Stack ************ */
void Pop (Stack * S, infotype* X)
/* Menghapus X dari Stack S. */
/* I.S. S  tidak mungkin kosong */
/* F.S. X adalah nilai elemen TOP yang lama, TOP berkurang 1 */
{
  *X = (*S).T[(*S).TOP];
  (*S).TOP--;
}

void CopyStack(Stack Sin, Stack * Sout)
/* Copy isi dari Stack Sin ke Stack Sout. */
{
  infotype X;
  Stack Stemp;
  CreateEmptyStack(Sout);
  while(!IsEmptyStack(Sin)){
    Pop(&Sin, &X);
    Push(&Stemp, X);
  }
  while(!IsEmptyStack(Stemp)){
    Pop(&Stemp, &X);
    Push(&Sin, X);
    Push(Sout, X);
  }
}

void InverseStack(Stack * S)
/* Membalikkan isi dari Stack S. */
{
  infotype X;
  Stack Stemp;
  CopyStack(*S, &Stemp);
  while(!IsEmptyStack){
    Pop(&Stemp, &X);
    Push(S, X);
  }
}