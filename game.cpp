#include "game.h"
#include <iostream>
#include <conio.h>

using namespace std;

game::game() {}

void game::p1display() {
    system("cls");
    cout << "Player 1:\n";
    cout << "Bombs Map:\n";
    p1bombs.display();
    cout << endl;
    cout << "Your Navy:\n";
    p1navy.display();
    cout << endl;
}

void game::p2display() {
    system("cls");
    cout << "Player 2:\n";
    cout << "Bombs Map:\n";
    p2bombs.display();
    cout << endl;
    cout << "Your Navy:\n";
    p2navy.display();
    cout << endl;
}

void game::input(char place[3]) {
    char L;
    char N;
    do {
        cout << "Letter: ";
        cin >> L;
    } while (tolower(L) < 97 || tolower(L) > 104);
    do {
        cout << "Number: ";
        cin >> N;
    } while (N < 49 || N > 56);
    place[0] = L;
    place[1] = N;
}

void game::placeP1Ships() {
    char place[3] = {
        '\0',
        '\0',
        '\0'
    };
    bool valid = true;
    for (int i = 1; i < 7; i++) {
        do {
            p1display();
            cout << "Place ship " << i << endl;
            input(place);
            valid = p1navy.place(place[0], place[1]);
        } while (valid == false);
    }
    p1display();
    wait(2);
}

void game::placeP2Ships() {
    char place[3] = {
        '\0',
        '\0',
        '\0'
    };
    bool valid = true;
    for (int i = 1; i < 7; i++) {
        do {
            p2display();
            cout << "Place ship " << i << endl;
            input(place);
            valid = p2navy.place(place[0], place[1]);
        } while (valid == false);
    }
    p2display();
    wait(1);
}

void game::wait(int player) {
    cout << "Press any key to continue...";
    getch();
    system("cls");
    cout << "Player " << player << "'s turn\nPress any key to continue...";
    getch();
    system("cls");
}

void game::loop(void) {
    while (true) {
        if (p1Turn()) {
            cout << "Player 1 Won!\n";
            break;
        }
        wait(2);
        if (p2Turn()) {
            cout << "Player 2 Won!\n";
            break;
        }
        wait(1);
    }
}

bool game::p1Turn() {
    char place[3] = {
        '\0',
        '\0',
        '\0'
    };
    int ret = true;
    do {
        p1display();
        cout << "Where to bomb?\n";
        input(place);
        ret = p2navy.shoot(place[0], place[1]);
        if (ret == 1) {
            p1bombs.update(place[0], place[1], 'H');
            p2Ships--;
            p1display();
            cout << "Hit!\n";
        } else if (ret == 0) {
            p1bombs.update(place[0], place[1], 'M');
            p1display();
            cout << "Miss.\n";
        }
    } while (ret == -1);
    if (p2Ships == 0)
        return true;
    else
        return false;
}
bool game::p2Turn() {
    char place[3] = {
        '\0',
        '\0',
        '\0'
    };
    int ret = true;
    do {
        p2display();
        cout << "Where to bomb?\n";
        input(place);
        ret = p1navy.shoot(place[0], place[1]);
        if (ret == 1) {
            p2bombs.update(place[0], place[1], 'H');
            p1Ships--;
            p2display();
            cout << "Hit!\n";
        } else if (ret == 0) {
            p2bombs.update(place[0], place[1], 'M');
            p2display();
            cout << "Miss.\n";
        }
    } while (ret == -1);
    if (p1Ships == 0)
        return true;
    else
        return false;
}

grid::grid() {}

void grid::display() {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 10; j++)
            cout << GRID[i][j] << " ";
        cout << endl;
    }
}

int grid::shoot(char L, char N) {
    int x = tolower(L) - 96;
    int y = 8 - (N - 48);
    if (GRID[y][x] == 'S') {
        GRID[y][x] = 'H';
        return 1;
    } else if (GRID[y][x] == '.') {
        GRID[y][x] = 'M';
        return 0;
    } else {
        return -1;
    }
}

bool grid::place(char L, char N) {
    int x = tolower(L) - 96;
    int y = 8 - (N - 48);
    if (GRID[y][x] == 'S')
        return 0;
    GRID[y][x] = 'S';
    return 1;
}

void grid::update(char L, char N, char mark) {
    int x = tolower(L) - 96;
    int y = 8 - (N - 48);
    GRID[y][x] = mark;
}
