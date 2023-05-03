#pragma once
#include <iostream>
#include <string> 
using namespace std;

#include "Gracz.h"
#include "Gracze.h"
#include "Has³o.h"
#include "Ko³o.h"

class Menu {
public:
	int kolejka = 0;
	string proba;
	int suma = 0;
	char literka;
	int zgadl = 0;
	int kwota = 0;
	char wybor;
	string rezultat;

	char wczytajZnak();
	char wczytajWybor();
	void zgaduj(Gracze& gracze, Haslo& haslo, Kolo& kolo);
	void krec(Gracze& gracze);

};