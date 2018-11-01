#include "IMDB.h"

IMDB::IMDB() {}

IMDB::~IMDB() {

}

double IMDB::getRating() const {
    return rating;
}

void IMDB::setRating(double rating) {
    IMDB::rating = rating;
}
