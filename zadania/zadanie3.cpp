#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    const int D = 5;
    const int G = 10;
    const int N = 4;

    // 1.
    int k;
    do
    {
        cout << "Podaj liczbe: ";
        cin >> k;
    } while (k < D || k > G);

    // 2.
    int liczbaNapisowZaczynajacychSieWielkaLitera = 0;
    for (int i = 0; i < k; i++)
    {
        string napis;
        cout << "Wprowadz napis: ";
        cin >> napis;
        if (napis.size() > 0 && isupper(napis[0]))
        {
            liczbaNapisowZaczynajacychSieWielkaLitera++;
        }
    }
    cout << "Liczba napisów zaczynających się wielką literą: " << liczbaNapisowZaczynajacychSieWielkaLitera << endl;

    // 3.
    double suma = 0;
    double liczby[N];
    for (int i = 0; i < N; i++)
    {
        cout << "Podaj liczbe rzeczywista: ";
        cin >> liczby[i];
        suma += liczby[i];
    }
    double srednia = suma / N;
    cout << "Średnia arytmetyczna: " << srednia << endl;

    int liczbaWiekszychOdSredniej = 0;
    for (int i = 0; i < N; i++)
    {
        if (liczby[i] > srednia)
        {
            liczbaWiekszychOdSredniej++;
        }
    }
    cout << "Liczba większych od średniej: " << liczbaWiekszychOdSredniej << endl;
    return 0;
}
