#include "parent.h"

void createListParent(listParent &L){
    first(L) = null;
}

adrP createParent(dataToko x){
    adrP P = new elmP;
    info(P) = x;
    createListRelation(info(P).relation);
    next(P) = null;
    return P;
}

void insertFirstParent(listParent &L, adrP P){
    if (first(L) == null) {
        first(L) = P;
    } else {
        next(P) = first(L);
        first(L) = P;
    }
}

void insertLastParent(listParent &L, adrP P){
    if (first(L) == null){
        insertFirstParent(L, P);
    } else {
        adrP x = first(L);
        while (next(x) != null) {
            x = next(x);
        }
        next(x) = P;
    }
}

void deleteFirstParent(listParent &L){
    if (first(L) != null) {
        adrP P = first(L);
        first(L) = next(P);
        next(P) = null;
    }
}

void deleteLastParent(listParent &L){
    if (next(first(L)) == null && first(L) != null){
        deleteFirstParent(L);
    } else {
        adrP P = first(L);
        while (next(next(P)) != null) {
            P = next(P);
        }
        next(P) = null;
    }
}

void deleteSelectedParent(listParent &L, adrP P){
    deleteAllRelation(info(P).relation);
    if (first(L) == P){
        deleteFirstParent(L);
    } else {
        adrP x = first(L), temp;
        while (next(x) != P && next(x) != null){
            x = next(x);
        }
        temp = next(x);
        next(x) = next(temp);
        next(temp) = null;
    }
}

int countCustomer(adrP P){
    int total = 0;
    listRelation listRelasi = info(P).relation;
    if (first(listRelasi) != null){
        total += 1;
        adrR R = first(listRelasi);
        while (next(R) != first(listRelasi)){
            R = next(R);
            total += 1;
        }
    }
    return total;
}

void showParent(listParent L){
    adrP P = first(L);
    if (P != null){
        while (P != null){
            cout << "ID Toko: " << info(P).idToko << endl;
            cout << "Nama Toko: " << info(P).namaToko << endl;
            cout << "No Telepon Toko: " << info(P).noTelpToko << endl;
            cout << "Jumlah Customer Toko: " << countCustomer(P) << endl;
            cout << "========================================================" << endl;
            P = next(P);
        }
    } else {
        cout << "Data Kosong"  << endl;
    }
}

adrP findParent(listParent L, int idToko){
    adrP P = first(L), foundAdr = null;
    bool found = false;
    while (P != null && !found){
        if (info(P).idToko == idToko) {
            found = true;
            foundAdr = P;
        }
        P = next(P);
    }
    return foundAdr;
}

void showMostFavoriteParent(listParent L){
    if (first(L) == null) {
        cout << "Data Kosong" << endl;
    } else {
        adrP P = first(L), maxParent = first(L);
        while (P != null){
            if (countCustomer(P) > countCustomer(maxParent)){
                maxParent = P;
            }
            P = next(P);
        }
        cout << "Toko terfavorit" << endl;
        cout << "ID Toko: " << info(maxParent).idToko << endl;
        cout << "Nama Toko: " << info(maxParent).namaToko << endl;
        cout << "No Telepon Toko: " << info(maxParent).noTelpToko << endl;
        cout << "Jumlah Customer Toko: " << countCustomer(maxParent) << endl;
        cout << "========================================================" << endl;
    }
}

void getCustomerRelation(listParent &L, adrC C){
    adrP P = first(L);
    while (P != null){
        adrR R = first(info(P).relation);
        if (R != null){
            while (info(R) != C){
                R = next(R);
                if (R == first(info(P).relation)){
                    break;
                }
            }if (info(R) == C){
                cout << "Pelanggan " << info(C).namaPelanggan << " terdapat pada toko " << info(P).namaToko << endl;
            }
        }
        P = next(P);
    }
    cout << endl;
}

void menu(){
    cout << "1. Input toko" << endl;
    cout << "2. Input pelanggan" << endl;
    cout << "3. Input transaksi pada toko" << endl;
    cout << "4. Hapus transaksi pada toko tertentu" << endl;
    cout << "5. Hapus toko" << endl;
    cout << "6. Menampilkan data seluruh toko" << endl;
    cout << "7. Menampilkan data seluruh pelanggan" << endl;
    cout << "8. Memampilkan Toko terfavorit" << endl;
    cout << "9. Menampilkan seluruh toko yang dikunjungi konsumen tertentu" << endl;
    cout << "0. Exit" << endl;
}
