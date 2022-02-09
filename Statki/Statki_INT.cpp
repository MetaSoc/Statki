#include<iostream>
#include<random>    //mt19937
#include<windows.h> //Sleep, HideCursor
#include<string>    //getline
#include<conio.h>   //_getch
using namespace std;
// \206 - ć  \210 - ł  \230 - ś  \242 - ó  \245 - ą  \251 - ę  \253 - ź  \276 - ż  \344 - ń

string _gracz1 = "GRACZ1", _gracz2 = "GRACZ2"; char _nic; bool _napisStatki, _doGry, _zas = 1, _nazwy_niepodane = 1; int _runda, _licznik1, _licznik2;

#pragma region GENERATOR
random_device r;
mt19937 generator(r());
uniform_int_distribution<int> pole(0, 9);
uniform_int_distribution<int> kier(1, 2); //    1 poziomy    2 pionowy
#pragma endregion GENERATOR

#pragma region DEKLARACJE PLANSZ
int twoja_plansza1[10][10]{};
int twoja_plansza2[10][10]{};
int plansza_przeciwnika1[10][10]{};
int plansza_przeciwnika2[10][10]{};
#pragma endregion DEKLARACJE PLANSZ

#pragma region DEKLARACJE FUNCKJI
void ladowanie(); void napis_statki();
void CursPos(int, int); void ShowConsoleCursor(bool showFlag);
void menu(); void gra(); void zasady();
void statek4(int[10][10]); void statek3(int[10][10]);
void statek2(int[10][10]); void statek1(int[10][10]);
void losowanie_twoja_plansza1(); void losowanie_twoja_plansza2();
void strzal_gracza();
#pragma endregion DEKLARACJE FUNCKJI

int main()
{
	#pragma region ladowanie() i menu()
	ladowanie();
menu:
	menu();
	#pragma endregion ladowanie() i menu()

	#pragma region LOSOWANIE PLANSZ
	losowanie_twoja_plansza1();
	losowanie_twoja_plansza2();
	#pragma endregion LOSOWANIE PLANSZ

	ShowConsoleCursor(0);

	while (_licznik1 < 50 && _licznik2 < 50)
		strzal_gracza();

	ShowConsoleCursor(0);
	if (_licznik1 == 50)
	{
		system("cls");
		Sleep(500);
		#pragma region NAPIS "WYGRYWA GRACZ GRACZ1!"
		cout << "\n\n  W"; Sleep(10); cout << "Y"; Sleep(10); cout << "G"; Sleep(10); cout << "R"; Sleep(10); cout << "Y"; Sleep(10); cout << "W"; Sleep(10); cout << "A"; Sleep(10); cout << " "; Sleep(10); cout << "G"; Sleep(10); cout << "R"; Sleep(10); cout << "A"; Sleep(10); cout << "C"; Sleep(10); cout << "Z"; Sleep(10); cout << " "; Sleep(10);
		for (int i = 0; i < _gracz1.size(); i++)
		{
			if (_gracz1[i] >= 97 && _gracz1[i] <= 122)
			{
				cout << (char)(_gracz1[i] - 32);
				Sleep(10);
			}
			else
			{
				cout << _gracz1[i];
				Sleep(10);
			}
		}
		cout << "!";
		#pragma endregion NAPIS "WYGRYWA GRACZ GRACZ1!"
		Sleep(2000);
	}
	if (_licznik2 == 50)
	{
		system("cls");
		Sleep(500);
		#pragma region NAPIS "WYGRYWA GRACZ GRACZ2!"
		cout << "\n\n  W"; Sleep(10); cout << "Y"; Sleep(10); cout << "G"; Sleep(10); cout << "R"; Sleep(10); cout << "Y"; Sleep(10); cout << "W"; Sleep(10); cout << "A"; Sleep(10); cout << " "; Sleep(10); cout << "G"; Sleep(10); cout << "R"; Sleep(10); cout << "A"; Sleep(10); cout << "C"; Sleep(10); cout << "Z"; Sleep(10); cout << " "; Sleep(10);
		for (int i = 0; i < _gracz2.size(); i++)
		{
			if (_gracz2[i] >= 97 && _gracz2[i] <= 122)
			{
				cout << (char)(_gracz2[i] - 32);
				Sleep(10);
			}
			else
			{
				cout << _gracz2[i];
				Sleep(10);
			}
		}
		cout << "!";
		#pragma endregion NAPIS "WYGRYWA GRACZ GRACZ2!"
		Sleep(2000);
	}

	#pragma region NAPIS " Co chcesz teraz zrobić? Wybierz jedną z opcji, wpisując odpowiednią cyfrę: "
	cout << "\n\n C"; Sleep(10); cout << "o"; Sleep(10); cout << " "; Sleep(10); cout << "c"; Sleep(10); cout << "h"; Sleep(10); cout << "c"; Sleep(10); cout << "e"; Sleep(10); cout << "s"; Sleep(10); cout << "z"; Sleep(10); cout << " "; Sleep(10); cout << "t"; Sleep(10); cout << "e"; Sleep(10); cout << "r"; Sleep(10); cout << "a"; Sleep(10); cout << "z"; Sleep(10); cout << " "; Sleep(10); cout << "z"; Sleep(10); cout << "r"; Sleep(10); cout << "o"; Sleep(10); cout << "b"; Sleep(10); cout << "i"; Sleep(10); cout << "\206"; Sleep(10); cout << "?"; Sleep(500); cout << " "; Sleep(10); cout << "W"; Sleep(10); cout << "y"; Sleep(10); cout << "b"; Sleep(10); cout << "i"; Sleep(10); cout << "e"; Sleep(10); cout << "r"; Sleep(10); cout << "z"; Sleep(10); cout << " "; Sleep(10); cout << "j"; Sleep(10); cout << "e"; Sleep(10); cout << "d"; Sleep(10); cout << "n"; Sleep(10); cout << "\245"; Sleep(10); cout << " "; Sleep(10); cout << "z"; Sleep(10); cout << " "; Sleep(10); cout << "o"; Sleep(10); cout << "p"; Sleep(10); cout << "c"; Sleep(10); cout << "j"; Sleep(10); cout << "i"; Sleep(10); cout << ","; Sleep(10); cout << "\n";
	cout << " w"; Sleep(10); cout << "p"; Sleep(10); cout << "i"; Sleep(10); cout << "s"; Sleep(10); cout << "u"; Sleep(10); cout << "j"; Sleep(10); cout << "\245"; Sleep(10); cout << "c"; Sleep(10); cout << " "; Sleep(10); cout << "o"; Sleep(10); cout << "d"; Sleep(10); cout << "p"; Sleep(10); cout << "o"; Sleep(10); cout << "w"; Sleep(10); cout << "i"; Sleep(10); cout << "e"; Sleep(10); cout << "d"; Sleep(10); cout << "n"; Sleep(10); cout << "i"; Sleep(10); cout << "\245"; Sleep(10); cout << " "; Sleep(10); cout << "c"; Sleep(10); cout << "y"; Sleep(10); cout << "f"; Sleep(10); cout << "r"; Sleep(10); cout << "\251"; Sleep(10); cout << ":";
	#pragma endregion NAPIS " MENU Co chcesz teraz zrobić? Wybierz jedną z opcji, wpisując odpowiednią cyfrę: "

	#pragma region NAPIS "1. Rozpocznij nową grę 2. Wyjście"
	Sleep(500);
	CursPos(1, 7); cout << "1"; CursPos(1, 9); cout << "2"; Sleep(20);
	CursPos(2, 7); cout << "."; CursPos(2, 9); cout << "."; Sleep(20);
	CursPos(3, 7); cout << " "; CursPos(3, 9); cout << " "; Sleep(20);
	CursPos(4, 7); cout << "R"; CursPos(4, 9); cout << "W"; Sleep(20);
	CursPos(5, 7); cout << "o"; CursPos(5, 9); cout << "y"; Sleep(20);
	CursPos(6, 7); cout << "z"; CursPos(6, 9); cout << "j"; Sleep(20);
	CursPos(7, 7); cout << "p"; CursPos(7, 9); cout << "\230"; Sleep(20);
	CursPos(8, 7); cout << "o"; CursPos(8, 9); cout << "c"; Sleep(20);
	CursPos(9, 7); cout << "c"; CursPos(9, 9); cout << "i"; Sleep(20);
	CursPos(10, 7); cout << "z"; CursPos(10, 9); cout << "e"; Sleep(20);
	CursPos(11, 7); cout << "n"; Sleep(20);
	CursPos(12, 7); cout << "i"; Sleep(20);
	CursPos(13, 7); cout << "j"; Sleep(20);
	CursPos(14, 7); cout << " "; Sleep(20);
	CursPos(15, 7); cout << "n"; Sleep(20);
	CursPos(16, 7); cout << "o"; Sleep(20);
	CursPos(17, 7); cout << "w"; Sleep(20);
	CursPos(18, 7); cout << "\245"; Sleep(20);
	CursPos(19, 7); cout << " "; Sleep(20);
	CursPos(20, 7); cout << "g"; Sleep(20);
	CursPos(21, 7); cout << "r"; Sleep(20);
	CursPos(22, 7); cout << "\251"; Sleep(20);
	#pragma endregion NAPIS "1. Rozpocznij nową grę 2. Wyjście"

	int wybor_menu{};
	Sleep(500);
wybor:
	CursPos(1, 13);
	ShowConsoleCursor(1);
	wybor_menu = _getch();
	ShowConsoleCursor(0);
	if (wybor_menu >= 48 && wybor_menu <= 57)
		cout << wybor_menu - '0';
	else
		cout << "0";
	Sleep(100);

	switch (wybor_menu)
	{
		case 49:  Sleep(500); goto menu;
			break;
		case 50:  Sleep(500); system("cls"); Sleep(500); cout << "\n W"; Sleep(10); cout << "y"; Sleep(10); cout << "c"; Sleep(10); cout << "h"; Sleep(10); cout << "o"; Sleep(10); cout << "d"; Sleep(10); cout << "z"; Sleep(10); cout << "e"; Sleep(10); cout << "n"; Sleep(10); cout << "i"; Sleep(10); cout << "e"; Sleep(10); cout << " "; Sleep(10); cout << "z"; Sleep(10); cout << " "; Sleep(10); cout << "g"; Sleep(10); cout << "r"; Sleep(10); cout << "y"; Sleep(10); cout << "."; Sleep(20); cout << "."; Sleep(20); cout << "."; for (int i = 0; i < 2; i++) { CursPos(18, 1); Sleep(800); cout << "   "; Sleep(200); CursPos(18, 1); cout << "."; Sleep(20); cout << "."; Sleep(20); cout << "."; } Sleep(500); exit(0);
			break;
		default:  CursPos(1, 11); for (int i = 0; i < 32; i++) cout << " "; Sleep(200); CursPos(1, 11); cout << "N"; Sleep(10); cout << "i"; Sleep(10); cout << "e"; Sleep(10); cout << " "; Sleep(10); cout << "r"; Sleep(10); cout << "o"; Sleep(10); cout << "z"; Sleep(10); cout << "u"; Sleep(10); cout << "m"; Sleep(10); cout << "i"; Sleep(10); cout << "e"; Sleep(10); cout << "m"; Sleep(10); cout << ","; Sleep(10); cout << " "; Sleep(10); cout << "s"; Sleep(10); cout << "p"; Sleep(10); cout << "r"; Sleep(10); cout << "\242"; Sleep(10); cout << "b"; Sleep(10); cout << "u"; Sleep(10); cout << "j"; Sleep(10); cout << " "; Sleep(10); cout << "p"; Sleep(10); cout << "o"; Sleep(10); cout << "n"; Sleep(10); cout << "o"; Sleep(10); cout << "w"; Sleep(10); cout << "n"; Sleep(10); cout << "i"; Sleep(10); cout << "e"; Sleep(10); cout << ": "; Sleep(500); CursPos(1, 13); cout << " "; goto wybor;
			break;
	}

	return(0);
}

#pragma region FUNKCJE
void ladowanie()
{
	unsigned char kr = 0x16;
	ShowConsoleCursor(0);

	Sleep(700);
	napis_statki();

	system("cls");
	Sleep(50);

	napis_statki();
	Sleep(400);

	cout << "             [";
	for (int i = 0; i < 43; i++)
		cout << " ";
	cout << "]\n  ";
	Sleep(780);
	system("cls");

	napis_statki();
	cout << "             [";
	for (int i = 0; i < 6; i++)
		cout << kr;
	for (int i = 0; i < 37; i++)
		cout << " ";
	cout << "]\n  ";
	Sleep(336);
	system("cls");

	napis_statki();
	cout << "             [";
	for (int i = 0; i < 17; i++)
		cout << kr;
	for (int i = 0; i < 26; i++)
		cout << " ";
	cout << "]\n  ";
	Sleep(192);
	system("cls");

	napis_statki();
	cout << "             [";
	for (int i = 0; i < 23; i++)
		cout << kr;
	for (int i = 0; i < 20; i++)
		cout << " ";
	cout << "]\n  ";
	Sleep(576);
	system("cls");

	napis_statki();
	cout << "             [";
	for (int i = 0; i < 33; i++)
		cout << kr;
	cout << "          ]\n  ";
	Sleep(240);
	system("cls");

	napis_statki();
	cout << "             [";
	for (int i = 0; i < 38; i++)
		cout << kr;
	cout << "     ]\n  ";
	Sleep(96);
	system("cls");

	napis_statki();
	cout << "             [";
	for (int i = 0; i < 42; i++)
		cout << kr;
	cout << " ]\n  ";
	Sleep(720);
	system("cls");

	napis_statki();
	cout << "             [";
	for (int i = 0; i < 43; i++)
		cout << kr;
	cout << "]\n  ";
	Sleep(1000);
}

void napis_statki()
{
	// NAPIS
	if (_napisStatki)
	{
		cout << endl;
		cout << "             °ŰŰŰŰŰŰ»ŰŰŰŰŰŰŰŰ»°ŰŰŰŰŰ»°ŰŰŰŰŰŰŰŰ»ŰŰ»°°ŰŰ»ŰŰ»\n";
		cout << "             ŰŰÉÍÍÍÍĽČÍÍŰŰÉÍÍĽŰŰÉÍÍŰŰ»ČÍÍŰŰÉÍÍĽŰŰş°ŰŰÉĽŰŰş\n";
		cout << "             ČŰŰŰŰŰ»°°°°ŰŰş°°°ŰŰŰŰŰŰŰş°°°ŰŰş°°°ŰŰŰŰŰÍĽ°ŰŰş\n";
		cout << "             °ČÍÍÍŰŰ»°°°ŰŰş°°°ŰŰÉÍÍŰŰş°°°ŰŰş°°°ŰŰÉÍŰŰ»°ŰŰş\n";
		cout << "             ŰŰŰŰŰŰÉĽ°°°ŰŰş°°°ŰŰş°°ŰŰş°°°ŰŰş°°°ŰŰş°ČŰŰ»ŰŰş\n";
		cout << "             ČÍÍÍÍÍĽ°°°°ČÍĽ°°°ČÍĽ°°ČÍĽ°°°ČÍĽ°°°ČÍĽ°°ČÍĽČÍĽ\n\n";

	}
	// ŁADOWANIE POCZĄTKOWE
	else if (!_napisStatki)
	{
		#pragma region STATKI
		CursPos(11 + 2, 1); cout << " "; CursPos(11 + 2, 2); cout << "Ű"; CursPos(11 + 2, 3); cout << "Č"; CursPos(11 + 2, 4); cout << " "; CursPos(11 + 2, 5); cout << "Ű"; CursPos(11 + 2, 6); cout << "Č"; Sleep(15);
		CursPos(11 + 3, 1); cout << "Ű"; CursPos(11 + 3, 2); cout << "Ű"; CursPos(11 + 3, 3); cout << "Ű"; CursPos(11 + 3, 4); cout << "Č"; CursPos(11 + 3, 5); cout << "Ű"; CursPos(11 + 3, 6); cout << "Í"; Sleep(15);
		CursPos(11 + 4, 1); cout << "Ű"; CursPos(11 + 4, 2); cout << "É"; CursPos(11 + 4, 3); cout << "Ű"; CursPos(11 + 4, 4); cout << "Í"; CursPos(11 + 4, 5); cout << "Ű"; CursPos(11 + 4, 6); cout << "Í"; Sleep(15);
		CursPos(11 + 5, 1); cout << "Ű"; CursPos(11 + 5, 2); cout << "Í"; CursPos(11 + 5, 3); cout << "Ű"; CursPos(11 + 5, 4); cout << "Í"; CursPos(11 + 5, 5); cout << "Ű"; CursPos(11 + 5, 6); cout << "Í"; Sleep(15);
		CursPos(11 + 6, 1); cout << "Ű"; CursPos(11 + 6, 2); cout << "Í"; CursPos(11 + 6, 3); cout << "Ű"; CursPos(11 + 6, 4); cout << "Í"; CursPos(11 + 6, 5); cout << "Ű"; CursPos(11 + 6, 6); cout << "Í"; Sleep(15);
		CursPos(11 + 7, 1); cout << "Ű"; CursPos(11 + 7, 2); cout << "Í"; CursPos(11 + 7, 3); cout << "Ű"; CursPos(11 + 7, 4); cout << "Ű"; CursPos(11 + 7, 5); cout << "Ű"; CursPos(11 + 7, 6); cout << "Í"; Sleep(15);
		CursPos(11 + 8, 1); cout << "Ű"; CursPos(11 + 8, 2); cout << "Í"; CursPos(11 + 8, 3); cout << "»"; CursPos(11 + 8, 4); cout << "Ű"; CursPos(11 + 8, 5); cout << "É"; CursPos(11 + 8, 6); cout << "Ľ"; Sleep(15);
		CursPos(11 + 9, 1); cout << "»"; CursPos(11 + 9, 2); cout << "Ľ"; CursPos(11 + 9, 3); cout << " "; CursPos(11 + 9, 4); cout << "»"; CursPos(11 + 9, 5); cout << "Ľ"; CursPos(11 + 9, 6); cout << " "; Sleep(300);

		CursPos(11 + 10, 1); cout << "Ű"; CursPos(11 + 10, 2); cout << "Č"; CursPos(11 + 10, 3); cout << " "; CursPos(11 + 10, 4); cout << " "; CursPos(11 + 10, 5); cout << " "; CursPos(11 + 10, 6); cout << " "; Sleep(15);
		CursPos(11 + 11, 1); cout << "Ű"; CursPos(11 + 11, 2); cout << "Í"; CursPos(11 + 11, 3); cout << " "; CursPos(11 + 11, 4); cout << " "; CursPos(11 + 11, 5); cout << " "; CursPos(11 + 11, 6); cout << " "; Sleep(15);
		CursPos(11 + 12, 1); cout << "Ű"; CursPos(11 + 12, 2); cout << "Í"; CursPos(11 + 12, 3); cout << " "; CursPos(11 + 12, 4); cout << " "; CursPos(11 + 12, 5); cout << " "; CursPos(11 + 12, 6); cout << " "; Sleep(15);
		CursPos(11 + 13, 1); cout << "Ű"; CursPos(11 + 13, 2); cout << "Ű"; CursPos(11 + 13, 3); cout << "Ű"; CursPos(11 + 13, 4); cout << "Ű"; CursPos(11 + 13, 5); cout << "Ű"; CursPos(11 + 13, 6); cout << "Č"; Sleep(15);
		CursPos(11 + 14, 1); cout << "Ű"; CursPos(11 + 14, 2); cout << "Ű"; CursPos(11 + 14, 3); cout << "Ű"; CursPos(11 + 14, 4); cout << "Ű"; CursPos(11 + 14, 5); cout << "Ű"; CursPos(11 + 14, 6); cout << "Í"; Sleep(15);
		CursPos(11 + 15, 1); cout << "Ű"; CursPos(11 + 15, 2); cout << "É"; CursPos(11 + 15, 3); cout << "ş"; CursPos(11 + 15, 4); cout << "ş"; CursPos(11 + 15, 5); cout << "ş"; CursPos(11 + 15, 6); cout << "Ľ"; Sleep(15);
		CursPos(11 + 16, 1); cout << "Ű"; CursPos(11 + 16, 2); cout << "Í"; CursPos(11 + 16, 3); cout << " "; CursPos(11 + 16, 4); cout << " "; CursPos(11 + 16, 5); cout << " "; CursPos(11 + 16, 6); cout << " "; Sleep(15);
		CursPos(11 + 17, 1); cout << "Ű"; CursPos(11 + 17, 2); cout << "Í"; CursPos(11 + 17, 3); cout << " "; CursPos(11 + 17, 4); cout << " "; CursPos(11 + 17, 5); cout << " "; CursPos(11 + 17, 6); cout << " "; Sleep(15);
		CursPos(11 + 18, 1); cout << "»"; CursPos(11 + 18, 2); cout << "Ľ"; CursPos(11 + 18, 3); cout << " "; CursPos(11 + 18, 4); cout << " "; CursPos(11 + 18, 5); cout << " "; CursPos(11 + 18, 6); cout << " "; Sleep(300);
		CursPos(11 + 19, 1); cout << " "; CursPos(11 + 19, 2); cout << "Ű"; CursPos(11 + 19, 3); cout << "Ű"; CursPos(11 + 19, 4); cout << "Ű"; CursPos(11 + 19, 5); cout << "Ű"; CursPos(11 + 19, 6); cout << "Č"; Sleep(15);

		CursPos(11 + 20, 1); cout << "Ű"; CursPos(11 + 20, 2); cout << "Ű"; CursPos(11 + 20, 3); cout << "Ű"; CursPos(11 + 20, 4); cout << "Ű"; CursPos(11 + 20, 5); cout << "Ű"; CursPos(11 + 20, 6); cout << "Í"; Sleep(15);
		CursPos(11 + 21, 1); cout << "Ű"; CursPos(11 + 21, 2); cout << "É"; CursPos(11 + 21, 3); cout << "Ű"; CursPos(11 + 21, 4); cout << "É"; CursPos(11 + 21, 5); cout << "ş"; CursPos(11 + 21, 6); cout << "Ľ"; Sleep(15);
		CursPos(11 + 22, 1); cout << "Ű"; CursPos(11 + 22, 2); cout << "Í"; CursPos(11 + 22, 3); cout << "Ű"; CursPos(11 + 22, 4); cout << "Í"; CursPos(11 + 22, 5); cout << " "; CursPos(11 + 22, 6); cout << " "; Sleep(15);
		CursPos(11 + 23, 1); cout << "Ű"; CursPos(11 + 23, 2); cout << "Í"; CursPos(11 + 23, 3); cout << "Ű"; CursPos(11 + 23, 4); cout << "Í"; CursPos(11 + 23, 5); cout << " "; CursPos(11 + 23, 6); cout << " "; Sleep(15);
		CursPos(11 + 24, 1); cout << "Ű"; CursPos(11 + 24, 2); cout << "Ű"; CursPos(11 + 24, 3); cout << "Ű"; CursPos(11 + 24, 4); cout << "Ű"; CursPos(11 + 24, 5); cout << "Ű"; CursPos(11 + 24, 6); cout << "Č"; Sleep(15);
		CursPos(11 + 25, 1); cout << "»"; CursPos(11 + 25, 2); cout << "Ű"; CursPos(11 + 25, 3); cout << "Ű"; CursPos(11 + 25, 4); cout << "Ű"; CursPos(11 + 25, 5); cout << "Ű"; CursPos(11 + 25, 6); cout << "Í"; Sleep(15);
		CursPos(11 + 26, 1); cout << " "; CursPos(11 + 26, 2); cout << "»"; CursPos(11 + 26, 3); cout << "ş"; CursPos(11 + 26, 4); cout << "ş"; CursPos(11 + 26, 5); cout << "ş"; CursPos(11 + 26, 6); cout << "Ľ"; Sleep(300);
		CursPos(11 + 27, 1); cout << "Ű"; CursPos(11 + 27, 2); cout << "Č"; CursPos(11 + 27, 3); cout << " "; CursPos(11 + 27, 4); cout << " "; CursPos(11 + 27, 5); cout << " "; CursPos(11 + 27, 6); cout << " "; Sleep(15);
		CursPos(11 + 28, 1); cout << "Ű"; CursPos(11 + 28, 2); cout << "Í"; CursPos(11 + 28, 3); cout << " "; CursPos(11 + 28, 4); cout << " "; CursPos(11 + 28, 5); cout << " "; CursPos(11 + 28, 6); cout << " "; Sleep(15);
		CursPos(11 + 29, 1); cout << "Ű"; CursPos(11 + 29, 2); cout << "Í"; CursPos(11 + 29, 3); cout << " "; CursPos(11 + 29, 4); cout << " "; CursPos(11 + 29, 5); cout << " "; CursPos(11 + 29, 6); cout << " "; Sleep(15);

		CursPos(11 + 30, 1); cout << "Ű"; CursPos(11 + 30, 2); cout << "Ű"; CursPos(11 + 30, 3); cout << "Ű"; CursPos(11 + 30, 4); cout << "Ű"; CursPos(11 + 30, 5); cout << "Ű"; CursPos(11 + 30, 6); cout << "Č"; Sleep(15);
		CursPos(11 + 31, 1); cout << "Ű"; CursPos(11 + 31, 2); cout << "Ű"; CursPos(11 + 31, 3); cout << "Ű"; CursPos(11 + 31, 4); cout << "Ű"; CursPos(11 + 31, 5); cout << "Ű"; CursPos(11 + 31, 6); cout << "Í"; Sleep(15);
		CursPos(11 + 32, 1); cout << "Ű"; CursPos(11 + 32, 2); cout << "É"; CursPos(11 + 32, 3); cout << "ş"; CursPos(11 + 32, 4); cout << "ş"; CursPos(11 + 32, 5); cout << "ş"; CursPos(11 + 32, 6); cout << "Ľ"; Sleep(15);
		CursPos(11 + 33, 1); cout << "Ű"; CursPos(11 + 33, 2); cout << "Í"; CursPos(11 + 33, 3); cout << " "; CursPos(11 + 33, 4); cout << " "; CursPos(11 + 33, 5); cout << " "; CursPos(11 + 33, 6); cout << " "; Sleep(15);
		CursPos(11 + 34, 1); cout << "Ű"; CursPos(11 + 34, 2); cout << "Í"; CursPos(11 + 34, 3); cout << " "; CursPos(11 + 34, 4); cout << " "; CursPos(11 + 34, 5); cout << " "; CursPos(11 + 34, 6); cout << " "; Sleep(15);
		CursPos(11 + 35, 1); cout << "»"; CursPos(11 + 35, 2); cout << "Ľ"; CursPos(11 + 35, 3); cout << " "; CursPos(11 + 35, 4); cout << " "; CursPos(11 + 35, 5); cout << " "; CursPos(11 + 35, 6); cout << " "; Sleep(300);
		CursPos(11 + 36, 1); cout << "Ű"; CursPos(11 + 36, 2); cout << "Ű"; CursPos(11 + 36, 3); cout << "Ű"; CursPos(11 + 36, 4); cout << "Ű"; CursPos(11 + 36, 5); cout << "Ű"; CursPos(11 + 36, 6); cout << "Č"; Sleep(15);
		CursPos(11 + 37, 1); cout << "Ű"; CursPos(11 + 37, 2); cout << "Ű"; CursPos(11 + 37, 3); cout << "Ű"; CursPos(11 + 37, 4); cout << "Ű"; CursPos(11 + 37, 5); cout << "Ű"; CursPos(11 + 37, 6); cout << "Í"; Sleep(15);
		CursPos(11 + 38, 1); cout << "»"; CursPos(11 + 38, 2); cout << "ş"; CursPos(11 + 38, 3); cout << "Ű"; CursPos(11 + 38, 4); cout << "É"; CursPos(11 + 38, 5); cout << "ş"; CursPos(11 + 38, 6); cout << "Ľ"; Sleep(15);
		CursPos(11 + 39, 1); cout << " "; CursPos(11 + 39, 2); cout << " "; CursPos(11 + 39, 3); cout << "Ű"; CursPos(11 + 39, 4); cout << "Í"; CursPos(11 + 39, 5); cout << " "; CursPos(11 + 39, 6); cout << " "; Sleep(15);

		CursPos(11 + 40, 1); cout << " "; CursPos(11 + 40, 2); cout << "Ű"; CursPos(11 + 40, 3); cout << "Ű"; CursPos(11 + 40, 4); cout << "Ű"; CursPos(11 + 40, 5); cout << "Č"; CursPos(11 + 40, 6); cout << " "; Sleep(15);
		CursPos(11 + 41, 1); cout << "Ű"; CursPos(11 + 41, 2); cout << "Ű"; CursPos(11 + 41, 3); cout << "Í"; CursPos(11 + 41, 4); cout << "Ű"; CursPos(11 + 41, 5); cout << "Ű"; CursPos(11 + 41, 6); cout << "Č"; Sleep(15);
		CursPos(11 + 42, 1); cout << "Ű"; CursPos(11 + 42, 2); cout << "É"; CursPos(11 + 42, 3); cout << "Ľ"; CursPos(11 + 42, 4); cout << "»"; CursPos(11 + 42, 5); cout << "Ű"; CursPos(11 + 42, 6); cout << "Í"; Sleep(15);
		CursPos(11 + 43, 1); cout << "»"; CursPos(11 + 43, 2); cout << "Ľ"; CursPos(11 + 43, 3); cout << " "; CursPos(11 + 43, 4); cout << " "; CursPos(11 + 43, 5); cout << "»"; CursPos(11 + 43, 6); cout << "Ľ"; Sleep(300);
		CursPos(11 + 44, 1); cout << "Ű"; CursPos(11 + 44, 2); cout << "Ű"; CursPos(11 + 44, 3); cout << "Ű"; CursPos(11 + 44, 4); cout << "Ű"; CursPos(11 + 44, 5); cout << "Ű"; CursPos(11 + 44, 6); cout << "Č"; Sleep(15);
		CursPos(11 + 45, 1); cout << "Ű"; CursPos(11 + 45, 2); cout << "Ű"; CursPos(11 + 45, 3); cout << "Ű"; CursPos(11 + 45, 4); cout << "Ű"; CursPos(11 + 45, 5); cout << "Ű"; CursPos(11 + 45, 6); cout << "Í"; Sleep(15);
		CursPos(11 + 46, 1); cout << "»"; CursPos(11 + 46, 2); cout << "ş"; CursPos(11 + 46, 3); cout << "ş"; CursPos(11 + 46, 4); cout << "ş"; CursPos(11 + 46, 5); cout << "ş"; CursPos(11 + 46, 6); cout << "Ľ"; Sleep(700);
		#pragma endregion STATKI

		#pragma region TŁO
		CursPos(11 + 43, 3); cout << "°"; CursPos(11 + 43, 4); cout << "°"; Sleep(60);
		CursPos(11 + 40, 1); cout << "°"; CursPos(11 + 40, 6); cout << "°"; Sleep(20);
		CursPos(11 + 39, 1); cout << "°"; CursPos(11 + 39, 2); cout << "°"; CursPos(11 + 39, 5); cout << "°"; CursPos(11 + 39, 6); cout << "°"; Sleep(80);
		CursPos(11 + 35, 3); cout << "°"; CursPos(11 + 35, 4); cout << "°"; CursPos(11 + 35, 5); cout << "°"; CursPos(11 + 35, 6); cout << "°"; Sleep(20);
		CursPos(11 + 34, 3); cout << "°"; CursPos(11 + 34, 4); cout << "°"; CursPos(11 + 34, 5); cout << "°"; CursPos(11 + 34, 6); cout << "°"; Sleep(20);
		CursPos(11 + 33, 3); cout << "°"; CursPos(11 + 33, 4); cout << "°"; CursPos(11 + 33, 5); cout << "°"; CursPos(11 + 33, 6); cout << "°"; Sleep(80);
		CursPos(11 + 29, 3); cout << "°"; CursPos(11 + 29, 4); cout << "°"; CursPos(11 + 29, 5); cout << "°"; CursPos(11 + 29, 6); cout << "°"; Sleep(20);
		CursPos(11 + 28, 3); cout << "°"; CursPos(11 + 28, 4); cout << "°"; CursPos(11 + 28, 5); cout << "°"; CursPos(11 + 28, 6); cout << "°"; Sleep(20);
		CursPos(11 + 27, 3); cout << "°"; CursPos(11 + 27, 4); cout << "°"; CursPos(11 + 27, 5); cout << "°"; CursPos(11 + 27, 6); cout << "°"; Sleep(20);
		CursPos(11 + 26, 1); cout << "°"; Sleep(60);
		CursPos(11 + 23, 5); cout << "°"; CursPos(11 + 23, 6); cout << "°"; Sleep(20);
		CursPos(11 + 22, 5); cout << "°"; CursPos(11 + 22, 6); cout << "°"; Sleep(60);
		CursPos(11 + 19, 1); cout << "°"; Sleep(20);
		CursPos(11 + 18, 3); cout << "°"; CursPos(11 + 18, 4); cout << "°"; CursPos(11 + 18, 5); cout << "°"; CursPos(11 + 18, 6); cout << "°"; Sleep(20);
		CursPos(11 + 17, 3); cout << "°"; CursPos(11 + 17, 4); cout << "°"; CursPos(11 + 17, 5); cout << "°"; CursPos(11 + 17, 6); cout << "°"; Sleep(20);
		CursPos(11 + 16, 3); cout << "°"; CursPos(11 + 16, 4); cout << "°"; CursPos(11 + 16, 5); cout << "°"; CursPos(11 + 16, 6); cout << "°"; Sleep(80);
		CursPos(11 + 12, 3); cout << "°"; CursPos(11 + 12, 4); cout << "°"; CursPos(11 + 12, 5); cout << "°"; CursPos(11 + 12, 6); cout << "°"; Sleep(20);
		CursPos(11 + 11, 3); cout << "°"; CursPos(11 + 11, 4); cout << "°"; CursPos(11 + 11, 5); cout << "°"; CursPos(11 + 11, 6); cout << "°"; Sleep(20);
		CursPos(11 + 10, 3); cout << "°"; CursPos(11 + 10, 4); cout << "°"; CursPos(11 + 10, 5); cout << "°"; CursPos(11 + 10, 6); cout << "°"; Sleep(20);
		CursPos(11 + 9, 3); cout << "°"; CursPos(11 + 9, 6); cout << "°"; Sleep(140);
		CursPos(11 + 2, 1); cout << "°"; CursPos(11 + 2, 4); cout << "°"; Sleep(1000);
		#pragma endregion TŁO

		_napisStatki = 1;
	}
}

void ShowConsoleCursor(bool showFlag)
{
	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_CURSOR_INFO     cursorInfo;

	GetConsoleCursorInfo(out, &cursorInfo);
	cursorInfo.bVisible = showFlag;
	SetConsoleCursorInfo(out, &cursorInfo);
}

void CursPos(int a, int b)
{
	COORD c{};
	c.X = a; c.Y = b;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

void menu()
{
	int wybor_menu{};

	ShowConsoleCursor(0);
	system("cls");
	Sleep(500);

	#pragma region NAPIS "MENU"
	CursPos(20, 4); cout << "ŰŰŰŰŰŰŰŰŰŰŰŰŰŰŰŰŰŰŰŰŰŰŰŰŰŰŰŰŰŰ"; Sleep(40);
	CursPos(20, 3); cout << "ŰŰŰŰŰŰŰŰŰŰŰŰŰŰŰŰŰŰŰŰŰŰŰŰŰŰŰŰŰŰ"; Sleep(40);
	CursPos(20, 2); cout << "ŰŰŰŰŰŰŰŰŰŰŰŰŰŰŰŰŰŰŰŰŰŰŰŰŰŰŰŰŰŰ"; Sleep(40);
	CursPos(20, 1); cout << "ÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜ"; Sleep(700);

	CursPos(20, 1); cout << "ÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜ"; Sleep(30);
	CursPos(20, 2); cout << "ŰÜÄßŰßÄÜŰÜÄÜÜÄŰÜÄßŰÜÄÜŰÜÄŰŰÄÜŰ"; Sleep(30);
	CursPos(20, 3); cout << "ŰŰÄŰÜŰÄŰŰŰÄÜŰßŰŰÄŰÜßÄŰŰŰÄŰŰÄŰŰ"; Sleep(30);
	CursPos(20, 4); cout << "ŰÜÜÜŰÜÜÜŰÜÜÜÜÜŰÜÜÜŰŰÜÜŰŰÜÜÜÜŰŰ"; Sleep(700);
	#pragma endregion NAPIS "MENU"

	#pragma region NAPIS " Co chcesz zrobić? Wybierz jedną z opcji, wpisując odpowiednią cyfrę: "
	cout << "\n\n C"; Sleep(10); cout << "o"; Sleep(10); cout << " "; Sleep(10); cout << "c"; Sleep(10); cout << "h"; Sleep(10); cout << "c"; Sleep(10); cout << "e"; Sleep(10); cout << "s"; Sleep(10); cout << "z"; Sleep(10); cout << " "; Sleep(10); cout << "z"; Sleep(10); cout << "r"; Sleep(10); cout << "o"; Sleep(10); cout << "b"; Sleep(10); cout << "i"; Sleep(10); cout << "\206"; Sleep(10); cout << "?"; Sleep(500); cout << " "; Sleep(10); cout << "W"; Sleep(10); cout << "y"; Sleep(10); cout << "b"; Sleep(10); cout << "i"; Sleep(10); cout << "e"; Sleep(10); cout << "r"; Sleep(10); cout << "z"; Sleep(10); cout << " "; Sleep(10); cout << "j"; Sleep(10); cout << "e"; Sleep(10); cout << "d"; Sleep(10); cout << "n"; Sleep(10); cout << "\245"; Sleep(10); cout << " "; Sleep(10); cout << "z"; Sleep(10); cout << " "; Sleep(10); cout << "o"; Sleep(10); cout << "p"; Sleep(10); cout << "c"; Sleep(10); cout << "j"; Sleep(10); cout << "i"; Sleep(10); cout << ","; Sleep(10); cout << " "; Sleep(10); cout << "w"; Sleep(10); cout << "p"; Sleep(10); cout << "i"; Sleep(10); cout << "s"; Sleep(10); cout << "u"; Sleep(10); cout << "j"; Sleep(10); cout << "\245"; Sleep(10); cout << "c"; Sleep(10); cout << " "; Sleep(10); cout << "o"; Sleep(10); cout << "d"; Sleep(10); cout << "p"; Sleep(10); cout << "o"; Sleep(10); cout << "w"; Sleep(10); cout << "i"; Sleep(10); cout << "e"; Sleep(10); cout << "d"; Sleep(10); cout << "n"; Sleep(10); cout << "i"; Sleep(10); cout << "\245"; Sleep(10); cout << " "; Sleep(10); cout << "c"; Sleep(10); cout << "y"; Sleep(10); cout << "f"; Sleep(10); cout << "r"; Sleep(10); cout << "\251"; Sleep(10); cout << ":";
	#pragma endregion NAPIS " Co chcesz zrobić? Wybierz jedną z opcji, wpisując odpowiednią cyfrę: "

	#pragma region NAPIS "1. Rozpocznij grę 2. Zasady 3. Wyjście"
	Sleep(500);
	CursPos(1, 8); cout << "1"; CursPos(1, 10); cout << "2"; CursPos(1, 12); cout << "3"; Sleep(20);
	CursPos(2, 8); cout << "."; CursPos(2, 10); cout << "."; CursPos(2, 12); cout << "."; Sleep(20);
	CursPos(3, 8); cout << " "; CursPos(3, 10); cout << " "; CursPos(3, 12); cout << " "; Sleep(20);
	CursPos(4, 8); cout << "R"; CursPos(4, 10); cout << "Z"; CursPos(4, 12); cout << "W"; Sleep(20);
	CursPos(5, 8); cout << "o"; CursPos(5, 10); cout << "a"; CursPos(5, 12); cout << "y"; Sleep(20);
	CursPos(6, 8); cout << "z"; CursPos(6, 10); cout << "s"; CursPos(6, 12); cout << "j"; Sleep(20);
	CursPos(7, 8); cout << "p"; CursPos(7, 10); cout << "a"; CursPos(7, 12); cout << "\230"; Sleep(20);
	CursPos(8, 8); cout << "o"; CursPos(8, 10); cout << "d"; CursPos(8, 12); cout << "c"; Sleep(20);
	CursPos(9, 8); cout << "c"; CursPos(9, 10); cout << "y"; CursPos(9, 12); cout << "i"; Sleep(20);
	CursPos(10, 8); cout << "z"; CursPos(10, 12); cout << "e"; Sleep(20);
	CursPos(11, 8); cout << "n"; Sleep(20);
	CursPos(12, 8); cout << "i"; Sleep(20);
	CursPos(13, 8); cout << "j"; Sleep(20);
	CursPos(14, 8); cout << " "; Sleep(20);
	CursPos(15, 8); cout << "g"; Sleep(20);
	CursPos(16, 8); cout << "r"; Sleep(20);
	CursPos(17, 8); cout << "\251"; Sleep(20);
	#pragma endregion NAPIS "1. Rozpocznij grę 2. Zasady 3. Wyjście"

	Sleep(500);
wybor:
	CursPos(1, 16);
	ShowConsoleCursor(1);
	wybor_menu = _getch();
	ShowConsoleCursor(0);
	if (wybor_menu >= 48 && wybor_menu <= 57)
		cout << wybor_menu - '0';
	else
		cout << "0";
	Sleep(100);

	switch (wybor_menu)
	{
		case 49:  Sleep(500); gra();
			break;
		case 50:  Sleep(500); zasady();
			break;
		case 51:  Sleep(500); system("cls"); Sleep(500); cout << "\n W"; Sleep(10); cout << "y"; Sleep(10); cout << "c"; Sleep(10); cout << "h"; Sleep(10); cout << "o"; Sleep(10); cout << "d"; Sleep(10); cout << "z"; Sleep(10); cout << "e"; Sleep(10); cout << "n"; Sleep(10); cout << "i"; Sleep(10); cout << "e"; Sleep(10); cout << " "; Sleep(10); cout << "z"; Sleep(10); cout << " "; Sleep(10); cout << "g"; Sleep(10); cout << "r"; Sleep(10); cout << "y"; Sleep(10); cout << "."; Sleep(20); cout << "."; Sleep(20); cout << "."; for (int i = 0; i < 2; i++) { CursPos(18, 1); Sleep(800); cout << "   "; CursPos(18, 1); Sleep(200); cout << "."; Sleep(20); cout << "."; Sleep(20); cout << "."; } Sleep(500); exit(0);
			break;
		default:  CursPos(1, 14); for (int i = 0; i < 32; i++) cout << " "; Sleep(200); CursPos(1, 14); cout << "N"; Sleep(10); cout << "i"; Sleep(10); cout << "e"; Sleep(10); cout << " "; Sleep(10); cout << "r"; Sleep(10); cout << "o"; Sleep(10); cout << "z"; Sleep(10); cout << "u"; Sleep(10); cout << "m"; Sleep(10); cout << "i"; Sleep(10); cout << "e"; Sleep(10); cout << "m"; Sleep(10); cout << ","; Sleep(10); cout << " "; Sleep(10); cout << "s"; Sleep(10); cout << "p"; Sleep(10); cout << "r"; Sleep(10); cout << "\242"; Sleep(10); cout << "b"; Sleep(10); cout << "u"; Sleep(10); cout << "j"; Sleep(10); cout << " "; Sleep(10); cout << "p"; Sleep(10); cout << "o"; Sleep(10); cout << "n"; Sleep(10); cout << "o"; Sleep(10); cout << "w"; Sleep(10); cout << "n"; Sleep(10); cout << "i"; Sleep(10); cout << "e"; Sleep(10); cout << ": "; Sleep(500); CursPos(1, 16); cout << " "; goto wybor;
			break;
	}
}

void gra()
{
	ShowConsoleCursor(0);
	system("cls"); Sleep(500);

	#pragma region NAPIS "Witajcie w Grze w Statki!"
	cout << "\n W"; Sleep(10); cout << "i"; Sleep(10); cout << "t"; Sleep(10); cout << "a"; Sleep(10); cout << "j"; Sleep(10); cout << "c"; Sleep(10); cout << "i"; Sleep(10); cout << "e"; Sleep(10); cout << " "; Sleep(10); cout << "w"; Sleep(10); cout << " "; Sleep(10); cout << "G"; Sleep(10); cout << "r"; Sleep(10); cout << "z"; Sleep(10); cout << "e"; Sleep(10); cout << " "; Sleep(10); cout << "w"; Sleep(10); cout << " "; Sleep(10); cout << "S"; Sleep(10); cout << "t"; Sleep(10); cout << "a"; Sleep(10); cout << "t"; Sleep(10); cout << "k"; Sleep(10); cout << "i"; Sleep(10); cout << "!";
	Sleep(800);
	#pragma endregion NAPIS "Witajcie w Grze w Statki!"

	#pragma region ZASADY
	bool end{}; string odp{};
	while (_zas)
	{
		if (end)
			cout << endl;
		#pragma region NAPIS "Czy znacie zasady gry? [Wpisz 'tak' lub 'nie']:"
		cout << "\n\n C"; Sleep(10); cout << "z"; Sleep(10); cout << "y"; Sleep(10); cout << " "; Sleep(10); cout << "z"; Sleep(10); cout << "n"; Sleep(10); cout << "a"; Sleep(10); cout << "c"; Sleep(10); cout << "i"; Sleep(10); cout << "e"; Sleep(10); cout << " "; Sleep(10); cout << "z"; Sleep(10); cout << "a"; Sleep(10); cout << "s"; Sleep(10); cout << "a"; Sleep(10); cout << "d"; Sleep(10); cout << "y"; Sleep(10); cout << " "; Sleep(10); cout << "g"; Sleep(10); cout << "r"; Sleep(10); cout << "y"; Sleep(10); cout << "?"; Sleep(10); cout << " "; Sleep(10); cout << "["; Sleep(10); cout << "W"; Sleep(10); cout << "p"; Sleep(10); cout << "i"; Sleep(10); cout << "s"; Sleep(10); cout << "z"; Sleep(10); cout << " "; Sleep(10); cout << "'"; Sleep(10); cout << "t"; Sleep(10); cout << "a"; Sleep(10); cout << "k"; Sleep(10); cout << "'"; Sleep(10); cout << " "; Sleep(10); cout << "l"; Sleep(10); cout << "u"; Sleep(10); cout << "b"; Sleep(10); cout << " "; Sleep(10); cout << "'"; Sleep(10); cout << "n"; Sleep(10); cout << "i"; Sleep(10); cout << "e"; Sleep(10); cout << "'"; Sleep(10); cout << "]"; Sleep(10); cout << ": ";
		#pragma endregion NAPIS "Czy znacie zasady gry? [Wpisz 'tak' lub 'nie']:"

		ShowConsoleCursor(1);
		getline(cin, odp);
		ShowConsoleCursor(0);

		if (odp == "nie" || odp == "NIE" || odp == "Nie" || odp == "nei" || odp == "NEI" || odp == "Nei" || odp == "ni" || odp == "NI" || odp == "Ni")
		{
			_doGry = 1;
			_zas = 0;
			zasady();
		}
		else if (odp == "tak" || odp == "TAK" || odp == "Tak" || odp == "ta" || odp == "TA" || odp == "Ta")
			_zas = 0;
		else
		{
			#pragma region	NAPIS "Nie rozumiem, spróbuj ponownie."
			cout << " N"; Sleep(10); cout << "i"; Sleep(10); cout << "e"; Sleep(10); cout << " "; Sleep(10); cout << "r"; Sleep(10); cout << "o"; Sleep(10); cout << "z"; Sleep(10); cout << "u"; Sleep(10); cout << "m"; Sleep(10); cout << "i"; Sleep(10); cout << "e"; Sleep(10); cout << "m"; Sleep(10); cout << ","; Sleep(10); cout << " "; Sleep(10); cout << "s"; Sleep(10); cout << "p"; Sleep(10); cout << "r"; Sleep(10); cout << "\242"; Sleep(10); cout << "b"; Sleep(10); cout << "u"; Sleep(10); cout << "j"; Sleep(10); cout << " "; Sleep(10); cout << "p"; Sleep(10); cout << "o"; Sleep(10); cout << "n"; Sleep(10); cout << "o"; Sleep(10); cout << "w"; Sleep(10); cout << "n"; Sleep(10); cout << "i"; Sleep(10); cout << "e"; Sleep(10); cout << ".";
			Sleep(1000); system("cls"); end = 1;
			#pragma endregion	NAPIS "Nie rozumiem, spróbuj ponownie."
		}
	}
	end = 0;
	ShowConsoleCursor(0);
	#pragma endregion ZASADY

	if (_nazwy_niepodane)
	{
		string g1{}, g2{}; int gracz_los{};
		#pragma region NAPIS "Okej, na początek podaj nazwę Gracza 1:"
		cout << "\n O"; Sleep(10); cout << "k"; Sleep(10); cout << "e"; Sleep(10); cout << "j"; Sleep(10); cout << ","; Sleep(10); cout << " "; Sleep(10); cout << "n"; Sleep(10); cout << "a"; Sleep(10); cout << " "; Sleep(10); cout << "p"; Sleep(10); cout << "o"; Sleep(10); cout << "c"; Sleep(10); cout << "z"; Sleep(10); cout << "\245"; Sleep(10); cout << "t"; Sleep(10); cout << "e"; Sleep(10); cout << "k"; Sleep(10); cout << " "; Sleep(10); cout << "p"; Sleep(10); cout << "o"; Sleep(10); cout << "d"; Sleep(10); cout << "a"; Sleep(10); cout << "j"; Sleep(10); cout << " "; Sleep(10); cout << "n"; Sleep(10); cout << "a"; Sleep(10); cout << "z"; Sleep(10); cout << "w"; Sleep(10); cout << "\251"; Sleep(10); cout << " "; Sleep(10); cout << "G"; Sleep(10); cout << "r"; Sleep(10); cout << "a"; Sleep(10); cout << "c"; Sleep(10); cout << "z"; Sleep(10); cout << "a"; Sleep(10); cout << " "; Sleep(10); cout << "1"; Sleep(10); cout << ": ";
		#pragma endregion NAPIS "Okej, na początek podaj nazwę Gracza 1:"
		while (_kbhit())
			_nic = _getch();
		ShowConsoleCursor(1);
		getline(cin, g1);
		ShowConsoleCursor(0);
		#pragma region NAPIS "oraz Gracza 2:"
		cout << " o"; Sleep(10); cout << "r"; Sleep(10); cout << "a"; Sleep(10); cout << "z"; Sleep(10); cout << " "; Sleep(10); cout << "G"; Sleep(10); cout << "r"; Sleep(10); cout << "a"; Sleep(10); cout << "c"; Sleep(10); cout << "z"; Sleep(10); cout << "a"; Sleep(10); cout << " "; Sleep(10); cout << "2"; Sleep(10); cout << ": ";
		#pragma endregion NAPIS "oraz Gracza 2:"
		while (_kbhit())
			_nic = _getch();
		ShowConsoleCursor(1);
		getline(cin, g2);
		ShowConsoleCursor(0);
		system("cls");
		Sleep(500);

		#pragma region LOSOWANIE GRACZA
		gracz_los = kier(generator);
		switch (gracz_los)
		{
			case 1: _gracz1 = g1; _gracz2 = g2;
				break;
			case 2: _gracz1 = g2; _gracz2 = g1;
				break;
			default:
				break;
		}
		#pragma endregion LOSOWANIE GRACZA

		#pragma region ANIMACJA LOSOWANIA GRACZA
		#pragma region NAPIS "Losowanie gracza rozpoczynającego:"
		cout << endl << " L"; Sleep(10); cout << "o"; Sleep(10); cout << "s"; Sleep(10); cout << "o"; Sleep(10); cout << "w"; Sleep(10); cout << "a"; Sleep(10); cout << "n"; Sleep(10); cout << "i"; Sleep(10); cout << "e"; Sleep(10); cout << " "; Sleep(10); cout << "g"; Sleep(10); cout << "r"; Sleep(10); cout << "a"; Sleep(10); cout << "c"; Sleep(10); cout << "z"; Sleep(10); cout << "a"; Sleep(10); cout << " "; Sleep(10); cout << "r"; Sleep(10); cout << "o"; Sleep(10); cout << "z"; Sleep(10); cout << "p"; Sleep(10); cout << "o"; Sleep(10); cout << "c"; Sleep(10); cout << "z"; Sleep(10); cout << "y"; Sleep(10); cout << "n"; Sleep(10); cout << "a"; Sleep(10); cout << "j"; Sleep(10); cout << "\245"; Sleep(10); cout << "c"; Sleep(10); cout << "e"; Sleep(10); cout << "g"; Sleep(10); cout << "o"; Sleep(10); cout << ": "; Sleep(200);
		#pragma endregion NAPIS "Losowanie gracza rozpoczynającego:"
		system("cls");
		for (int i = 0; i < 3; i++)
		{
			cout << endl << " Losowanie gracza rozpoczynaj\245cego: | \n ";
			Sleep(100); system("cls");
			cout << endl << " Losowanie gracza rozpoczynaj\245cego: / \n ";
			Sleep(100); system("cls");
			cout << endl << " Losowanie gracza rozpoczynaj\245cego: - \n ";
			Sleep(100); system("cls");
			cout << endl << " Losowanie gracza rozpoczynaj\245cego: \\ \n ";
			Sleep(100); system("cls");
			cout << endl << " Losowanie gracza rozpoczynaj\245cego: | \n ";
			Sleep(200); system("cls");
		}
		cout << endl << " Losowanie gracza rozpoczynaj\245cego: ";
		for (int i = 0; i < _gracz1.size(); i++)
		{
			cout << _gracz1[i];
			Sleep(10);
		}
		Sleep(1500); system("cls"); Sleep(500);
		#pragma endregion ANIMACJA LOSOWANIA GRACZA
	}

	#pragma region NAPIS "Okej, możemy zaczynać! Zaczyna GRACZ1! Wciśnij dowolny klawisz, żeby kontynuować."
	cout << "\n O"; Sleep(10); cout << "k"; Sleep(10); cout << "e"; Sleep(10); cout << "j"; Sleep(10); cout << ","; Sleep(10); cout << " "; Sleep(10); cout << "m"; Sleep(10); cout << "o"; Sleep(10); cout << "\276"; Sleep(10); cout << "e"; Sleep(10); cout << "m"; Sleep(10); cout << "y"; Sleep(10); cout << " "; Sleep(10); cout << "z"; Sleep(10); cout << "a"; Sleep(10); cout << "c"; Sleep(10); cout << "z"; Sleep(10); cout << "y"; Sleep(10); cout << "n"; Sleep(10); cout << "a"; Sleep(10); cout << "\206"; Sleep(10); cout << "!"; Sleep(10); cout << "\n";
	Sleep(1000);
	cout << " Z"; Sleep(10); cout << "a"; Sleep(10); cout << "c"; Sleep(10); cout << "z"; Sleep(10); cout << "y"; Sleep(10); cout << "n"; Sleep(10); cout << "a"; Sleep(10); cout << " "; Sleep(10); cout << "g"; Sleep(10); cout << "r"; Sleep(10); cout << "a"; Sleep(10); cout << "c"; Sleep(10); cout << "z"; Sleep(10); cout << " "; Sleep(10);
	for (int i = 0; i < _gracz1.size(); i++)
	{
		cout << _gracz1[i];
		Sleep(10);
	}
	cout << "!";
	Sleep(1000);
	cout << "\n\n W"; Sleep(10); cout << "c"; Sleep(10); cout << "i"; Sleep(10); cout << "\230"; Sleep(10); cout << "n"; Sleep(10); cout << "i"; Sleep(10); cout << "j"; Sleep(10); cout << " "; Sleep(10); cout << "d"; Sleep(10); cout << "o"; Sleep(10); cout << "w"; Sleep(10); cout << "o"; Sleep(10); cout << "l"; Sleep(10); cout << "n"; Sleep(10); cout << "y"; Sleep(10); cout << " "; Sleep(10); cout << "k"; Sleep(10); cout << "l"; Sleep(10); cout << "a"; Sleep(10); cout << "w"; Sleep(10); cout << "i"; Sleep(10); cout << "s"; Sleep(10); cout << "z"; Sleep(10); cout << ","; Sleep(10); cout << " "; Sleep(10); cout << "\276"; Sleep(10); cout << "e"; Sleep(10); cout << "b"; Sleep(10); cout << "y"; Sleep(10); cout << " "; Sleep(10); cout << "k"; Sleep(10); cout << "o"; Sleep(10); cout << "n"; Sleep(10); cout << "t"; Sleep(10); cout << "y"; Sleep(10); cout << "n"; Sleep(10); cout << "u"; Sleep(10); cout << "o"; Sleep(10); cout << "w"; Sleep(10); cout << "a"; Sleep(10); cout << "\206"; Sleep(10); cout << ". ";
	while (_kbhit())
		_nic = _getch();
	ShowConsoleCursor(1);
	_nic = _getch();
	ShowConsoleCursor(0);
	#pragma endregion NAPIS "Okej, możemy zaczynać! Zaczyna GRACZ1! Wciśnij dowolny klawisz, żeby kontynuować."

	#pragma region ODLICZANIE
	system("cls");
	Sleep(500);
	cout << "\n Z"; Sleep(10); cout << "a"; Sleep(10); cout << "c"; Sleep(10); cout << "z"; Sleep(10); cout << "y"; Sleep(10); cout << "n"; Sleep(10); cout << "a"; Sleep(10); cout << "m"; Sleep(10); cout << "y"; Sleep(10); cout << " "; Sleep(10); cout << "z"; Sleep(10); cout << "a"; Sleep(10); cout << ": ";
	Sleep(100);
	system("cls");
	for (int i = 3; i > 0; i--)
	{
		cout << "\n Zaczynamy za: ";
		cout << i;
		Sleep(1000);
		system("cls");
	}
	#pragma endregion ODLICZANIE
}

void zasady()
{
	ShowConsoleCursor(0);
	system("cls"); Sleep(500);

	if (_nazwy_niepodane)
	{
		_nazwy_niepodane = 0;
		string g1{}, g2{}; int gracz_los{};
		#pragma region NAPIS "Na początek podaj nazwę Gracza 1:"
		cout << endl << " N"; Sleep(10); cout << "a"; Sleep(10); cout << " "; Sleep(10); cout << "p"; Sleep(10); cout << "o"; Sleep(10); cout << "c"; Sleep(10); cout << "z"; Sleep(10); cout << "\245"; Sleep(10); cout << "t"; Sleep(10); cout << "e"; Sleep(10); cout << "k"; Sleep(10); cout << " "; Sleep(10); cout << "p"; Sleep(10); cout << "o"; Sleep(10); cout << "d"; Sleep(10); cout << "a"; Sleep(10); cout << "j"; Sleep(10); cout << " "; Sleep(10); cout << "n"; Sleep(10); cout << "a"; Sleep(10); cout << "z"; Sleep(10); cout << "w"; Sleep(10); cout << "\251"; Sleep(10); cout << " "; Sleep(10); cout << "G"; Sleep(10); cout << "r"; Sleep(10); cout << "a"; Sleep(10); cout << "c"; Sleep(10); cout << "z"; Sleep(10); cout << "a"; Sleep(10); cout << " "; Sleep(10); cout << "1"; Sleep(10); cout << ": ";
		#pragma endregion NAPIS "Na początek podaj nazwę Gracza 1:"
		while (_kbhit())
			_nic = _getch();
		ShowConsoleCursor(1);
		getline(cin, g1);
		ShowConsoleCursor(0);

		#pragma region NAPIS "oraz Gracza 2:"
		cout << " o"; Sleep(10); cout << "r"; Sleep(10); cout << "a"; Sleep(10); cout << "z"; Sleep(10); cout << " "; Sleep(10); cout << "G"; Sleep(10); cout << "r"; Sleep(10); cout << "a"; Sleep(10); cout << "c"; Sleep(10); cout << "z"; Sleep(10); cout << "a"; Sleep(10); cout << " "; Sleep(10); cout << "2"; Sleep(10); cout << ": ";
		while (_kbhit())
			_nic = _getch();
		#pragma endregion NAPIS "oraz Gracza 2:"
		while (_kbhit())
			_nic = _getch();
		ShowConsoleCursor(1);
		getline(cin, g2);
		ShowConsoleCursor(0);

		system("cls");
		Sleep(500);

		#pragma region LOSOWANIE GRACZA
		gracz_los = kier(generator);
		switch (gracz_los)
		{
			case 1: _gracz1 = g1; _gracz2 = g2;
				break;
			case 2: _gracz1 = g2; _gracz2 = g1;
				break;
			default:
				break;
		}
		#pragma endregion LOSOWANIE GRACZA

		#pragma region ANIMACJA LOSOWANIA GRACZA
		#pragma region NAPIS "Losowanie gracza rozpoczynającego:"
		cout << endl << " L"; Sleep(10); cout << "o"; Sleep(10); cout << "s"; Sleep(10); cout << "o"; Sleep(10); cout << "w"; Sleep(10); cout << "a"; Sleep(10); cout << "n"; Sleep(10); cout << "i"; Sleep(10); cout << "e"; Sleep(10); cout << " "; Sleep(10); cout << "g"; Sleep(10); cout << "r"; Sleep(10); cout << "a"; Sleep(10); cout << "c"; Sleep(10); cout << "z"; Sleep(10); cout << "a"; Sleep(10); cout << " "; Sleep(10); cout << "r"; Sleep(10); cout << "o"; Sleep(10); cout << "z"; Sleep(10); cout << "p"; Sleep(10); cout << "o"; Sleep(10); cout << "c"; Sleep(10); cout << "z"; Sleep(10); cout << "y"; Sleep(10); cout << "n"; Sleep(10); cout << "a"; Sleep(10); cout << "j"; Sleep(10); cout << "\245"; Sleep(10); cout << "c"; Sleep(10); cout << "e"; Sleep(10); cout << "g"; Sleep(10); cout << "o"; Sleep(10); cout << ": "; Sleep(200);
		#pragma endregion NAPIS "Losowanie gracza rozpoczynającego:"
		system("cls");
		for (int i = 0; i < 3; i++)
		{
			cout << endl << " Losowanie gracza rozpoczynaj\245cego: | \n ";
			Sleep(100); system("cls");
			cout << endl << " Losowanie gracza rozpoczynaj\245cego: / \n ";
			Sleep(100); system("cls");
			cout << endl << " Losowanie gracza rozpoczynaj\245cego: - \n ";
			Sleep(100); system("cls");
			cout << endl << " Losowanie gracza rozpoczynaj\245cego: \\ \n ";
			Sleep(100); system("cls");
			cout << endl << " Losowanie gracza rozpoczynaj\245cego: | \n ";
			Sleep(200); system("cls");
		}
		cout << endl << " Losowanie gracza rozpoczynaj\245cego: ";
		for (int i = 0; i < _gracz1.size(); i++)
		{
			cout << _gracz1[i];
			Sleep(10);
		}
		Sleep(1500); system("cls"); Sleep(500);
		#pragma endregion ANIMACJA LOSOWANIA GRACZA
	}

	#pragma region NAPIS "Zasady są proste- każdy gracz ma przed sobą planszę 10x10 z losowo ustawionymi statkami. Każdy ma 1 statek czteromasztowy, 2 statki trzymasztowe, 3 statki dwumasztowe oraz 1 statek jednomasztowy. Każdy gracz podczas swojej kolejki oddaje jeden strzał - wybiera pole, które ma zostać zatopione. Najpierw GRACZ 1 wybiera pole do ostrzału, a następnie strzela GRACZ 2. Wygrywa ten, kto zatopi wszystkie statki przeciwnika. I tyle! Załapiecie podczas gry. Wciśnij dowolny klawisz, żeby kontynuować."
	cout << "\n Z"; Sleep(10); cout << "a"; Sleep(10); cout << "s"; Sleep(10); cout << "a"; Sleep(10); cout << "d"; Sleep(10); cout << "y"; Sleep(10); cout << " "; Sleep(10); cout << "s"; Sleep(10); cout << "\245"; Sleep(10); cout << " "; Sleep(10); cout << "p"; Sleep(10); cout << "r"; Sleep(10); cout << "o"; Sleep(10); cout << "s"; Sleep(10); cout << "t"; Sleep(10); cout << "e"; Sleep(10); cout << "-"; Sleep(10); cout << " "; Sleep(10); cout << "k"; Sleep(10); cout << "a"; Sleep(10); cout << "\276"; Sleep(10); cout << "d"; Sleep(10); cout << "y"; Sleep(10); cout << " "; Sleep(10); cout << "g"; Sleep(10); cout << "r"; Sleep(10); cout << "a"; Sleep(10); cout << "c"; Sleep(10); cout << "z"; Sleep(10); cout << " "; Sleep(10); cout << "m"; Sleep(10); cout << "a"; Sleep(10); cout << " "; Sleep(10); cout << "p"; Sleep(10); cout << "r"; Sleep(10); cout << "z"; Sleep(10); cout << "e"; Sleep(10); cout << "d"; Sleep(10); cout << " "; Sleep(10); cout << "s"; Sleep(10); cout << "o"; Sleep(10); cout << "b"; Sleep(10); cout << "\245"; Sleep(10); cout << " "; Sleep(10); cout << "p"; Sleep(10); cout << "l"; Sleep(10); cout << "a"; Sleep(10); cout << "n"; Sleep(10); cout << "s"; Sleep(10); cout << "z"; Sleep(10); cout << "\251"; Sleep(10); cout << " "; Sleep(10); cout << "1"; Sleep(10); cout << "0"; Sleep(10); cout << "x"; Sleep(10); cout << "1"; Sleep(10); cout << "0"; Sleep(10); cout << " "; Sleep(10); cout << "z"; Sleep(10); cout << " "; Sleep(10); cout << "l"; Sleep(10); cout << "o"; Sleep(10); cout << "s"; Sleep(10); cout << "o"; Sleep(10); cout << "w"; Sleep(10); cout << "o"; Sleep(10); cout << "\n";
	cout << " u"; Sleep(10); cout << "s"; Sleep(10); cout << "t"; Sleep(10); cout << "a"; Sleep(10); cout << "w"; Sleep(10); cout << "i"; Sleep(10); cout << "o"; Sleep(10); cout << "n"; Sleep(10); cout << "y"; Sleep(10); cout << "m"; Sleep(10); cout << "i"; Sleep(10); cout << " "; Sleep(10); cout << "s"; Sleep(10); cout << "t"; Sleep(10); cout << "a"; Sleep(10); cout << "t"; Sleep(10); cout << "k"; Sleep(10); cout << "a"; Sleep(10); cout << "m"; Sleep(10); cout << "i"; Sleep(10); cout << ".\n";
	cout << " K"; Sleep(10); cout << "a"; Sleep(10); cout << "\276"; Sleep(10); cout << "d"; Sleep(10); cout << "y"; Sleep(10); cout << " "; Sleep(10); cout << "m"; Sleep(10); cout << "a"; Sleep(10); cout << " "; Sleep(10); cout << "1"; Sleep(10); cout << " "; Sleep(10); cout << "s"; Sleep(10); cout << "t"; Sleep(10); cout << "a"; Sleep(10); cout << "t"; Sleep(10); cout << "e"; Sleep(10); cout << "k"; Sleep(10); cout << " "; Sleep(10); cout << "4"; Sleep(10); cout << "-"; Sleep(10); cout << "m"; Sleep(10); cout << "a"; Sleep(10); cout << "s"; Sleep(10); cout << "z"; Sleep(10); cout << "t"; Sleep(10); cout << "o"; Sleep(10); cout << "w"; Sleep(10); cout << "y"; Sleep(10); cout << ","; Sleep(10); cout << " "; Sleep(10); cout << "2"; Sleep(10); cout << " "; Sleep(10); cout << "s"; Sleep(10); cout << "t"; Sleep(10); cout << "a"; Sleep(10); cout << "t"; Sleep(10); cout << "k"; Sleep(10); cout << "i"; Sleep(10); cout << " "; Sleep(10); cout << "3"; Sleep(10); cout << "-"; Sleep(10); cout << "m"; Sleep(10); cout << "a"; Sleep(10); cout << "s"; Sleep(10); cout << "z"; Sleep(10); cout << "t"; Sleep(10); cout << "o"; Sleep(10); cout << "w"; Sleep(10); cout << "e"; Sleep(10); cout << ","; Sleep(10); cout << "\n";
	cout << " 3"; Sleep(10); cout << " "; Sleep(10); cout << "s"; Sleep(10); cout << "t"; Sleep(10); cout << "a"; Sleep(10); cout << "t"; Sleep(10); cout << "k"; Sleep(10); cout << "i"; Sleep(10); cout << " "; Sleep(10); cout << "2"; Sleep(10); cout << "-"; Sleep(10); cout << "m"; Sleep(10); cout << "a"; Sleep(10); cout << "s"; Sleep(10); cout << "z"; Sleep(10); cout << "t"; Sleep(10); cout << "o"; Sleep(10); cout << "w"; Sleep(10); cout << "e"; Sleep(10); cout << " "; Sleep(10); cout << "o"; Sleep(10); cout << "r"; Sleep(10); cout << "a"; Sleep(10); cout << "z"; Sleep(10); cout << " "; Sleep(10); cout << "4"; Sleep(10); cout << " "; Sleep(10); cout << "s"; Sleep(10); cout << "t"; Sleep(10); cout << "a"; Sleep(10); cout << "t"; Sleep(10); cout << "k"; Sleep(10); cout << "i"; Sleep(10); cout << " "; Sleep(10); cout << "1"; Sleep(10); cout << "-"; Sleep(10); cout << "m"; Sleep(10); cout << "a"; Sleep(10); cout << "s"; Sleep(10); cout << "z"; Sleep(10); cout << "t"; Sleep(10); cout << "o"; Sleep(10); cout << "w"; Sleep(10); cout << "e"; Sleep(10); cout << ".\n";
	cout << " K"; Sleep(10); cout << "a"; Sleep(10); cout << "\276"; Sleep(10); cout << "d"; Sleep(10); cout << "y"; Sleep(10); cout << " "; Sleep(10); cout << "g"; Sleep(10); cout << "r"; Sleep(10); cout << "a"; Sleep(10); cout << "c"; Sleep(10); cout << "z"; Sleep(10); cout << " "; Sleep(10); cout << "p"; Sleep(10); cout << "o"; Sleep(10); cout << "d"; Sleep(10); cout << "c"; Sleep(10); cout << "z"; Sleep(10); cout << "a"; Sleep(10); cout << "s"; Sleep(10); cout << " "; Sleep(10); cout << "s"; Sleep(10); cout << "w"; Sleep(10); cout << "o"; Sleep(10); cout << "j"; Sleep(10); cout << "e"; Sleep(10); cout << "j"; Sleep(10); cout << " "; Sleep(10); cout << "k"; Sleep(10); cout << "o"; Sleep(10); cout << "l"; Sleep(10); cout << "e"; Sleep(10); cout << "j"; Sleep(10); cout << "k"; Sleep(10); cout << "i"; Sleep(10); cout << " "; Sleep(10); cout << "o"; Sleep(10); cout << "d"; Sleep(10); cout << "d"; Sleep(10); cout << "a"; Sleep(10); cout << "j"; Sleep(10); cout << "e"; Sleep(10); cout << " "; Sleep(10); cout << "j"; Sleep(10); cout << "e"; Sleep(10); cout << "d"; Sleep(10); cout << "e"; Sleep(10); cout << "n"; Sleep(10); cout << " "; Sleep(10); cout << "s"; Sleep(10); cout << "t"; Sleep(10); cout << "r"; Sleep(10); cout << "z"; Sleep(10); cout << "a"; Sleep(10); cout << "\210"; Sleep(10); cout << "-"; Sleep(10); cout << " "; Sleep(10); cout << "w"; Sleep(10); cout << "y"; Sleep(10); cout << "b"; Sleep(10); cout << "i"; Sleep(10); cout << "e"; Sleep(10); cout << "r"; Sleep(10); cout << "a"; Sleep(10); cout << " "; Sleep(10); cout << "p"; Sleep(10); cout << "o"; Sleep(10); cout << "l"; Sleep(10); cout << "e"; Sleep(10); cout << ",\n";
	cout << " k"; Sleep(10); cout << "t"; Sleep(10); cout << "\242"; Sleep(10); cout << "r"; Sleep(10); cout << "e"; Sleep(10); cout << " "; Sleep(10); cout << "m"; Sleep(10); cout << "a"; Sleep(10); cout << " "; Sleep(10); cout << "z"; Sleep(10); cout << "o"; Sleep(10); cout << "s"; Sleep(10); cout << "t"; Sleep(10); cout << "a"; Sleep(10); cout << "\206"; Sleep(10); cout << " "; Sleep(10); cout << "z"; Sleep(10); cout << "a"; Sleep(10); cout << "t"; Sleep(10); cout << "o"; Sleep(10); cout << "p"; Sleep(10); cout << "i"; Sleep(10); cout << "o"; Sleep(10); cout << "n"; Sleep(10); cout << "e"; Sleep(10); cout << "."; Sleep(10); cout << "\n";
	cout << " N"; Sleep(10); cout << "a"; Sleep(10); cout << "j"; Sleep(10); cout << "p"; Sleep(10); cout << "i"; Sleep(10); cout << "e"; Sleep(10); cout << "r"; Sleep(10); cout << "w"; Sleep(10); cout << " "; Sleep(10);
	for (int i = 0; i < _gracz1.size(); i++)
	{
		cout << _gracz1[i];
		Sleep(10);
	}
	cout << " "; Sleep(10); cout << "w"; Sleep(10); cout << "y"; Sleep(10); cout << "b"; Sleep(10); cout << "i"; Sleep(10); cout << "e"; Sleep(10); cout << "r"; Sleep(10); cout << "a"; Sleep(10); cout << " "; Sleep(10); cout << "p"; Sleep(10); cout << "o"; Sleep(10); cout << "l"; Sleep(10); cout << "e"; Sleep(10); cout << " "; Sleep(10); cout << "d"; Sleep(10); cout << "o"; Sleep(10); cout << " "; Sleep(10); cout << "o"; Sleep(10); cout << "s"; Sleep(10); cout << "t"; Sleep(10); cout << "r"; Sleep(10); cout << "z"; Sleep(10); cout << "a"; Sleep(10); cout << "\210"; Sleep(10); cout << "u"; Sleep(10); cout << ","; Sleep(10); cout << "\n";
	cout << " a"; Sleep(10); cout << " "; Sleep(10); cout << "n"; Sleep(10); cout << "a"; Sleep(10); cout << "s"; Sleep(10); cout << "t"; Sleep(10); cout << "\251"; Sleep(10); cout << "p"; Sleep(10); cout << "n"; Sleep(10); cout << "i"; Sleep(10); cout << "e"; Sleep(10); cout << " "; Sleep(10); cout << "s"; Sleep(10); cout << "t"; Sleep(10); cout << "r"; Sleep(10); cout << "z"; Sleep(10); cout << "e"; Sleep(10); cout << "l"; Sleep(10); cout << "a"; Sleep(10); cout << " "; Sleep(10);
	for (int i = 0; i < _gracz2.size(); i++)
	{
		cout << _gracz2[i];
		Sleep(10);
	}
	cout << "."; Sleep(10); cout << "\n";
	cout << " W"; Sleep(10); cout << "y"; Sleep(10); cout << "g"; Sleep(10); cout << "r"; Sleep(10); cout << "y"; Sleep(10); cout << "w"; Sleep(10); cout << "a"; Sleep(10); cout << " "; Sleep(10); cout << "t"; Sleep(10); cout << "e"; Sleep(10); cout << "n"; Sleep(10); cout << ","; Sleep(10); cout << " "; Sleep(10); cout << "k"; Sleep(10); cout << "t"; Sleep(10); cout << "o"; Sleep(10); cout << " "; Sleep(10); cout << "z"; Sleep(10); cout << "a"; Sleep(10); cout << "t"; Sleep(10); cout << "o"; Sleep(10); cout << "p"; Sleep(10); cout << "i"; Sleep(10); cout << " "; Sleep(10); cout << "w"; Sleep(10); cout << "s"; Sleep(10); cout << "z"; Sleep(10); cout << "y"; Sleep(10); cout << "s"; Sleep(10); cout << "t"; Sleep(10); cout << "k"; Sleep(10); cout << "i"; Sleep(10); cout << "e"; Sleep(10); cout << " "; Sleep(10); cout << "s"; Sleep(10); cout << "t"; Sleep(10); cout << "a"; Sleep(10); cout << "t"; Sleep(10); cout << "k"; Sleep(10); cout << "i"; Sleep(10); cout << " "; Sleep(10); cout << "p"; Sleep(10); cout << "r"; Sleep(10); cout << "z"; Sleep(10); cout << "e"; Sleep(10); cout << "c"; Sleep(10); cout << "i"; Sleep(10); cout << "w"; Sleep(10); cout << "n"; Sleep(10); cout << "i"; Sleep(10); cout << "k"; Sleep(10); cout << "a"; Sleep(10); cout << "."; Sleep(10); cout << "\n";
	cout << " I"; Sleep(10); cout << " "; Sleep(10); cout << "t"; Sleep(10); cout << "y"; Sleep(10); cout << "l"; Sleep(10); cout << "e"; Sleep(10); cout << "!"; Sleep(10); cout << " "; Sleep(10); cout << "Z"; Sleep(10); cout << "a"; Sleep(10); cout << "\210"; Sleep(10); cout << "a"; Sleep(10); cout << "p"; Sleep(10); cout << "i"; Sleep(10); cout << "e"; Sleep(10); cout << "c"; Sleep(10); cout << "i"; Sleep(10); cout << "e"; Sleep(10); cout << " "; Sleep(10); cout << "p"; Sleep(10); cout << "o"; Sleep(10); cout << "d"; Sleep(10); cout << "c"; Sleep(10); cout << "z"; Sleep(10); cout << "a"; Sleep(10); cout << "s"; Sleep(10); cout << " "; Sleep(10); cout << "g"; Sleep(10); cout << "r"; Sleep(10); cout << "y"; Sleep(10); cout << "."; Sleep(10); cout << "\n\n";
	Sleep(1000);
	cout << " W"; Sleep(10); cout << "c"; Sleep(10); cout << "i"; Sleep(10); cout << "\230"; Sleep(10); cout << "n"; Sleep(10); cout << "i"; Sleep(10); cout << "j"; Sleep(10); cout << " "; Sleep(10); cout << "d"; Sleep(10); cout << "o"; Sleep(10); cout << "w"; Sleep(10); cout << "o"; Sleep(10); cout << "l"; Sleep(10); cout << "n"; Sleep(10); cout << "y"; Sleep(10); cout << " "; Sleep(10); cout << "k"; Sleep(10); cout << "l"; Sleep(10); cout << "a"; Sleep(10); cout << "w"; Sleep(10); cout << "i"; Sleep(10); cout << "s"; Sleep(10); cout << "z"; Sleep(10); cout << ","; Sleep(10); cout << " "; Sleep(10); cout << "\276"; Sleep(10); cout << "e"; Sleep(10); cout << "b"; Sleep(10); cout << "y"; Sleep(10); cout << " "; Sleep(10); cout << "k"; Sleep(10); cout << "o"; Sleep(10); cout << "n"; Sleep(10); cout << "t"; Sleep(10); cout << "y"; Sleep(10); cout << "n"; Sleep(10); cout << "u"; Sleep(10); cout << "o"; Sleep(10); cout << "w"; Sleep(10); cout << "a"; Sleep(10); cout << "\206"; Sleep(10); cout << "."; Sleep(10); cout << " ";
	#pragma endregion NAPIS "Zasady są proste- każdy gracz ma przed sobą planszę 10x10 z losowo ustawionymi statkami. Każdy ma 1 statek czteromasztowy, 2 statki trzymasztowe, 3 statki dwumasztowe oraz 1 statek jednomasztowy. Każdy gracz podczas swojej kolejki oddaje jeden strzał - wybiera pole, które ma zostać zatopione. Najpierw GRACZ 1 wybiera pole do ostrzału, a następnie strzela GRACZ 2. Wygrywa ten, kto zatopi wszystkie statki przeciwnika. I tyle! Załapiecie podczas gry. Wciśnij dowolny klawisz, żeby kontynuować."
	ShowConsoleCursor(1);
	_nic = _getch();
	ShowConsoleCursor(0);
	_zas = 0;
	if (_doGry)
	{
		_doGry = 0;
		system("cls"); Sleep(500);
	}
	else
		menu();
}

void statek4(int plansza[10][10])
{
	int wiersz{}, kolumna{}, kierunek{}, n{};

	while (n < 1)
	{
		wiersz = pole(generator);
		kolumna = pole(generator);
		kierunek = kier(generator);

		#pragma region POZIOMY
		if (kierunek == 1)
		{
			if (kolumna + 3 <= 9)
			{
				#pragma region WYPIS CZWÓREK
				while (n < 4)
				{
					plansza[wiersz][kolumna + n] = 4;
					n++;
				}
				#pragma endregion WYPIS CZWÓREK

				#pragma region USTAW -1
								// -1 -> 'x'
				if (wiersz != 0) // 4up
					for (int i = 0; i < 4; i++)
						plansza[wiersz - 1][kolumna + i] = -1;

				if (wiersz != 9) // 4down
					for (int i = 0; i < 4; i++)
						plansza[wiersz + 1][kolumna + i] = -1;

				if (kolumna != 0) // 1left
					plansza[wiersz][kolumna - 1] = -1;

				if (kolumna + 3 != 9) // 1right
					plansza[wiersz][kolumna + 4] = -1;

				if (kolumna != 0 && wiersz != 0) // left_up
					plansza[wiersz - 1][kolumna - 1] = -1;

				if (kolumna + 3 != 9 && wiersz != 0) // right_up
					plansza[wiersz - 1][kolumna + 4] = -1;

				if (kolumna != 0 && wiersz != 9) // left_down
					plansza[wiersz + 1][kolumna - 1] = -1;

				if (kolumna + 3 != 9 && wiersz != 9) // right_down
					plansza[wiersz + 1][kolumna + 4] = -1;
				#pragma endregion USTAW -1
			}
		}
		#pragma endregion POZIOMY

		#pragma region PIONOWY
		else if (kierunek == 2)
		{
			if (wiersz + 3 <= 9)
			{
				#pragma region WYPIS CZWÓREK
				while (n < 4)
				{
					plansza[wiersz + n][kolumna] = 4;
					n++;
				}
				#pragma endregion WYPIS CZWÓREK

				#pragma region USTAW -1
								// -1 -> 'x'
				if (wiersz != 0) // 1up
					plansza[wiersz - 1][kolumna] = -1;

				if (wiersz + 3 != 9) // 1down
					plansza[wiersz + 4][kolumna] = -1;

				if (kolumna != 0) // 4left
					for (int i = 0; i < 4; i++)
						plansza[wiersz + i][kolumna - 1] = -1;

				if (kolumna != 9) // 4right
					for (int i = 0; i < 4; i++)
						plansza[wiersz + i][kolumna + 1] = -1;

				if (kolumna != 0 && wiersz != 0) // left_up
					plansza[wiersz - 1][kolumna - 1] = -1;

				if (kolumna != 9 && wiersz != 0) // right_up
					plansza[wiersz - 1][kolumna + 1] = -1;

				if (kolumna != 0 && wiersz + 3 != 9) // left_down
					plansza[wiersz + 4][kolumna - 1] = -1;

				if (kolumna != 9 && wiersz + 3 != 9) // right_down
					plansza[wiersz + 4][kolumna + 1] = -1;
				#pragma endregion USTAW -1
			}
		}
		#pragma endregion PIONOWY
	}
}

void statek3(int plansza[10][10])
{
	int wiersz{}, kolumna{}, kierunek{}, n{};

	while (n < 1)
	{
		wiersz = pole(generator);
		kolumna = pole(generator);
		kierunek = kier(generator);

		#pragma region POZIOMY
		if (kierunek == 1)
		{
			if (kolumna + 2 <= 9 && (plansza[wiersz][kolumna] == 0 && plansza[wiersz][kolumna + 1] == 0 && plansza[wiersz][kolumna + 2] == 0)) // kwadraty
			{
				#pragma region WYPIS TRÓJEK
				while (n < 3)
				{
					plansza[wiersz][kolumna + n] = 3;
					n++;
				}
				#pragma endregion WYPIS TRÓJEK

				#pragma region USTAW -1
								// -1 -> 'x'
				if (wiersz != 0) // 3up
					for (int i = 0; i < 3; i++)
						plansza[wiersz - 1][kolumna + i] = -1;

				if (wiersz != 9) // 3down
					for (int i = 0; i < 3; i++)
						plansza[wiersz + 1][kolumna + i] = -1;

				if (kolumna != 0) // 1left
					plansza[wiersz][kolumna - 1] = -1;

				if (kolumna + 2 != 9) // 1right
					plansza[wiersz][kolumna + 3] = -1;

				if (kolumna != 0 && wiersz != 0) // left_up
					plansza[wiersz - 1][kolumna - 1] = -1;

				if (kolumna + 2 != 9 && wiersz != 0) // right_up
					plansza[wiersz - 1][kolumna + 3] = -1;

				if (kolumna != 0 && wiersz != 9) // left_down
					plansza[wiersz + 1][kolumna - 1] = -1;

				if (kolumna + 2 != 9 && wiersz != 9) // right_down
					plansza[wiersz + 1][kolumna + 3] = -1;
				#pragma endregion USTAW -1
			}
		}
		#pragma endregion POZIOMY

		#pragma region PIONOWY
		else if (kierunek == 2)
		{
			if (wiersz + 2 <= 9 && (plansza[wiersz][kolumna] == 0 && plansza[wiersz + 1][kolumna] == 0 && plansza[wiersz + 2][kolumna] == 0)) // kwadraty
			{
				#pragma region WYPIS TRÓJEK
				while (n < 3)
				{
					plansza[wiersz + n][kolumna] = 3;
					n++;
				}
				#pragma endregion WYPIS TRÓJEK

				#pragma region USTAW -1
								// -1 -> 'x'
				if (wiersz != 0) // 1up
					plansza[wiersz - 1][kolumna] = -1;

				if (wiersz + 2 != 9) // 1down
					plansza[wiersz + 3][kolumna] = -1;

				if (kolumna != 0) // 3left
					for (int i = 0; i < 3; i++)
						plansza[wiersz + i][kolumna - 1] = -1;

				if (kolumna != 9) // 3right
					for (int i = 0; i < 3; i++)
						plansza[wiersz + i][kolumna + 1] = -1;

				if (kolumna != 0 && wiersz != 0) // left_up
					plansza[wiersz - 1][kolumna - 1] = -1;

				if (kolumna != 9 && wiersz != 0) // right_up
					plansza[wiersz - 1][kolumna + 1] = -1;

				if (kolumna != 0 && wiersz + 2 != 9) // left_down
					plansza[wiersz + 3][kolumna - 1] = -1;

				if (kolumna != 9 && wiersz + 2 != 9) // right_down
					plansza[wiersz + 3][kolumna + 1] = -1;
				#pragma endregion USTAW -1
			}
		}
		#pragma endregion PIONOWY
	}
}

void statek2(int plansza[10][10])
{
	int wiersz{}, kolumna{}, kierunek{}, n{};

	while (n < 1)
	{
		wiersz = pole(generator);
		kolumna = pole(generator);
		kierunek = kier(generator);

		#pragma region POZIOMY
		if (kierunek == 1)
		{
			if (kolumna + 1 <= 9 && (plansza[wiersz][kolumna] == 0 && plansza[wiersz][kolumna + 1] == 0)) // kwadraty
			{
				#pragma region WYPIS DWÓJEK
				while (n < 2)
				{
					plansza[wiersz][kolumna + n] = 2;
					n++;
				}
				#pragma endregion WYPIS DWÓJEK

				#pragma region USTAW -1
								// -1 -> 'x'
				if (wiersz != 0) // 2up
					for (int i = 0; i < 2; i++)
						plansza[wiersz - 1][kolumna + i] = -1;

				if (wiersz != 9) // 2down
					for (int i = 0; i < 2; i++)
						plansza[wiersz + 1][kolumna + i] = -1;

				if (kolumna != 0) // 1left
					plansza[wiersz][kolumna - 1] = -1;

				if (kolumna + 1 != 9) // 1right
					plansza[wiersz][kolumna + 2] = -1;

				if (kolumna != 0 && wiersz != 0) // left_up
					plansza[wiersz - 1][kolumna - 1] = -1;

				if (kolumna + 1 != 9 && wiersz != 0) // right_up
					plansza[wiersz - 1][kolumna + 2] = -1;

				if (kolumna != 0 && wiersz != 9) // left_down
					plansza[wiersz + 1][kolumna - 1] = -1;

				if (kolumna + 1 != 9 && wiersz != 9) // right_down
					plansza[wiersz + 1][kolumna + 2] = -1;
				#pragma endregion USTAW -1
			}
		}
		#pragma endregion POZIOMY

		#pragma region PIONOWY
		else if (kierunek == 2)
		{
			if (wiersz + 1 <= 9 && (plansza[wiersz][kolumna] == 0 && plansza[wiersz + 1][kolumna] == 0)) // kwadraty
			{
				#pragma region WYPIS DWÓJEK
				while (n < 2)
				{
					plansza[wiersz + n][kolumna] = 2;
					n++;
				}
				#pragma endregion WYPIS DWÓJEK

				#pragma region USTAW -1
								// -1 -> 'x'
				if (wiersz != 0) // 1up
					plansza[wiersz - 1][kolumna] = -1;

				if (wiersz + 1 != 9) // 1down
					plansza[wiersz + 2][kolumna] = -1;

				if (kolumna != 0) // 2left
					for (int i = 0; i < 2; i++)
						plansza[wiersz + i][kolumna - 1] = -1;

				if (kolumna != 9) // 2right
					for (int i = 0; i < 2; i++)
						plansza[wiersz + i][kolumna + 1] = -1;

				if (kolumna != 0 && wiersz != 0) // left_up
					plansza[wiersz - 1][kolumna - 1] = -1;

				if (kolumna != 9 && wiersz != 0) // right_up
					plansza[wiersz - 1][kolumna + 1] = -1;

				if (kolumna != 0 && wiersz + 1 != 9) // left_down
					plansza[wiersz + 2][kolumna - 1] = -1;

				if (kolumna != 9 && wiersz + 1 != 9) // right_down
					plansza[wiersz + 2][kolumna + 1] = -1;
				#pragma endregion USTAW -1
			}
		}
		#pragma endregion PIONOWY
	}
}

void statek1(int plansza[10][10])
{
	int wiersz{}, kolumna{}, n{};

	while (n < 1)
	{
		wiersz = pole(generator);
		kolumna = pole(generator);

		if (kolumna <= 9 && (plansza[wiersz][kolumna] == 0))
		{
			#pragma region WYPIS JEDYNKI
			plansza[wiersz][kolumna] = 1;
			n++;
			#pragma endregion WYPIS JEDYNKI

			#pragma region USTAW -1
						// -1 -> 'x'
			if (wiersz != 0) // 1up
				plansza[wiersz - 1][kolumna] = -1;

			if (wiersz != 9) // 1down
				plansza[wiersz + 1][kolumna] = -1;

			if (kolumna != 0) // 1left
				plansza[wiersz][kolumna - 1] = -1;

			if (kolumna != 9) // 1right
				plansza[wiersz][kolumna + 1] = -1;

			if (kolumna != 0 && wiersz != 0) // left_up
				plansza[wiersz - 1][kolumna - 1] = -1;

			if (kolumna != 9 && wiersz != 0) // right_up
				plansza[wiersz - 1][kolumna + 1] = -1;

			if (kolumna != 0 && wiersz != 9) // left_down
				plansza[wiersz + 1][kolumna - 1] = -1;

			if (kolumna != 9 && wiersz != 9) // right_down
				plansza[wiersz + 1][kolumna + 1] = -1;
			#pragma endregion USTAW -1
		}
	}
}

void losowanie_twoja_plansza1()
{
	#pragma region WYPEŁNIENIE TWOJA_PLANSZA1 ZERAMI
	for (int i = 0; i <= 9; i++)
		for (int j = 0; j <= 9; j++)
			twoja_plansza1[i][j] = 0; // PÓŹNIEJ -> KWADRATY
	#pragma endregion WYPEŁNIENIE TWOJA_PLANSZA1 ZERAMI

	#pragma region WYPELNIENIE PLANSZA_PRZECIWNIKA1 ZERAMI
	for (int i = 0; i <= 9; i++)
		for (int j = 0; j <= 9; j++)
			plansza_przeciwnika1[i][j] = 0; // PÓŹNIEJ -> KWADRATY
	#pragma endregion WYPELNIENIE PLANSZA_PRZECIWNIKA1 ZERAMI

	#pragma region LOSOWANIE STATKÓW TWOJA_PLANSZA1
	statek4(twoja_plansza1);
	statek3(twoja_plansza1); statek3(twoja_plansza1);
	statek2(twoja_plansza1); statek2(twoja_plansza1); statek2(twoja_plansza1);
	statek1(twoja_plansza1); statek1(twoja_plansza1); statek1(twoja_plansza1); statek1(twoja_plansza1);
	#pragma endregion LOSOWANIE STATKÓW TWOJA_PLANSZA1

		//#pragma region USUWANIE 'x' Z TWOJA_PLANSZA1
		//	for (int i = 0; i <= 9; i++)
		//	{
		//		for (int j = 0; j <= 9; j++)
		//		{
		//			if (twoja_plansza1[i][j] == -1)
		//			{
		//				twoja_plansza1[i][j] = 0;
		//			}
		//		}
		//	}
		//#pragma endregion USUWANIE 'x' Z TWOJA_PLANSZA1
}

void losowanie_twoja_plansza2()
{
	#pragma region WYPELNIENIE TWOJA_PLANSZA2 ZERAMI
	for (int i = 0; i <= 9; i++)
		for (int j = 0; j <= 9; j++)
			twoja_plansza2[i][j] = 0; // PÓŹNIEJ -> KWADRATY
	#pragma endregion WYPELNIENIE TWOJA_PLANSZA2 ZERAMI

	#pragma region WYPELNIENIE PLANSZA_PRZECIWNIKA2 ZERAMI
	for (int i = 0; i <= 9; i++)
		for (int j = 0; j <= 9; j++)
			plansza_przeciwnika2[i][j] = 0; // PÓŹNIEJ -> KWADRATY
	#pragma endregion WYPELNIENIE PLANSZA_PRZECIWNIKA2 ZERAMI

	#pragma region LOSOWANIE STATKÓW TWOJA_PLANSZA2
	statek4(twoja_plansza2);
	statek3(twoja_plansza2); statek3(twoja_plansza2);
	statek2(twoja_plansza2); statek2(twoja_plansza2); statek2(twoja_plansza2);
	statek1(twoja_plansza2); statek1(twoja_plansza2); statek1(twoja_plansza2); statek1(twoja_plansza2);
	#pragma endregion LOSOWANIE STATKÓW TWOJA_PLANSZA2

		//#pragma region USUWANIE 'x' Z TWOJA_PLANSZA2
		//	for (int i = 0; i <= 9; i++)
		//	{
		//		for (int j = 0; j <= 9; j++)
		//		{
		//			if (twoja_plansza2[i][j] == -1)
		//			{
		//				twoja_plansza2[i][j] = 0;
		//			}
		//		}
		//	}
		//#pragma endregion USUWANIE 'x' Z TWOJA_PLANSZA2
}

void strzal_gracza()
{
	string strzal{}; char litera{}; int liczba{}, wiersz{}, kolumna{};

		////// GRACZ 1
	if (_runda % 2 == 0)
	{
		ShowConsoleCursor(0);
		system("cls");
		Sleep(500);

		#pragma region NAPIS "GRACZ1, wciśnij dowolny klawisz, żeby kontynuować."
		cout << "\n  ";
		for (int i = 0; i < _gracz1.size(); i++)
		{
			cout << _gracz1[i];
			Sleep(10);
		}
		cout << ","; Sleep(10); cout << " "; Sleep(10); cout << "w"; Sleep(10); cout << "c"; Sleep(10); cout << "i"; Sleep(10); cout << "\230"; Sleep(10); cout << "n"; Sleep(10); cout << "i"; Sleep(10); cout << "j"; Sleep(10); cout << " "; Sleep(10); cout << "d"; Sleep(10); cout << "o"; Sleep(10); cout << "w"; Sleep(10); cout << "o"; Sleep(10); cout << "l"; Sleep(10); cout << "n"; Sleep(10); cout << "y"; Sleep(10); cout << " "; Sleep(10); cout << "k"; Sleep(10); cout << "l"; Sleep(10); cout << "a"; Sleep(10); cout << "w"; Sleep(10); cout << "i"; Sleep(10); cout << "s"; Sleep(10); cout << "z"; Sleep(10); cout << ","; Sleep(10); cout << " "; Sleep(10); cout << "\276"; Sleep(10); cout << "e"; Sleep(10); cout << "b"; Sleep(10); cout << "y"; Sleep(10); cout << " "; Sleep(10); cout << "k"; Sleep(10); cout << "o"; Sleep(10); cout << "n"; Sleep(10); cout << "t"; Sleep(10); cout << "y"; Sleep(10); cout << "n"; Sleep(10); cout << "u"; Sleep(10); cout << "o"; Sleep(10); cout << "w"; Sleep(10); cout << "a"; Sleep(10); cout << "\206"; Sleep(10); cout << "."; Sleep(10); cout << " ";
		Sleep(300);
		while (_kbhit())
			_nic = _getch();
		ShowConsoleCursor(1);
		_nic = _getch();
		#pragma endregion NAPIS "GRACZ1, wciśnij dowolny klawisz, żeby kontynuować."

		ShowConsoleCursor(0);
		system("cls");
		Sleep(500);

	wypis1:
		ShowConsoleCursor(0);

		//
		#pragma region WYPIS PLANSZ No1
		system("cls");
		#pragma region NAPISY "Ruch gracza: GRACZ1", "PLANSZA PRZECIWNIKA:" i "TWOJA PLANSZA:"
		cout << "\n  Ruch gracza: " << _gracz1 << "\n\n";
		Sleep(20);
		cout.width(24);
		cout << "PLANSZA PRZECIWNIKA:";
		cout.width(29);
		cout << "TWOJA PLANSZA:\n\n";
		Sleep(20);
		#pragma endregion NAPISY "Ruch gracza: GRACZ1", "PLANSZA PRZECIWNIKA:" i "TWOJA PLANSZA:"
		#pragma region WYPIS LITER A - J PLANSZA_PRZECIWNIKA1 (NUMEROWANIE KOLUMN)
		char wier = 'A'; int lit{};
		cout.width(4); cout << " ";
		for (int i = 0; i <= 9; i++)
		{
			cout.width(2);
			cout << static_cast<char>(wier + lit);
			lit++;
		}
		lit = 0;
		#pragma endregion WYPIS LITER A - J PLANSZA_PRZECIWNIKA1 (NUMEROWANIE KOLUMN)
		#pragma region WYPIS LITER A - J TWOJA_PLANSZA1 (NUMEROWANIE KOLUMN)
		cout.width(10); cout << " ";
		for (int i = 0; i <= 9; i++)
		{
			cout.width(2);
			cout << static_cast<char>(wier + lit);
			lit++;
		}
		cout << endl; lit = 0;
		Sleep(10);
		#pragma endregion WYPIS LITER A - J TWOJA_PLANSZA1 (NUMEROWANIE KOLUMN)
		#pragma region WYPIS PLANSZA_PRZECIWNIKA1 i TWOJA_PLANSZA1
		for (int i = 0; i <= 9; i++)
		{
			#pragma region WYPIS PLANSZA_PRZECIWNIKA1
			cout.width(3);
			cout << i + 1 << "."; // NUMEROWANIE WIERSZY PLANSZA_PRZECIWNIKA
			for (int j = 0; j <= 9; j++)
			{
				cout.width(2);
				if (plansza_przeciwnika1[i][j] == -1 || plansza_przeciwnika1[i][j] == -2)
					cout << (unsigned char)0x9E; // 'x'
				else if (plansza_przeciwnika1[i][j] == 0)
					cout << (unsigned char)0xFE; // kwadraty
				else if (plansza_przeciwnika1[i][j] > 4)
					cout << (unsigned char)0x4F; // 'O'
				else
					cout << plansza_przeciwnika1[i][j];
			}
			#pragma endregion WYPIS PLANSZA_PRZECIWNIKA1

			cout.width(6);
			cout << " ";

			#pragma region WYPIS TWOJA_PLANSZA1
			cout.width(3);
			cout << i + 1 << "."; // NUMEROWANIE WIERSZY TWOJA_PLANSZA
			for (int j = 0; j <= 9; j++)
			{
				cout.width(2);
				if (twoja_plansza1[i][j] == 0 || twoja_plansza1[i][j] == -1)
					cout << (unsigned char)0xFE; // kwadraty
				else if (twoja_plansza1[i][j] == -2)
					cout << (unsigned char)0x9E; // 'x'
				else if (twoja_plansza1[i][j] > 4)
					cout << (unsigned char)0x4F; // 'O'
				else
					cout << twoja_plansza1[i][j];
			}
			#pragma endregion WYPIS TWOJA_PLANSZA1
			cout << endl;
			Sleep(10);
		}
		#pragma endregion WYPIS PLANSZA_PRZECIWNIKA1 i TWOJA_PLANSZA1

		#pragma endregion WYPIS PLANSZ No1
		//

		Sleep(700);
		#pragma region NAPIS "Wpisz literę kolumny [A-J] oraz numer wiersza [1-10] do strzału:"
		cout << "\n  W"; Sleep(10); cout << "p"; Sleep(10); cout << "i"; Sleep(10); cout << "s"; Sleep(10); cout << "z"; Sleep(10); cout << " "; Sleep(10); cout << "l"; Sleep(10); cout << "i"; Sleep(10); cout << "t"; Sleep(10); cout << "e"; Sleep(10); cout << "r"; Sleep(10); cout << "\251"; Sleep(10); cout << " "; Sleep(10); cout << "k"; Sleep(10); cout << "o"; Sleep(10); cout << "l"; Sleep(10); cout << "u"; Sleep(10); cout << "m"; Sleep(10); cout << "n"; Sleep(10); cout << "y"; Sleep(10); cout << " "; Sleep(10); cout << "["; Sleep(10); cout << "A"; Sleep(10); cout << "-"; Sleep(10); cout << "J"; Sleep(10); cout << "]"; Sleep(10); cout << " "; Sleep(10); cout << "o"; Sleep(10); cout << "r"; Sleep(10); cout << "a"; Sleep(10); cout << "z"; Sleep(10); cout << " "; Sleep(10); cout << "n"; Sleep(10); cout << "u"; Sleep(10); cout << "m"; Sleep(10); cout << "e"; Sleep(10); cout << "r"; Sleep(10); cout << " "; Sleep(10); cout << "w"; Sleep(10); cout << "i"; Sleep(10); cout << "e"; Sleep(10); cout << "r"; Sleep(10); cout << "s"; Sleep(10); cout << "z"; Sleep(10); cout << "a"; Sleep(10); cout << " "; Sleep(10); cout << "["; Sleep(10); cout << "1"; Sleep(10); cout << "-"; Sleep(10); cout << "1"; Sleep(10); cout << "0"; Sleep(10); cout << "]"; Sleep(10); cout << " "; Sleep(10); cout << "d"; Sleep(10); cout << "o"; Sleep(10); cout << " "; Sleep(10); cout << "s"; Sleep(10); cout << "t"; Sleep(10); cout << "r"; Sleep(10); cout << "z"; Sleep(10); cout << "a"; Sleep(10); cout << "\210"; Sleep(10); cout << "u"; Sleep(10); cout << ": "; Sleep(10);
		#pragma endregion NAPIS "Wpisz literę kolumny [A-J] oraz numer wiersza [1-10] do strzału:"
		ShowConsoleCursor(1);
		getline(cin, strzal);
		ShowConsoleCursor(0);

		#pragma region SPRAWDZENIE POPRAWNOŚCI ZAPISU
			// LITERA i LICZBA
		if (isalpha(strzal[0]) && isdigit(strzal[1]) && (isdigit(strzal[2]) || strzal[2] == '\0'))
		{
			litera = strzal[0];
			if (strzal.size() == 2)      // 1 CYFRA
				liczba = stoi(strzal.substr(1, 1));
			else if (strzal.size() == 3) // 2 CYFRY
				liczba = stoi(strzal.substr(1, 2));
		}
			// LICZBA (1 CYFRA) i LITERA
		else if (isdigit(strzal[0]) && isalpha(strzal[1]))
		{
			litera = strzal[1];
			liczba = stoi(strzal.substr(0, 1));
		}
			// LICZBA (2 CYFRY) i LITERA
		else if (isdigit(strzal[0]) && isdigit(strzal[1]) && isalpha(strzal[2]))
		{
			litera = strzal[2];
			liczba = stoi(strzal.substr(0, 2));
		}
		else
		{
			#pragma region NAPIS "Błędne współrzędne, spróbuj ponownie!"
			cout << "\n  B"; Sleep(10); cout << "\210"; Sleep(10); cout << "\251"; Sleep(10); cout << "d"; Sleep(10); cout << "n"; Sleep(10); cout << "e"; Sleep(10); cout << " "; Sleep(10); cout << "w"; Sleep(10); cout << "s"; Sleep(10); cout << "p"; Sleep(10); cout << "\242"; Sleep(10); cout << "\210"; Sleep(10); cout << "r"; Sleep(10); cout << "z"; Sleep(10); cout << "\251"; Sleep(10); cout << "d"; Sleep(10); cout << "n"; Sleep(10); cout << "e"; Sleep(10); cout << ","; Sleep(10); cout << " "; Sleep(10); cout << "s"; Sleep(10); cout << "p"; Sleep(10); cout << "r"; Sleep(10); cout << "\242"; Sleep(10); cout << "b"; Sleep(10); cout << "u"; Sleep(10); cout << "j"; Sleep(10); cout << " "; Sleep(10); cout << "p"; Sleep(10); cout << "o"; Sleep(10); cout << "n"; Sleep(10); cout << "o"; Sleep(10); cout << "w"; Sleep(10); cout << "n"; Sleep(10); cout << "i"; Sleep(10); cout << "e"; Sleep(10); cout << "!";
			#pragma endregion NAPIS "Błędne współrzędne, spróbuj ponownie!"
			Sleep(1500);
			goto wypis1;
		}

		if (litera >= 65 && litera <= 74)
			kolumna = litera - 65;
		else if (litera >= 97 && litera <= 106)
			kolumna = litera - 97;
		wiersz = liczba - 1;

		#pragma endregion SPRAWDZENIE POPRAWNOŚCI ZAPISU

		#pragma region WPISANIE W PLANSZE
		if (((litera >= 65 && litera <= 74) || (litera >= 97 && litera <= 106)) && (liczba >= 1 && liczba <= 10))
		{
				// 'x' lub PUSTE
			if (twoja_plansza2[wiersz][kolumna] == -1 || twoja_plansza2[wiersz][kolumna] == 0)
			{
				plansza_przeciwnika1[wiersz][kolumna] = -2;
				twoja_plansza2[wiersz][kolumna] = -2;
			}
				// JUŻ TRAFIONE
			else if (twoja_plansza2[wiersz][kolumna] == -2 || twoja_plansza2[wiersz][kolumna] > 4)
			{
				#pragma region NAPIS "Podane pole zostało już trafione, wybierz inne!"
				cout << "\n  P"; Sleep(10); cout << "o"; Sleep(10); cout << "d"; Sleep(10); cout << "a"; Sleep(10); cout << "n"; Sleep(10); cout << "e"; Sleep(10); cout << " "; Sleep(10); cout << "p"; Sleep(10); cout << "o"; Sleep(10); cout << "l"; Sleep(10); cout << "e"; Sleep(10); cout << " "; Sleep(10); cout << "z"; Sleep(10); cout << "o"; Sleep(10); cout << "s"; Sleep(10); cout << "t"; Sleep(10); cout << "a"; Sleep(10); cout << "\210"; Sleep(10); cout << "o"; Sleep(10); cout << " "; Sleep(10); cout << "j"; Sleep(10); cout << "u"; Sleep(10); cout << "\276"; Sleep(10); cout << " "; Sleep(10); cout << "t"; Sleep(10); cout << "r"; Sleep(10); cout << "a"; Sleep(10); cout << "f"; Sleep(10); cout << "i"; Sleep(10); cout << "o"; Sleep(10); cout << "n"; Sleep(10); cout << "e"; Sleep(10); cout << ","; Sleep(10); cout << " "; Sleep(10); cout << "w"; Sleep(10); cout << "y"; Sleep(10); cout << "b"; Sleep(10); cout << "i"; Sleep(10); cout << "e"; Sleep(10); cout << "r"; Sleep(10); cout << "z"; Sleep(10); cout << " "; Sleep(10); cout << "i"; Sleep(10); cout << "n"; Sleep(10); cout << "n"; Sleep(10); cout << "e"; Sleep(10); cout << "!";
				#pragma endregion NAPIS "Podane pole zostało już trafione, wybierz inne!"
				Sleep(1500);
				goto wypis1;
			}
				// TRAFIENIE
			else
			{
				plansza_przeciwnika1[wiersz][kolumna] += 10;
				twoja_plansza2[wiersz][kolumna] += 10;
					// DLA 4
				if (twoja_plansza2[wiersz][kolumna] == 14)
				{
					if (((twoja_plansza2[wiersz - 1][kolumna] == 14 && twoja_plansza2[wiersz - 2][kolumna] == 14 && twoja_plansza2[wiersz - 3][kolumna] == 14) || (twoja_plansza2[wiersz + 1][kolumna] == 14 && twoja_plansza2[wiersz + 2][kolumna] == 14 && twoja_plansza2[wiersz + 3][kolumna] == 14) || (twoja_plansza2[wiersz][kolumna - 1] == 14 && twoja_plansza2[wiersz][kolumna - 2] == 14 && twoja_plansza2[wiersz][kolumna - 3] == 14) || (twoja_plansza2[wiersz][kolumna + 1] == 14 && twoja_plansza2[wiersz][kolumna + 2] == 14 && twoja_plansza2[wiersz][kolumna + 3] == 14)) || ((twoja_plansza2[wiersz - 1][kolumna] == 14 && twoja_plansza2[wiersz - 2][kolumna] == 14 && twoja_plansza2[wiersz + 1][kolumna] == 14) || (twoja_plansza2[wiersz + 1][kolumna] == 14 && twoja_plansza2[wiersz + 2][kolumna] == 14 && twoja_plansza2[wiersz - 1][kolumna] == 14) || (twoja_plansza2[wiersz][kolumna - 1] == 14 && twoja_plansza2[wiersz][kolumna - 2] == 14 && twoja_plansza2[wiersz][kolumna + 1] == 14) || (twoja_plansza2[wiersz][kolumna + 1] == 14 && twoja_plansza2[wiersz][kolumna + 2] == 14 && twoja_plansza2[wiersz][kolumna - 1] == 14)))
					{
							// POZIOMY
						if (twoja_plansza2[wiersz][kolumna - 1] == 14 || twoja_plansza2[wiersz][kolumna + 1] == 14)
						{
							if (twoja_plansza2[wiersz][kolumna - 1] == 14 && twoja_plansza2[wiersz][kolumna + 1] == 14 && twoja_plansza2[wiersz][kolumna + 2] == 14)
								kolumna -= 1;
							else if (twoja_plansza2[wiersz][kolumna - 1] == 14 && twoja_plansza2[wiersz][kolumna + 1] == 14 && twoja_plansza2[wiersz][kolumna - 2] == 14)
								kolumna -= 2;
							else if (twoja_plansza2[wiersz][kolumna - 1] == 14 && twoja_plansza2[wiersz][kolumna + 1] != 14)
								kolumna -= 3;

							#pragma region USTAW -2 dla TWOJA_PLANSZA2
								// -2 -> '0'
							if (wiersz != 0) // 4up
								for (int i = 0; i < 4; i++)
									twoja_plansza2[wiersz - 1][kolumna + i] = -2;

							if (wiersz != 9) // 4down
								for (int i = 0; i < 4; i++)
									twoja_plansza2[wiersz + 1][kolumna + i] = -2;

							if (kolumna != 0) // 1left
								twoja_plansza2[wiersz][kolumna - 1] = -2;

							if (kolumna + 3 != 9) // 1right
								twoja_plansza2[wiersz][kolumna + 4] = -2;

							if (kolumna != 0 && wiersz != 0) // left_up
								twoja_plansza2[wiersz - 1][kolumna - 1] = -2;

							if (kolumna + 3 != 9 && wiersz != 0) // right_up
								twoja_plansza2[wiersz - 1][kolumna + 4] = -2;

							if (kolumna != 0 && wiersz != 9) // left_down
								twoja_plansza2[wiersz + 1][kolumna - 1] = -2;

							if (kolumna + 3 != 9 && wiersz != 9) // right_down
								twoja_plansza2[wiersz + 1][kolumna + 4] = -2;
							#pragma endregion USTAW -2 dla TWOJA_PLANSZA2

							#pragma region USTAW -2 dla PLANSZA_PRZECIWNIKA1
								// -2 -> '0'
							if (wiersz != 0) // 4up
								for (int i = 0; i < 4; i++)
									plansza_przeciwnika1[wiersz - 1][kolumna + i] = -2;

							if (wiersz != 9) // 4down
								for (int i = 0; i < 4; i++)
									plansza_przeciwnika1[wiersz + 1][kolumna + i] = -2;

							if (kolumna != 0) // 1left
								plansza_przeciwnika1[wiersz][kolumna - 1] = -2;

							if (kolumna + 3 != 9) // 1right
								plansza_przeciwnika1[wiersz][kolumna + 4] = -2;

							if (kolumna != 0 && wiersz != 0) // left_up
								plansza_przeciwnika1[wiersz - 1][kolumna - 1] = -2;

							if (kolumna + 3 != 9 && wiersz != 0) // right_up
								plansza_przeciwnika1[wiersz - 1][kolumna + 4] = -2;

							if (kolumna != 0 && wiersz != 9) // left_down
								plansza_przeciwnika1[wiersz + 1][kolumna - 1] = -2;

							if (kolumna + 3 != 9 && wiersz != 9) // right_down
								plansza_przeciwnika1[wiersz + 1][kolumna + 4] = -2;
							#pragma endregion USTAW -2 dla PLANSZA_PRZECIWNIKA1
						}
							// PIONOWY
						else
						{
							if (twoja_plansza2[wiersz - 1][kolumna] == 14 && twoja_plansza2[wiersz + 1][kolumna] == 14 && twoja_plansza2[wiersz + 2][kolumna] == 14)
								wiersz -= 1;
							else if (twoja_plansza2[wiersz - 1][kolumna] == 14 && twoja_plansza2[wiersz + 1][kolumna] == 14 && twoja_plansza2[wiersz - 2][kolumna] == 14)
								wiersz -= 2;
							else if (twoja_plansza2[wiersz - 1][kolumna] == 14 && twoja_plansza2[wiersz + 1][kolumna] != 14)
								wiersz -= 3;

							#pragma region USTAW -2 dla TWOJA_PLANSZA2
								// -2 -> '0'
							if (wiersz != 0) // 1up
								twoja_plansza2[wiersz - 1][kolumna] = -2;

							if (wiersz + 3 != 9) // 1down
								twoja_plansza2[wiersz + 4][kolumna] = -2;

							if (kolumna != 0) // 4left
								for (int i = 0; i < 4; i++)
									twoja_plansza2[wiersz + i][kolumna - 1] = -2;

							if (kolumna != 9) // 4right
								for (int i = 0; i < 4; i++)
									twoja_plansza2[wiersz + i][kolumna + 1] = -2;

							if (kolumna != 0 && wiersz != 0) // left_up
								twoja_plansza2[wiersz - 1][kolumna - 1] = -2;

							if (kolumna != 9 && wiersz != 0) // right_up
								twoja_plansza2[wiersz - 1][kolumna + 1] = -2;

							if (kolumna != 0 && wiersz + 3 != 9) // left_down
								twoja_plansza2[wiersz + 4][kolumna - 1] = -2;

							if (kolumna != 9 && wiersz + 3 != 9) // right_down
								twoja_plansza2[wiersz + 4][kolumna + 1] = -2;
							#pragma endregion USTAW -2 dla TWOJA_PLANSZA2

							#pragma region USTAW -2 dla PLANSZA_PRZECIWNIKA1
								// -2 -> '0'
							if (wiersz != 0) // 1up
								plansza_przeciwnika1[wiersz - 1][kolumna] = -2;

							if (wiersz + 3 != 9) // 1down
								plansza_przeciwnika1[wiersz + 4][kolumna] = -2;

							if (kolumna != 0) // 4left
								for (int i = 0; i < 4; i++)
									plansza_przeciwnika1[wiersz + i][kolumna - 1] = -2;

							if (kolumna != 9) // 4right
								for (int i = 0; i < 4; i++)
									plansza_przeciwnika1[wiersz + i][kolumna + 1] = -2;

							if (kolumna != 0 && wiersz != 0) // left_up
								plansza_przeciwnika1[wiersz - 1][kolumna - 1] = -2;

							if (kolumna != 9 && wiersz != 0) // right_up
								plansza_przeciwnika1[wiersz - 1][kolumna + 1] = -2;

							if (kolumna != 0 && wiersz + 3 != 9) // left_down
								plansza_przeciwnika1[wiersz + 4][kolumna - 1] = -2;

							if (kolumna != 9 && wiersz + 3 != 9) // right_down
								plansza_przeciwnika1[wiersz + 4][kolumna + 1] = -2;
							#pragma endregion USTAW -2 dla PLANSZA_PRZECIWNIKA1
						}
					}
					_licznik1 += 4;
				}
					// DLA 3
				else if (twoja_plansza2[wiersz][kolumna] == 13)
				{
					if (((twoja_plansza2[wiersz - 1][kolumna] == 13 && twoja_plansza2[wiersz - 2][kolumna] == 13) || (twoja_plansza2[wiersz + 1][kolumna] == 13 && twoja_plansza2[wiersz + 2][kolumna] == 13) || (twoja_plansza2[wiersz][kolumna - 1] == 13 && twoja_plansza2[wiersz][kolumna - 2] == 13) || (twoja_plansza2[wiersz][kolumna + 1] == 13 && twoja_plansza2[wiersz][kolumna + 2] == 13)) || ((twoja_plansza2[wiersz - 1][kolumna] == 13 && twoja_plansza2[wiersz + 1][kolumna] == 13) || (twoja_plansza2[wiersz][kolumna - 1] == 13 && twoja_plansza2[wiersz][kolumna + 1] == 13)))
					{
							// POZIOMY
						if (twoja_plansza2[wiersz][kolumna - 1] == 13 || twoja_plansza2[wiersz][kolumna + 1] == 13)
						{
							if (twoja_plansza2[wiersz][kolumna - 1] == 13 && twoja_plansza2[wiersz][kolumna + 1] == 13)
								kolumna -= 1;
							else if (twoja_plansza2[wiersz][kolumna - 1] == 13 && twoja_plansza2[wiersz][kolumna + 1] != 13)
								kolumna -= 2;

							#pragma region USTAW -2 dla TWOJA_PLANSZA2
								// -2 -> '0'
							if (wiersz != 0) // 3up
								for (int i = 0; i < 3; i++)
									twoja_plansza2[wiersz - 1][kolumna + i] = -2;

							if (wiersz != 9) // 3down
								for (int i = 0; i < 3; i++)
									twoja_plansza2[wiersz + 1][kolumna + i] = -2;

							if (kolumna != 0) // 1left
								twoja_plansza2[wiersz][kolumna - 1] = -2;

							if (kolumna + 2 != 9) // 1right
								twoja_plansza2[wiersz][kolumna + 3] = -2;

							if (kolumna != 0 && wiersz != 0) // left_up
								twoja_plansza2[wiersz - 1][kolumna - 1] = -2;

							if (kolumna + 2 != 9 && wiersz != 0) // right_up
								twoja_plansza2[wiersz - 1][kolumna + 3] = -2;

							if (kolumna != 0 && wiersz != 9) // left_down
								twoja_plansza2[wiersz + 1][kolumna - 1] = -2;

							if (kolumna + 2 != 9 && wiersz != 9) // right_down
								twoja_plansza2[wiersz + 1][kolumna + 3] = -2;
							#pragma endregion USTAW -2 dla TWOJA_PLANSZA2

							#pragma region USTAW -2 dla PLANSZA_PRZECIWNIKA1
								// -2 -> '0'
							if (wiersz != 0) // 3up
								for (int i = 0; i < 3; i++)
									plansza_przeciwnika1[wiersz - 1][kolumna + i] = -2;

							if (wiersz != 9) // 3down
								for (int i = 0; i < 3; i++)
									plansza_przeciwnika1[wiersz + 1][kolumna + i] = -2;

							if (kolumna != 0) // 1left
								plansza_przeciwnika1[wiersz][kolumna - 1] = -2;

							if (kolumna + 2 != 9) // 1right
								plansza_przeciwnika1[wiersz][kolumna + 3] = -2;

							if (kolumna != 0 && wiersz != 0) // left_up
								plansza_przeciwnika1[wiersz - 1][kolumna - 1] = -2;

							if (kolumna + 2 != 9 && wiersz != 0) // right_up
								plansza_przeciwnika1[wiersz - 1][kolumna + 3] = -2;

							if (kolumna != 0 && wiersz != 9) // left_down
								plansza_przeciwnika1[wiersz + 1][kolumna - 1] = -2;

							if (kolumna + 2 != 9 && wiersz != 9) // right_down
								plansza_przeciwnika1[wiersz + 1][kolumna + 3] = -2;
							#pragma endregion USTAW -2 dla PLANSZA_PRZECIWNIKA1
						}
							// PIONOWY
						else
						{
							if (twoja_plansza2[wiersz - 1][kolumna] == 13 && twoja_plansza2[wiersz + 1][kolumna] == 13)
								wiersz -= 1;
							else if (twoja_plansza2[wiersz - 1][kolumna] == 13 && twoja_plansza2[wiersz + 1][kolumna] != 13)
								wiersz -= 2;

							#pragma region USTAW -2 dla TWOJA_PLANSZA2
								// -2 -> '0'
							if (wiersz != 0) // 1up
								twoja_plansza2[wiersz - 1][kolumna] = -2;

							if (wiersz + 2 != 9) // 1down
								twoja_plansza2[wiersz + 3][kolumna] = -2;

							if (kolumna != 0) // 3left
								for (int i = 0; i < 3; i++)
									twoja_plansza2[wiersz + i][kolumna - 1] = -2;

							if (kolumna != 9) // 3right
								for (int i = 0; i < 3; i++)
									twoja_plansza2[wiersz + i][kolumna + 1] = -2;

							if (kolumna != 0 && wiersz != 0) // left_up
								twoja_plansza2[wiersz - 1][kolumna - 1] = -2;

							if (kolumna != 9 && wiersz != 0) // right_up
								twoja_plansza2[wiersz - 1][kolumna + 1] = -2;

							if (kolumna != 0 && wiersz + 2 != 9) // left_down
								twoja_plansza2[wiersz + 3][kolumna - 1] = -2;

							if (kolumna != 9 && wiersz + 2 != 9) // right_down
								twoja_plansza2[wiersz + 3][kolumna + 1] = -2;
							#pragma endregion USTAW -2 dla TWOJA_PLANSZA2

							#pragma region USTAW -2 dla PLANSZA_PRZECIWNIKA1
								// -2 -> '0'
							if (wiersz != 0) // 1up
								plansza_przeciwnika1[wiersz - 1][kolumna] = -2;

							if (wiersz + 2 != 9) // 1down
								plansza_przeciwnika1[wiersz + 3][kolumna] = -2;

							if (kolumna != 0) // 3left
								for (int i = 0; i < 3; i++)
									plansza_przeciwnika1[wiersz + i][kolumna - 1] = -2;

							if (kolumna != 9) // 3right
								for (int i = 0; i < 3; i++)
									plansza_przeciwnika1[wiersz + i][kolumna + 1] = -2;

							if (kolumna != 0 && wiersz != 0) // left_up
								plansza_przeciwnika1[wiersz - 1][kolumna - 1] = -2;

							if (kolumna != 9 && wiersz != 0) // right_up
								plansza_przeciwnika1[wiersz - 1][kolumna + 1] = -2;

							if (kolumna != 0 && wiersz + 2 != 9) // left_down
								plansza_przeciwnika1[wiersz + 3][kolumna - 1] = -2;

							if (kolumna != 9 && wiersz + 2 != 9) // right_down
								plansza_przeciwnika1[wiersz + 3][kolumna + 1] = -2;
							#pragma endregion USTAW -2 dla PLANSZA_PRZECIWNIKA1
						}
					}
					_licznik1 += 3;
				}
					// DLA 2
				else if (twoja_plansza2[wiersz][kolumna] == 12)
				{
					if (twoja_plansza2[wiersz - 1][kolumna] == 12 || twoja_plansza2[wiersz + 1][kolumna] == 12 || twoja_plansza2[wiersz][kolumna - 1] == 12 || twoja_plansza2[wiersz][kolumna + 1] == 12)
					{
							// POZIOMY
						if (twoja_plansza2[wiersz][kolumna - 1] == 12 || twoja_plansza2[wiersz][kolumna + 1] == 12)
						{
							if (twoja_plansza2[wiersz][kolumna - 1] == 12)
								kolumna -= 1;

							#pragma region USTAW -2 dla TWOJA_PLANSZA2
								// -2 -> 'O'
							if (wiersz != 0) // 2up
								for (int i = 0; i < 2; i++)
									twoja_plansza2[wiersz - 1][kolumna + i] = -2;

							if (wiersz != 9) // 2down
								for (int i = 0; i < 2; i++)
									twoja_plansza2[wiersz + 1][kolumna + i] = -2;

							if (kolumna != 0) // 1left
								twoja_plansza2[wiersz][kolumna - 1] = -2;

							if (kolumna + 1 != 9) // 1right
								twoja_plansza2[wiersz][kolumna + 2] = -2;

							if (kolumna != 0 && wiersz != 0) // left_up
								twoja_plansza2[wiersz - 1][kolumna - 1] = -2;

							if (kolumna + 1 != 9 && wiersz != 0) // right_up
								twoja_plansza2[wiersz - 1][kolumna + 2] = -2;

							if (kolumna != 0 && wiersz != 9) // left_down
								twoja_plansza2[wiersz + 1][kolumna - 1] = -2;

							if (kolumna + 1 != 9 && wiersz != 9) // right_down
								twoja_plansza2[wiersz + 1][kolumna + 2] = -2;
							#pragma endregion USTAW -2 dla TWOJA_PLANSZA2

							#pragma region USTAW -2 dla PLANSZA_PRZECIWNIKA1
								// -2 -> 'O'
							if (wiersz != 0) // 2up
								for (int i = 0; i < 2; i++)
									plansza_przeciwnika1[wiersz - 1][kolumna + i] = -2;

							if (wiersz != 9) // 2down
								for (int i = 0; i < 2; i++)
									plansza_przeciwnika1[wiersz + 1][kolumna + i] = -2;

							if (kolumna != 0) // 1left
								plansza_przeciwnika1[wiersz][kolumna - 1] = -2;

							if (kolumna + 1 != 9) // 1right
								plansza_przeciwnika1[wiersz][kolumna + 2] = -2;

							if (kolumna != 0 && wiersz != 0) // left_up
								plansza_przeciwnika1[wiersz - 1][kolumna - 1] = -2;

							if (kolumna + 1 != 9 && wiersz != 0) // right_up
								plansza_przeciwnika1[wiersz - 1][kolumna + 2] = -2;

							if (kolumna != 0 && wiersz != 9) // left_down
								plansza_przeciwnika1[wiersz + 1][kolumna - 1] = -2;

							if (kolumna + 1 != 9 && wiersz != 9) // right_down
								plansza_przeciwnika1[wiersz + 1][kolumna + 2] = -2;
							#pragma endregion USTAW -2 dla PLANSZA_PRZECIWNIKA1
						}
							// PIONOWY
						else
						{
							if (twoja_plansza2[wiersz - 1][kolumna] == 12)
								wiersz -= 1;

							#pragma region USTAW -2 dla TWOJA_PLANSZA2
								// -2 -> '0'
							if (wiersz != 0) // 1up
								twoja_plansza2[wiersz - 1][kolumna] = -2;

							if (wiersz + 1 != 9) // 1down
								twoja_plansza2[wiersz + 2][kolumna] = -2;

							if (kolumna != 0) // 2left
								for (int i = 0; i < 2; i++)
									twoja_plansza2[wiersz + i][kolumna - 1] = -2;

							if (kolumna != 9) // 2right
								for (int i = 0; i < 2; i++)
									twoja_plansza2[wiersz + i][kolumna + 1] = -2;

							if (kolumna != 0 && wiersz != 0) // left_up
								twoja_plansza2[wiersz - 1][kolumna - 1] = -2;

							if (kolumna != 9 && wiersz != 0) // right_up
								twoja_plansza2[wiersz - 1][kolumna + 1] = -2;

							if (kolumna != 0 && wiersz + 1 != 9) // left_down
								twoja_plansza2[wiersz + 2][kolumna - 1] = -2;

							if (kolumna != 9 && wiersz + 1 != 9) // right_down
								twoja_plansza2[wiersz + 2][kolumna + 1] = -2;
							#pragma endregion USTAW -2 dla TWOJA_PLANSZA2

							#pragma region USTAW -2 dla PLANSZA_PRZECIWNIKA1
								// -2 -> '0'
							if (wiersz != 0) // 1up
								plansza_przeciwnika1[wiersz - 1][kolumna] = -2;

							if (wiersz + 1 != 9) // 1down
								plansza_przeciwnika1[wiersz + 2][kolumna] = -2;

							if (kolumna != 0) // 2left
								for (int i = 0; i < 2; i++)
									plansza_przeciwnika1[wiersz + i][kolumna - 1] = -2;

							if (kolumna != 9) // 2right
								for (int i = 0; i < 2; i++)
									plansza_przeciwnika1[wiersz + i][kolumna + 1] = -2;

							if (kolumna != 0 && wiersz != 0) // left_up
								plansza_przeciwnika1[wiersz - 1][kolumna - 1] = -2;

							if (kolumna != 9 && wiersz != 0) // right_up
								plansza_przeciwnika1[wiersz - 1][kolumna + 1] = -2;

							if (kolumna != 0 && wiersz + 1 != 9) // left_down
								plansza_przeciwnika1[wiersz + 2][kolumna - 1] = -2;

							if (kolumna != 9 && wiersz + 1 != 9) // right_down
								plansza_przeciwnika1[wiersz + 2][kolumna + 1] = -2;
							#pragma endregion USTAW -2 dla PLANSZA_PRZECIWNIKA1
						}
					}
					_licznik1 += 2;
				}
					// DLA 1
				else
				{
					#pragma region USTAW -2 dla TWOJA_PLANSZA2
						// -2 -> 'O'
					if (wiersz != 0) // 1up
						twoja_plansza2[wiersz - 1][kolumna] = -2;

					if (wiersz != 9) // 1down
						twoja_plansza2[wiersz + 1][kolumna] = -2;

					if (kolumna != 0) // 1left
						twoja_plansza2[wiersz][kolumna - 1] = -2;

					if (kolumna != 9) // 1right
						twoja_plansza2[wiersz][kolumna + 1] = -2;

					if (kolumna != 0 && wiersz != 0) // left_up
						twoja_plansza2[wiersz - 1][kolumna - 1] = -2;

					if (kolumna != 9 && wiersz != 0) // right_up
						twoja_plansza2[wiersz - 1][kolumna + 1] = -2;

					if (kolumna != 0 && wiersz != 9) // left_down
						twoja_plansza2[wiersz + 1][kolumna - 1] = -2;

					if (kolumna != 9 && wiersz != 9) // right_down
						twoja_plansza2[wiersz + 1][kolumna + 1] = -2;
					#pragma endregion USTAW -2 dla TWOJA_PLANSZA2

					#pragma region USTAW -2 dla PLANSZA_PRZECIWNIKA1
						// -2 -> 'O'
					if (wiersz != 0) // 1up
						plansza_przeciwnika1[wiersz - 1][kolumna] = -2;

					if (wiersz != 9) // 1down
						plansza_przeciwnika1[wiersz + 1][kolumna] = -2;

					if (kolumna != 0) // 1left
						plansza_przeciwnika1[wiersz][kolumna - 1] = -2;

					if (kolumna != 9) // 1right
						plansza_przeciwnika1[wiersz][kolumna + 1] = -2;

					if (kolumna != 0 && wiersz != 0) // left_up
						plansza_przeciwnika1[wiersz - 1][kolumna - 1] = -2;

					if (kolumna != 9 && wiersz != 0) // right_up
						plansza_przeciwnika1[wiersz - 1][kolumna + 1] = -2;

					if (kolumna != 0 && wiersz != 9) // left_down
						plansza_przeciwnika1[wiersz + 1][kolumna - 1] = -2;

					if (kolumna != 9 && wiersz != 9) // right_down
						plansza_przeciwnika1[wiersz + 1][kolumna + 1] = -2;
					#pragma endregion USTAW -2 dla PLANSZA_PRZECIWNIKA1

					_licznik1 += 1;
				}
			}
		}
		else
		{
			#pragma region NAPIS "Błędne współrzędne, spróbuj ponownie!"
			cout << "\n  B"; Sleep(10); cout << "\210"; Sleep(10); cout << "\251"; Sleep(10); cout << "d"; Sleep(10); cout << "n"; Sleep(10); cout << "e"; Sleep(10); cout << " "; Sleep(10); cout << "w"; Sleep(10); cout << "s"; Sleep(10); cout << "p"; Sleep(10); cout << "\242"; Sleep(10); cout << "\210"; Sleep(10); cout << "r"; Sleep(10); cout << "z"; Sleep(10); cout << "\251"; Sleep(10); cout << "d"; Sleep(10); cout << "n"; Sleep(10); cout << "e"; Sleep(10); cout << ","; Sleep(10); cout << " "; Sleep(10); cout << "s"; Sleep(10); cout << "p"; Sleep(10); cout << "r"; Sleep(10); cout << "\242"; Sleep(10); cout << "b"; Sleep(10); cout << "u"; Sleep(10); cout << "j"; Sleep(10); cout << " "; Sleep(10); cout << "p"; Sleep(10); cout << "o"; Sleep(10); cout << "n"; Sleep(10); cout << "o"; Sleep(10); cout << "w"; Sleep(10); cout << "n"; Sleep(10); cout << "i"; Sleep(10); cout << "e"; Sleep(10); cout << "!";
			#pragma endregion NAPIS "Błędne współrzędne, spróbuj ponownie!"
			Sleep(1500);
			goto wypis1;
		}
		#pragma endregion WPISANIE W PLANSZE

		//
		#pragma region WYPIS PLANSZ No2
		system("cls");
		#pragma region NAPISY "Ruch gracza: GRACZ1", "PLANSZA PRZECIWNIKA:" i "TWOJA PLANSZA:"
		cout << "\n  Ruch gracza: " << _gracz1 << "\n\n";
		cout.width(24);
		cout << "PLANSZA PRZECIWNIKA:";
		cout.width(29);
		cout << "TWOJA PLANSZA:\n\n";
		#pragma endregion NAPISY "Ruch gracza: GRACZ1", "PLANSZA PRZECIWNIKA:" i "TWOJA PLANSZA:"
		#pragma region WYPIS LITER A - J PLANSZA_PRZECIWNIKA1 (NUMEROWANIE KOLUMN)
		wier = 'A';
		cout.width(4); cout << " ";
		for (int i = 0; i <= 9; i++)
		{
			cout.width(2);
			cout << static_cast<char>(wier + lit);
			lit++;
		}
		lit = 0;
		#pragma endregion WYPIS LITER A - J PLANSZA_PRZECIWNIKA1 (NUMEROWANIE KOLUMN)
		#pragma region WYPIS LITER A - J TWOJA_PLANSZA1 (NUMEROWANIE KOLUMN)
		cout.width(10); cout << " ";
		for (int i = 0; i <= 9; i++)
		{
			cout.width(2);
			cout << static_cast<char>(wier + lit);
			lit++;
		}
		cout << endl; lit = 0;
		#pragma endregion WYPIS LITER A - J TWOJA_PLANSZA1 (NUMEROWANIE KOLUMN)
		#pragma region WYPIS PLANSZA_PRZECIWNIKA1 i TWOJA_PLANSZA1
		for (int i = 0; i <= 9; i++)
		{
			#pragma region WYPIS PLANSZA_PRZECIWNIKA1
			cout.width(3);
			cout << i + 1 << "."; // NUMEROWANIE WIERSZY PLANSZA_PRZECIWNIKA
			for (int j = 0; j <= 9; j++)
			{
				cout.width(2);
				if (plansza_przeciwnika1[i][j] == -1 || plansza_przeciwnika1[i][j] == -2)
					cout << (unsigned char)0x9E; // 'x'
				else if (plansza_przeciwnika1[i][j] == 0)
					cout << (unsigned char)0xFE; // kwadraty
				else if (plansza_przeciwnika1[i][j] > 4)
					cout << (unsigned char)0x4F; // 'O'
				else
					cout << plansza_przeciwnika1[i][j];
			}
			#pragma endregion WYPIS PLANSZA_PRZECIWNIKA1

			Sleep(10);
			cout.width(6);
			cout << " ";

			#pragma region WYPIS TWOJA_PLANSZA1
			cout.width(3);
			cout << i + 1 << "."; // NUMEROWANIE WIERSZY TWOJA_PLANSZA
			for (int j = 0; j <= 9; j++)
			{
				cout.width(2);
				if (twoja_plansza1[i][j] == 0 || twoja_plansza1[i][j] == -1)
					cout << (unsigned char)0xFE; // kwadraty
				else if (twoja_plansza1[i][j] == -2)
					cout << (unsigned char)0x9E; // 'x'
				else if (twoja_plansza1[i][j] > 4)
					cout << (unsigned char)0x4F; // 'O'
				else
					cout << twoja_plansza1[i][j];
			}
			#pragma endregion WYPIS TWOJA_PLANSZA1
			cout << endl;
		}
		#pragma endregion WYPIS PLANSZA_PRZECIWNIKA1 i TWOJA_PLANSZA1

		#pragma endregion WYPIS PLANSZ No2
		//

		Sleep(500);

		#pragma region INFORMACJE

		#pragma region NAPIS "TO OSTATNI STATEK! WYGRYWASZ!"
		if (_licznik1 == 50)
		{
			cout << "\n  T"; Sleep(10); cout << "O"; Sleep(10); cout << " "; Sleep(10); cout << "O"; Sleep(10); cout << "S"; Sleep(10); cout << "T"; Sleep(10); cout << "A"; Sleep(10); cout << "T"; Sleep(10); cout << "N"; Sleep(10); cout << "I"; Sleep(10); cout << " "; Sleep(10); cout << "S"; Sleep(10); cout << "T"; Sleep(10); cout << "A"; Sleep(10); cout << "T"; Sleep(10); cout << "E"; Sleep(10); cout << "K"; Sleep(10); cout << "!"; Sleep(500); cout << " W"; Sleep(10); cout << "Y"; Sleep(10); cout << "G"; Sleep(10); cout << "R"; Sleep(10); cout << "Y"; Sleep(10); cout << "W"; Sleep(10); cout << "A"; Sleep(10); cout << "S"; Sleep(10); cout << "Z"; Sleep(10); cout << "!";
			_nazwy_niepodane = 1;
			Sleep(2000);
		}
		#pragma endregion NAPIS "TO OSTATNI STATEK! WYGRYWASZ!"
		#pragma region NAPIS "Pudło."
		else if (twoja_plansza2[wiersz][kolumna] == -2)
		{
			cout << "\n  P"; Sleep(10); cout << "u"; Sleep(10); cout << "d"; Sleep(10); cout << "\210"; Sleep(10); cout << "o"; Sleep(10); cout << ".";
			Sleep(1000);
		}
		#pragma endregion NAPIS "Pudło."
		#pragma region NAPIS "Zatopiłeś statek 4-masztowy!"
		else if (((twoja_plansza2[wiersz - 1][kolumna] == 14 && twoja_plansza2[wiersz - 2][kolumna] == 14 && twoja_plansza2[wiersz - 3][kolumna] == 14) || (twoja_plansza2[wiersz + 1][kolumna] == 14 && twoja_plansza2[wiersz + 2][kolumna] == 14 && twoja_plansza2[wiersz + 3][kolumna] == 14) || (twoja_plansza2[wiersz][kolumna - 1] == 14 && twoja_plansza2[wiersz][kolumna - 2] == 14 && twoja_plansza2[wiersz][kolumna - 3] == 14) || (twoja_plansza2[wiersz][kolumna + 1] == 14 && twoja_plansza2[wiersz][kolumna + 2] == 14 && twoja_plansza2[wiersz][kolumna + 3] == 14)) || ((twoja_plansza2[wiersz - 1][kolumna] == 14 && twoja_plansza2[wiersz - 2][kolumna] == 14 && twoja_plansza2[wiersz + 1][kolumna] == 14) || (twoja_plansza2[wiersz + 1][kolumna] == 14 && twoja_plansza2[wiersz + 2][kolumna] == 14 && twoja_plansza2[wiersz - 1][kolumna] == 14) || (twoja_plansza2[wiersz][kolumna - 1] == 14 && twoja_plansza2[wiersz][kolumna - 2] == 14 && twoja_plansza2[wiersz][kolumna + 1] == 14) || (twoja_plansza2[wiersz][kolumna + 1] == 14 && twoja_plansza2[wiersz][kolumna + 2] == 14 && twoja_plansza2[wiersz][kolumna - 1] == 14)))
		{
			cout << "\n  Z"; Sleep(10); cout << "a"; Sleep(10); cout << "t"; Sleep(10); cout << "o"; Sleep(10); cout << "p"; Sleep(10); cout << "i"; Sleep(10); cout << "\210"; Sleep(10); cout << "e"; Sleep(10); cout << "\230"; Sleep(10); cout << " "; Sleep(10); cout << "s"; Sleep(10); cout << "t"; Sleep(10); cout << "a"; Sleep(10); cout << "t"; Sleep(10); cout << "e"; Sleep(10); cout << "k"; Sleep(10); cout << " "; Sleep(10); cout << "4"; Sleep(10); cout << "-"; Sleep(10); cout << "m"; Sleep(10); cout << "a"; Sleep(10); cout << "s"; Sleep(10); cout << "z"; Sleep(10); cout << "t"; Sleep(10); cout << "o"; Sleep(10); cout << "w"; Sleep(10); cout << "y"; Sleep(10); cout << "!";
			Sleep(1000);
		}
		#pragma endregion NAPIS "Zatopiłeś statek 4-masztowy!"
		#pragma region NAPIS "Zatopiłeś statek 3-masztowy!"
		else if (((twoja_plansza2[wiersz - 1][kolumna] == 13 && twoja_plansza2[wiersz - 2][kolumna] == 13) || (twoja_plansza2[wiersz + 1][kolumna] == 13 && twoja_plansza2[wiersz + 2][kolumna] == 13) || (twoja_plansza2[wiersz][kolumna - 1] == 13 && twoja_plansza2[wiersz][kolumna - 2] == 13) || (twoja_plansza2[wiersz][kolumna + 1] == 13 && twoja_plansza2[wiersz][kolumna + 2] == 13)) || ((twoja_plansza2[wiersz - 1][kolumna] == 13 && twoja_plansza2[wiersz + 1][kolumna] == 13) || (twoja_plansza2[wiersz][kolumna - 1] == 13 && twoja_plansza2[wiersz][kolumna + 1] == 13)))
		{
			cout << "\n  Z"; Sleep(10); cout << "a"; Sleep(10); cout << "t"; Sleep(10); cout << "o"; Sleep(10); cout << "p"; Sleep(10); cout << "i"; Sleep(10); cout << "\210"; Sleep(10); cout << "e"; Sleep(10); cout << "\230"; Sleep(10); cout << " "; Sleep(10); cout << "s"; Sleep(10); cout << "t"; Sleep(10); cout << "a"; Sleep(10); cout << "t"; Sleep(10); cout << "e"; Sleep(10); cout << "k"; Sleep(10); cout << " "; Sleep(10); cout << "3"; Sleep(10); cout << "-"; Sleep(10); cout << "m"; Sleep(10); cout << "a"; Sleep(10); cout << "s"; Sleep(10); cout << "z"; Sleep(10); cout << "t"; Sleep(10); cout << "o"; Sleep(10); cout << "w"; Sleep(10); cout << "y"; Sleep(10); cout << "!";
			Sleep(1000);
		}
		#pragma endregion NAPIS "Zatopiłeś statek 3-masztowy!"
		#pragma region NAPIS "Zatopiłeś statek 2-masztowy!"
		else if (twoja_plansza2[wiersz - 1][kolumna] == 12 || twoja_plansza2[wiersz + 1][kolumna] == 12 || twoja_plansza2[wiersz][kolumna - 1] == 12 || twoja_plansza2[wiersz][kolumna + 1] == 12)
		{
			cout << "\n  Z"; Sleep(10); cout << "a"; Sleep(10); cout << "t"; Sleep(10); cout << "o"; Sleep(10); cout << "p"; Sleep(10); cout << "i"; Sleep(10); cout << "\210"; Sleep(10); cout << "e"; Sleep(10); cout << "\230"; Sleep(10); cout << " "; Sleep(10); cout << "s"; Sleep(10); cout << "t"; Sleep(10); cout << "a"; Sleep(10); cout << "t"; Sleep(10); cout << "e"; Sleep(10); cout << "k"; Sleep(10); cout << " "; Sleep(10); cout << "2"; Sleep(10); cout << "-"; Sleep(10); cout << "m"; Sleep(10); cout << "a"; Sleep(10); cout << "s"; Sleep(10); cout << "z"; Sleep(10); cout << "t"; Sleep(10); cout << "o"; Sleep(10); cout << "w"; Sleep(10); cout << "y"; Sleep(10); cout << "!";
			Sleep(1000);
		}
		#pragma endregion NAPIS "Zatopiłeś statek 2-masztowy!"
		#pragma region NAPIS "Zatopiłeś statek 1-masztowy!"
		else if (twoja_plansza2[wiersz][kolumna] == 11)
		{
			cout << "\n  Z"; Sleep(10); cout << "a"; Sleep(10); cout << "t"; Sleep(10); cout << "o"; Sleep(10); cout << "p"; Sleep(10); cout << "i"; Sleep(10); cout << "\210"; Sleep(10); cout << "e"; Sleep(10); cout << "\230"; Sleep(10); cout << " "; Sleep(10); cout << "s"; Sleep(10); cout << "t"; Sleep(10); cout << "a"; Sleep(10); cout << "t"; Sleep(10); cout << "e"; Sleep(10); cout << "k"; Sleep(10); cout << " "; Sleep(10); cout << "1"; Sleep(10); cout << "-"; Sleep(10); cout << "m"; Sleep(10); cout << "a"; Sleep(10); cout << "s"; Sleep(10); cout << "z"; Sleep(10); cout << "t"; Sleep(10); cout << "o"; Sleep(10); cout << "w"; Sleep(10); cout << "y"; Sleep(10); cout << "!";
			Sleep(1000);
		}
		#pragma endregion NAPIS "Zatopiłeś statek 1-masztowy!"
		#pragma region NAPIS "Trafiłeś!"
		else
		{
			cout << "\n  T"; Sleep(10); cout << "r"; Sleep(10); cout << "a"; Sleep(10); cout << "f"; Sleep(10); cout << "i"; Sleep(10); cout << "\210"; Sleep(10); cout << "e"; Sleep(10); cout << "\230"; Sleep(10); cout << "!";
			Sleep(1000);
		}
		#pragma endregion NAPIS "Trafiłeś!"

		#pragma endregion INFORMACJE

		#pragma region NAPIS "Wciśnij dowolny klawisz, żeby kontynuować."
		cout << "\n\n  W"; Sleep(10); cout << "c"; Sleep(10); cout << "i"; Sleep(10); cout << "\230"; Sleep(10); cout << "n"; Sleep(10); cout << "i"; Sleep(10); cout << "j"; Sleep(10); cout << " "; Sleep(10); cout << "d"; Sleep(10); cout << "o"; Sleep(10); cout << "w"; Sleep(10); cout << "o"; Sleep(10); cout << "l"; Sleep(10); cout << "n"; Sleep(10); cout << "y"; Sleep(10); cout << " "; Sleep(10); cout << "k"; Sleep(10); cout << "l"; Sleep(10); cout << "a"; Sleep(10); cout << "w"; Sleep(10); cout << "i"; Sleep(10); cout << "s"; Sleep(10); cout << "z"; Sleep(10); cout << ","; Sleep(10); cout << " "; Sleep(10); cout << "\276"; Sleep(10); cout << "e"; Sleep(10); cout << "b"; Sleep(10); cout << "y"; Sleep(10); cout << " "; Sleep(10); cout << "k"; Sleep(10); cout << "o"; Sleep(10); cout << "n"; Sleep(10); cout << "t"; Sleep(10); cout << "y"; Sleep(10); cout << "n"; Sleep(10); cout << "u"; Sleep(10); cout << "o"; Sleep(10); cout << "w"; Sleep(10); cout << "a"; Sleep(10); cout << "\206"; Sleep(10); cout << "."; Sleep(10); cout << " ";
		Sleep(300);
		ShowConsoleCursor(1);
		_nic = _getch();
		#pragma endregion NAPIS "Wciśnij dowolny klawisz, żeby kontynuować."

		_runda++;
	}

		////// GRACZ 2
	else if (_runda % 2 != 0)
	{
		ShowConsoleCursor(0);
		system("cls");
		Sleep(500);

		#pragma region NAPIS "GRACZ2, wciśnij dowolny klawisz, żeby kontynuować."
		cout << "\n  ";
		for (int i = 0; i < _gracz2.size(); i++)
		{
			cout << _gracz2[i];
			Sleep(10);
		}
		cout << ","; Sleep(10); cout << " "; Sleep(10); cout << "w"; Sleep(10); cout << "c"; Sleep(10); cout << "i"; Sleep(10); cout << "\230"; Sleep(10); cout << "n"; Sleep(10); cout << "i"; Sleep(10); cout << "j"; Sleep(10); cout << " "; Sleep(10); cout << "d"; Sleep(10); cout << "o"; Sleep(10); cout << "w"; Sleep(10); cout << "o"; Sleep(10); cout << "l"; Sleep(10); cout << "n"; Sleep(10); cout << "y"; Sleep(10); cout << " "; Sleep(10); cout << "k"; Sleep(10); cout << "l"; Sleep(10); cout << "a"; Sleep(10); cout << "w"; Sleep(10); cout << "i"; Sleep(10); cout << "s"; Sleep(10); cout << "z"; Sleep(10); cout << ","; Sleep(10); cout << " "; Sleep(10); cout << "\276"; Sleep(10); cout << "e"; Sleep(10); cout << "b"; Sleep(10); cout << "y"; Sleep(10); cout << " "; Sleep(10); cout << "k"; Sleep(10); cout << "o"; Sleep(10); cout << "n"; Sleep(10); cout << "t"; Sleep(10); cout << "y"; Sleep(10); cout << "n"; Sleep(10); cout << "u"; Sleep(10); cout << "o"; Sleep(10); cout << "w"; Sleep(10); cout << "a"; Sleep(10); cout << "\206"; Sleep(10); cout << "."; Sleep(10); cout << " ";
		Sleep(300);
		while (_kbhit())
			_nic = _getch();
		ShowConsoleCursor(1);
		_nic = _getch();
		#pragma endregion NAPIS "GRACZ2, wciśnij dowolny klawisz, żeby kontynuować."

		ShowConsoleCursor(0);
		system("cls");
		Sleep(500);

	wypis2:
		ShowConsoleCursor(0);

		//
		#pragma region WYPIS PLANSZ No1
		system("cls");
		#pragma region NAPISY "Ruch gracza: GRACZ2", "PLANSZA PRZECIWNIKA:" i "TWOJA PLANSZA:"
		cout << "\n  Ruch gracza: " << _gracz2 << "\n\n";
		Sleep(20);
		cout.width(24);
		cout << "PLANSZA PRZECIWNIKA:";
		cout.width(29);
		cout << "TWOJA PLANSZA:\n\n";
		Sleep(20);
		#pragma endregion NAPISY "Ruch gracza: GRACZ2", "PLANSZA PRZECIWNIKA:" i "TWOJA PLANSZA:"
		#pragma region WYPIS LITER A - J PLANSZA_PRZECIWNIKA2 (NUMEROWANIE KOLUMN)
		char wier = 'A'; int lit{};
		cout.width(4); cout << " ";
		for (int i = 0; i <= 9; i++)
		{
			cout.width(2);
			cout << static_cast<char>(wier + lit);
			lit++;
		}
		lit = 0;
		#pragma endregion WYPIS LITER A - J PLANSZA_PRZECIWNIKA2 (NUMEROWANIE KOLUMN)
		#pragma region WYPIS LITER A - J TWOJA_PLANSZA2 (NUMEROWANIE KOLUMN)
		cout.width(10); cout << " ";
		for (int i = 0; i <= 9; i++)
		{
			cout.width(2);
			cout << static_cast<char>(wier + lit);
			lit++;
		}
		cout << endl; lit = 0;
		Sleep(10);
		#pragma endregion WYPIS LITER A - J TWOJA_PLANSZA2 (NUMEROWANIE KOLUMN)
		#pragma region WYPIS PLANSZA_PRZECIWNIKA2 i TWOJA_PLANSZA1
		for (int i = 0; i <= 9; i++)
		{
			#pragma region WYPIS PLANSZA_PRZECIWNIKA2
			cout.width(3);
			cout << i + 1 << "."; // NUMEROWANIE WIERSZY PLANSZA_PRZECIWNIKA
			for (int j = 0; j <= 9; j++)
			{
				cout.width(2);
				if (plansza_przeciwnika2[i][j] == -1 || plansza_przeciwnika2[i][j] == -2)
					cout << (unsigned char)0x9E; // 'x'
				else if (plansza_przeciwnika2[i][j] == 0)
					cout << (unsigned char)0xFE; // kwadraty
				else if (plansza_przeciwnika2[i][j] > 4)
					cout << (unsigned char)0x4F; // 'O'
				else
					cout << plansza_przeciwnika2[i][j];
			}
			#pragma endregion WYPIS PLANSZA_PRZECIWNIKA2

			cout.width(6);
			cout << " ";

			#pragma region WYPIS TWOJA_PLANSZA2
			cout.width(3);
			cout << i + 1 << "."; // NUMEROWANIE WIERSZY TWOJA_PLANSZA
			for (int j = 0; j <= 9; j++)
			{
				cout.width(2);
				if (twoja_plansza2[i][j] == 0 || twoja_plansza2[i][j] == -1)
					cout << (unsigned char)0xFE; // kwadraty
				else if (twoja_plansza2[i][j] == -2)
					cout << (unsigned char)0x9E; // 'x'
				else if (twoja_plansza2[i][j] > 4)
					cout << (unsigned char)0x4F; // 'O'
				else
					cout << twoja_plansza2[i][j];
			}
			#pragma endregion WYPIS TWOJA_PLANSZA2
			cout << endl;
			Sleep(10);
		}
		#pragma endregion WYPIS plansza_przeciwnika2 i TWOJA_PLANSZA1

		#pragma endregion WYPIS PLANSZ No1
		//

		Sleep(700);
		#pragma region NAPIS "Wpisz literę kolumny [A-J] oraz numer wiersza [1-10] do strzału:"
		cout << "\n  W"; Sleep(10); cout << "p"; Sleep(10); cout << "i"; Sleep(10); cout << "s"; Sleep(10); cout << "z"; Sleep(10); cout << " "; Sleep(10); cout << "l"; Sleep(10); cout << "i"; Sleep(10); cout << "t"; Sleep(10); cout << "e"; Sleep(10); cout << "r"; Sleep(10); cout << "\251"; Sleep(10); cout << " "; Sleep(10); cout << "k"; Sleep(10); cout << "o"; Sleep(10); cout << "l"; Sleep(10); cout << "u"; Sleep(10); cout << "m"; Sleep(10); cout << "n"; Sleep(10); cout << "y"; Sleep(10); cout << " "; Sleep(10); cout << "["; Sleep(10); cout << "A"; Sleep(10); cout << "-"; Sleep(10); cout << "J"; Sleep(10); cout << "]"; Sleep(10); cout << " "; Sleep(10); cout << "o"; Sleep(10); cout << "r"; Sleep(10); cout << "a"; Sleep(10); cout << "z"; Sleep(10); cout << " "; Sleep(10); cout << "n"; Sleep(10); cout << "u"; Sleep(10); cout << "m"; Sleep(10); cout << "e"; Sleep(10); cout << "r"; Sleep(10); cout << " "; Sleep(10); cout << "w"; Sleep(10); cout << "i"; Sleep(10); cout << "e"; Sleep(10); cout << "r"; Sleep(10); cout << "s"; Sleep(10); cout << "z"; Sleep(10); cout << "a"; Sleep(10); cout << " "; Sleep(10); cout << "["; Sleep(10); cout << "1"; Sleep(10); cout << "-"; Sleep(10); cout << "1"; Sleep(10); cout << "0"; Sleep(10); cout << "]"; Sleep(10); cout << " "; Sleep(10); cout << "d"; Sleep(10); cout << "o"; Sleep(10); cout << " "; Sleep(10); cout << "s"; Sleep(10); cout << "t"; Sleep(10); cout << "r"; Sleep(10); cout << "z"; Sleep(10); cout << "a"; Sleep(10); cout << "\210"; Sleep(10); cout << "u"; Sleep(10); cout << ": "; Sleep(10);
		#pragma endregion NAPIS "Wpisz literę kolumny [A-J] oraz numer wiersza [1-10] do strzału:"
		ShowConsoleCursor(1);
		getline(cin, strzal);
		ShowConsoleCursor(0);

		#pragma region SPRAWDZENIE POPRAWNOŚCI ZAPISU
			// LITERA i LICZBA
		if (isalpha(strzal[0]) && isdigit(strzal[1]) && (isdigit(strzal[2]) || strzal[2] == '\0'))
		{
			litera = strzal[0];
			if (strzal.size() == 2)      // 1 CYFRA
				liczba = stoi(strzal.substr(1, 1));
			else if (strzal.size() == 3) // 2 CYFRY
				liczba = stoi(strzal.substr(1, 2));
		}
			// LICZBA (1 CYFRA) i LITERA
		else if (isdigit(strzal[0]) && isalpha(strzal[1]))
		{
			litera = strzal[1];
			liczba = stoi(strzal.substr(0, 1));
		}
			// LICZBA (2 CYFRY) i LITERA
		else if (isdigit(strzal[0]) && isdigit(strzal[1]) && isalpha(strzal[2]))
		{
			litera = strzal[2];
			liczba = stoi(strzal.substr(0, 2));
		}
		else
		{
			#pragma region NAPIS "Błędne współrzędne, spróbuj ponownie!"
			cout << "\n  B"; Sleep(10); cout << "\210"; Sleep(10); cout << "\251"; Sleep(10); cout << "d"; Sleep(10); cout << "n"; Sleep(10); cout << "e"; Sleep(10); cout << " "; Sleep(10); cout << "w"; Sleep(10); cout << "s"; Sleep(10); cout << "p"; Sleep(10); cout << "\242"; Sleep(10); cout << "\210"; Sleep(10); cout << "r"; Sleep(10); cout << "z"; Sleep(10); cout << "\251"; Sleep(10); cout << "d"; Sleep(10); cout << "n"; Sleep(10); cout << "e"; Sleep(10); cout << ","; Sleep(10); cout << " "; Sleep(10); cout << "s"; Sleep(10); cout << "p"; Sleep(10); cout << "r"; Sleep(10); cout << "\242"; Sleep(10); cout << "b"; Sleep(10); cout << "u"; Sleep(10); cout << "j"; Sleep(10); cout << " "; Sleep(10); cout << "p"; Sleep(10); cout << "o"; Sleep(10); cout << "n"; Sleep(10); cout << "o"; Sleep(10); cout << "w"; Sleep(10); cout << "n"; Sleep(10); cout << "i"; Sleep(10); cout << "e"; Sleep(10); cout << "!";
			#pragma endregion NAPIS "Błędne współrzędne, spróbuj ponownie!"
			Sleep(1500);
			goto wypis2;
		}

		if (litera >= 65 && litera <= 74)
			kolumna = litera - 65;
		else if (litera >= 97 && litera <= 106)
			kolumna = litera - 97;
		wiersz = liczba - 1;

		#pragma endregion SPRAWDZENIE POPRAWNOŚCI ZAPISU

		#pragma region WPISANIE W PLANSZE
		if (((litera >= 65 && litera <= 74) || (litera >= 97 && litera <= 106)) && (liczba >= 1 && liczba <= 10))
		{
				// 'x' lub PUSTE
			if (twoja_plansza1[wiersz][kolumna] == -1 || twoja_plansza1[wiersz][kolumna] == 0)
			{
				plansza_przeciwnika2[wiersz][kolumna] = -2;
				twoja_plansza1[wiersz][kolumna] = -2;
			}
				// JUŻ TRAFIONE
			else if (twoja_plansza1[wiersz][kolumna] == -2 || twoja_plansza1[wiersz][kolumna] > 4)
			{
				#pragma region NAPIS "Podane pole zostało już trafione, wybierz inne!"
				cout << "\n  P"; Sleep(10); cout << "o"; Sleep(10); cout << "d"; Sleep(10); cout << "a"; Sleep(10); cout << "n"; Sleep(10); cout << "e"; Sleep(10); cout << " "; Sleep(10); cout << "p"; Sleep(10); cout << "o"; Sleep(10); cout << "l"; Sleep(10); cout << "e"; Sleep(10); cout << " "; Sleep(10); cout << "z"; Sleep(10); cout << "o"; Sleep(10); cout << "s"; Sleep(10); cout << "t"; Sleep(10); cout << "a"; Sleep(10); cout << "\210"; Sleep(10); cout << "o"; Sleep(10); cout << " "; Sleep(10); cout << "j"; Sleep(10); cout << "u"; Sleep(10); cout << "\276"; Sleep(10); cout << " "; Sleep(10); cout << "t"; Sleep(10); cout << "r"; Sleep(10); cout << "a"; Sleep(10); cout << "f"; Sleep(10); cout << "i"; Sleep(10); cout << "o"; Sleep(10); cout << "n"; Sleep(10); cout << "e"; Sleep(10); cout << ","; Sleep(10); cout << " "; Sleep(10); cout << "w"; Sleep(10); cout << "y"; Sleep(10); cout << "b"; Sleep(10); cout << "i"; Sleep(10); cout << "e"; Sleep(10); cout << "r"; Sleep(10); cout << "z"; Sleep(10); cout << " "; Sleep(10); cout << "i"; Sleep(10); cout << "n"; Sleep(10); cout << "n"; Sleep(10); cout << "e"; Sleep(10); cout << "!";
				#pragma endregion NAPIS "Podane pole zostało już trafione, wybierz inne!"
				Sleep(1500);
				goto wypis2;
			}
				// TRAFIENIE
			else
			{
				plansza_przeciwnika2[wiersz][kolumna] += 10;
				twoja_plansza1[wiersz][kolumna] += 10;
					// DLA 4
				if (twoja_plansza1[wiersz][kolumna] == 14)
				{
					if (((twoja_plansza1[wiersz - 1][kolumna] == 14 && twoja_plansza1[wiersz - 2][kolumna] == 14 && twoja_plansza1[wiersz - 3][kolumna] == 14) || (twoja_plansza1[wiersz + 1][kolumna] == 14 && twoja_plansza1[wiersz + 2][kolumna] == 14 && twoja_plansza1[wiersz + 3][kolumna] == 14) || (twoja_plansza1[wiersz][kolumna - 1] == 14 && twoja_plansza1[wiersz][kolumna - 2] == 14 && twoja_plansza1[wiersz][kolumna - 3] == 14) || (twoja_plansza1[wiersz][kolumna + 1] == 14 && twoja_plansza1[wiersz][kolumna + 2] == 14 && twoja_plansza1[wiersz][kolumna + 3] == 14)) || ((twoja_plansza1[wiersz - 1][kolumna] == 14 && twoja_plansza1[wiersz - 2][kolumna] == 14 && twoja_plansza1[wiersz + 1][kolumna] == 14) || (twoja_plansza1[wiersz + 1][kolumna] == 14 && twoja_plansza1[wiersz + 2][kolumna] == 14 && twoja_plansza1[wiersz - 1][kolumna] == 14) || (twoja_plansza1[wiersz][kolumna - 1] == 14 && twoja_plansza1[wiersz][kolumna - 2] == 14 && twoja_plansza1[wiersz][kolumna + 1] == 14) || (twoja_plansza1[wiersz][kolumna + 1] == 14 && twoja_plansza1[wiersz][kolumna + 2] == 14 && twoja_plansza1[wiersz][kolumna - 1] == 14)))
					{
							// POZIOMY
						if (twoja_plansza1[wiersz][kolumna - 1] == 14 || twoja_plansza1[wiersz][kolumna + 1] == 14)
						{
							if (twoja_plansza1[wiersz][kolumna - 1] == 14 && twoja_plansza1[wiersz][kolumna + 1] == 14 && twoja_plansza1[wiersz][kolumna + 2] == 14)
								kolumna -= 1;
							else if (twoja_plansza1[wiersz][kolumna - 1] == 14 && twoja_plansza1[wiersz][kolumna + 1] == 14 && twoja_plansza1[wiersz][kolumna - 2] == 14)
								kolumna -= 2;
							else if (twoja_plansza1[wiersz][kolumna - 1] == 14 && twoja_plansza1[wiersz][kolumna + 1] != 14)
								kolumna -= 3;

							#pragma region USTAW -2 dla TWOJA_PLANSZA1
								// -2 -> '0'
							if (wiersz != 0) // 4up
								for (int i = 0; i < 4; i++)
									twoja_plansza1[wiersz - 1][kolumna + i] = -2;

							if (wiersz != 9) // 4down
								for (int i = 0; i < 4; i++)
									twoja_plansza1[wiersz + 1][kolumna + i] = -2;

							if (kolumna != 0) // 1left
								twoja_plansza1[wiersz][kolumna - 1] = -2;

							if (kolumna + 3 != 9) // 1right
								twoja_plansza1[wiersz][kolumna + 4] = -2;

							if (kolumna != 0 && wiersz != 0) // left_up
								twoja_plansza1[wiersz - 1][kolumna - 1] = -2;

							if (kolumna + 3 != 9 && wiersz != 0) // right_up
								twoja_plansza1[wiersz - 1][kolumna + 4] = -2;

							if (kolumna != 0 && wiersz != 9) // left_down
								twoja_plansza1[wiersz + 1][kolumna - 1] = -2;

							if (kolumna + 3 != 9 && wiersz != 9) // right_down
								twoja_plansza1[wiersz + 1][kolumna + 4] = -2;
							#pragma endregion USTAW -2 dla TWOJA_PLANSZA1

							#pragma region USTAW -2 dla PLANSZA_PRZECIWNIKA2
								// -2 -> '0'
							if (wiersz != 0) // 4up
								for (int i = 0; i < 4; i++)
									plansza_przeciwnika2[wiersz - 1][kolumna + i] = -2;

							if (wiersz != 9) // 4down
								for (int i = 0; i < 4; i++)
									plansza_przeciwnika2[wiersz + 1][kolumna + i] = -2;

							if (kolumna != 0) // 1left
								plansza_przeciwnika2[wiersz][kolumna - 1] = -2;

							if (kolumna + 3 != 9) // 1right
								plansza_przeciwnika2[wiersz][kolumna + 4] = -2;

							if (kolumna != 0 && wiersz != 0) // left_up
								plansza_przeciwnika2[wiersz - 1][kolumna - 1] = -2;

							if (kolumna + 3 != 9 && wiersz != 0) // right_up
								plansza_przeciwnika2[wiersz - 1][kolumna + 4] = -2;

							if (kolumna != 0 && wiersz != 9) // left_down
								plansza_przeciwnika2[wiersz + 1][kolumna - 1] = -2;

							if (kolumna + 3 != 9 && wiersz != 9) // right_down
								plansza_przeciwnika2[wiersz + 1][kolumna + 4] = -2;
							#pragma endregion USTAW -2 dla PLANSZA_PRZECIWNIKA2
						}
							// PIONOWY
						else
						{
							if (twoja_plansza1[wiersz - 1][kolumna] == 14 && twoja_plansza1[wiersz + 1][kolumna] == 14 && twoja_plansza1[wiersz + 2][kolumna] == 14)
								wiersz -= 1;
							else if (twoja_plansza1[wiersz - 1][kolumna] == 14 && twoja_plansza1[wiersz + 1][kolumna] == 14 && twoja_plansza1[wiersz - 2][kolumna] == 14)
								wiersz -= 2;
							else if (twoja_plansza1[wiersz - 1][kolumna] == 14 && twoja_plansza1[wiersz + 1][kolumna] != 14)
								wiersz -= 3;

							#pragma region USTAW -2 dla TWOJA_PLANSZA1
								// -2 -> '0'
							if (wiersz != 0) // 1up
								twoja_plansza1[wiersz - 1][kolumna] = -2;

							if (wiersz + 3 != 9) // 1down
								twoja_plansza1[wiersz + 4][kolumna] = -2;

							if (kolumna != 0) // 4left
								for (int i = 0; i < 4; i++)
									twoja_plansza1[wiersz + i][kolumna - 1] = -2;

							if (kolumna != 9) // 4right
								for (int i = 0; i < 4; i++)
									twoja_plansza1[wiersz + i][kolumna + 1] = -2;

							if (kolumna != 0 && wiersz != 0) // left_up
								twoja_plansza1[wiersz - 1][kolumna - 1] = -2;

							if (kolumna != 9 && wiersz != 0) // right_up
								twoja_plansza1[wiersz - 1][kolumna + 1] = -2;

							if (kolumna != 0 && wiersz + 3 != 9) // left_down
								twoja_plansza1[wiersz + 4][kolumna - 1] = -2;

							if (kolumna != 9 && wiersz + 3 != 9) // right_down
								twoja_plansza1[wiersz + 4][kolumna + 1] = -2;
							#pragma endregion USTAW -2 dla TWOJA_PLANSZA1

							#pragma region USTAW -2 dla PLANSZA_PRZECIWNIKA2
								// -2 -> '0'
							if (wiersz != 0) // 1up
								plansza_przeciwnika2[wiersz - 1][kolumna] = -2;

							if (wiersz + 3 != 9) // 1down
								plansza_przeciwnika2[wiersz + 4][kolumna] = -2;

							if (kolumna != 0) // 4left
								for (int i = 0; i < 4; i++)
									plansza_przeciwnika2[wiersz + i][kolumna - 1] = -2;

							if (kolumna != 9) // 4right
								for (int i = 0; i < 4; i++)
									plansza_przeciwnika2[wiersz + i][kolumna + 1] = -2;

							if (kolumna != 0 && wiersz != 0) // left_up
								plansza_przeciwnika2[wiersz - 1][kolumna - 1] = -2;

							if (kolumna != 9 && wiersz != 0) // right_up
								plansza_przeciwnika2[wiersz - 1][kolumna + 1] = -2;

							if (kolumna != 0 && wiersz + 3 != 9) // left_down
								plansza_przeciwnika2[wiersz + 4][kolumna - 1] = -2;

							if (kolumna != 9 && wiersz + 3 != 9) // right_down
								plansza_przeciwnika2[wiersz + 4][kolumna + 1] = -2;
							#pragma endregion USTAW -2 dla PLANSZA_PRZECIWNIKA2
						}
					}
					_licznik2 += 4;
				}
					// DLA 3
				else if (twoja_plansza1[wiersz][kolumna] == 13)
				{
					if (((twoja_plansza1[wiersz - 1][kolumna] == 13 && twoja_plansza1[wiersz - 2][kolumna] == 13) || (twoja_plansza1[wiersz + 1][kolumna] == 13 && twoja_plansza1[wiersz + 2][kolumna] == 13) || (twoja_plansza1[wiersz][kolumna - 1] == 13 && twoja_plansza1[wiersz][kolumna - 2] == 13) || (twoja_plansza1[wiersz][kolumna + 1] == 13 && twoja_plansza1[wiersz][kolumna + 2] == 13)) || ((twoja_plansza1[wiersz - 1][kolumna] == 13 && twoja_plansza1[wiersz + 1][kolumna] == 13) || (twoja_plansza1[wiersz][kolumna - 1] == 13 && twoja_plansza1[wiersz][kolumna + 1] == 13)))
					{
							// POZIOMY
						if (twoja_plansza1[wiersz][kolumna - 1] == 13 || twoja_plansza1[wiersz][kolumna + 1] == 13)
						{
							if (twoja_plansza1[wiersz][kolumna - 1] == 13 && twoja_plansza1[wiersz][kolumna + 1] == 13)
								kolumna -= 1;
							else if (twoja_plansza1[wiersz][kolumna - 1] == 13 && twoja_plansza1[wiersz][kolumna + 1] != 13)
								kolumna -= 2;

							#pragma region USTAW -2 dla TWOJA_PLANSZA1
								// -2 -> '0'
							if (wiersz != 0) // 3up
								for (int i = 0; i < 3; i++)
									twoja_plansza1[wiersz - 1][kolumna + i] = -2;

							if (wiersz != 9) // 3down
								for (int i = 0; i < 3; i++)
									twoja_plansza1[wiersz + 1][kolumna + i] = -2;

							if (kolumna != 0) // 1left
								twoja_plansza1[wiersz][kolumna - 1] = -2;

							if (kolumna + 2 != 9) // 1right
								twoja_plansza1[wiersz][kolumna + 3] = -2;

							if (kolumna != 0 && wiersz != 0) // left_up
								twoja_plansza1[wiersz - 1][kolumna - 1] = -2;

							if (kolumna + 2 != 9 && wiersz != 0) // right_up
								twoja_plansza1[wiersz - 1][kolumna + 3] = -2;

							if (kolumna != 0 && wiersz != 9) // left_down
								twoja_plansza1[wiersz + 1][kolumna - 1] = -2;

							if (kolumna + 2 != 9 && wiersz != 9) // right_down
								twoja_plansza1[wiersz + 1][kolumna + 3] = -2;
							#pragma endregion USTAW -2 dla TWOJA_PLANSZA1

							#pragma region USTAW -2 dla PLANSZA_PRZECIWNIKA2
								// -2 -> '0'
							if (wiersz != 0) // 3up
								for (int i = 0; i < 3; i++)
									plansza_przeciwnika2[wiersz - 1][kolumna + i] = -2;

							if (wiersz != 9) // 3down
								for (int i = 0; i < 3; i++)
									plansza_przeciwnika2[wiersz + 1][kolumna + i] = -2;

							if (kolumna != 0) // 1left
								plansza_przeciwnika2[wiersz][kolumna - 1] = -2;

							if (kolumna + 2 != 9) // 1right
								plansza_przeciwnika2[wiersz][kolumna + 3] = -2;

							if (kolumna != 0 && wiersz != 0) // left_up
								plansza_przeciwnika2[wiersz - 1][kolumna - 1] = -2;

							if (kolumna + 2 != 9 && wiersz != 0) // right_up
								plansza_przeciwnika2[wiersz - 1][kolumna + 3] = -2;

							if (kolumna != 0 && wiersz != 9) // left_down
								plansza_przeciwnika2[wiersz + 1][kolumna - 1] = -2;

							if (kolumna + 2 != 9 && wiersz != 9) // right_down
								plansza_przeciwnika2[wiersz + 1][kolumna + 3] = -2;
							#pragma endregion USTAW -2 dla PLANSZA_PRZECIWNIKA2
						}
							// PIONOWY
						else
						{
							if (twoja_plansza1[wiersz - 1][kolumna] == 13 && twoja_plansza1[wiersz + 1][kolumna] == 13)
								wiersz -= 1;
							else if (twoja_plansza1[wiersz - 1][kolumna] == 13 && twoja_plansza1[wiersz + 1][kolumna] != 13)
								wiersz -= 2;

							#pragma region USTAW -2 dla TWOJA_PLANSZA1
								// -2 -> '0'
							if (wiersz != 0) // 1up
								twoja_plansza1[wiersz - 1][kolumna] = -2;

							if (wiersz + 2 != 9) // 1down
								twoja_plansza1[wiersz + 3][kolumna] = -2;

							if (kolumna != 0) // 3left
								for (int i = 0; i < 3; i++)
									twoja_plansza1[wiersz + i][kolumna - 1] = -2;

							if (kolumna != 9) // 3right
								for (int i = 0; i < 3; i++)
									twoja_plansza1[wiersz + i][kolumna + 1] = -2;

							if (kolumna != 0 && wiersz != 0) // left_up
								twoja_plansza1[wiersz - 1][kolumna - 1] = -2;

							if (kolumna != 9 && wiersz != 0) // right_up
								twoja_plansza1[wiersz - 1][kolumna + 1] = -2;

							if (kolumna != 0 && wiersz + 2 != 9) // left_down
								twoja_plansza1[wiersz + 3][kolumna - 1] = -2;

							if (kolumna != 9 && wiersz + 2 != 9) // right_down
								twoja_plansza1[wiersz + 3][kolumna + 1] = -2;
							#pragma endregion USTAW -2 dla TWOJA_PLANSZA1

							#pragma region USTAW -2 dla PLANSZA_PRZECIWNIKA2
								// -2 -> '0'
							if (wiersz != 0) // 1up
								plansza_przeciwnika2[wiersz - 1][kolumna] = -2;

							if (wiersz + 2 != 9) // 1down
								plansza_przeciwnika2[wiersz + 3][kolumna] = -2;

							if (kolumna != 0) // 3left
								for (int i = 0; i < 3; i++)
									plansza_przeciwnika2[wiersz + i][kolumna - 1] = -2;

							if (kolumna != 9) // 3right
								for (int i = 0; i < 3; i++)
									plansza_przeciwnika2[wiersz + i][kolumna + 1] = -2;

							if (kolumna != 0 && wiersz != 0) // left_up
								plansza_przeciwnika2[wiersz - 1][kolumna - 1] = -2;

							if (kolumna != 9 && wiersz != 0) // right_up
								plansza_przeciwnika2[wiersz - 1][kolumna + 1] = -2;

							if (kolumna != 0 && wiersz + 2 != 9) // left_down
								plansza_przeciwnika2[wiersz + 3][kolumna - 1] = -2;

							if (kolumna != 9 && wiersz + 2 != 9) // right_down
								plansza_przeciwnika2[wiersz + 3][kolumna + 1] = -2;
							#pragma endregion USTAW -2 dla PLANSZA_PRZECIWNIKA2
						}
					}
					_licznik2 += 3;
				}
					// DLA 2
				else if (twoja_plansza1[wiersz][kolumna] == 12)
				{
					if (twoja_plansza1[wiersz - 1][kolumna] == 12 || twoja_plansza1[wiersz + 1][kolumna] == 12 || twoja_plansza1[wiersz][kolumna - 1] == 12 || twoja_plansza1[wiersz][kolumna + 1] == 12)
					{
							// POZIOMY
						if (twoja_plansza1[wiersz][kolumna - 1] == 12 || twoja_plansza1[wiersz][kolumna + 1] == 12)
						{
							if (twoja_plansza1[wiersz][kolumna - 1] == 12)
								kolumna -= 1;

							#pragma region USTAW -2 dla TWOJA_PLANSZA1
								// -2 -> 'O'
							if (wiersz != 0) // 2up
								for (int i = 0; i < 2; i++)
									twoja_plansza1[wiersz - 1][kolumna + i] = -2;

							if (wiersz != 9) // 2down
								for (int i = 0; i < 2; i++)
									twoja_plansza1[wiersz + 1][kolumna + i] = -2;

							if (kolumna != 0) // 1left
								twoja_plansza1[wiersz][kolumna - 1] = -2;

							if (kolumna + 1 != 9) // 1right
								twoja_plansza1[wiersz][kolumna + 2] = -2;

							if (kolumna != 0 && wiersz != 0) // left_up
								twoja_plansza1[wiersz - 1][kolumna - 1] = -2;

							if (kolumna + 1 != 9 && wiersz != 0) // right_up
								twoja_plansza1[wiersz - 1][kolumna + 2] = -2;

							if (kolumna != 0 && wiersz != 9) // left_down
								twoja_plansza1[wiersz + 1][kolumna - 1] = -2;

							if (kolumna + 1 != 9 && wiersz != 9) // right_down
								twoja_plansza1[wiersz + 1][kolumna + 2] = -2;
							#pragma endregion USTAW -2 dla TWOJA_PLANSZA1

							#pragma region USTAW -2 dla PLANSZA_PRZECIWNIKA2
								// -2 -> 'O'
							if (wiersz != 0) // 2up
								for (int i = 0; i < 2; i++)
									plansza_przeciwnika2[wiersz - 1][kolumna + i] = -2;

							if (wiersz != 9) // 2down
								for (int i = 0; i < 2; i++)
									plansza_przeciwnika2[wiersz + 1][kolumna + i] = -2;

							if (kolumna != 0) // 1left
								plansza_przeciwnika2[wiersz][kolumna - 1] = -2;

							if (kolumna + 1 != 9) // 1right
								plansza_przeciwnika2[wiersz][kolumna + 2] = -2;

							if (kolumna != 0 && wiersz != 0) // left_up
								plansza_przeciwnika2[wiersz - 1][kolumna - 1] = -2;

							if (kolumna + 1 != 9 && wiersz != 0) // right_up
								plansza_przeciwnika2[wiersz - 1][kolumna + 2] = -2;

							if (kolumna != 0 && wiersz != 9) // left_down
								plansza_przeciwnika2[wiersz + 1][kolumna - 1] = -2;

							if (kolumna + 1 != 9 && wiersz != 9) // right_down
								plansza_przeciwnika2[wiersz + 1][kolumna + 2] = -2;
							#pragma endregion USTAW -2 dla PLANSZA_PRZECIWNIKA2
						}
							// PIONOWY
						else
						{
							if (twoja_plansza1[wiersz - 1][kolumna] == 12)
								wiersz -= 1;

							#pragma region USTAW -2 dla TWOJA_PLANSZA1
								// -2 -> '0'
							if (wiersz != 0) // 1up
								twoja_plansza1[wiersz - 1][kolumna] = -2;

							if (wiersz + 1 != 9) // 1down
								twoja_plansza1[wiersz + 2][kolumna] = -2;

							if (kolumna != 0) // 2left
								for (int i = 0; i < 2; i++)
									twoja_plansza1[wiersz + i][kolumna - 1] = -2;

							if (kolumna != 9) // 2right
								for (int i = 0; i < 2; i++)
									twoja_plansza1[wiersz + i][kolumna + 1] = -2;

							if (kolumna != 0 && wiersz != 0) // left_up
								twoja_plansza1[wiersz - 1][kolumna - 1] = -2;

							if (kolumna != 9 && wiersz != 0) // right_up
								twoja_plansza1[wiersz - 1][kolumna + 1] = -2;

							if (kolumna != 0 && wiersz + 1 != 9) // left_down
								twoja_plansza1[wiersz + 2][kolumna - 1] = -2;

							if (kolumna != 9 && wiersz + 1 != 9) // right_down
								twoja_plansza1[wiersz + 2][kolumna + 1] = -2;
							#pragma endregion USTAW -2 dla TWOJA_PLANSZA1

							#pragma region USTAW -2 dla PLANSZA_PRZECIWNIKA2
								// -2 -> '0'
							if (wiersz != 0) // 1up
								plansza_przeciwnika2[wiersz - 1][kolumna] = -2;

							if (wiersz + 1 != 9) // 1down
								plansza_przeciwnika2[wiersz + 2][kolumna] = -2;

							if (kolumna != 0) // 2left
								for (int i = 0; i < 2; i++)
									plansza_przeciwnika2[wiersz + i][kolumna - 1] = -2;

							if (kolumna != 9) // 2right
								for (int i = 0; i < 2; i++)
									plansza_przeciwnika2[wiersz + i][kolumna + 1] = -2;

							if (kolumna != 0 && wiersz != 0) // left_up
								plansza_przeciwnika2[wiersz - 1][kolumna - 1] = -2;

							if (kolumna != 9 && wiersz != 0) // right_up
								plansza_przeciwnika2[wiersz - 1][kolumna + 1] = -2;

							if (kolumna != 0 && wiersz + 1 != 9) // left_down
								plansza_przeciwnika2[wiersz + 2][kolumna - 1] = -2;

							if (kolumna != 9 && wiersz + 1 != 9) // right_down
								plansza_przeciwnika2[wiersz + 2][kolumna + 1] = -2;
							#pragma endregion USTAW -2 dla PLANSZA_PRZECIWNIKA2
						}
					}
					_licznik2 += 2;
				}
					// DLA 1
				else
				{
					#pragma region USTAW -2 dla TWOJA_PLANSZA1
						// -2 -> 'O'
					if (wiersz != 0) // 1up
						twoja_plansza1[wiersz - 1][kolumna] = -2;

					if (wiersz != 9) // 1down
						twoja_plansza1[wiersz + 1][kolumna] = -2;

					if (kolumna != 0) // 1left
						twoja_plansza1[wiersz][kolumna - 1] = -2;

					if (kolumna != 9) // 1right
						twoja_plansza1[wiersz][kolumna + 1] = -2;

					if (kolumna != 0 && wiersz != 0) // left_up
						twoja_plansza1[wiersz - 1][kolumna - 1] = -2;

					if (kolumna != 9 && wiersz != 0) // right_up
						twoja_plansza1[wiersz - 1][kolumna + 1] = -2;

					if (kolumna != 0 && wiersz != 9) // left_down
						twoja_plansza1[wiersz + 1][kolumna - 1] = -2;

					if (kolumna != 9 && wiersz != 9) // right_down
						twoja_plansza1[wiersz + 1][kolumna + 1] = -2;
					#pragma endregion USTAW -2 dla TWOJA_PLANSZA1

					#pragma region USTAW -2 dla PLANSZA_PRZECIWNIKA2
						// -2 -> 'O'
					if (wiersz != 0) // 1up
						plansza_przeciwnika2[wiersz - 1][kolumna] = -2;

					if (wiersz != 9) // 1down
						plansza_przeciwnika2[wiersz + 1][kolumna] = -2;

					if (kolumna != 0) // 1left
						plansza_przeciwnika2[wiersz][kolumna - 1] = -2;

					if (kolumna != 9) // 1right
						plansza_przeciwnika2[wiersz][kolumna + 1] = -2;

					if (kolumna != 0 && wiersz != 0) // left_up
						plansza_przeciwnika2[wiersz - 1][kolumna - 1] = -2;

					if (kolumna != 9 && wiersz != 0) // right_up
						plansza_przeciwnika2[wiersz - 1][kolumna + 1] = -2;

					if (kolumna != 0 && wiersz != 9) // left_down
						plansza_przeciwnika2[wiersz + 1][kolumna - 1] = -2;

					if (kolumna != 9 && wiersz != 9) // right_down
						plansza_przeciwnika2[wiersz + 1][kolumna + 1] = -2;
					#pragma endregion USTAW -2 dla PLANSZA_PRZECIWNIKA2

					_licznik2 += 1;
				}
			}
		}
		else
		{
			#pragma region NAPIS "Błędne współrzędne, spróbuj ponownie!"
			cout << "\n  B"; Sleep(10); cout << "\210"; Sleep(10); cout << "\251"; Sleep(10); cout << "d"; Sleep(10); cout << "n"; Sleep(10); cout << "e"; Sleep(10); cout << " "; Sleep(10); cout << "w"; Sleep(10); cout << "s"; Sleep(10); cout << "p"; Sleep(10); cout << "\242"; Sleep(10); cout << "\210"; Sleep(10); cout << "r"; Sleep(10); cout << "z"; Sleep(10); cout << "\251"; Sleep(10); cout << "d"; Sleep(10); cout << "n"; Sleep(10); cout << "e"; Sleep(10); cout << ","; Sleep(10); cout << " "; Sleep(10); cout << "s"; Sleep(10); cout << "p"; Sleep(10); cout << "r"; Sleep(10); cout << "\242"; Sleep(10); cout << "b"; Sleep(10); cout << "u"; Sleep(10); cout << "j"; Sleep(10); cout << " "; Sleep(10); cout << "p"; Sleep(10); cout << "o"; Sleep(10); cout << "n"; Sleep(10); cout << "o"; Sleep(10); cout << "w"; Sleep(10); cout << "n"; Sleep(10); cout << "i"; Sleep(10); cout << "e"; Sleep(10); cout << "!";
			#pragma endregion NAPIS "Błędne współrzędne, spróbuj ponownie!"
			Sleep(1500);
			goto wypis2;
		}
		#pragma endregion WPISANIE W PLANSZE

		//
		#pragma region WYPIS PLANSZ No2
		system("cls");
		#pragma region NAPISY "Ruch gracza: GRACZ2", "PLANSZA PRZECIWNIKA:" i "TWOJA PLANSZA:"
		cout << "\n  Ruch gracza: " << _gracz2 << "\n\n";
		cout.width(24);
		cout << "PLANSZA PRZECIWNIKA:";
		cout.width(29);
		cout << "TWOJA PLANSZA:\n\n";
		#pragma endregion NAPISY "Ruch gracza: GRACZ2", "PLANSZA PRZECIWNIKA:" i "TWOJA PLANSZA:"
		#pragma region WYPIS LITER A - J PLANSZA_PRZECIWNIKA2 (NUMEROWANIE KOLUMN)
		wier = 'A';
		cout.width(4); cout << " ";
		for (int i = 0; i <= 9; i++)
		{
			cout.width(2);
			cout << static_cast<char>(wier + lit);
			lit++;
		}
		lit = 0;
		#pragma endregion WYPIS LITER A - J PLANSZA_PRZECIWNIKA2 (NUMEROWANIE KOLUMN)
		#pragma region WYPIS LITER A - J TWOJA_PLANSZA2 (NUMEROWANIE KOLUMN)
		cout.width(10); cout << " ";
		for (int i = 0; i <= 9; i++)
		{
			cout.width(2);
			cout << static_cast<char>(wier + lit);
			lit++;
		}
		cout << endl; lit = 0;
		#pragma endregion WYPIS LITER A - J TWOJA_PLANSZA2 (NUMEROWANIE KOLUMN)
		#pragma region WYPIS PLANSZA_PRZECIWNIKA2 i TWOJA_PLANSZA2
		for (int i = 0; i <= 9; i++)
		{
			#pragma region WYPIS plansza_przeciwnika2
			cout.width(3);
			cout << i + 1 << "."; // NUMEROWANIE WIERSZY PLANSZA_PRZECIWNIKA
			for (int j = 0; j <= 9; j++)
			{
				cout.width(2);
				if (plansza_przeciwnika2[i][j] == -1 || plansza_przeciwnika2[i][j] == -2)
					cout << (unsigned char)0x9E; // 'x'
				else if (plansza_przeciwnika2[i][j] == 0)
					cout << (unsigned char)0xFE; // kwadraty
				else if (plansza_przeciwnika2[i][j] > 4)
					cout << (unsigned char)0x4F; // 'O'
				else
					cout << plansza_przeciwnika2[i][j];
			}
			#pragma endregion WYPIS PLANSZA_PRZECIWNIKA2

			Sleep(10);
			cout.width(6);
			cout << " ";

			#pragma region WYPIS TWOJA_PLANSZA2
			cout.width(3);
			cout << i + 1 << "."; // NUMEROWANIE WIERSZY TWOJA_PLANSZA
			for (int j = 0; j <= 9; j++)
			{
				cout.width(2);
				if (twoja_plansza2[i][j] == 0 || twoja_plansza2[i][j] == -1)
					cout << (unsigned char)0xFE; // kwadraty
				else if (twoja_plansza2[i][j] == -2)
					cout << (unsigned char)0x9E; // 'x'
				else if (twoja_plansza2[i][j] > 4)
					cout << (unsigned char)0x4F; // 'O'
				else
					cout << twoja_plansza2[i][j];
			}
			#pragma endregion WYPIS TWOJA_PLANSZA2
			cout << endl;
		}
		#pragma endregion WYPIS PLANSZA_PRZECIWNIKA2 i TWOJA_PLANSZA2

		#pragma endregion WYPIS PLANSZ No2
		//

		Sleep(500);

		#pragma region INFORMACJE

		#pragma region NAPIS "TO OSTATNI STATEK! WYGRYWASZ!"
		if (_licznik2 == 50)
		{
			cout << "\n  T"; Sleep(10); cout << "O"; Sleep(10); cout << " "; Sleep(10); cout << "O"; Sleep(10); cout << "S"; Sleep(10); cout << "T"; Sleep(10); cout << "A"; Sleep(10); cout << "T"; Sleep(10); cout << "N"; Sleep(10); cout << "I"; Sleep(10); cout << " "; Sleep(10); cout << "S"; Sleep(10); cout << "T"; Sleep(10); cout << "A"; Sleep(10); cout << "T"; Sleep(10); cout << "E"; Sleep(10); cout << "K"; Sleep(10); cout << "!"; Sleep(500); cout << " W"; Sleep(10); cout << "Y"; Sleep(10); cout << "G"; Sleep(10); cout << "R"; Sleep(10); cout << "Y"; Sleep(10); cout << "W"; Sleep(10); cout << "A"; Sleep(10); cout << "S"; Sleep(10); cout << "Z"; Sleep(10); cout << "!";
			_nazwy_niepodane = 1;
			Sleep(2000);
		}
		#pragma endregion NAPIS "TO OSTATNI STATEK! WYGRYWASZ!"
		#pragma region NAPIS "Pudło."
		else if (twoja_plansza1[wiersz][kolumna] == -2)
		{
			cout << "\n  P"; Sleep(10); cout << "u"; Sleep(10); cout << "d"; Sleep(10); cout << "\210"; Sleep(10); cout << "o"; Sleep(10); cout << ".";
			Sleep(1000);
		}
		#pragma endregion NAPIS "Pudło."
		#pragma region NAPIS "Zatopiłeś statek 4-masztowy!"
		else if (((twoja_plansza1[wiersz - 1][kolumna] == 14 && twoja_plansza1[wiersz - 2][kolumna] == 14 && twoja_plansza1[wiersz - 3][kolumna] == 14) || (twoja_plansza1[wiersz + 1][kolumna] == 14 && twoja_plansza1[wiersz + 2][kolumna] == 14 && twoja_plansza1[wiersz + 3][kolumna] == 14) || (twoja_plansza1[wiersz][kolumna - 1] == 14 && twoja_plansza1[wiersz][kolumna - 2] == 14 && twoja_plansza1[wiersz][kolumna - 3] == 14) || (twoja_plansza1[wiersz][kolumna + 1] == 14 && twoja_plansza1[wiersz][kolumna + 2] == 14 && twoja_plansza1[wiersz][kolumna + 3] == 14)) || ((twoja_plansza1[wiersz - 1][kolumna] == 14 && twoja_plansza1[wiersz - 2][kolumna] == 14 && twoja_plansza1[wiersz + 1][kolumna] == 14) || (twoja_plansza1[wiersz + 1][kolumna] == 14 && twoja_plansza1[wiersz + 2][kolumna] == 14 && twoja_plansza1[wiersz - 1][kolumna] == 14) || (twoja_plansza1[wiersz][kolumna - 1] == 14 && twoja_plansza1[wiersz][kolumna - 2] == 14 && twoja_plansza1[wiersz][kolumna + 1] == 14) || (twoja_plansza1[wiersz][kolumna + 1] == 14 && twoja_plansza1[wiersz][kolumna + 2] == 14 && twoja_plansza1[wiersz][kolumna - 1] == 14)))
		{
			cout << "\n  Z"; Sleep(10); cout << "a"; Sleep(10); cout << "t"; Sleep(10); cout << "o"; Sleep(10); cout << "p"; Sleep(10); cout << "i"; Sleep(10); cout << "\210"; Sleep(10); cout << "e"; Sleep(10); cout << "\230"; Sleep(10); cout << " "; Sleep(10); cout << "s"; Sleep(10); cout << "t"; Sleep(10); cout << "a"; Sleep(10); cout << "t"; Sleep(10); cout << "e"; Sleep(10); cout << "k"; Sleep(10); cout << " "; Sleep(10); cout << "4"; Sleep(10); cout << "-"; Sleep(10); cout << "m"; Sleep(10); cout << "a"; Sleep(10); cout << "s"; Sleep(10); cout << "z"; Sleep(10); cout << "t"; Sleep(10); cout << "o"; Sleep(10); cout << "w"; Sleep(10); cout << "y"; Sleep(10); cout << "!";
			Sleep(1000);
		}
		#pragma endregion NAPIS "Zatopiłeś statek 4-masztowy!"
		#pragma region NAPIS "Zatopiłeś statek 3-masztowy!"
		else if (((twoja_plansza1[wiersz - 1][kolumna] == 13 && twoja_plansza1[wiersz - 2][kolumna] == 13) || (twoja_plansza1[wiersz + 1][kolumna] == 13 && twoja_plansza1[wiersz + 2][kolumna] == 13) || (twoja_plansza1[wiersz][kolumna - 1] == 13 && twoja_plansza1[wiersz][kolumna - 2] == 13) || (twoja_plansza1[wiersz][kolumna + 1] == 13 && twoja_plansza1[wiersz][kolumna + 2] == 13)) || ((twoja_plansza1[wiersz - 1][kolumna] == 13 && twoja_plansza1[wiersz + 1][kolumna] == 13) || (twoja_plansza1[wiersz][kolumna - 1] == 13 && twoja_plansza1[wiersz][kolumna + 1] == 13)))
		{
			cout << "\n  Z"; Sleep(10); cout << "a"; Sleep(10); cout << "t"; Sleep(10); cout << "o"; Sleep(10); cout << "p"; Sleep(10); cout << "i"; Sleep(10); cout << "\210"; Sleep(10); cout << "e"; Sleep(10); cout << "\230"; Sleep(10); cout << " "; Sleep(10); cout << "s"; Sleep(10); cout << "t"; Sleep(10); cout << "a"; Sleep(10); cout << "t"; Sleep(10); cout << "e"; Sleep(10); cout << "k"; Sleep(10); cout << " "; Sleep(10); cout << "3"; Sleep(10); cout << "-"; Sleep(10); cout << "m"; Sleep(10); cout << "a"; Sleep(10); cout << "s"; Sleep(10); cout << "z"; Sleep(10); cout << "t"; Sleep(10); cout << "o"; Sleep(10); cout << "w"; Sleep(10); cout << "y"; Sleep(10); cout << "!";
			Sleep(1000);
		}
		#pragma endregion NAPIS "Zatopiłeś statek 3-masztowy!"
		#pragma region NAPIS "Zatopiłeś statek 2-masztowy!"
		else if (twoja_plansza1[wiersz - 1][kolumna] == 12 || twoja_plansza1[wiersz + 1][kolumna] == 12 || twoja_plansza1[wiersz][kolumna - 1] == 12 || twoja_plansza1[wiersz][kolumna + 1] == 12)
		{
			cout << "\n  Z"; Sleep(10); cout << "a"; Sleep(10); cout << "t"; Sleep(10); cout << "o"; Sleep(10); cout << "p"; Sleep(10); cout << "i"; Sleep(10); cout << "\210"; Sleep(10); cout << "e"; Sleep(10); cout << "\230"; Sleep(10); cout << " "; Sleep(10); cout << "s"; Sleep(10); cout << "t"; Sleep(10); cout << "a"; Sleep(10); cout << "t"; Sleep(10); cout << "e"; Sleep(10); cout << "k"; Sleep(10); cout << " "; Sleep(10); cout << "2"; Sleep(10); cout << "-"; Sleep(10); cout << "m"; Sleep(10); cout << "a"; Sleep(10); cout << "s"; Sleep(10); cout << "z"; Sleep(10); cout << "t"; Sleep(10); cout << "o"; Sleep(10); cout << "w"; Sleep(10); cout << "y"; Sleep(10); cout << "!";
			Sleep(1000);
		}
		#pragma endregion NAPIS "Zatopiłeś statek 2-masztowy!"
		#pragma region NAPIS "Zatopiłeś statek 1-masztowy!"
		else if (twoja_plansza1[wiersz][kolumna] == 11)
		{
			cout << "\n  Z"; Sleep(10); cout << "a"; Sleep(10); cout << "t"; Sleep(10); cout << "o"; Sleep(10); cout << "p"; Sleep(10); cout << "i"; Sleep(10); cout << "\210"; Sleep(10); cout << "e"; Sleep(10); cout << "\230"; Sleep(10); cout << " "; Sleep(10); cout << "s"; Sleep(10); cout << "t"; Sleep(10); cout << "a"; Sleep(10); cout << "t"; Sleep(10); cout << "e"; Sleep(10); cout << "k"; Sleep(10); cout << " "; Sleep(10); cout << "1"; Sleep(10); cout << "-"; Sleep(10); cout << "m"; Sleep(10); cout << "a"; Sleep(10); cout << "s"; Sleep(10); cout << "z"; Sleep(10); cout << "t"; Sleep(10); cout << "o"; Sleep(10); cout << "w"; Sleep(10); cout << "y"; Sleep(10); cout << "!";
			Sleep(1000);
		}
		#pragma endregion NAPIS "Zatopiłeś statek 1-masztowy!"
		#pragma region NAPIS "Trafiłeś!"
		else
		{
			cout << "\n  T"; Sleep(10); cout << "r"; Sleep(10); cout << "a"; Sleep(10); cout << "f"; Sleep(10); cout << "i"; Sleep(10); cout << "\210"; Sleep(10); cout << "e"; Sleep(10); cout << "\230"; Sleep(10); cout << "!";
			Sleep(1000);
		}
		#pragma endregion NAPIS "Trafiłeś!"

		#pragma endregion INFORMACJE

		#pragma region NAPIS "Wciśnij dowolny klawisz, żeby kontynuować."
		cout << "\n\n  W"; Sleep(10); cout << "c"; Sleep(10); cout << "i"; Sleep(10); cout << "\230"; Sleep(10); cout << "n"; Sleep(10); cout << "i"; Sleep(10); cout << "j"; Sleep(10); cout << " "; Sleep(10); cout << "d"; Sleep(10); cout << "o"; Sleep(10); cout << "w"; Sleep(10); cout << "o"; Sleep(10); cout << "l"; Sleep(10); cout << "n"; Sleep(10); cout << "y"; Sleep(10); cout << " "; Sleep(10); cout << "k"; Sleep(10); cout << "l"; Sleep(10); cout << "a"; Sleep(10); cout << "w"; Sleep(10); cout << "i"; Sleep(10); cout << "s"; Sleep(10); cout << "z"; Sleep(10); cout << ","; Sleep(10); cout << " "; Sleep(10); cout << "\276"; Sleep(10); cout << "e"; Sleep(10); cout << "b"; Sleep(10); cout << "y"; Sleep(10); cout << " "; Sleep(10); cout << "k"; Sleep(10); cout << "o"; Sleep(10); cout << "n"; Sleep(10); cout << "t"; Sleep(10); cout << "y"; Sleep(10); cout << "n"; Sleep(10); cout << "u"; Sleep(10); cout << "o"; Sleep(10); cout << "w"; Sleep(10); cout << "a"; Sleep(10); cout << "\206"; Sleep(10); cout << "."; Sleep(10); cout << " ";
		Sleep(300);
		ShowConsoleCursor(1);
		_nic = _getch();
		#pragma endregion NAPIS "Wciśnij dowolny klawisz, żeby kontynuować."

		_runda++;
	}
}

#pragma endregion FUNKCJE
