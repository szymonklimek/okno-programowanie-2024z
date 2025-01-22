#include <iostream>
#include <iomanip>
using namespace std;

const int w = 5;
const int k = 5;

void wylosujZnaki(char znakOd, char znakDo, char tablica[w][k])
{
  for (int i = 0; i < w; i++)
  {
    for (int j = 0; j < k; j++)
    {
      char znak = znakOd + rand() % (znakDo + 1 - znakOd);
      tablica[i][j] = znak;
    }
  }
}

void wydrukujTablice(char tablica[w][k])
{
  for (int i = 0; i < w; i++)
  {
    for (int j = 0; j < k; j++)
    {
      cout << tablica[i][j] << " ";
    }
    cout << endl;
  }
}

void uzupelnijZnakGdyBrakZnakuWeWierszu(char tablice[w][k], char znakOczekiwany, char znakZastepujacy)
{
  for (int i = 0; i < w; i++)
  {
    bool czyZnakJest = false;
    for (int j = 0; j < k; j++)
    {
      if (tablice[i][j] == znakOczekiwany)
      {
        czyZnakJest = true;
      }
    }
    if (!czyZnakJest)
    {
      for (int j = 0; j < k; j++)
      {
        tablice[i][j] = znakZastepujacy;
      }
    }
  }
}

int main()
{
  srand(time(0));
  char Li[w][k] = {};
  char Cy[w][k] = {};

  // 1.
  wylosujZnaki('A', 'Z', Li);
  wylosujZnaki('0', '9', Cy);
  wydrukujTablice(Li);
  cout << endl;
  wydrukujTablice(Cy);
  cout << endl;

  // 2.
  uzupelnijZnakGdyBrakZnakuWeWierszu(
      Li,
      'P', // znak oczekiwany
      '%'  // znak zastępujący
  );

  uzupelnijZnakGdyBrakZnakuWeWierszu(
      Cy,
      '5', // znak oczekiwany
      '&'  // znak zastępujący
  );

  // 3.
  wydrukujTablice(Li);
  cout << endl;
  wydrukujTablice(Cy);
  return 0;
}
