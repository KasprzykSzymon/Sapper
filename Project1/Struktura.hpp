#pragma once

#include <iostream>
using namespace std;

struct element
{
    int wartosc1, wartosc2;
    element* nastepny;
};

element* dodaj(int liczba1, int liczba2, element* koniec)
{
    element* wsk;
    wsk = new element;
    wsk->wartosc1 = liczba1;
    wsk->wartosc2 = liczba2;
    wsk->nastepny = NULL;
    if (koniec) koniec->nastepny = wsk;

    return wsk;
}
element* usun(int* liczba1,int* liczba2, element* poczatek)
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
    else return NULL;

}