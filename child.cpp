#include "child.h"

void createListChild(listChild &L){
    first(L) = null;
    last(L) = null;
}

adrC createChild(dataPelanggan x){
    adrC C = new elmC;
    info(C) = x;
    next(C) = null;
    prev(C) = null;
}

void insertFirstChild(listChild &L, adrC C){
    if (first(L) == null){
        first(L) = C;
        last(L) = C;
    } else {
        prev(first(L)) = C;
        next(C) = first(L);
        first(L) = C;
    }
}

void insertLastChild(listChild &L, adrC C){
    if (first(L) == null){
        insertFirstChild(L, C);
    } else {
        prev(C) = last(L);
        next(last(L)) = C;
        last(L) = C;
    }
}

void deleteFirstChild(listChild &L){
    if (first(L) == null){
        cout << "Data Kosong" << endl;
    } else if (first(L) == last(L)){
        first(L) = null;
        last(L) = null;
    } else {
        first(L) = next(first(L));
        next(prev(first(L))) = null;
        prev(first(L)) = null;
    }
}

void deleteLastChild(listChild &L){
    if (first(L) == null){
        cout << "Data Kosong" << endl;
    } else if (first(L) == last(L)){
        deleteFirstChild(L);
    } else {
        last(L) = prev(last(L));
        prev(next(last(L))) = null;
        next(last(L)) = null;
    }
}

void deleteSelectedChild(listChild &L, adrC C){
    if (first(L) == C){
        deleteFirstChild(L);
    } else if (last(L) == C) {
        deleteLastChild(L);
    } else {
        adrC x = first(L);
        while (x != null && x != C){
            x = next(x);
        }
        if (x == C){
            prev(C) = next(C);
            prev(next(C)) = next(C);
            next(prev(C)) = prev(C);
            prev(C) = null;
            next(C) = null;
        }
    }
}

void showCustomer(listChild L){
    adrC C = first(L);
    if (C != null){
        while (C != null){
        cout << "ID Pelanggan: " << info(C).idPelanggan << endl;
        cout << "Nama Pelanggan: " << info(C).namaPelanggan << endl;
        cout << "Nomo Telepon Pelanggan: " << info(C).noTelpPelanggan << endl;
        cout << "==========================================================" << endl;
        C = next(C);
        }
    } else {
        cout << "Data Kosong" << endl;
    }
}

adrC findChild(listChild L, int idPelanggan){
    adrC C = first(L), foundAdr = null;
    bool found = false;
    while (C != null && !found){
        if (info(C).idPelanggan == idPelanggan) {
            found = true;
            foundAdr = C;
        }
        C = next(C);
    }
    return foundAdr;
}
