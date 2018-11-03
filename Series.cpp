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

const std::vector<int> &Series::getEpisodesDuration() const {
    return episodesDuration;
}

void Series::setEpisodesDuration(const std::vector<int> &episodesDuration) {
    Series::episodesDuration = episodesDuration;
}

void Series::display() {
    std::cout << "Name: " << getName() << std::endl;
    std::cout << "Rating: " << getRating() << std::endl;
    std::cout << "Amount of episodes: " << getEpisodes().size() << std::endl;
    std::cout << std::endl;
}

int Series::getWeeklyDuration() {
    int duration = 0;
    for (int i = 0; i < episodesDuration.size(); ++i) {
        duration += episodesDuration[i];
    }
    return duration;
}

std::string Series::prepareFileText() {
    std::string text = "s\n";
    text = text + getName() + "\n";
    text = text + std::to_string(getRating()) + "\n";
    text = text + std::to_string(getEpisodesAmount()) + "\n";
    for (int i = 0; i < episodesAmount; ++i) {
        text = text + episodes[i] + "\n";
    }
    return text;
}
