#ifndef PROJEKT_MOVIE_H
#define PROJEKT_MOVIE_H


#include "IMDB.h"

class Movie : public IMDB {
private:
    int duration;
public:
    Movie();

    virtual ~Movie();

    int getDuration() const;

    void setDuration(int duration);

    void display() override;
};


#endif //PROJEKT_MOVIE_H
