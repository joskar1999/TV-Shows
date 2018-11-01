#include <iostream>
#include "Live.h"

Live::Live() {}

Live::~Live() {}

const std::string &Live::getStart() const {
    return start;
}

void Live::setStart(const std::string &start) {
    Live::start = start;
}

int Live::getDuration() const {
    return duration;
}

void Live::setDuration(int duration) {
    Live::duration = duration;
}

void Live::display() {
    std::cout << "Name: " << getName() << std::endl;
    std::cout << "Start: " << getStart() << std::endl;
    std::cout << std::endl;
}
