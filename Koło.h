#pragma once
using namespace std;
#include <stdlib.h> 
#include <time.h> 

class Kolo {
public:
    int* pola;

    Kolo();
    ~Kolo();
    int wylosujWygrana();
};