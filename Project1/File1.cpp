//#include "New.hpp"

#include <stdlib.h>

// Klasa planszy gry
//------------------

// Konstruktor planszy
//--------------------
Minefield::Minefield(int m, int n, int mn)
{
    // Ustalamy liczb� wierszy
    r = m;
    if (r < RMIN) r = RMIN;  // Je�li r nie mie�ci si� w zakresie,
    if (r > RMAX) r = RMAX;  // to je odpowiednio dopasowujemy

    // Ustalamy liczb� kolumn
    c = n;
    if (c < CMIN) c = CMIN;  // Je�li c nie mie�ci si� w zakresie,
    if (c > CMAX) c = CMAX;  // to je odpowiednio dopasowujemy

    // Tworzymy macierz p�l
    T = new Pool * [r];
    for (int i = 0; i < r; i++)
    {
        T[i] = new Pool[c];

        // Ka�d� kom�rk� pola inicjujemy zerami

        for (int j = 0; j < c; j++)
        {
            T[i][j].open = T[i][j].flag = T[i][j].mine = T[i][j].exploded = false;
            T[i][j].count = 0;
        }
    }

    // Ustalamy liczb� min na polu, dopasowuj�c j� do zakresu

    if (mn < MMIN) mn = MMIN;
    if (mn > (r * c) / 3) mn = (r * c) / 3;

    // Wstawiamy miny na pole do kom�rek
    // W mc b�dzie ostateczna liczba min

    mc = 0;

    while (mc < mn)
    {
        int rr = rand() % r;         // Generujemy losowe pole planszy
        int cc = rand() % c;
        if (T[rr][cc].mine) continue; // Je�li zawiera min�, to powtarzamy
        T[rr][cc].mine = true;       // Wstawiamy min� w pole
        mc++;                        // Zwi�kszamy licznik min
    }

    // Zliczamy miny w s�siedztwie ka�dego pola

    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            for (int ii = i - 1; ii <= i + 1; ii++)
                if ((ii >= 0) && (ii < r))
                    for (int jj = j - 1; jj <= j + 1; jj++)
                        if ((jj >= 0) && (jj < c) && T[ii][jj].mine)
                            T[i][j].count++;

}

// Destruktor planszy
//-------------------
Minefield::~Minefield()
{
    for (int i = 0; i < r; i++) delete[] T[i]; // Usuwamy wiersze
    delete[] T;                               // Usuwamy tablic� wierszy
}

// Zwraca liczb� wierszy
//----------------------
int Minefield::RowCount()
{
    return r;
}

// Zwraca liczb� kolumn
//---------------------
int Minefield::ColCount()
{
    return c;
}

// Zwraca liczb� min
//------------------
int Minefield::MinCount()
{
    return mc;
}

// Zwraca referencj� do kom�rki planszy
// rr - numer wiersza
// cc - numer kolumny
//-------------------------------------
Pool& Minefield::At(int rr, int cc)
{
    return T[rr][cc];
}

// Klasa Stosu
//------------

// Konstruktor
//------------
Stack::Stack()
{
    n = SSIZE;         // Zapami�tujemy rozmiar
    S = new int[n];   // Tworzymy stos
    sp = 0;             // Zerujemy wska�nik stosu
}

// Destruktor
//-----------
Stack::~Stack()
{
    delete[] S;
}

// Zwraca true, je�li stos nie jest pusty
//---------------------------------------
bool Stack::notEmpty()
{
    return sp;
}

// Umieszcza na stosie a i b
//--------------------------
void Stack::push(int a, int b)
{
    if (sp == n)                   // Sprawdzamy, czy na stosie jest miejsce
    {                             // Je�li nie, to
        n += SGROW;                 // Powi�kszamy rozmiar
        int* T = new int[n];       // Tworzymy nowy stos
        for (int i = 0; i < sp; i++)
            T[i] = S[i];              // Kopiujemy stary stos do nowego
        delete[] S;                // Stary stos usuwamy
        S = T;                      // Nowy stos przydzielamy S
    }

    S[sp++] = a;                  // Na stosie umieszczamy a i b
    S[sp++] = b;
}

// Pobiera ze stosu a i b
//-----------------------
void Stack::pop(int& a, int& b)
{
    b = S[--sp];                  // Pobieramy ze stosu najpierw b 
    a = S[--sp];                  // a nast�pnie a
}