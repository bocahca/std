#include "game.h"

int main()
{
    listHero H;
    listItem I;
    createListItem(I);
    createListHero(H);
    int pilihan;
    pilihan = mainMenu();
    while ( pilihan != 0 ) {
        switch(pilihan) {
        case 1:
            addData(H, I);
            break;
        case 2:
            deleteData(H, I);
            break;
        case 3:
            findData(H, I);
            break;
        case 4:
            showData(H, I);
            break;
        }
        pilihan = mainMenu();
    }
    cout << "terima kasih!";
    return 0;
}
