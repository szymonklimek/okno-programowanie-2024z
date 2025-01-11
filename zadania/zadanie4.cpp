#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    const int w = 8;
    const int k = 4;
    const int Sz = 10;
    double tab[w][k];
    double sumaZKolumny[k] = {0};

    srand(time(0));
    // 1. & 2.
    for (int i = 0; i < w; i++)
    {
        for (int j = 0; j < k; j++)
        {
            // Losowanie liczby z przedziału <0, 5>
            tab[i][j] = (double)5 * rand() / double(RAND_MAX);
            cout << fixed << setprecision(1) << setw(Sz) << tab[i][j];

            sumaZKolumny[j] += tab[i][j];
        }
        cout << endl;
    }

    // 3.
    double najwyzszaSrednia = 0;
    int numerKolumnyNajwyzszaSrednia = 0;

    for (int i = 0; i < k; i++)
    {
        double sredniaZKolumny = sumaZKolumny[i] / w;
        cout << fixed << setprecision(2) << setw(Sz) << sredniaZKolumny;
        if (sredniaZKolumny > najwyzszaSrednia)
        {
            najwyzszaSrednia = sredniaZKolumny;
            numerKolumnyNajwyzszaSrednia = i;
        }
    }
    cout << endl;

//    cout << "Najwyzsza srednia: " << najwyzszaSrednia << " w kolumnie " << numerKolumnyNajwyzszaSrednia << endl;

    cout << endl;

    // 4. & 5.
    for (int i = 0; i < w; i++)
    {
        for (int j = 0; j < k; j++)
        {
            int indexKolumnyDoDrukowania = j;
            if (j == numerKolumnyNajwyzszaSrednia)
            {
                indexKolumnyDoDrukowania = k - 1;
            }
            else if (j == k - 1)
            {
                indexKolumnyDoDrukowania = numerKolumnyNajwyzszaSrednia;
            }

            cout << fixed << setprecision(1) << setw(Sz) << tab[i][indexKolumnyDoDrukowania];
        }
        cout << endl;
    }

    return 0;
}
