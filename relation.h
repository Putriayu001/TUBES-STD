#ifndef RELATION_H_INCLUDED
#define RELATION_H_INCLUDED

#include "child.h"
#include <iostream>
using namespace std;

#define first(L) L.first
#define next(P) P->next
#define info(P) P->info
#define null NULL

typedef struct elmR *adrR;
struct elmR {
    adrC info;
    adrR next;
};

struct listRelation{
    adrR first;
};

void createListRelation(listRelation &L);
adrR createRelation(adrC C);
void insertFirstRelation(listRelation &L, adrC C);
void insertLastRelation(listRelation &L, adrC C);
void deleteFirstRelation(listRelation &L);
void deleteLastRelation(listRelation &L);
void deleteSelectedRelation(listRelation &L, adrC C);
void deleteAllRelation(listRelation &L);
void showAllRelation(listRelation &L);


#endif // RELATION_H_INCLUDED
