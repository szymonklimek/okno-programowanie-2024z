#include <iostream>
#include <iomanip>
using namespace std;

struct Student
{
    char inicjalImienia;
    char inicjalNazwiska;
    double ocena;
};

int main()
{
    const int w = 5;
    const int k = 5;
    const int G = 25;

    srand(time(0));

    // 1. & 2.
    struct Student student[w][k];
    for (int i = 0; i < w; i++)
    {
        for (int j = 0; j < k; j++)
        {
            student[i][j].inicjalImienia = 'A' + rand() % ('Z' + 1 - 'A');
            student[i][j].inicjalNazwiska = 'A' + rand() % ('Z' + 1 - 'A');
            student[i][j].ocena = (double)G * rand() / double(RAND_MAX);
            cout << student[i][j].inicjalImienia << student[i][j].inicjalNazwiska << fixed << setprecision(2) << setw(6) << student[i][j].ocena << " ";
        }
        cout << endl;
    }

    cout << endl;

    // 3.
    for (int wiersz = 0; wiersz < k; wiersz++)
    {
        bool czyPrzesunac = student[wiersz][0].inicjalImienia == 'A' || student[wiersz][0].inicjalImienia == 'B';
        if (czyPrzesunac)
        {
            struct Student pierwszyStudent = student[wiersz][0];
            for (int kolumna = 0; kolumna < k; kolumna++)
            {
                if (kolumna == k - 1)
                {
                    // Ostatnia kolumna ma przydzieloną wartość z pierwszej
                    student[wiersz][kolumna] = pierwszyStudent;
                }
                else
                {
                    student[wiersz][kolumna] = student[wiersz][kolumna + 1];
                }
            }
        }
    }

    // 4.
    for (int i = 0; i < w; i++)
    {
        for (int j = 0; j < k; j++)
        {
            cout << student[i][j].inicjalImienia << student[i][j].inicjalNazwiska << fixed << setprecision(2) << setw(6) << student[i][j].ocena << " ";
        }
        cout << endl;
    }

    // 4.
    return 0;
}
