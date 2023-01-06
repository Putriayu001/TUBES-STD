#ifndef CHILD_H_INCLUDED
#define CHILD_H_INCLUDED

#include <iostream>
using namespace std;

#define first(L) L.first
#define last(L) L.last
#define next(P) P->next
#define prev(P) P->prev
#define info(P) P->info
#define null NULL

struct dataPelanggan {
    int idPelanggan;
    string namaPelanggan;
    string noTelpPelanggan;
};
typedef dataPelanggan infoChild;
typedef struct elmC *adrC;
struct elmC {
    dataPelanggan info;
    adrC next;
    adrC prev;
};

struct listChild{
    adrC first;
    adrC last;
};

void createListChild(listChild &L);
adrC createChild(dataPelanggan x);
void insertFirstChild(listChild &L, adrC C);
void insertLastChild(listChild &L, adrC C);
void deleteFirstChild(listChild &L);
void deleteLastChild(listChild &L);
void deleteSelectedChild(listChild &L, adrC C);
void showCustomer(listChild L);
adrC findChild(listChild L, int idPelanggan);

#endif // CHILD_H_INCLUDED
