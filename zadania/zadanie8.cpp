#include <iostream>
#include <iomanip>
using namespace std;

const int MaxO = 6;
const int n = 5;

struct Student
{
    char inicjalImienia;
    char inicjalNazwiska;
    int ocena;
};

int funkcja1(struct Student student[n], double& srednia)
{
    double suma = 0;
    int najwyzszaOcena = 0;

    cout << "Grupa studentów: ";
    for (int i = 0; i < n; i++)
    {
        student[i].inicjalImienia = 'A' + rand() % ('Z' + 1 - 'A');
        student[i].inicjalNazwiska = 'A' + rand() % ('Z' + 1 - 'A');
        int ocena = rand() % MaxO;
        student[i].ocena = ocena;
        suma += ocena;
        if (ocena > najwyzszaOcena)
        {
            najwyzszaOcena = ocena;
        }
        cout << endl;
        cout << student[i].inicjalImienia << student[i].inicjalNazwiska << fixed << setprecision(2) << setw(6) << student[i].ocena << " ";

    }
    cout << endl;
    srednia = suma / n;
    return najwyzszaOcena;
}

int main()
{
    srand(time(0));
    struct Student G1[n];
    struct Student G2[n];

    double sredniaG1 = 0;
    double sredniaG2 = 0;
    int najwyzszaOcena1 = funkcja1(G1, sredniaG1);
    int najwyzszaOcena2 = funkcja1(G2, sredniaG2);

    cout << "Srednia ocen grupy 1: " << sredniaG1 << endl;
    cout << "Srednia ocen grupy 2: " << sredniaG2 << endl;
    cout << "Najwyzsza ocena grupy 1: " << najwyzszaOcena1 << endl;
    cout << "Najwyzsza ocena grupy 2: " << najwyzszaOcena2 << endl;
    cout << endl;
    return 0;
}
