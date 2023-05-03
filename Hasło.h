#pragma once
#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <locale.h>
#include <string>
#include <fstream>
#include <vector> 
#include <cassert>
#include <stdlib.h>     
#include <time.h>
using namespace std;

class Haslo {
public:
	int i, j;
	string haslo = "haslo";
	int n;
	int maska[100];
	int sa_spolgloski = 0;
	vector<string> hasla;

	Haslo();
	int jestSamogloska(char c);
	void jestSpolgloska();
	void schowajHaslo();
	void printHaslo();
};