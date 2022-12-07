#pragma once

struct element
{
    int wartosc1, wartosc2;
    element* nastepny;
};


element* dodaj(int liczba1,int liczba2, element* koniec)
{
    element* wsk;
    wsk = new element;
    wsk->wartosc1 = liczba1;
    wsk->wartosc2 = liczba2;
    wsk->nastepny = NULL;
    return wsk;
}

element* usun(int* liczba1, int* liczba2, element* poczatek)
{
    if (poczatek)
    {
        element* wsk;
        *liczba1 = poczatek->wartosc1;
        *liczba2 = poczatek->wartosc2;
        wsk = poczatek->nastepny;
        delete poczatek;
        return wsk;
    }



#include <iostream>
//Pole planszy
struct Pool {
	bool show=false;
	//bool flag;
	bool bomb;
	//bool exploded;
	unsigned short mines;
    unsigned short actual=10;
	};

Pool a[12][12];

int wylosuj() {
	return (rand() % 10) + 1;
}

//int tabX[100], tabY[100],tab,ile;

/*void odslon(int x, int y) {
            ile++;
            a[x][y].show = true;

            if (a[x + 1][y].actual==10 and a[x + 1][y].actual == 0 and x + 1 >= 1 and x + 1 <= 10 and y >= 1 and y < 11) a[x + 1][y].actual = a[x + 1][y].mines ;
            if (a[x + 1][y].show == false and a[x + 1][y].actual == 0 and x + 1 >= 1 and x + 1 < 11 and y >= 1 and y < 11) tabX[tab] = x + 1; tabY[tab] = y; tab++;
            
            if (a[x][y + 1].actual == 10 and a[x][y + 1].actual == 0 and x >= 1 and x < 11 and y + 1 >= 1 and y + 1 < 11) a[x][y + 1].actual = a[x][y + 1].mines ;
            if (a[x][y + 1].show == false and a[x][y + 1].actual == 0 and x >= 1 and x < 11 and y + 1 >= 1 and y + 1 < 11) tabX[tab] = x; tabY[tab] = y+1; tab++;
            
            if (a[x - 1][y].actual == 10 and a[x - 1][y].actual == 0 and x - 1 >= 1 and x - 1 < 11 and y >= 1 and y < 11) a[x - 1][y].actual = a[x - 1][y].mines ;
            if (a[x - 1][y].show == false and a[x - 1][y].actual == 0 and x - 1 >= 1 and x - 1 < 11 and y >= 1 and y < 11) tabX[tab] = x-1; tabY[tab] = y; tab++;
            
            if (a[x][y - 1].actual == 10 and a[x][y - 1].actual == 0 and x >= 1 and x < 11 and y - 1 >= 1 and y - 1 < 11) a[x][y - 1].actual = a[x][y - 1].mines ;
            if (a[x][y - 1].show == false and a[x][y - 1].actual == 0 and x >= 1 and x < 11 and y - 1 >= 1 and y - 1 < 11) tabX[tab] = x; tabY[tab] = y-1; tab++;
            
            if (a[x + 1][y + 1].actual == 10 and a[x + 1][y + 1].actual == 0 and x + 1 >= 1 and x + 1 < 11 and y + 1 >= 1 and y + 1 < 11) a[x + 1][y + 1].actual = a[x + 1][y + 1].mines ;
            if (a[x + 1][y + 1].show == false and a[x + 1][y + 1].actual == 0 and x + 1 >= 1 and x + 1 < 11 and y + 1 >= 1 and y + 1 < 11) tabX[tab] = x+1; tabY[tab] = y+1; tab++;
            
            if (a[x - 1][y - 1].actual == 10 and a[x - 1][y - 1].actual == 0 and x - 1 >= 1 and x - 1 < 11 and y - 1 >= 1 and y - 1 < 11) a[x - 1][y - 1].actual = a[x - 1][y - 1].mines ;
            if (a[x - 1][y - 1].show == false and a[x - 1][y - 1].actual == 0 and x - 1 >= 1 and x - 1 < 11 and y - 1 >= 1 and y - 1 < 11) tabX[tab] = x+1; tabY[tab] = y-1; tab++;
            
            if (a[x - 1][y + 1].actual == 10 and a[x - 1][y + 1].actual == 0 and x - 1 >= 1 and x - 1 < 11 and y + 1 >= 1 and y + 1 < 11) a[x - 1][y + 1].actual = a[x - 1][y + 1].mines ;
            if (a[x - 1][y + 1].show == false and a[x - 1][y + 1].actual == 0 and x - 1 >= 1 and x - 1 < 11 and y + 1 >= 1 and y + 1 < 11) tabX[tab] = x-1; tabY[tab] = y+1; tab++;
            
            if (a[x + 1][y - 1].actual == 10 and a[x + 1][y - 1].actual == 0 and x + 1 >= 1 and x + 1 < 11 and y - 1 >= 1 and y - 1 < 11) a[x + 1][y - 1].actual = a[x + 1][y - 1].mines ;
            if (a[x + 1][y - 1].show == false and a[x + 1][y - 1].actual == 0 and x + 1 >= 1 and x + 1 < 11 and y - 1 >= 1 and y - 1 < 11) tabX[tab] = x+1; tabY[tab] = y-1; tab++;
       

}*/

