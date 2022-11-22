#include <SFML/Graphics.hpp>
#include "Headers/Pole.hpp"
//#include <SFML/Audio.hpp>
//#include<SFML/Network.hpp>
//#include<SFML/System.hpp>
//#include<SFML/Window.hpp>
#include <time.h>
 
using namespace sf;

int main(){

    srand(time(0));
    Pole a[12][12];

    //Renderowanie okna aplikacji
    RenderWindow app(VideoMode(400, 400), "Sapper!");

    int pixels = 32;

    int b = 0, bombs = 10;
    
    Texture picture1;
    picture1.loadFromFile("images/iconPools.jpg");
    Sprite s(picture1);
    
    //losowanie miejsc bomb 
    while (b != bombs) {
        int P1 = (rand() % 10 + 1);
        int P2 = (rand() % 10 + 1);

        if (a[P1][P2].bomb == 0) {
            a[P1][P2].bomb = true;
            a[P1][P2].pole = 9;
            b++;
        }
    }



    for (int i = 1; i <= 10; i++)
        for (int j = 1; j <= 10; j++)
        {
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
            a[i][j].pole = n;
        }


    while (app.isOpen())
    {

        Vector2i position = Mouse::getPosition(app);
        int x = position.x / pixels;
        int y = position.y / pixels;

        Event e;

        while (app.pollEvent(e))
        {
            if (e.type == Event::Closed)
                app.close();

            if (e.type == Event::MouseButtonPressed) {
                if (e.key.code == Mouse::Left){
                    if(a[x][y].actual!=11)
                        a[x][y].actual = a[x][y].pole;}
                    

                else if (e.key.code == Mouse::Right) {
                    if (a[x][y].actual == 10)
                        a[x][y].actual = 11;
                    else if (a[x][y].actual == 11)
                        a[x][y].actual = 10;
                }
            }
        }




            app.clear(Color::Black);

            for (int i = 1; i <= 10; i++)
                for (int j = 1; j <= 10; j++)
                {
                    if (a[i][j].actual == 9) a[i][j].actual = a[i][j].pole;
                    s.setTextureRect(IntRect(a[i][j].actual * pixels, 0, pixels, pixels));
                    s.setPosition(i * pixels, j * pixels);
                    app.draw(s);
                }
            

            app.display();

    }

        return 0;
}
