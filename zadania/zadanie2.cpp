#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    const int D = 5;

    // Na starcie zmienna jest ustawiona na INT_MIN, tak aby podane liczby mogłby być tylko większe (lub równe) od niej
    int najwieksza_liczba_ujemna = INT_MIN;
    // Dodatkowa flaga potrzebna do pokrycia przypadku gdy użytkownik poda liczbę odpowiadającą INT_MIN
    bool czyWczytanoLiczbeUjemna = false;

    int suma_liczb_dwucyfrowych_ujemnych = 0;

    int licznik_wczytanych_liczb_dwucyfrowych_ujemnych = 0;
    int licznik_wczytanych_liczb_wiekszych_od_poprzedniej = 0;

    bool czyWczytanoLiczbe = false;
    int liczba = -1;

    while (liczba % D != 0 || liczba % 2 != 0)
    {
        int poprzednia_liczba = liczba;

        cout << "Podaj liczbe: ";
        cin >> liczba;
        czyWczytanoLiczbe = true;

        if (czyWczytanoLiczbe && liczba > poprzednia_liczba)
        {
            licznik_wczytanych_liczb_wiekszych_od_poprzedniej++;
        }

        if (liczba < -9 && liczba > -100)
        {
            licznik_wczytanych_liczb_dwucyfrowych_ujemnych++;
            suma_liczb_dwucyfrowych_ujemnych += liczba;
        }

        if (liczba < 0 && liczba > najwieksza_liczba_ujemna)
        {
            czyWczytanoLiczbeUjemna = true;
            najwieksza_liczba_ujemna = liczba;
        }
    }

    if (!czyWczytanoLiczbeUjemna)
    {
        cout << "Nie podano żadnej liczby ujemnej" << endl;
    }
    else
    {
        cout << "Najwieksza liczba ujemna: " << najwieksza_liczba_ujemna << endl;
    }

    cout << "Suma liczb dwucyfrowych ujemnych: " << suma_liczb_dwucyfrowych_ujemnych << endl;
    if (licznik_wczytanych_liczb_dwucyfrowych_ujemnych > 0)
    {
        cout << "Średnia liczb dwucyfrowych ujemnych: " << (double)suma_liczb_dwucyfrowych_ujemnych / licznik_wczytanych_liczb_dwucyfrowych_ujemnych << endl;
    }
    else
    {
        cout << "Nie podano żadnej liczby dwucyfrowej ujemnej, nie można wyliczyć z nich średniej" << endl;
    }
    return 0;
}
