#pragma once
#include <iostream>
#include <string> 
using namespace std;

class Gracz {
public:
	string imie;
	int kasa = 0;		//kasa z danej rundy
	int portfel = 0;	//kasa z wygranych rund lacznie
	static int counter;

    Gracz(string imie);

    void dodajKase(int kwota);
    void dodajPortfel(int kwota);
    void resetujKase();
    void resetujPortfel();
};