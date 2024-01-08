#include "game.h"

void createListHero(listHero &H) {
    firstH(H) = NULL;
    lastH(H) = NULL;
}

void createListItem(listItem &I) {
    firstI(I) = NULL;
    lastI(I) = NULL;
}

adrHero alokasiElmHero(infotypeHero x) {
    adrHero p = new elmHero;
    info(p) = x;
    next(p) = NULL;
    Relasi(p) = NULL;
}

adrItem alokasiElmItem(infotypeItem x) {
    adrItem p = new elmItem;
    info(p) = x;
    next(p) = NULL;

}

adrHero searchHero(listHero H, string namaHero) {
    adrHero p;
    p = firstH(H);
    while (p != NULL) {
        if (info(p).nama == namaHero) {
            return p;
        }
        p = next(p);
    }
    return NULL;
}

adrItem searchItem(listItem I, string namaItem) {
    adrItem p;
    p = firstI(I);
    while (p != NULL) {
        if (info(p).namaItem == namaItem) {
            return p;
        }
        p = next(p);
    }
    return NULL;
}

void insertLastHero(listHero &H, adrHero P) {
    adrHero q;
    q = searchHero(H, info(P).nama);
    if (q == NULL) {
        if (firstH(H) == NULL) {
            firstH(H) = P;
            lastH(H) = P;
        }else {
            next(lastH(H)) = P;
            lastH(H) = P;
        }
    }else {
        cout << "hero telah terdaftar di list Parent!" << endl;
    }
}

void insertLastItem(listItem &I, adrItem p) {
    adrItem q;
    q = searchItem(I, info(p).namaItem);
    if (q == NULL) {
        if (firstI(I) == NULL) {
            firstI(I) = p;
            lastI(I) = p;
        }else {
            next(lastI(I)) = p;
            lastI(I) = p;
        }
    }else {
        cout << "Item telah terdaftar di list Child!" << endl;
    }
}

void showAllItem(listItem I) {
    adrItem p;
    p = firstI(I);
    cout << "========Data Item========" << endl;
    cout << endl;
    while (p != NULL) {
        cout << "Nama Item      : " << info(p).namaItem << endl;
        cout << "Harga          : " << info(p).harga << endl;
        cout << "HP             : " << info(p).statItem.HP << endl;
        cout << "Attack         : " << info(p).statItem.ATT << endl;
        cout << "DEF            : " << info(p).statItem.DEF << endl;
        cout << endl;
        cout <<"-------------------------" << endl;
        p = next(p);
    }
}

void showAllHero(listHero H) {
    adrHero p;
    adrRelasi r;
    p = firstH(H);
    cout <<"========Data Hero========" << endl;
    cout << endl;
    while (p != NULL) {
        cout << "Nama Hero      : " << info(p).nama << endl;
        cout << "Gold           : " << info(p).gold << endl;
        cout << "HP             : " << info(p).statHero.HP << endl;
        cout << "Attack         : " << info(p).statHero.ATT << endl;
        cout << "DEF            : " << info(p).statHero.DEF << endl;
        cout << "Equipped Item  : ";
        r = Relasi(p);
        while (r != NULL) {
            cout << info(infoRelasi(r)).namaItem<< "; ";
            r = next(r);
        }
        cout << endl;
        cout <<"-------------------------" << endl;
        p = next(p);
    }
}

void show1Hero(adrHero p) {
    adrRelasi r;
    cout << "Nama Hero      : " << info(p).nama << endl;
    cout << "Gold           : " << info(p).gold << endl;
    cout << "HP             : " << info(p).statHero.HP << endl;
    cout << "Attack         : " << info(p).statHero.ATT << endl;
    cout << "DEF            : " << info(p).statHero.DEF << endl;
    cout << "Equipped Item  :";
    r = Relasi(p);
    while (r != NULL) {
            cout << info(infoRelasi(r)).namaItem << "; ";
            r = next(r);
    }
    cout << endl;
}

void show1Item(adrItem q) {
    cout << "Nama Item      : " << info(q).namaItem << endl;
    cout << "Harga          : " << info(q).harga << endl;
    cout << "HP             : " << info(q).statItem.HP << endl;
    cout << "Attack         : " << info(q).statItem.ATT << endl;
    cout << "DEF            : " << info(q).statItem.DEF << endl;
    cout << endl;
}

void deleteHero(listHero &H, string namaHero) {
    adrHero p,preq;
    adrRelasi r;
    int i, n;
    p = searchHero(H, namaHero);
    if (p != NULL) {
        n = countRelasi(p);
        for (i = 1; i <= n; i++) {
            r = Relasi(p);
            deleteFirstRelasi(H, p, r);
        }
        if (p == NULL) {
            cout << "Hero tidak ditemukan";
        }else if (firstH(H) == p) {
            deleteFirstHero(H, p);
        }else if (lastH(H) == p) {
            deleteLastHero(H, p);
        }else {
            preq = searchPreqHero(H, p);
            deleteAfterHero(H, preq, p);
        }
        cout << "Hero deleted!" << endl;
        showAllHero(H);
    }else {
        cout << "Hero tidak ditemukan" << endl;
    }
}

void deleteFirstHero(listHero &H, adrHero p) {
    if (next(p) == NULL) {
        firstH(H) = NULL;
        lastH(H) = NULL;
    }else {
        firstH(H) = next(p);
        next(p) = NULL;
    }
}

void deleteLastHero(listHero &H, adrHero p) {
    if (firstH(H) == p) {
        firstH(H) = NULL;
        lastH(H) = NULL;
    }else {
        adrHero s = firstH(H);
        while (next(s) != p) {
            s = next(s);
        }
        next(s) = NULL;
    }
}

void deleteAfterHero(listHero &H, adrHero preq, adrHero p) {
        next(preq) = next(p);
        next(p) = NULL;
}

adrHero searchPreqHero(listHero H, adrHero p) {
    adrHero preq = firstH(H);
    while (next(preq) != p) {
        preq = next(preq);
    }
    return preq;
}

