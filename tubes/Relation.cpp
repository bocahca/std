#include "game.h"

void tambahRelasi(listHero &H, listItem I, string idHero, string idItem) {
    adrHero p;
    adrItem q;
    adrRelasi s;

    p = searchHero(H, idHero);
    q = searchItem(I, idItem);
    if (p != NULL && q != NULL) {
        s = new elmRelasi;
        infoRelasi(s) = q;
        next(s) = NULL;

        if (info(p).gold >= info(q).harga) {
            if (Relasi(p) == NULL) {
               Relasi(p) = s;
            }else {
                next(s) = Relasi(p);
                Relasi(p) = s;
            }
            info(p).gold -= info(q).harga;
            info(p).statHero.ATT += info(q).statItem.ATT;
            info(p).statHero.HP += info(q).statItem.HP;
            info(p).statHero.DEF += info(q).statItem.DEF;
            show1Hero(p);
        }else {
            cout << "gold tidak cukup" << endl;
        }
    }else {
        cout << "data tidak ditemukan" << endl;
    }
}

adrItem searchEquipped(listItem I,adrHero p, string idItem) {
    adrRelasi r;
    if (p != NULL) {
        r = Relasi(p);
        while (r != NULL) {
            if (info(infoRelasi(r)).namaItem == idItem) {
                return infoRelasi(r);
            }
            r = next(r);
        }
    }
    return NULL;
}

adrRelasi searchRelasi(adrHero p, adrItem q) {
    adrRelasi r = Relasi(p);
    while (r != NULL) {
        if (infoRelasi(r) == q) {
            return r;
        }
        r = next(r);
    }
    return NULL;
}
adrRelasi searchPreq(adrHero p, adrRelasi r) {
    adrRelasi preq = Relasi(p);
    while (next(preq) != r) {
        preq = next(preq);
    }
    return preq;
}

void deleteFirstRelasi(listHero &H, adrHero p, adrRelasi r) {
    r = Relasi(p);
    if (next(r) == NULL) {
        Relasi(p) = NULL;
    }else {
        Relasi(p) = next(r);
        next(r) = NULL;
    }
}

void deleteLastRelasi(listHero &H, adrHero p,adrRelasi r) {
    if (Relasi(p) == r) {
        Relasi(p) = NULL;
    }else {
        adrRelasi s = Relasi(p);
        while (next(s) != r) {
            s = next(s);
        }
        next(s) = NULL;
    }
}

void deleteAfterRelasi(listHero &H, adrRelasi preq, adrRelasi r) {
        next(preq) = next(r);
        next(r) = NULL;
}


void disconnectRelasi(listHero &H, listItem I, string idHero, string idItem ) {
    adrHero p;
    adrItem q;
    adrRelasi r, preq;

    p = searchHero(H, idHero);
    q = searchItem(I, idItem);
    if (p != NULL && q != NULL) {
        r = searchRelasi(p, q);
        if (r == NULL) {
            cout << "Item tidak ditemukan" << endl;
        }else if(Relasi(p) == r) {
            deleteFirstRelasi(H, p, r);
            info(p).gold += info(q).harga;
            info(p).statHero.ATT -= info(q).statItem.ATT;
            info(p).statHero.HP -= info(q).statItem.HP;
            info(p).statHero.DEF -= info(q).statItem.DEF;
        }else if (next(r) == NULL) {
            deleteLastRelasi(H, p, r);
            info(p).gold += info(q).harga;
            info(p).statHero.ATT -= info(q).statItem.ATT;
            info(p).statHero.HP -= info(q).statItem.HP;
            info(p).statHero.DEF -= info(q).statItem.DEF;
        }else {
            preq = searchPreq(p, r);
            deleteAfterRelasi(H, preq, r);
            info(p).gold += info(q).harga;
            info(p).statHero.ATT -= info(q).statItem.ATT;
            info(p).statHero.HP -= info(q).statItem.HP;
            info(p).statHero.DEF -= info(q).statItem.DEF;
        }
        show1Hero(p);
    }else if (p == NULL) {
        cout << "Hero tidak ditemukan" << endl;
    }else {
        cout << "Item tidak ditemukan" << endl;
    }
}

int countRelasi(adrHero p) {
    adrRelasi r;
    int sum = 0;
    r = Relasi(p);
    while (r != NULL) {
        sum = sum + 1;
        r = next(r);
    }

    return sum;
}

