#ifndef PARENT_H_INCLUDED
#define PARENT_H_INCLUDED


#include <iostream>
using namespace std;
#include "relation.h"
#include "child.h"
#define first(L) L.first
#define next(P) P->next
#define info(P) P->info
#define null NULL


struct dataToko {
    int idToko;
    string namaToko;
    string noTelpToko;
    int jumlahKonsumen;
    listRelation relation;
};
typedef dataToko infoParent;
typedef struct elmP *adrP;
struct elmP {
    dataToko info;
    adrP next;
};

struct listParent{
    adrP first;
};

void createListParent(listParent &L);
adrP createParent(dataToko x);
void insertFirstParent(listParent &L, adrP P);
void insertLastParent(listParent &L, adrP P);
void deleteFirstParent(listParent &L);
void deleteLastParent(listParent &L);
void deleteSelectedParent(listParent &L, adrP P);
int countCustomer(adrP P);
void showParent(listParent L);
adrP findParent(listParent L, int idToko);
void showMostFavoriteParent(listParent L);
void getCustomerRelation(listParent &L, adrC C);
void menu();

#endif // PARENT_H_INCLUDED
