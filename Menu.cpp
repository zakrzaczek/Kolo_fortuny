using namespace std;
#include "Menu.h"


char Menu::wczytajZnak()
{
    string letter;
    cin >> letter;

    while (letter.length() != 1)
    {
        cout << endl << "Wpisz jedna litere i nacisnij <enter>: ";
        cin >> letter;
    }
    for (auto& c : letter)  // & zapamietuje modyfikacje w petli & - referencja
        c = toupper(c);
    return letter[0];
}

char Menu::wczytajWybor()
{
    char wybor;
    wybor = wczytajZnak();

    while (wybor != '1' && wybor != '2')
    {
        cout << endl << "Wybierz [1-2]: ";
        cin >> wybor;
    }
    return wybor;
}

void Menu::zgaduj(Gracze& gracze, Haslo& haslo, Kolo& kolo) {
    cout << "Podaj haslo" << endl;
    getline(cin >> ws, proba);  // wczytanie z klawiatury string z uwzgl. whitespa
    for (auto& c : proba)  // & zapamietuje modyfikacje w petli & - referencja
        c = toupper(c);
    if (haslo == proba) {
        cout << endl << " !!!!!!!!!! =======   WYGRANA ========== !!!!!!!!!!!!!" << endl;
        gracze[kolejka].portfel += gracze[kolejka].kasa;
    }
    else
    {
        kolejka = (kolejka + 1) % 3;
        suma = 1;
        cout << endl << " !!!!!!!!!! =======   ZLE ========== !!!!!!!!!!!!!" << endl;
        cout << endl << "=================================================" << endl;
    }
}

void Menu::krec(Gracze& gracze) {
    rezultat = "";
    i = rand() % 15;
    if (pola[i] == 0)
        rezultat = "Strata kolejki";
    if (pola[i] == -1)
        rezultat = "Bankrut";
    if (rezultat != "")
        cout << "\033[1;31m" << rezultat << "\033[0m" << endl;
    else
    {
        cout << "\033[1;34m" << pola[i] << "\033[0m" << endl;
        kwota = pola[i];
    }

    // Strata kolejki i bankrut
    if (pola[i] == 0) || (pola[i] == -1))
    {
        if (pola[i] == -1) // bankrut
            gracze[kolejka].kasa = 0;

        kolejka = (kolejka + 1) % 3;
        suma = 1;
        cout << endl << "=================================================" << endl;

        return;

    }
    cout << gracze[kolejka].imie << ": Podaj litere" << endl;

    literka = wczytajZnak();

    zgadl = 0;

    if (Haslo::jestSamogloska(literka))
        cout << "samogloska";
    else
        cout << "spolgloska";
    cout << endl;

    for (i = 0; i < n; i++)
    {
        if ((haslo[i] == literka) && (maska[i] == 1)) {
            maska[i] = 0;
            zgadl++;
        }
    }

    if (zgadl)
    {
        cout << "OK";
        gracze[kolejka].kasa += kwota * zgadl;

        cout << endl << gracze[kolejka].imie << "\033[1;32m " << gracze[kolejka].kasa << "\033[0m";


    }
    else {
        cout << "Zle!";
        // strata kolejki
        kolejka = (kolejka + 1) % 3;
        cout << endl << "=================================================" << endl;
        suma = 1;
    }
    cout << endl;

    suma = 0;
    for (i = 0; i < n; i++)
    {
        suma += maska[i];
    }
}