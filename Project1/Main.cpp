#include <SFML/Graphics.hpp>
#include "Headers/Pole.hpp"
//#include <SFML/Audio.hpp>
//#include<SFML/Network.hpp>
//#include<SFML/System.hpp>
//#include<SFML/Window.hpp>
#include <time.h>



using namespace sf;

int main(){
    srand(time(NULL));

    //Renderowanie okna aplikacji
    RenderWindow app(VideoMode(400, 400), "Sapper");

    int b = 0, bombs = 20, pixels = 32;
    
    //Wczytanie obrazu
    Texture picture1;
    picture1.loadFromFile("images/iconPools.jpg");
    Sprite s(picture1);
    
    
    //losowanie miejsc bomb 
    while (b!=bombs) {
        int P1 = wylosuj();
        int P2 = wylosuj();

        if (a[P1][P2].mines != 9){
            a[P1][P2].bomb = true;
            a[P1][P2].mines = 9;
            b++;
        }
        
    } 
  

    //Liczenie min na obwodzie pola
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
            a[i][j].mines = n;
        }


    while (app.isOpen())
    {
        // Ustalenie pozycji kursora
        Vector2i position = Mouse::getPosition(app);
        int x = position.x / pixels;
        int y = position.y / pixels;

        Event e;

        while (app.pollEvent(e))
        {
            if (e.type == Event::KeyPressed) {
                if (e.key.code == Keyboard::R) {
                    for (int i = 0; i <= 10; i++) {
                        for (int j = 0; j <= 10; j++) {
                            a[i][j].actual = 10;
                        }
                    }
                }
            }
            if (e.type == Event::Closed)
                app.close();


            //Evet wciœniêcia przycisków na myszce
            if (e.type == Event::MouseButtonPressed) {
                if (e.key.code == Mouse::Left){
                    if(a[x][y].actual!=11)
                        a[x][y].actual = a[x][y].mines;
                    /*if (a[x][y].actual == 0) {
                        odslon(x, y);
                        while (tab > ile) {
                            odslon(tabX[ile], tabY[ile]);
                            std::cout << ile <<  std::endl;
                        }
                    }*/
                }
                    
                else if (e.key.code == Mouse::Right) {
                    if (a[x][y].actual == 10)
                        a[x][y].actual = 11;
                    else if (a[x][y].actual == 11)
                        a[x][y].actual = 10;
                }
            }
        }
            //Kolor t³a
            app.clear(Color::Black);


            //Wyœwietlanie ikon
            for (int i = 1; i <= 10; i++)
                for (int j = 1; j <= 10; j++)
                {
                    if (a[x][y].actual == 9) a[i][j].actual = a[i][j].mines;
                    s.setTextureRect(IntRect(a[i][j].actual * pixels, 0, pixels, pixels));
                    s.setPosition(i * pixels, j * pixels);
                    app.draw(s);
                }
            
            app.display();
    }

        return 0;
}
