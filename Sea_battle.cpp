#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <iomanip>
#include <string>
#include <Windows.h>
using namespace std;
int main(void)
{
    srand((unsigned)time(NULL));
    setlocale(LC_ALL, "Rus");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    const int n = 10;
    int field[n][n] = { 0 }; // поле 10х10
    int x, y;              // координаты корабля
    int way = 0;
    x = rand() % n;
    y = rand() % n;
    bool ship_stay = true;
    //проверка возможности постановки корабля
    way = rand() % 4;
    for (int i = 0; i < 4; i++)
    {
        if (field[x][y] == 1 ||  // проверка девяти клеток вокруг
            field[x - 1][y + 1] == 1 ||
            field[x][y + 1] == 1 ||
            field[x + 1][y + 1] == 1 ||
            field[x + 1][y] == 1 ||
            field[x + 1][y - 1] == 1 ||
            field[x][y - 1] == 1 ||
            field[x - 1][y - 1] == 1 ||
            field[x - 1][y] == 1)
        {
            ship_stay = false;
            break;
        }
        switch (way)
        {
        case (0):
            x++;
            break;
        case (1):
            y++;
            break;
        case (2):
            x--;
            break;
        case (3):
            y--;
            break;        
        }
    }
    //если есть возможность поставить корабль ставим его
    if (ship_stay == true)
    {
        for (int i = 0; i < 4; i++)
        {
            switch (way)
            {
            case (0):
                field[x][y] = 1;
                x++;
                break;
            case (1):
                field[x][y] = 1;
                y++;
                break;
            case (2):
                field[x][y] = 1;
                x--;
                break;
            case (3):
                field[x][y] = 1;
                y--;
                break;
            }
        }
    }


















        //проверка на экране
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (field[i][j] == 0)
                {
                    cout << '-'<< " ";
                }
                else 
                {
                    cout << field[i][j] << " ";
                }
            }
            cout << endl;
        }
        system("pause>nul");

    




    system("pause>nul");
    return 0;
}

