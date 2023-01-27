#pragma once
class Korisnik
{
private:
	char ime[20], prezime[30], adresa[50], grad[30];
public:
	Korisnik();

	void setIme();
	void setPrezime();
	void setAdresa();
	void setGrad();

	char* getIme();
	char* getPrezime();
	char* getAdresa();
	char* getGrad();

	void postaviKorisnika();
	~Korisnik() = default;
};

