using namespace std;
#include "Gracze.h"
#include "Gracz.h"
#include "Menu.h"

void Gracze::addGracz(string im, int k, int p) {

	Gracz* g = new Gracz(im);
	g->imie = im;
	g->kasa = k;
	g->portfel = p;
	Gracze::vGracze.push_back(g); 

}

void Gracze::printGracze() {
	
	for (int i = 0; i < Gracz::counter; i++) {
		if (i == Menu::kolejka) {
			cout << "\033[1;34m";
		}
		cout  << i+1 << ". " << Gracze::vGracze[i]->imie << "\t" << Gracze::vGracze[i]->kasa << endl;
		cout << "\033[0m";
	}

}
