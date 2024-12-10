#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    // 1.
    string imie;
    cout << "Podaj swoje imie: ";
    cin >> imie;

    // 2.
    cout << "Witaj, " << imie << "!" << endl;

    // 3.
    int xA, yA, xB, yB, xC, yC;
    cout << "Podaj wspolrzedne punktu A: " << endl;
    cin >> xA >> yA;
    cout << "Podaj wspolrzedne punktu B: " << endl;
    cin >> xB >> yB;
    cout << "Podaj wspolrzedne punktu C: " << endl;
    cin >> xC >> yC;

    // 4.
    cout << "Punkty A(" << xA << ", " << yA << "), B(" << xB << ", " << yB << "), C(" << xC << ", " << yC << ")" << endl;
    if (
        (xA == xB && yA == yB) ||
        (xA == xC && yA == yC) ||
        (xB == xC && yB == yC))
    {
        cout << "Punkty mają te same współrzędne" << endl;
        return 1;
    }

    // 4.2.
    double pole = double(abs((xB - xA) * (yC - yA) - (yB - yA) * (xC - xA))) / 2;
    if (pole == 0)
    {
        cout << "Punkty są współliniowe." << endl;
        return 1;
    }

    cout << "Pole trójkąta: " << pole << endl;

    // 4.1.
    double bokA = sqrt(pow(xB - xA, 2) + pow(yB - yA, 2));
    double bokB = sqrt(pow(xC - xB, 2) + pow(yC - yB, 2));
    double bokC = sqrt(pow(xA - xC, 2) + pow(yA - yC, 2));
    cout << "Długości boków: A = " << bokA << ", B = " << bokB << ", C = " << bokC << endl;

    double obwod = bokA + bokB + bokC;
    cout << "Obwód trójkąta: " << obwod << endl;

    // 4.3.
    double srodekX = (xA + xB + xC) / 3;
    double srodekY = (yA + yB + yC) / 3;
    cout << "Współrzędne środka ciężkości: (" << srodekX << ", " << srodekY << ")" << endl;

    // 4.4.
    double polowaObwodu = obwod / 2;
    double promienWpisany = sqrt((polowaObwodu - bokA) * (polowaObwodu - bokB) * (polowaObwodu - bokC) / polowaObwodu);
    double promienOpisany = bokA * bokB * bokC / (4 * promienWpisany * ((bokA + bokB + bokC) / 2));
    cout << "Promień okręgu opisanego: " << promienOpisany << endl;
    return 0;
}
