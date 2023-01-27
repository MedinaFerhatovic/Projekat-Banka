#pragma once
#include "Korisnik.h"
#include "Datum.h"
class Racun
{
private:
	int brRacuna;
	Korisnik korisnik;
	Datum* datumTransakcije;
	float* iznosTransakcije;
	float* stanjeRacuna;
	float limit;
	int brTransakcija;
	bool otvoren;
public:
	Racun();
	void setBrRacuna();
	void setLimit();
	int getBrRacuna();
	float getLimit();
	int getBrTransakcija();
	bool getOtvoren();
	
	void otvaranjeRacuna();
	void uplata();
	void isplata();
	float getStanjeRacuna();
	void ispisTransakcija();
	~Racun();



};

