#pragma once
#include "Struktura.hpp"
#include <SFML/Graphics.hpp>
//#include <SFML/Audio.hpp>
//#include<SFML/Network.hpp>
//#include<SFML/System.hpp>
#include<SFML/Window.hpp>
#include <time.h>



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
int b = 0, bombs = 10, pixels = 32;

int wylosuj(){
	return (rand() % 10) + 1;
}

int tabX[100], tabY[100],tab,ile;

void boom(int x, int y) {
    for (int i = 1; i <= 10; i++)
        for (int j = 1; j <= 10; j++)
        {
            a[i][j].actual = a[i][j].mines;
        }
}
    

void odslon(int i, int j){
    if(a[i][j].show == false and a[i][j].actual==10)  
        a[i][j].actual= a[i][j].mines;

    else {
        a[i][j].show = true;
        {
            int n = 0;
            if (a[i + 1][j].actual == 11) n++;
            if (a[i][j + 1].actual == 11) n++;
            if (a[i - 1][j].actual == 11) n++;
            if (a[i][j - 1].actual == 11) n++;
            if (a[i + 1][j + 1].actual == 11) n++;
            if (a[i - 1][j - 1].actual == 11) n++;
            if (a[i - 1][j + 1].actual == 11) n++;
            if (a[i + 1][j - 1].actual == 11) n++;
            if (a[i][j].mines == n) {
                if(a[i + 1][j].actual != 11){
                    if (a[i + 1][j].mines == 9) boom(i + 1,j);
                        a[i + 1][j].actual = a[i + 1][j].mines;}
                if(a[i][j + 1].actual != 11){
                    if (a[i][j + 1].mines == 9) boom(i,j + 1);
                        a[i][j + 1].actual = a[i][j + 1].mines;}
                if(a[i - 1][j].actual != 11){
                    if (a[i - 1][j].mines == 9) boom(i - 1,j);
                        a[i - 1][j].actual = a[i - 1][j].mines;}
                if(a[i][j - 1].actual != 11){
                    if (a[i][j - 1].mines == 9) boom(i, j - 1);
                        a[i][j - 1].actual = a[i][j - 1].mines;}
                if(a[i + 1][j + 1].actual != 11){
                    if (a[i + 1][j + 1].mines == 9) boom(i + 1, j + 1);
                    a[i + 1][j + 1].actual = a[i + 1][j + 1].mines;}
                if(a[i - 1][j - 1].actual != 11){
                    if (a[i - 1][j - 1].mines == 9) boom(i - 1, j - 1);
                    a[i - 1][j - 1].actual = a[i - 1][j - 1].mines;}
                if(a[i - 1][j + 1].actual != 11){
                    if (a[i - 1][j + 1].mines == 9) boom(i - 1, j + 1);
                        a[i - 1][j + 1].actual = a[i - 1][j + 1].mines;}
                if(a[i + 1][j - 1].actual != 11){
                    if (a[i + 1][j - 1].mines == 9) boom(i + 1, j - 1);
                        a[i + 1][j - 1].actual = a[i + 1][j - 1].mines;}
                
            };
        }
    }
}

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

