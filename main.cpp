#include <iostream>
#include <string>
#include "parent.h"
#include "child.h"
#include "relation.h"
using namespace std;

int main()
{

    listParent listToko;
    listChild listPelanggan;
    createListParent(listToko);
    createListChild(listPelanggan);
    int inputMenu;
    while (true){
        menu();
        cout << "Masukkan menu yang dipilih: ";
        cin >> inputMenu; cout << endl;
        if (inputMenu == 1){
            int banyakToko, i = 0;
            dataToko inputToko;
            cout << "Masukkan banyak toko yang akan diinput: ";
            cin >> banyakToko;
            while (i < banyakToko){
                cout << "ID Toko: ";
                cin >> inputToko.idToko;
                cout << "Nama Toko: ";
                cin>>inputToko.namaToko;
                cout << "Nomor Telepon Toko: ";
                cin>> inputToko.noTelpToko;
                insertLastParent(listToko, createParent(inputToko));
                i += 1;
            }
        } else if (inputMenu == 2){
            int banyakPelanggan, i = 0;
            dataPelanggan inputPelanggan;
            cout << "Masukkan banyak pelanggan yang akan diinput: ";
            cin >> banyakPelanggan;
            while (i < banyakPelanggan){
                cout << "ID Pelanggan: ";
                cin >> inputPelanggan.idPelanggan;
                cout << "Nama Pelanggan: ";
                cin>>  inputPelanggan.namaPelanggan;
                cout << "No Telepon Pelanggan: ";
                cin >> inputPelanggan.noTelpPelanggan;
                insertLastChild(listPelanggan, createChild(inputPelanggan));
                i += 1;
            }
        } else if (inputMenu == 3){
            cout << "Daftar toko dan pelanggan" << endl;
            showParent(listToko);
            showCustomer(listPelanggan);
            if (first(listToko) != null && first(listPelanggan) != null){
                int idToko, idPelanggan;
                cout << "Masukkan ID Toko: "; cin >> idToko;
                cout << "Masukkan ID Pelanggan: "; cin >> idPelanggan;
                adrP toko = findParent(listToko, idToko);
                adrC pelanggan = findChild(listPelanggan, idPelanggan);
                if (toko != null && pelanggan != null){
                    insertFirstRelation(info(toko).relation, pelanggan);
                } else {
                    cout << "ID Toko atau ID Pelanggan tidak ditemukan" << endl;
                }
            }
        } else if (inputMenu == 4){
            showParent(listToko);
            int idToko;
            cout << "Masukkan ID Toko yang akan dihapus transaksinya: "; cin >> idToko;
            adrP toko = findParent(listToko, idToko);
            if (toko != null && first(info(toko).relation) != null){
                showAllRelation(info(toko).relation);
                int idPelanggan;
                cout << "Masukkan ID Pelanggan yang akan dihapus transaksinya: "; cin >> idPelanggan;
                adrC pelanggan = findChild(listPelanggan, idPelanggan);
                if (pelanggan != null){
                    deleteSelectedRelation(info(toko).relation, pelanggan);
                } else {
                    cout << "ID Pelanggan tidak ditemukan" << endl;
                }
            }
        } else if (inputMenu == 5){
            showParent(listToko);
            int idToko;
            cout << "Masukkan ID Toko yang akan dihapus: "; cin >> idToko;
            adrP toko = findParent(listToko, idToko);
            if (toko != null){
                deleteSelectedParent(listToko, toko);
            } else {
                cout << "ID Toko yang dimasukkan tidak ditemukan" << endl;
            }
        } else if (inputMenu == 6){
            showParent(listToko);
        } else if (inputMenu == 7){
            showCustomer(listPelanggan);
        } else if (inputMenu == 8){
            showMostFavoriteParent(listToko);
        } else if (inputMenu == 9){
            showCustomer(listPelanggan);
            if (first(listPelanggan) != null){
                int idPelanggan;
                cout << "Masukkan ID Pelanggan: "; cin >> idPelanggan;
                adrC pelanggan = findChild(listPelanggan, idPelanggan);
                if (pelanggan != null){
                    getCustomerRelation(listToko, pelanggan);
                } else {
                    cout << "ID Pelanggan tidak ditemukan" << endl;
                }
            }
        } else if (inputMenu == 0){
            break;
        } else {
            cout << "Menu tidak valid" << endl;
        }
        cout << endl;
    }



    return 0;
}
