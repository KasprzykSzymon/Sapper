#pragma once

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

int tabX[100], tabY[100],tab,ile;

void odslon(int x, int y) {
            ile++;
            if (a[x][y].show == true) goto end;
            a[x][y].show = true;

            a[x + 1][y].actual = a[x + 1][y].mines ;
            if (a[x + 1][y].show == false and a[x + 1][y].actual == 0 and x + 1 > 0 and x + 1 < 11 and y > 0 and y < 11) tabX[tab] = x + 1; tabY[tab] = y; tab++;
            
            a[x][y + 1].actual = a[x][y + 1].mines ;
            if (a[x][y + 1].show == false and a[x][y + 1].actual == 0 and x > 0 and x < 11 and y + 1 > 0 and y + 1 < 11) tabX[tab] = x; tabY[tab] = y+1; tab++;
            
            a[x - 1][y].actual = a[x - 1][y].mines ; 
            if (a[x - 1][y].show == false and a[x - 1][y].actual == 0 and x - 1 > 0 and x - 1 < 11 and y > 0 and y < 11) tabX[tab] = x-1; tabY[tab] = y; tab++;
            
            a[x][y - 1].actual = a[x][y - 1].mines ;
            if (a[x][y - 1].show == false and a[x][y - 1].actual == 0 and x > 0 and x < 11 and y - 1 > 0 and y - 1 < 11) tabX[tab] = x; tabY[tab] = y-1; tab++;
            
            a[x + 1][y + 1].actual = a[x + 1][y + 1].mines ;
            if (a[x + 1][y + 1].show == false and a[x + 1][y + 1].actual == 0 and x + 1 > 0 and x + 1 < 11 and y + 1 > 0 and y + 1 < 11) tabX[tab] = x+1; tabY[tab] = y+1; tab++;
            
            a[x - 1][y - 1].actual = a[x - 1][y - 1].mines ;
            if (a[x - 1][y - 1].show == false and a[x - 1][y - 1].actual == 0 and x - 1 > 0 and x - 1 < 11 and y - 1 > 0 and y - 1 < 11) tabX[tab] = x+1; tabY[tab] = y-1; tab++;
            
            a[x - 1][y + 1].actual = a[x - 1][y + 1].mines ;
            if (a[x - 1][y + 1].show == false and a[x - 1][y + 1].actual == 0 and x - 1 > 0 and x - 1 < 11 and y + 1 > 0 and y + 1 < 11) tabX[tab] = x-1; tabY[tab] = y+1; tab++;
            
            a[x + 1][y - 1].actual = a[x + 1][y - 1].mines ;
            if (a[x + 1][y - 1].show == false and a[x + 1][y - 1].actual == 0 and x + 1 > 0 and x + 1 < 11 and y - 1 > 0 and y - 1 < 11) tabX[tab] = x+1; tabY[tab] = y-1; tab++;
        end:
            std::cout << "Uzycie" << std::endl;

}

