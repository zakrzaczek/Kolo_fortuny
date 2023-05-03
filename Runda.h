#pragma once
#include "Runda.h"
#include "Gracze.h"
#include "Gracz.h"

#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <string>  
#include <fstream>
#include <vector>
#include <cstring>
#include <cassert>
#include <locale.h>

class tRunda {
public:
    int kolejka = 0;
    int Kolo[16] = { -1, 0, 100, 200, 100, 200, 100, 200, 500, 500, 1000, 1000, 1500, 2000, 3000, 5000 };
    // -1 bankrut
    // 0 strata kolejki
    int i;
    std::string haslo; // = "wielka antarktyda";
    std::string proba;
    char literka;
    int n;
    int maska[100];
    int suma = 0;
    int zgadl = 0;
    int sa_spolgloski = 0;
    int kwota = 0;
    char wybor;
    std::string rezultat;
    std::vector<std::string> hasla;
    int j;


    tRunda();

    void textPlayers();
    int jestSamogloska(char c);
    char WczytajZnak();
    char WczytajWybor();
    void printMenu();
    void zgaduj();
    void krec();

};