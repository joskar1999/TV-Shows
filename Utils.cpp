#include "Utils.h"

Series Utils::createNewSeries() {
    Series series;
    std::string tmp;
    double rating;
    int eps;
    std::vector<std::string> episodes;

    std::cout << "Podaj nazwe serialu: ";
    std::cin >> tmp;
    series.setName(tmp);

    std::cout << "Podaj rating: ";
    std::cin >> rating;
    series.setRating(rating);

    std::cout << "Podaj ilosc odcinkow: ";
    std::cin >> eps;
    series.setEpisodesAmount(eps);

    for (int i = 1; i <= eps; ++i) {
        std::cout << "Podaj nazwe odcinka " << i << ": ";
        std::cin >> tmp;
        episodes.push_back(tmp);
    }

    series.setEpisodes(episodes);
    std::cout << "Dziekuje. Serial dodany. Nacisnij dowolny klawisz aby kontynuowac...";
    getch();

    return series;
}

Movie Utils::createNewMovie() {
    Movie movie;
    std::string tmp;
    double rating;
    int duration;

    std::cout << "Podaj nazwe filmu: ";
    std::cin >> tmp;
    movie.setName(tmp);

    std::cout << "Podaj rating: ";
    std::cin >> rating;
    movie.setRating(rating);

    std::cout << "Podaj czas trwania: ";
    std::cin >> duration;
    movie.setDuration(duration);

    std::cout << "Dziekuje. Film dodany. Nacisnij dowolny klawisz aby kontynuowac...";
    getch();

    return movie;
}

Live Utils::createNewLive() {
    Live live;
    std::string tmp;
    double duration;

    std::cout << "Podaj nazwe live: ";
    std::cin >> tmp;
    live.setName(tmp);

    std::cout << "Podaj start live: ";
    std::cin >> tmp;
    live.setStart(tmp);

    std::cout << "Podaj czas trwania: ";
    std::cin >> duration;
    live.setDuration(duration);

    std::cout << "Dziekuje. Live dodany. Nacisnij dowolny klawisz aby kontynuowac...";
    getch();

    return live;
}
