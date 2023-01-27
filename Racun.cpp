#include "Racun.h"
#include <iostream>
#include <iomanip>
using namespace std;

Racun::Racun() {
	this->datumTransakcije = new Datum[50];
	this->iznosTransakcije = new float[50];
	this->stanjeRacuna = new float[50];
	this->brTransakcija = 0;
	this->otvoren = false;
}
void Racun::setBrRacuna() {
	cout << "Unesite broj racuna: ";
	cin >> this->brRacuna;
	cin.ignore();
}
void Racun::setLimit() {
	cout << "Unesite iznos limita racuna: ";
	cin >> this->limit;
	cin.ignore();
}
int Racun::getBrRacuna() {
	return this->brRacuna;
}
float Racun::getLimit() {
	return this->limit;
}
int Racun::getBrTransakcija() {
	return this->brTransakcija;
}
bool Racun::getOtvoren() {
	return this->otvoren;
}
void Racun::otvaranjeRacuna() {
	if (this->getOtvoren()) {
		cout << "Racun je vec otvoren!\n";
	}
	else {
		cout << "\t***** Otvaranje racuna *****\n";
		this->korisnik.postaviKorisnika();
		this->setBrRacuna();
		cout << "Unesite datum otvaranja racuna: \n";
		this->datumTransakcije[this->getBrTransakcija()].setDatum();
		cout << "Unesite iznos prvobitne uplate: ";
		cin >> this->iznosTransakcije[this->getBrTransakcija()];
		cin.ignore();
		this->stanjeRacuna[this->getBrTransakcija()] = this->iznosTransakcije[this->getBrTransakcija()];
		this->setLimit();
		this->brTransakcija++;
		this->otvoren = true;
	}
}
void Racun::uplata() {
	if (!this->getOtvoren()) {
		cout << "Racun nije otvoren!\n";
		return;
	}
	cout << "Unesite iznos za uplatu: ";
	cin >> this->iznosTransakcije[this->getBrTransakcija()];
	cin.ignore();
	this->stanjeRacuna[this->getBrTransakcija()] = this->getStanjeRacuna() + this->iznosTransakcije[this->getBrTransakcija()];
	cout << "Unesite datum uplate:\n";
	this->datumTransakcije[this->getBrTransakcija()].setDatum();
	this->brTransakcija++;
	cout << "Stanje racuna: " << this->getStanjeRacuna() << " KM\n";
}
void Racun::isplata() {
	if (!this->getOtvoren()) {
		cout << "Racun nije otvoren!\n";
		return;
	}
	float x;
	cout << "Trenutno stanje racuna: " << this->getStanjeRacuna() << " KM\n";
	cout << "Unesite iznos za isplatu: ";
	cin >> x;
	cin.ignore();
	if (-1 * this->getLimit() < this->getStanjeRacuna() - x) {
		this->iznosTransakcije[this->getBrTransakcija()] = x * -1;
		this->stanjeRacuna[this->getBrTransakcija()] = this->getStanjeRacuna() + this->iznosTransakcije[this->getBrTransakcija()];
		cout << "Unesite datum isplate: \n";
		this->datumTransakcije[this->getBrTransakcija()].setDatum();
		this->brTransakcija++;
		cout << "Stanje racuna: " << this->getStanjeRacuna() << " KM\n";
	}
	else {
		cout << "Nije moguce podignuti toliki novac!\n";
	}
}
float Racun::getStanjeRacuna() {
	return this->stanjeRacuna[this->getBrTransakcija() - 1];
}
void Racun::ispisTransakcija() {
	if (!this->getOtvoren()) {
		cout << "Racun nije otvoren!\n";
		return;
	}
	system("cls");
	cout << "****************************************************************************\n";
	cout << "Broj racuna: " << this->getBrRacuna() << "\n";
	cout << "Korisnik: " << this->korisnik.getIme() << " " << this->korisnik.getPrezime() << "\n";
	cout << "****************************************************************************\n";
	cout.width(6); cout << "R. br.";
	cout.width(20); cout << "Datum transakcije";
	cout.width(23); cout << "Iznos transakcije";
	cout.width(23); cout << "Stanje racuna";
	cout << endl;
	cout << "****************************************************************************\n";
	for (int i = 0; i < this->getBrTransakcija(); i++) {
		cout.width(6); cout << i + 1;
		cout.width(20); cout << this->datumTransakcije[i].getDatum();
		cout.width(20); cout << right << setprecision(2) << fixed << this->iznosTransakcije[i] << " KM";
		cout.width(20); cout << right << setprecision(2) << fixed << this->stanjeRacuna[i] << " KM";
		cout << endl;
	}
	cout << "****************************************************************************\n";
}
Racun::~Racun() {
	delete[] this->datumTransakcije;
	delete[] this->iznosTransakcije;
	delete[] this->stanjeRacuna;
}