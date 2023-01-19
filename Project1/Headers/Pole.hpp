#pragma once
#include<iostream>
#include <SFML/Graphics.hpp>
//#include <SFML/Audio.hpp>
//#include<SFML/Network.hpp>
//#include<SFML/System.hpp>
//#include<SFML/Window.hpp>
#include <time.h>


//Pole planszy
struct Pool {
    bool show = false;
    bool bomb;
    unsigned short mines;
    unsigned short actual = 10;
};

//Inicjowanie pola gry
Pool a[12][13];


//Na przysz³oœæ;
//Pool LVL2[20][20];
//Pool LVL3[30][30];

int b=0, bombs = 10, pixels = 32;

//Losowanie
int wylosuj() {
    return (rand() % 10) + 1;
}

int tabX[100], tabY[100], tab, ile;

//Funkcja pokazuj¹ca, ¿e siê przegra³o
void boom() {
    std::cout << "Przegrana" << std::endl;
    for (int i = 1; i <= 10; i++)
        for (int j = 1; j <= 10; j++)
        {
            a[i][j].actual = a[i][j].mines;
        }
}

//losowanie miejsc bomb 
void losowanie_bomb(){
    while (b != bombs) {
        int P1 = wylosuj();
        int P2 = wylosuj();

        if (a[P1][P2].mines != 9) {
            a[P1][P2].bomb = true;
            a[P1][P2].mines = 9;
            b++;
        }
    }
}

//reset pól
void reset(){
    for (int i = 1; i <= 10; i++)
        for (int j = 1; j <= 10; j++){
            a[i][j].actual = 10;
            a[i][j].bomb = 0;
        }
}


//Liczenie min na obwodzie pola
void liczenie_min(){
    for (int i = 1; i <= 10; i++)
        for (int j = 1; j <= 10; j++){
            int n = 0;
            if (a[i][j].bomb == true) continue;
            if (a[i + 1][j].bomb == true) n++;
            if (a[i][j + 1].bomb == true) n++;
            if (a[i - 1][j].bomb == true) n++;
            if (a[i][j - 1].bomb == true) n++;
            if (a[i + 1][j + 1].bomb == true) n++;
            if (a[i - 1][j - 1].bomb == true) n++;
            if (a[i - 1][j + 1].bomb == true) n++;
            if (a[i + 1][j - 1].bomb == true) n++;
            a[i][j].mines = n;
        }
}

//Menu na polach
void menu() {
    for (int i = 1; i < 12; i++) {
        a[i][11].mines = i + 11;
        a[i][11].actual = i + 11;
    }
}

void zamiana_opcji_menu(int i,int j){
    menu();
    a[i][j].actual = i + 18;
    a[i][j].mines = i + 18;
}

//Ods³oniêcie
void odslon(int i, int j) {
    if(11>j)
        a[i][j].actual = a[i][j].mines;
    if (i == 4 and j == 11) {
        bombs = 10;
        zamiana_opcji_menu(i, j);
    }
    else if (i == 5 and j == 11) {
        bombs = 20;
        zamiana_opcji_menu(i, j);
    }
    else if (i == 6 and j == 11) {
        bombs = 30;
        zamiana_opcji_menu(i, j);
    }
    else if (i == 7 and j == 11) {
        bombs = 40;
        zamiana_opcji_menu(i, j);
    }
    else if (i == 8 and j == 11) {
        bombs = 50;
        zamiana_opcji_menu(i, j);
    }
    else if ((i == 9 or i == 10) and j == 11) {
        reset();
        b = 0;
        losowanie_bomb();
        liczenie_min();
    }
        
 }
    
