#include "Korisnik.h"
#include <iostream>
#include <string.h>

using namespace std;

Korisnik::Korisnik() {
	strcpy_s(this->ime, "Niko");
	strcpy_s(this->prezime, "Nikic");
	strcpy_s(this->adresa, "Tu i tamo");
	strcpy_s(this->grad, "Ovamo");
}
void Korisnik::setIme() {
	cout << "Unesite ime korisnika: ";
	cin.getline(this->ime, 20);
}
void Korisnik::setPrezime() {
	cout << "Unesite prezime korisnika: ";
	cin.getline(this->prezime, 30);
}
void Korisnik::setAdresa() {
	cout << "Unesite adresu korisnika: ";
	cin.getline(this->adresa, 50);
}
void Korisnik::setGrad() {
	cout << "Unesite grad korisnika: ";
	cin.getline(this->grad, 30);
}
char* Korisnik::getIme() {
	return this->ime;
}
char* Korisnik::getPrezime() {
	return this->prezime;
}
char* Korisnik::getAdresa() {
	return this->adresa;
}
char* Korisnik::getGrad() {
	return this->grad;
}
void Korisnik::postaviKorisnika() {
	cout << "\t***** Unos korisnika u sistem *****\n";
	this->setIme();
	this->setPrezime();
	this->setAdresa();
	this->setGrad();
}