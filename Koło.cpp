using namespace std;
#include "Ko³o.h"

Kolo::Kolo() {
    pola = new int[16] { -1, 0, 100, 200, 100, 200, 100, 200, 500, 500, 1000, 1000, 1500, 2000, 3000, 5000 };
}

Kolo::~Kolo() {
    delete[] pola;
}

int Kolo::wylosujWygrana() {
    srand(time(NULL));
    int i = rand() % 16;
    return pola[i];
}