#include <SFML/Graphics.hpp>
#include "Headers/Pole.hpp"
//#include <SFML/Audio.hpp>
//#include<SFML/Network.hpp>
//#include<SFML/System.hpp>
//#include<SFML/Window.hpp>
#include <time.h>
Pole a[10][10];


using namespace sf;

void show(unsigned short x, unsigned short y) {
    a[x][y].show = 1;
}


int main()
{
     
    srand(time(0));

    //Renderowanie okna aplikacji
    RenderWindow app(VideoMode(400, 400), "Sapper!");

    int w = 32;
    int x, y;
    int b=0,bombs = 10;

    //losowanie miejsc bomb 
    while (b == bombs) {
        
        if (a[x][y].bomb == 0) {
            a[x][y].bomb = 1;
            b++;
        }
    }


    

    Texture picture1;
    picture1.loadFromFile("images/iconPools.jpg");
    Sprite s(picture1);


    

    while (app.isOpen()) {

        Vector2i pos = Mouse::getPosition(app);
        x = pos.x / w;
        y = pos.y / w;

        Event e;

        while (app.pollEvent(e))
        {
            if (e.type == Event::Closed)
                app.close();

        if (e.type == Event::MouseButtonPressed)
                if (e.key.code == Mouse::Left) a[x][y].show=1;
                else if (e.key.code == Mouse::Right) a[x][y].flag = 1;

        

                
         
        }
        for (unsigned short i = 0; i < 10; i++) {
            for (unsigned short j = 0; j < 10; j++) {
                if (a[i][j].show == 0) a[i][j].pole = 10;
                else if (a[i][j].flag == 1) a[i][j].pole == 11;
            }
        }
        

        app.clear(Color::Black);

        s.setTextureRect(IntRect(a[x][y].pole * w, 0, w, w));
        s.setPosition(10, 10);
        app.draw(s); 
        

        

        app.display();
}

    
    

    return 0;
}