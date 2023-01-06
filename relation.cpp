#include "relation.h"
#include "child.h"
void createListRelation(listRelation &L){
    first(L) = null;
}

adrR createRelation(adrC C){
    adrR R = new elmR;
    info(R) = C;
    next(R) = null;
}

void insertFirstRelation(listRelation &L, adrC C){
    adrR R = createRelation(C);
    if (first(L) == null){
        first(L) = R;
        next(first(L)) = R;
    } else if (next(first(L) == first(L))){
        next(R) = first(L);
        next(first(L)) = R;
        first(L) = R;
    } else {
        adrR lastR = first(L);
        while (next(lastR) != (first(L))){
            lastR = next(lastR);
        }
        next(R) = first(L);
        next(lastR) = R;
        first(L) = R;
    }
}

void insertLastRelation(listRelation &L, adrC C){
    adrR R = createRelation(C);
    if (first(L) == null){
        insertFirstRelation(L, C);
    } else {
        adrR lastR = first(L);
        while (next(lastR) != first(L)){
            cout << "LOOP" << endl;
            lastR = next(lastR);
        }
        next(lastR) = R;
        next(R) = first(L);
    }
}

void deleteFirstRelation(listRelation &L){
    if (first(L) == null){
        cout << "Data Kosong" << endl;
    } else if (first(L) == next(first(L))){
        next(first(L)) = null;
        first(L) = null;
    } else {
        adrR lastR = first(L);
        while (next(lastR) != first(L)){
            lastR = next(lastR);
        }
        next(lastR) = next(first(L));
        next(first(L)) = null;
        first(L) = next(lastR);
    }
}

void deleteLastRelation(listRelation &L){
    if (first(L) == null || (first(L) == next(first(L)))){
        deleteFirstRelation(L);
    } else {
        adrR lastR = first(L);
        while (next(next(lastR)) != first(L)){
            lastR = next(lastR);
        }
        next(next(lastR)) = null;
        next(lastR) = first(L);
    }
}

void deleteSelectedRelation(listRelation &L, adrC C){
    if (first(L) == null || info(first(L)) == C){
        deleteFirstRelation(L);
    } else {
        adrR current = first(L), prev;
        while (info(current) != C){
            prev = current;
            current = next(current);
            if (current == first(L)){
                break;
            }

        }
        if (info(current) == C){
            next(prev) = next(current);
            next(current) = null;
        } else {
            cout << "Data pelanggan tidak terdapat pada transaksi di toko ini" << endl;
        }
    }
}

void deleteAllRelation(listRelation &L){
    while (first(L) != null){
        deleteFirstRelation(L);
    }
}

void showAllRelation(listRelation &L){
    adrR R = first(L);
    if (first(L) == null){
        cout << "Data Kosong" << endl;
    } else {
        cout << "ID Pelanggan: " << info(info(R)).idPelanggan << endl;
        cout << "Nama Pelanggan: " << info(info(R)).namaPelanggan << endl;
        cout << "Nomor Telepon Pelanggan: " << info(info(R)).noTelpPelanggan << endl;
        cout << "=================================================" << endl;
        R = next(R);
        while (R != first(L)){
            cout << "ID Pelanggan: " << info(info(R)).idPelanggan << endl;
            cout << "Nama Pelanggan: " << info(info(R)).namaPelanggan << endl;
            cout << "Nomor Telepon Pelanggan: " << info(info(R)).noTelpPelanggan << endl;
            cout << "=================================================" << endl;
            R = next(R);
        }
    }
}
