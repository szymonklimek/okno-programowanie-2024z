#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

int main()
{
    const int n = 5;
    double A[n][n] = {};
    double x = 3.5;
    int M = 2;
    int D = 7;

    // 1.
    string nazwaPliku;
    cout << "Podaj nazwe pliku: ";
    cin >> nazwaPliku;

    ifstream plik;
    plik.open(nazwaPliku);
    if (!plik.is_open())
    {
        cout << "Nie udalo sie otworzyc pliku." << endl;
        return 1;
    }

    int wartosciBrakujace = 0;

    for (int wiersz = 0; wiersz < n; wiersz++)
    {
        for (int kolumna = 0; kolumna < n; kolumna++)
        {
            if (!plik.eof())
            {
                plik >> A[wiersz][kolumna];
            }
            else
            {
                wartosciBrakujace++;
                A[wiersz][kolumna] = x;
            }
        }
    }
    plik.close();
    cout << "Wartości brakujące w pliku: " << wartosciBrakujace << endl;

    // 2.
    for (int wiersz = 0; wiersz < n; wiersz++)
    {
        for (int kolumna = 0; kolumna < n; kolumna++)
        {
            cout << fixed << setprecision(M) << setw(D) << A[wiersz][kolumna];
        }
        cout << endl;
    }

    // 3.
    double najwiekszaLiczbaZGlownejPrzekatnej = A[0][0];
    int indeksNajwiekszejLiczbyZGlownejPrzekatnej = 0;
    for (int i = 0; i < n; i++)
    {
        if (A[i][i] > najwiekszaLiczbaZGlownejPrzekatnej)
        {
            najwiekszaLiczbaZGlownejPrzekatnej = A[i][i];
            indeksNajwiekszejLiczbyZGlownejPrzekatnej = i;
        }
    }

    double najmniejszaLiczbaZDrugiejPrzekatnej = A[0][n - 1];
    for (int i = 0; i < n; i++)
    {
        if (A[i][n - 1 - i] < najmniejszaLiczbaZDrugiejPrzekatnej)
        {
            najmniejszaLiczbaZDrugiejPrzekatnej = A[i][n - 1 - i];
        }
    }

    for (int i = 0; i < n; i++)
    {
        A[indeksNajwiekszejLiczbyZGlownejPrzekatnej][i] = najwiekszaLiczbaZGlownejPrzekatnej;
        A[i][indeksNajwiekszejLiczbyZGlownejPrzekatnej] = najwiekszaLiczbaZGlownejPrzekatnej;
    }
    A[indeksNajwiekszejLiczbyZGlownejPrzekatnej][indeksNajwiekszejLiczbyZGlownejPrzekatnej] = najmniejszaLiczbaZDrugiejPrzekatnej;

    // 4.
    cout << endl;
    for (int wiersz = 0; wiersz < n; wiersz++)
    {
        for (int kolumna = 0; kolumna < n; kolumna++)
        {
            cout << fixed << setprecision(M) << setw(D) << A[wiersz][kolumna];
        }
        cout << endl;
    }

    // 5.
    ofstream plikWyjsciowy;
    plikWyjsciowy.open("coDrugi.txt");
    for (int wiersz = 1; wiersz < n; wiersz += 2)
    {
        for (int kolumna = 0; kolumna < n; kolumna++)
        {
            plikWyjsciowy << fixed << setprecision(M) << setw(D) << A[wiersz][kolumna];
        }
        plikWyjsciowy << endl;
    }
    plikWyjsciowy.close();
    return 0;
}
