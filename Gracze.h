#pragma once
#include <vector> 
using namespace std;

#include "Gracz.h"

class Gracze {
public:
	vector <Gracz* > vGracze;

	void addGracz(string im, int k, int p);
	void printGracze();
};
