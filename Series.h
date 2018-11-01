#ifndef PROJEKT_SERIES_H
#define PROJEKT_SERIES_H


#include "IMDB.h"
#include <vector>
#include <string>

class Series : public IMDB {
private:
    int episodesAmount;
    std::vector<std::string> episodes;
    std::vector<int> episodesDuration;
public:
    Series();

    virtual ~Series();

    int getEpisodesAmount() const;

    void setEpisodesAmount(int episodesAmount);

    const std::vector<std::string> &getEpisodes() const;

    void setEpisodes(const std::vector<std::string> &episodes);

    const std::vector<int> &getEpisodesDuration() const;

    void setEpisodesDuration(const std::vector<int> &episodesDuration);

    void display() override;

    virtual int getWeeklyDuration();
};


#endif //PROJEKT_SERIES_H
