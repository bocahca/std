#include "game.h"
int mainMenu() {
    system("cls");
    cout << "TUGAS BESAR STRUKTUR DATA" << endl;
    cout << "OLIVER SERVATIO LEON - 1303220115" << endl;
    cout << "GIVO SYABANI - 1303220154" << endl;

    cout << "========Main Menu========" << endl;
    cout << "1. Tambah Data" << endl;
    cout << "2. Hapus Data" << endl;
    cout << "3. Find Data" << endl;
    cout << "4. Show Data" << endl;
    cout << "0. exit" << endl;
    cout << "-------------------------"<<endl;
    cout << "pilihan: ";
    int input;
    cin >> input;

    return input;
}

int menuAdd() {
    system("cls");
    int input;
    cout << "========Tambah Data========" << endl;
    cout << "1. Tambah Data Hero" << endl;
    cout << "2. Tambah Data Item" << endl;
    cout << "3. Beli Item" << endl;
    cout << "4. Kembali" << endl;
    cout << "-------------------------"<<endl;
    cout << "pilihan: ";

    cin >> input;
    return input;
}

void addData(listHero &H, listItem &I) {
    int N, input;
    infotypeHero dataH;
    infotypeItem dataI;
    adrItem Q;
    adrHero P;
    input = menuAdd();
    switch(input) {
    case 1:
        system("cls");
        cout << "masukkan jumlah hero yang akan diinputkan: ";
        cin >> N;
        for (int i = 1; i <= N; i++) {
            cout << "masukkan data ke- " << i << ":" << endl;
            cout << "Nama Hero      : ";
            cin >> dataH.nama;
            cout << "Gold           : ";
            cin >> dataH.gold;
            cout << "HP             : ";
            cin >> dataH.statHero.HP;
            cout << "ATT            : ";
            cin >> dataH.statHero.ATT;
            cout << "DEF            : ";
            cin >> dataH.statHero.DEF;
            P = alokasiElmHero(dataH);
            insertLastHero(H, P);
        }
        showAllHero(H);
        break;
    case 2:
        system("cls");
        cout << "masukkan jumlah item yang akan diinputkan: ";
        cin >> N;
        for (int i = 1; i <= N; i++) {
            cout << "masukkan data ke- " << i << ":" << endl;
            cout << "Nama Item      : ";
            cin >> dataI.namaItem;
            cout << "Harga          : ";
            cin >> dataI.harga;
            cout << "HP             : ";
            cin >> dataI.statItem.HP;
            cout << "ATT            : ";
            cin >> dataI.statItem.ATT;
            cout << "DEF            : ";
            cin >> dataI.statItem.DEF;
            Q = alokasiElmItem(dataI);
            insertLastItem(I, Q);
        }
        showAllItem(I);
        break;
    case 3:
        string idHero;
        string idItem;
        system("cls");
        cout << "masukkan nama Hero: ";
        cin >>idHero;
        cout << "masukkan nama Item: ";
        cin >> idItem;
        tambahRelasi(H, I, idHero, idItem);
        break;
    }

    cout << "klik 'y' untuk kembali ";
    char pilih;
    cin >> pilih;
    while (pilih != 'y') {
        cin >> pilih;
    }

}

int menuDelete() {
    system("cls");
    int input;
    cout << "========Hapus Data========" << endl;
    cout << "1. Delete Hero" << endl;
    cout << "2. Sell Item" << endl;
    cout << "3. Kembali" << endl;
    cout << "-------------------------"<<endl;
    cout << "pilihan: ";

    cin >> input;
    return input;
}

void deleteData(listHero &H, listItem &I) {
    int N, input;
    input = menuDelete();
    string idHero, idItem;
    switch (input) {
    case 1:
        cout << "Masukkan nama Hero: ";
        cin >> idHero;
        deleteHero(H, idHero);
        break;
    case 2:
        cout << "masukkan nama Hero: ";
        cin >> idHero;
        cout << "masukkan Item yang ingin dijual: ";
        cin >> idItem;
        disconnectRelasi(H, I, idHero, idItem);

        break;
    }

    cout << "klik 'y' untuk kembali ";
    char pilih;
    cin >> pilih;
    while (pilih != 'y') {
        cin >> pilih;
    }
}

int menuFind() {
    system("cls");
    int input;
    cout << "========Find Data========" << endl;
    cout << "1. Cari Data Hero" << endl;
    cout << "2. Cari Data Item" << endl;
    cout << "3. Cari Equipped Item" << endl;
    cout << "4. Kembali" << endl;
    cout << "-------------------------"<<endl;
    cout << "pilihan: ";

    cin >> input;

    return input;
}

void findData(listHero H, listItem I) {
    int input;
    string id_item;
    string id_hero;
    input = menuFind();
    switch (input) {
    case 1:
        {
            adrHero p;
            adrRelasi r;
            string id_hero;
            cout << "masukkan nama Hero yang dicari: ";
            cin >> id_hero;
            p = searchHero(H, id_hero);
            if (p != NULL) {
                show1Hero(p);
                cout << "jumlah equipped Item: " << countRelasi(p) << endl;
            }else {
                cout << "Hero tidak ditemukan" << endl;
            }
        }
        break;
    case 2:
        adrItem q;
        cout << "masukkan nama Item yang dicari: ";
        cin >> id_item;
        q = searchItem(I, id_item);
        if (q != NULL) {
            show1Item(q);
        }else {
            cout << "Item tidak ditemukan" << endl;
        }
        break;
    case 3:
        adrHero p;
        cout << "masukkan nama Hero: ";
        cin >> id_hero;
        cout << "masukkan item yang dicari: ";
        cin >> id_item;
        p = searchHero(H, id_hero);
        if (p == NULL) {
            cout <<"Hero tidak ditemukan" << endl;
        }else {
            q = searchEquipped(I, p, id_item);
            if (q == NULL) {
                cout << "item not equipped" << endl;
            }else {
                cout << "Item Equipped! stats: " << endl;
                cout << "-----------------------"<< endl;
                show1Item(q);
            }
        }
        break;
    }


    cout << "klik 'y' untuk kembali ";
    char pilih;
    cin >> pilih;
    while (pilih != 'y') {
        cin >> pilih;
    }
}

int menuShow() {
    system("cls");
    int input;
    cout << "========Show Data========" << endl;
    cout << "1. Show All Hero" << endl;
    cout << "2. Show All Item" << endl;
    cout << "3. Kembali" << endl;
    cout << "-------------------------"<<endl;
    cout << "pilihan: ";

    cin >> input;
    return input;
}

void showData(listHero H, listItem I) {
    int input;
    string id_item;
    string id_hero;
    input = menuShow();
    switch (input) {
    case 1:
        showAllHero(H);
        break;
    case 2:
        showAllItem(I);
        break;
    }


    cout << "klik 'y' untuk kembali ";
    char pilih;
    cin >> pilih;
    while (pilih != 'y') {
        cin >> pilih;
    }
}
