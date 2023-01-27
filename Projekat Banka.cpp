// Projekat Banka.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Racun.h"
using namespace std;

int izbornik() {
	int izbor;
	cout << "\t***** MENI *****\n";
	cout << "1. Otvaranje racuna\n";
	cout << "2. Uplata\n";
	cout << "3. Isplata\n";
	cout << "4. Pregled transakcija\n";
	cout << "5. Kraj\n";
	do {
		cout << "Izbor: ";
		cin >> izbor;
	} while (izbor < 1 || izbor>5);
	cin.ignore();
	return izbor;

}
int main()
{
	Racun racun;
	int izbor;
	do {
		system("cls");
		izbor = izbornik();
		switch (izbor)
		{
		case 1:
			racun.otvaranjeRacuna();
			system("pause");
			break;
		case 2:
			racun.uplata();
			system("pause");
			break;
		case 3:
			racun.isplata();
			system("pause");
			break;
		case 4:
			racun.ispisTransakcija();
			system("pause");
			break;
		case 5:
			cout << "Hvala i dovidjenja!\n";
			break;
		default:
			break;
		}
	} while (izbor != 5);
	system("pause");
	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
