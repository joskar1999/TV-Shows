#ifndef PROJEKT_STATS_H
#define PROJEKT_STATS_H


#include <vector>
#include "Video.h"

class Stats {

private:
    double averageRateSeries;

    double averageRateMovie;

public:
    Stats();

    virtual ~Stats();

    void countAverageRate(std::vector<Video *> video);

    double getAverageRateSeries() const;

    double getAverageRateMovie() const;
};


#endif //PROJEKT_STATS_H
