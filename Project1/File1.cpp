//#include "New.hpp"

#include <stdlib.h>

// Klasa planszy gry
//------------------

// Konstruktor planszy
//--------------------
Minefield::Minefield(int m, int n, int mn)
{
    // Ustalamy liczbê wierszy
    r = m;
    if (r < RMIN) r = RMIN;  // Jeœli r nie mieœci siê w zakresie,
    if (r > RMAX) r = RMAX;  // to je odpowiednio dopasowujemy

    // Ustalamy liczbê kolumn
    c = n;
    if (c < CMIN) c = CMIN;  // Jeœli c nie mieœci siê w zakresie,
    if (c > CMAX) c = CMAX;  // to je odpowiednio dopasowujemy

    // Tworzymy macierz pól
    T = new Pool * [r];
    for (int i = 0; i < r; i++)
    {
        T[i] = new Pool[c];

        // Ka¿d¹ komórkê pola inicjujemy zerami

        for (int j = 0; j < c; j++)
        {
            T[i][j].open = T[i][j].flag = T[i][j].mine = T[i][j].exploded = false;
            T[i][j].count = 0;
        }
    }

    // Ustalamy liczbê min na polu, dopasowuj¹c j¹ do zakresu

    if (mn < MMIN) mn = MMIN;
    if (mn > (r * c) / 3) mn = (r * c) / 3;

    // Wstawiamy miny na pole do komórek
    // W mc bêdzie ostateczna liczba min

    mc = 0;

    while (mc < mn)
    {
        int rr = rand() % r;         // Generujemy losowe pole planszy
        int cc = rand() % c;
        if (T[rr][cc].mine) continue; // Jeœli zawiera minê, to powtarzamy
        T[rr][cc].mine = true;       // Wstawiamy minê w pole
        mc++;                        // Zwiêkszamy licznik min
    }

    // Zliczamy miny w s¹siedztwie ka¿dego pola

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
    delete[] T;                               // Usuwamy tablicê wierszy
}

// Zwraca liczbê wierszy
//----------------------
int Minefield::RowCount()
{
    return r;
}

// Zwraca liczbê kolumn
//---------------------
int Minefield::ColCount()
{
    return c;
}

// Zwraca liczbê min
//------------------
int Minefield::MinCount()
{
    return mc;
}

// Zwraca referencjê do komórki planszy
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
    n = SSIZE;         // Zapamiêtujemy rozmiar
    S = new int[n];   // Tworzymy stos
    sp = 0;             // Zerujemy wskaŸnik stosu
}

// Destruktor
//-----------
Stack::~Stack()
{
    delete[] S;
}

// Zwraca true, jeœli stos nie jest pusty
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
    {                             // Jeœli nie, to
        n += SGROW;                 // Powiêkszamy rozmiar
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
    a = S[--sp];                  // a nastêpnie a
}