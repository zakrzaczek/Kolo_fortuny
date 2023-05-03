using namespace std;
#include "Gracz.h"

Gracz::Gracz(string imie) : imie(imie), kasa(0), portfel(0) {
	counter++;
}

void Gracz::dodajKase(int kwota) { 
	kasa += kwota; 
}
void Gracz::dodajPortfel(int kwota) { 
	portfel += kwota; 
}
void Gracz::resetujKase() { 
	kasa = 0; 
}
void Gracz::resetujPortfel() { 
	portfel = 0; 
}