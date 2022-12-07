#pragma once
#include "Struktura.hpp"

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

int wylosuj(){
	return (rand() % 10) + 1;
}

int tabX[100], tabY[100],tab,ile;

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

