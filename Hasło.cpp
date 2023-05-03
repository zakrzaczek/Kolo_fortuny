#include "Has³o.h"
using namespace std;

Haslo::Haslo() {
    ifstream strum;
    strum.open("dane.txt");

    setlocale(LC_CTYPE, "Polish");

    while (!strum.eof())
    {
        string s;
        //strum >> s;
        getline(strum, s);
        //cout << s << endl;
        hasla.push_back(s);

    }
    strum.close();

    for (string item : hasla)
        cout << item << endl;

    cout << endl << endl;
    assert(hasla.size() > 0);
    j = rand() % hasla.size(); // losujemy j-te haslo z przedzialu 0 ... size - 1

    haslo = hasla[j];
    n = haslo.size();
}

int Haslo::jestSamogloska(char c){
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'y' ||
        c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U' || c == 'Y')
        return 1;
    else
        return 0;
}

void Haslo::jestSpolgloska() {
    for (i = 0; i < n; i++)
        if ((!jestSamogloska(haslo[i])) && (maska[i]))
        {
            sa_spolgloski = 1;
            break;
        }

    if (sa_spolgloski)
        cout << " -- Spolgloski sa --" << endl;
    else
        cout << " -- Brak spolglosek --" << endl;
}

void Haslo::schowajHaslo() {
    for (i = 0; i < n; i++)
    {
        if (haslo[i] == ' ')
            maska[i] = 0;
        else
            maska[i] = 1;
    }
}

void Haslo::printHaslo() {
    cout << "\033[47m" << "\033[31m";
    for (i = 0; i < n; i++)
    {

        if (maska[i] == 1)
            cout << ".";
        else
            cout << haslo[i];
    }

    cout << "\033[0m";
    cout << endl;
}