#include <fstream>
#include "Utils.h"

Series Utils::createNewSeries() {
    Series series;
    std::string tmp;
    double rating;
    int eps;
    std::vector<std::string> episodes;

    std::cout << "Podaj nazwe serialu: ";
//    std::getline(std::cin, tmp);
    std::cin >> tmp;
    series.setName(tmp);

    std::cout << "Podaj rating: ";
    std::cin >> rating;
    series.setRating(rating);

    std::cout << "Podaj ilosc odcinkow: ";
    std::cin >> eps;
    series.setEpisodesAmount(eps);

//    std::getline(std::cin, tmp);
    for (int i = 1; i <= eps; ++i) {
        std::cout << "Podaj nazwe odcinka " << i << ": ";
//        std::getline(std::cin, tmp);
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

//    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Podaj nazwe filmu: ";
//    std::getline(std::cin, tmp);
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
//    std::getline(std::cin, tmp);
    std::cin >> tmp;
    live.setName(tmp);

    std::cout << "Podaj start live: ";
//    std::getline(std::cin, tmp);
    std::cin >> tmp;
    live.setStart(tmp);

    std::cout << "Podaj czas trwania: ";
    std::cin >> duration;
    live.setDuration(duration);

    std::cout << "Dziekuje. Live dodany. Nacisnij dowolny klawisz aby kontynuowac...";
    getch();

    return live;
}

Series Utils::editSeries(std::string name) {
    Series series;
    std::string tmp;
    double rating;
    int eps;
    std::vector<std::string> episodes;

    std::cout << "Edytujesz serial, wprowadz nowe dane lub sktualne jesli nie chcesz zmieniac " << name << std::endl;
    std::cout << "Podaj nazwe: ";
//    std::getline(std::cin, tmp);
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
//        std::getline(std::cin, tmp);
        std::cin >> tmp;
        episodes.push_back(tmp);
    }
    series.setEpisodes(episodes);

    std::cout << "Dziekuje. Serial zedytowany. Nacisnij dowolny klawisz aby kontynuowac...";
    getch();
    return series;
}

Movie Utils::editMovie(std::string name) {
    Movie movie;
    std::string tmp;
    double rating;
    int duration;

//    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Edytujesz film, wprowadz nowe dane lub sktualne jesli nie chcesz zmieniac " << name << std::endl;
    std::cout << "Podaj nazwe filmu: ";
//    std::getline(std::cin, tmp);
    std::cin >> tmp;
    movie.setName(tmp);

    std::cout << "Podaj rating: ";
    std::cin >> rating;
    movie.setRating(rating);

    std::cout << "Podaj czas trwania: ";
    std::cin >> duration;
    movie.setDuration(duration);

    std::cout << "Dziekuje. Film zedytowany. Nacisnij dowolny klawisz aby kontynuowac...";
    getch();

    return movie;
}

Live Utils::editLive(std::string name) {
    Live live;
    std::string tmp;
    double duration;

    std::cout << "Edytujesz live, wprowadz nowe dane lub sktualne jesli nie chcesz zmieniac " << name << std::endl;
    std::cout << "Podaj nazwe live: ";
//    std::getline(std::cin, tmp);
    std::cin >> tmp;
    live.setName(tmp);

    std::cout << "Podaj start live: ";
//    std::getline(std::cin, tmp);
    std::cin >> tmp;
    live.setStart(tmp);

    std::cout << "Podaj czas trwania: ";
    std::cin >> duration;
    live.setDuration(duration);

    std::cout << "Dziekuje. Live zedytowany. Nacisnij dowolny klawisz aby kontynuowac...";
    getch();

    return live;
}

std::vector<Series *> Utils::sort(std::vector<Video *> video) {
    std::vector<Series *> filteredSeries;

    for (int i = 0; i < video.size(); ++i) {
        if (dynamic_cast<Series *>(video[i])) {
            filteredSeries.push_back(dynamic_cast<Series *>(video[i]));
        }
    }
    for (int i = 0; i < filteredSeries.size(); ++i) {
        for (int j = 0; j < filteredSeries.size() - 1; ++j) {
            double tmp1 = dynamic_cast<Series *>(filteredSeries[j])->getRating();
            double tmp2 = dynamic_cast<Series *>(filteredSeries[j + 1])->getRating();
            if (tmp1 < tmp2) {
                std::iter_swap(filteredSeries[j], filteredSeries[j + 1]);
            }
        }
    }
    return filteredSeries;
}

std::vector<Video *> Utils::readFromFile(std::string fileName) {

    std::string tmp, text;
    int ln;

    std::vector<std::string> eps;
    std::vector<Video *> video;

    Series *series;
    Movie *movie;
    Live *live;

    std::fstream file;
    file.open(fileName, std::fstream::in);

    while (!file.eof()) {
        file >> tmp;
        switch (tmp[0]) {
            case 's':
                series = new Series();
                eps.clear();
                text = "";
                file >> tmp;
                series->setName(tmp);
                file >> tmp;
                series->setRating(std::stod(tmp));
                file >> tmp;
                series->setEpisodesAmount(std::stoi(tmp));
                ln = std::stoi(tmp);
                for (int i = 0; i < ln; ++i) {
                    file >> tmp;
                    eps.push_back(tmp);
                }
                series->setEpisodes(eps);
                video.push_back(series);
                break;
            case 'm':
                movie = new Movie();
                text = "";
                file >> tmp;
                movie->setName(tmp);
                file >> tmp;
                movie->setRating(std::stod(tmp));
                file >> tmp;
                movie->setDuration(std::stoi(tmp));
                video.push_back(movie);
                break;
            case 'l':
                live = new Live();
                text = "";
                file >> tmp;
                live->setName(tmp);
                file >> tmp;
                live->setStart(tmp);
                file >> tmp;
                live->setDuration(std::stoi(tmp));
                video.push_back(live);
                break;
        }
    }
    file.close();

    return video;
}
