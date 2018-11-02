#include "Stats.h"
#include "Series.h"
#include "Movie.h"

Stats::Stats() {
    this->averageRateSeries = 0;
    this->averageRateMovie = 0;
}

Stats::~Stats() {

}

double Stats::getAverageRateSeries() const {
    return averageRateSeries;
}

double Stats::getAverageRateMovie() const {
    return averageRateMovie;
}

void Stats::countAverageRate(std::vector<Video *> video) {
    int ser = 0;
    int mov = 0;
    double serSum = 0, serAvg;
    double movSum = 0, movAvg;
    for (int i = 0; i < video.size(); ++i) {
        if (dynamic_cast<Series *>(video[i])) {
            ser++;
            serSum += dynamic_cast<Series *>(video[i])->getRating();
        } else if (dynamic_cast<Movie *>(video[i])) {
            mov++;
            movSum += dynamic_cast<Movie *>(video[i])->getRating();
        }
    }
    serAvg = serSum / double(ser);
    movAvg = movSum / double(mov);
    this->averageRateSeries = serAvg;
    this->averageRateMovie = movAvg;
}

