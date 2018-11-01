#ifndef PROJEKT_UTILS_H
#define PROJEKT_UTILS_H

#include <iostream>
#include <conio.h>
#include "Series.h"
#include "Movie.h"
#include "Live.h"

/**
 * Funkcje służące do wczytywania obiektu
 * z klawiatury, metody zwracają utworzony obiekt
 * danego typu
 */
class Utils {

public:
    static Series createNewSeries();

    static Movie createNewMovie();

    static Live createNewLive();
};


#endif //PROJEKT_UTILS_H
