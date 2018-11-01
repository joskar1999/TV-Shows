#include <iostream>
#include "Movie.h"

Movie::Movie() {}

Movie::~Movie() {}

int Movie::getDuration() const {
    return duration;
}

void Movie::setDuration(int duration) {
    Movie::duration = duration;
}

void Movie::display() {
    std::cout << "Name: " << getName() << std::endl;
    std::cout << "Rating: " << getRating() << std::endl;
    std::cout << "Duration: " << getDuration() << std::endl;
    std::cout << std::endl;
}

int Movie::getWeeklyDuration() {
    return duration;
}

