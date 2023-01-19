#include "SFML/Graphics.hpp"
#include "Headers/Pole.hpp"

using namespace sf;

int main() {

    srand(time(NULL));

    //Renderowanie okna aplikacji
    RenderWindow app(VideoMode(400, 432), "Sapper");

    //Wczytanie obrazu
    Texture picture1;
    picture1.loadFromFile("images/iconPools.jpg");
    Sprite s(picture1);

    //losowanie miejsc bomb
    losowanie_bomb();
     
   
    //liczenie s¹siaduj¹cych bomb
    liczenie_min();
    

    //Menu pod polami
    menu();
    a[4][11].mines = bombs/10 + 21;
    a[4][11].actual = bombs/10 + 21;

    while (app.isOpen())
    {

        Event e;

        // Ustalenie pozycji kursora
        Vector2i position = Mouse::getPosition(app);
        int x = position.x / pixels;
        int y = position.y / pixels;


        while (app.pollEvent(e))
        {
            
            // 
            //Zabezpieczenie przed odkryciem pól podczas wyjœcia kursora poza okno
            if (e.type == Event::MouseEntered)
                std::cout << "the mouse cursor has entered the window" << std::endl;

            if (e.type == Event::KeyPressed) {

                //resetowanie obecnej rozgrywki po naciœniêciu R
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
            


//Evety wciœniêcia przycisków na myszce
            if (e.type == Event::MouseButtonPressed) {
                if (e.key.code == Mouse::Left) {
                    if (a[x][y].actual != 11)
                        odslon(x, y);
                    
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
            for (int j = 1; j <= 11; j++)
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



