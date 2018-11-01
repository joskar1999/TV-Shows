#ifndef PROJEKT_UTILS_H
#define PROJEKT_UTILS_H

#include <iostream>
#include <conio.h>
#include "Series.h"
#include "Movie.h"
#include "Live.h"

class Utils {

public:
    static Series createNewSeries();

    static Movie createNewMovie();

    static Live createNewLive();
};


#endif //PROJEKT_UTILS_H
