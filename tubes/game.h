// Tubes Kelompok 3
// Oliver Servatio Leon /1303220115
// Givo Syabani /1303220154
#include <iostream>

#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

#define next(p) p->next
#define info(p) p->info
#define firstH(L) L.firstH
#define lastH(L) L.lastH
#define firstI(L) L.firstI
#define lastI(L) L.lastI
#define infoRelasi(p) p->infoRelasi
#define Relasi(p) p->Relasi
#define firstR(L) L.firstR
#define lastR(L) L.lastR
using namespace std;

struct stats {
    int HP;
    int DEF;
    int ATT;
};

struct infotypeHero {
    string nama;
    int gold;
    stats statHero;
};
struct infotypeItem {
    int harga;
    string namaItem;
    stats statItem;
};

typedef struct elmHero *adrHero;
typedef struct elmItem *adrItem;
typedef struct elmRelasi *adrRelasi;

struct listHero {
    adrHero firstH;
    adrHero lastH;
};

struct listItem {
    adrItem firstI;
    adrItem lastI;
};

struct elmHero {
    infotypeHero info;
    adrHero next;
    adrRelasi Relasi;
};
struct elmItem {
    infotypeItem info;
    adrItem next;
};

struct elmRelasi {
    adrItem infoRelasi;
    adrRelasi next;

};

void createListHero(listHero &H);
void createListItem(listItem &I);
adrHero alokasiElmHero(infotypeHero x);
adrItem alokasiElmItem(infotypeItem x);
void insertLastHero(listHero &H, adrHero P);
void insertLastItem(listItem &I, adrItem P);
void showAllHero(listHero H);
void showAllItem(listItem I);
adrHero searchHero(listHero H, string namaHero);
adrItem searchItem(listItem I, string namaItem);
void show1Hero(adrHero p);
void show1Item(adrItem q);
void deleteFirstHero(listHero &H, adrHero p);
void deleteLastHero(listHero &H, adrHero p);
void deleteHero(listHero &H, string namaHero);
void deleteAfterHero(listHero &H, adrHero preq, adrHero p);
adrHero searchPreqHero(listHero H, adrHero p);

int mainMenu();
int menuAdd();
int menuDelete();
int menuFind();
int menuShow();
void addData(listHero &H, listItem &I);
void deleteData(listHero &H, listItem &I);
void findData(listHero H, listItem I);
void showData(listHero H, listItem I);



void tambahRelasi(listHero &H, listItem I, string idHero, string idItem);
adrItem searchEquipped(listItem I,adrHero p, string idItem);
adrRelasi searchRelasi(adrHero p, adrItem q);
adrRelasi searchPreq(adrHero p, adrRelasi r);
void deleteFirstRelasi(listHero &H, adrHero p, adrRelasi r);
void deleteLastRelasi(listHero &H, adrHero p,adrRelasi r);
void deleteAfterRelasi(listHero &H, adrRelasi preq, adrRelasi r);
void disconnectRelasi(listHero &H, listItem I, string idHero, string idItem );
int countRelasi(adrHero p);
#endif // GAME_H_INCLUDED
