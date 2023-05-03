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

tRunda::tRunda() {
    //losowanie has³a i wyswietlenie wszystkich hase³
    std::ifstream strum;
    strum.open("dane.txt");

    setlocale(LC_CTYPE, "Polish");

    while (!strum.eof())
    {
        std::string s;
        //strum >> s;
        getline(strum, s);
        //cout << s << endl;
        tRunda::hasla.push_back(s);

    }

    strum.close();

    for (std::string item : hasla)
        std::cout << item << std::endl;

    std::cout << std::endl << std::endl;

    std::srand(time(NULL));
    assert(hasla.size() > 0);
    j = rand() % hasla.size(); // losujemy j-te haslo z przedzialu 0 ... size - 1
    //cout << hasla[j];

    haslo = hasla[j];
    n = haslo.size();

}

void tRunda::textPlayers()
{
    int i;
    std::cout << "\n";
    for (i = 0; i < tGracz::counter; i++) {
        if (i == tGracz::counter) {
            std::cout << "\033[1;34m";
        }
        std::cout << tGracze::vGracze[i]->imie << "\t" << tGracze::vGracze[i]->kasa << "\n";
        std::cout << "\033[0m";

    }
    std::cout << "\n";
}

int tRunda::jestSamogloska(char c)
{
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'y' ||
        c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U' || c == 'Y')
        return 1;
    else
        return 0;

}

char tRunda::WczytajZnak()
{
    std::string letter;
    std::cin >> letter;

    while (letter.length() != 1)
    {
        std::cout << std::endl << "Type a single letter and press <enter>: ";
        std::cin >> letter;
    }

    for (auto& c : letter)  // & zapamietuje modyfikacje w petli & - referencja
        c = toupper(c);

    return letter[0];

}

char tRunda::WczytajWybor()
{
    char wybor;
    wybor = WczytajZnak();

    while (wybor != '1' && wybor != '2')
    {
        std::cout << std::endl << "Wybierz [1-2]: ";
        std::cin >> wybor;
    }

    return wybor;

}

void tRunda::printMenu() {
    
    std::cout << "\033[47m" << "\033[31m";
    for (i = 0; i < n; i++)
    {

        if (maska[i] == 1)
            std::cout << ".";
        else
            std::cout << haslo[i];
    }

    std::cout << "\033[0m";
    std::cout << std::endl;


    sa_spolgloski = 0;
    kwota = 0;

    for (i = 0; i < n; i++)
        if ((!jestSamogloska(haslo[i])) && (maska[i]))
        {
            sa_spolgloski = 1;
            break;
        }

    if (sa_spolgloski)
        std::cout << " -- Spolgloski sa --" << std::endl;

    textPlayers();

    std::cout << "1. zgaduj haslo" << std::endl;
    std::cout << "2. krecenie kolem" << std::endl;

    wybor = WczytajWybor();
}

void tRunda::zgaduj() {
    
    std::cout << "Podaj haslo" << std::endl;
    getline(std::cin >> ws, proba);  // wczytanie z klawiatury string z uwzgl. whitespa
    for (auto& c : proba)  // & zapamietuje modyfikacje w petli & - referencja
        c = toupper(c);
    if (haslo == proba) {
        std::cout << std::endl << " !!!!!!!!!! =======   WYGRANA ========== !!!!!!!!!!!!!" << std::endl;
        gracze[kolejka].portfel += gracze[kolejka].kasa;
        break;
    }
    else
    {
        kolejka = (kolejka + 1) % 3;
        suma = 1;
        std::cout << std::endl << " !!!!!!!!!! =======   ZLE ========== !!!!!!!!!!!!!" << std::endl;
        std::cout << std::endl << "=================================================" << std::endl;
        continue;


    }
}

void tRunda::krec() {
    
    rezultat = "";
    i = rand() % 15;
    if (Kolo[i] == 0)
        rezultat = "Strata kolejki";
    if (Kolo[i] == -1)
        rezultat = "Bankrut";
    if (rezultat != "")
        std::cout << "\033[1;31m" << rezultat << "\033[0m" << std::endl;
    else
    {
        std::cout << "\033[1;34m" << Kolo[i] << "\033[0m" << std::endl;
        kwota = Kolo[i];
    }

    // Strata kolejki i bankrut
    if ((Kolo[i] == 0) || (Kolo[i] == -1))
    {
        if (Kolo[i] == -1) // bankrut
            gracze[kolejka].kasa = 0;

        kolejka = (kolejka + 1) % 3;
        suma = 1;
        std::cout << std::endl << "=================================================" << std::endl;

        // TODO
        // sleep for
        // kupowanie samoglosek

        continue;

    }





    std::cout << gracze[kolejka].imie << ": Podaj litere" << std::endl;



    literka = WczytajZnak();


    zgadl = 0;

    if (jestSamogloska(literka))
        std::cout << "samogloska";
    else
        std::cout << "spolgloska";
    std::cout << std::endl;

    for (i = 0; i < n; i++)
    {
        if ((haslo[i] == literka) && (maska[i] == 1)) {
            maska[i] = 0;
            zgadl++;
        }
    }

    if (zgadl)
    {
        std::cout << "OK";
        gracze[kolejka].kasa += kwota * zgadl;

        std::cout << std::endl << gracze[kolejka].imie << "\033[1;32m " << gracze[kolejka].kasa << "\033[0m";


    }
    else {
        std::cout << "Zle!";
        // strata kolejki
        kolejka = (kolejka + 1) % 3;
        std::cout << std::endl << "=================================================" << std::endl;
        suma = 1;
        continue;
    }




    std::cout<< std::endl;



    suma = 0;

    for (i = 0; i < n; i++)
    {
        suma += maska[i];
    }
}