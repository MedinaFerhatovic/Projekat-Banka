#include "Datum.h"
#include <string.h>
#include <iostream>
using namespace std;

Datum::Datum() {
	strcpy_s(this->datum, "01.01.1900.");
}
void Datum::setDatum() {
	cout << "Unesite datum: ";
	cin.getline(this->datum, 12);
}
char* Datum::getDatum() {
	return this->datum;
}
