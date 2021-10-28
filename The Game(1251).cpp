#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <iomanip>
#include <string>
#include <cstring>
#include <Windows.h>
using namespace std;

void Show_map_comp(int* field_comp_ship, int* field_comp_move)
{
	int n = 10;
	cout << " \n\t\t\tС О П Е Р Н И К " << endl << endl;
	cout << "      А Б В Г Д Е Ж З И К " << setw(40) << "      А Б В Г Д Е Ж З И К " << endl;
	cout << "     ######################" << setw(40) << "     ######################";
	cout << endl;
	//проверка на экране
	for (int i = 0; i < n; i++)
	{
		cout << setw(3) << i + 1 << "  #";

		for (int j = 0; j < n; j++)
		{

			if (field_comp_ship[i * 10 + j] == 0)
			{
				cout << "\x1b[36m-\x1b[0m" << " ";
			}
			if (field_comp_ship[i * 10 + j] == 1)
			{
				cout << "%" << " ";// "\x1b[32m%\x1b[0m"
			}
			if (field_comp_ship[i * 10 + j] == 2)
			{
				cout << "\x1b[31mX\x1b[0m" << " ";// "\x1b[32m%\x1b[0m"
			}
			if (field_comp_ship[i * 10 + j] == 3)
			{
				cout << "\x1b[32m#\x1b[0m" << " ";// "\x1b[32m%\x1b[0m"
			}
		}
		cout << "#";
		//
		cout << setw(16) << i + 1 << "  #";
		for (int j = 0; j < n; j++)
		{

			if (field_comp_move[i * 10 + j] == 0)
			{
				cout << "\x1b[36m-\x1b[0m" << " ";
			}
			if (field_comp_move[i * 10 + j] == 1)
			{
				cout << "%" << " ";
			}
			if (field_comp_move[i * 10 + j] == 2)
			{
				cout << "\x1b[31mX\x1b[0m" << " ";// "\x1b[32m%\x1b[0m"
			}
			if (field_comp_move[i * 10 + j] == 3)
			{
				cout << "\x1b[32m#\x1b[0m" << " ";// "\x1b[32m%\x1b[0m"
			}
		}
		cout << "#";

		cout << endl;
	}
	cout << "     ######################" << setw(40) << "     ######################";
}

void Show_map_player(int* field_player_ship, int* field_player_move)
{
	int n = 10;
	cout << "\n\n\t\t\t И Г Р О К" << endl << endl;

	cout << "      А Б В Г Д Е Ж З И К " << setw(40) << "      А Б В Г Д Е Ж З И К " << endl;
	cout << "     ######################" << setw(40) << "     ######################";
	cout << endl;
	//проверка на экране
	for (int i = 0; i < n; i++)
	{
		cout << setw(3) << i + 1 << "  #";
		for (int j = 0; j < n; j++)
		{

			if (field_player_ship[i * 10 + j] == 0)
			{
				cout << "\x1b[36m-\x1b[0m" << " ";
			}
			if (field_player_ship[i * 10 + j] == 1)
			{
				cout << "%" << " ";
			}
			if (field_player_ship[i * 10 + j] == 2)
			{
				cout << "\x1b[31mX\x1b[0m" << " ";// "\x1b[32m%\x1b[0m"
			}
			if (field_player_ship[i * 10 + j] == 3)
			{
				cout << "\x1b[32m#\x1b[0m" << " ";// "\x1b[32m%\x1b[0m"
			}
		}
		cout << "#";

		//начало отрисовки поля сопреника
		cout << setw(16) << i + 1 << "  #";
		for (int j = 0; j < n; j++)
		{

			if (field_player_move[i * 10 + j] == 0)
			{
				cout << "\x1b[36m-\x1b[0m" << " ";
			}
			if (field_player_move[i * 10 + j] == 1)
			{
				cout << "%" << " ";
			}
			if (field_player_move[i * 10 + j] == 2)
			{
				cout << "\x1b[31mX\x1b[0m" << " ";// "\x1b[32m%\x1b[0m"
			}
			if (field_player_move[i * 10 + j] == 3)
			{
				cout << "\x1b[32m#\x1b[0m" << " ";// "\x1b[32m%\x1b[0m"
			}
		}
		cout << "#";
		cout << endl;
	}
	cout << "     ######################" << setw(40) << "     ######################";

}

const int n = 10;
int field_comp_ship[n * n] = {  }; // поле 10х10 
int field_comp_move[n * n] = {  };
int field_player_ship[n * n] = {  };
int field_player_move[n * n] = {  };
int x, y;
string coordinates;
int move_count = 0;
extern string attack, defender;
string attack = "player";
string defender = "comp";
void Shoot()
{
	bool good_x = false, good_y = false;
	extern int x;
	extern int y;
	extern int move_count;
	extern string attack;
	extern string defender;
	while (!good_x || !good_y)
	{
		system("cls");
		Show_map_comp(field_comp_ship, field_comp_move);
		Show_map_player(field_player_ship, field_player_move);
		cout << endl << endl;
		cout << "Сделано ходов: " << move_count << endl;

		if (attack == "player") {

			cout << "Ввести координаты: ";
			cin >> coordinates;
		}
		else if (attack == "comp")
		{
			//генерировать ход противника
			char coord_comp[] = "абвгдежзик";
			coordinates = coord_comp[rand() % 10] + (to_string(rand() % 10));
		}

		switch (coordinates[0])
		{
		case 'а':
		case 'А':
			x = 1;
			good_x = true;
			break;
		case 'б':
		case 'Б':
			good_x = true;
			x = 2;
			break;
		case 'в':
		case 'В':
			good_x = true;
			x = 3;
			break;
		case 'г':
		case 'Г':
			good_x = true;
			x = 4;
			break;
		case 'д':
		case 'Д':
			x = 5;
			good_x = true;
			break;
		case 'е':
		case 'Е':
			good_x = true;
			x = 6;
			break;
		case 'ж':
		case 'Ж':
			good_x = true;
			x = 7;
			break;
		case 'з':
		case 'З':
			good_x = true;
			x = 8;
			break;
		case 'и':
		case 'И':
			good_x = true;
			x = 9;
			break;
		case 'к':
		case 'К':
			good_x = true;
			x = 10;
			break;
		default:
			break;
		}
		if (!good_x)
			break;
		coordinates.erase(0, 1);
		y = stoi(coordinates);
		if (y >= 1 && y <= 10)
		{
			good_y = true;
			int* own_field, * enemy_field;
			if (attack == "comp")
			{
				own_field = field_comp_move;
				enemy_field = field_player_ship;
			}
			else if (attack == "player")
			{
				own_field = field_player_move;
				enemy_field = field_comp_ship;
			}
			if (own_field[(y - 1) * 10 + (x - 1)] == 0)
			{
				if (enemy_field[(y - 1) * 10 + (x - 1)] == 1)
				{
					own_field[(y - 1) * 10 + (x - 1)] = 2;
					enemy_field[(y - 1) * 10 + (x - 1)] = 2;
					cout << "Попал!!!";
					Sleep(2000);
					break;
				}
				if (enemy_field[(y - 1) * 10 + (x - 1)] == 0)
				{
					own_field[(y - 1) * 10 + (x - 1)] = 3;
					enemy_field[(y - 1) * 10 + (x - 1)] = 3;
					cout << "МИМО!!!";
					swap(attack, defender);
					Sleep(2000);
					break;
				}
			}
			if ((own_field[(y - 1) * 10 + (x - 1)] == 2) || (own_field[(y - 1) * 10 + (x - 1)] == 3))
			{
				cout << "УЖЕ СТРЕЛЯЛ ТУДА!!!";
				Sleep(2000);
				break;
			}
		}
		if (!good_y)
			break;
	}
	move_count++;
}


void PositionOfShip(int* field, int cntShip, int Deck)
{
	int x, y, n = 10;
	int way = 0;
	int count_ship = 0;
	int deck;
	while (count_ship < cntShip)
	{
		x = rand() % n;
		y = rand() % n;
		int x_temp = x;
		int y_temp = y;
		//проверка возможности постановки корабля
		way = rand() % 4;
		bool ship_stay = true;
		for (int i = 0; i < Deck; i++)
		{
			if (x < 0 || y < 0 || x >= n || y >= n)
			{
				ship_stay = false;
				break;
			}
			if (field[x * 10 + y] == 1 ||  // проверка девяти клеток вокруг
				field[(x - 1) * 10 + y + 1] == 1 ||
				field[x * 10 + y + 1] == 1 ||
				field[(x + 1) * 10 + y + 1] == 1 ||
				field[(x + 1) * 10 + y] == 1 ||
				field[(x + 1) * 10 + y - 1] == 1 ||
				field[x * 10 + y - 1] == 1 ||
				field[(x - 1) * 10 + y - 1] == 1 ||
				field[(x - 1) * 10 + y] == 1)
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
			x = x_temp;
			y = y_temp;
			for (int i = 0; i < Deck; i++)
			{
				switch (way)
				{
				case (0):
					field[x * 10 + y] = 1;
					x++;
					break;
				case (1):
					field[x * 10 + y] = 1;
					y++;
					break;
				case (2):
					field[x * 10 + y] = 1;
					x--;
					break;
				case (3):
					field[x * 10 + y] = 1;
					y--;
					break;
				}
			}
			count_ship++;
		}
	}
}



int main(void)
{
	srand((unsigned)time(NULL));
	setlocale(LC_ALL, "Rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	
	//заполнение кораблями поля соперника (рандом)
	PositionOfShip(field_comp_ship, 1, 4);
	PositionOfShip(field_comp_ship, 2, 3);
	PositionOfShip(field_comp_ship, 3, 2);
	PositionOfShip(field_comp_ship, 4, 1); // (поле, кол-во кораблей, кол-во палуб)
	//заполнение кораблями поля игрока (рандом)
	PositionOfShip(field_player_ship, 1, 4);
	PositionOfShip(field_player_ship, 2, 3);
	PositionOfShip(field_player_ship, 3, 2);
	PositionOfShip(field_player_ship, 4, 1); // (поле, кол-во кораблей, кол-во палуб)

	while (true)
	{
		Shoot();
	}

	system("pause>nul");
	return 0;
}

