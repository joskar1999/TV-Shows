#ifndef PROJEKT_SERIES_H
#define PROJEKT_SERIES_H


#include "IMDB.h"
#include <vector>
#include <string>

class Series : public IMDB {
private:
    int episodesAmount;
    std::vector<std::string> episodes;
    std::vector<std::string> episodesDuration;
public:
    Series();

    virtual ~Series();

    int getEpisodesAmount() const;

    void setEpisodesAmount(int episodesAmount);

    const std::vector<std::string> &getEpisodes() const;

    void setEpisodes(const std::vector<std::string> &episodes);

    const std::vector<std::string> &getEpisodesDuration() const;

    void setEpisodesDuration(const std::vector<std::string> &episodesDuration);

    void display() override;
};


#endif //PROJEKT_SERIES_H
