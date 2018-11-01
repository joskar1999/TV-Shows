#ifndef PROJEKT_IMDB_H
#define PROJEKT_IMDB_H


#include "Video.h"

class IMDB : public Video {
private:
    double rating;
public:
    IMDB();

    virtual ~IMDB();

    double getRating() const;

    void setRating(double rating);
};


#endif //PROJEKT_IMDB_H
