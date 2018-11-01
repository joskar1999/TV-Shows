#include <iostream>
#include "Series.h"

Series::Series() {}

Series::~Series() {}

int Series::getEpisodesAmount() const {
    return episodesAmount;
}

void Series::setEpisodesAmount(int episodesAmount) {
    Series::episodesAmount = episodesAmount;
}

const std::vector<std::string> &Series::getEpisodes() const {
    return episodes;
}

void Series::setEpisodes(const std::vector<std::string> &episodes) {
    Series::episodes = episodes;
}

const std::vector<std::string> &Series::getEpisodesDuration() const {
    return episodesDuration;
}

void Series::setEpisodesDuration(const std::vector<std::string> &episodesDuration) {
    Series::episodesDuration = episodesDuration;
}

void Series::display() {
    std::cout << "Name: " << getName() << std::endl;
    std::cout << "Rating: " << getRating() << std::endl;
    std::cout << "Amount of episodes: " << getEpisodes().size() << std::endl;
    std::cout << std::endl;
}

