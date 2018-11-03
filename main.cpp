#include <iostream>
#include <conio.h>
#include "Series.h"
#include "List.h"
#include "Collection.h"
#include "Movie.h"
#include "Live.h"
#include "Utils.h"
#include "Stats.h"
#include <string>

int main() {

    char choice = 'c';
    std::string name;

    Series tmpSer, *serPtr;
    Movie tmpMov, *movPtr;
    Live tmpLiv, *livPtr;

    Stats stats;
    std::vector<Series *> sorted;
    Collection<Video> list;

    while (choice != 'q') {

        system("cls");
        std::cout << "Witaj w aplikacji TV-Shows" << std::endl;
        std::cout << "1: Wyswietl liste wszystkich Video" << std::endl;
        std::cout << "2: Wyswietl liste sledzonych" << std::endl;
        std::cout << "3: Dodaj do sledzonych" << std::endl;
        std::cout << "4: Dodaj nowy serial" << std::endl;
        std::cout << "5: Dodaj nowy film" << std::endl;
        std::cout << "6: Dodaj nowy live" << std::endl;
        std::cout << "7: Usun ze sledzonych" << std::endl;
        std::cout << "8: Rekomendacje" << std::endl;
        std::cout << "9: Edytuj Wideo" << std::endl;
        std::cout << "a: Wyswietl statystyki" << std::endl;
        std::cout << "b: Sortuj" << std::endl;
        std::cout << "q: Zakoncz" << std::endl;
        choice = getch();

        switch (choice) {
            case '1':
                system("cls");
                list.displayList();
                std::cout << "Nacisnij dowolny klawisz aby kontynuowac... ";
                getch();
                break;
            case '2':
                system("cls");
                list.displayCollection();
                std::cout << "Sledzone: Nacisnij dowolny klawisz aby kontynuowac... ";
                getch();
                break;
            case '3': //todo jak już takie wideo istnieje w bazie to rzucić wyjątek
                system("cls");
                list.displayList();
                std::cout << "Dodaj do sledzonych: Wprowadz nazwe wideo ktore chcesz dodac... ";
//                std::getline(std::cin, name);
                std::cin >> name;
                list.addToCollection(name);
                list.writeToFile();
                break;
            case '4':
                system("cls");
                Series *tmpSeries;
                tmpSeries = new Series();

                tmpSer = Utils::createNewSeries();
                tmpSeries->setName(tmpSer.getName());
                tmpSeries->setRating(tmpSer.getRating());
                tmpSeries->setEpisodesAmount(tmpSer.getEpisodesAmount());
                tmpSeries->setEpisodes(tmpSer.getEpisodes());

                list.add(dynamic_cast<Series *>(tmpSeries));
                list.writeToFile();
                break;
            case '5':
                system("cls");
                Movie *tmpMovie;
                tmpMovie = new Movie();

                tmpMov = Utils::createNewMovie();
                tmpMovie->setName(tmpMov.getName());
                tmpMovie->setRating(tmpMov.getRating());
                tmpMovie->setDuration(tmpMov.getDuration());

                list.add(dynamic_cast<Movie *>(tmpMovie));
                list.writeToFile();
                break;
            case '6':
                system("cls");
                Live *tmpLive;
                tmpLive = new Live();

                tmpLiv = Utils::createNewLive();
                tmpLive->setName(tmpLiv.getName());
                tmpLive->setStart(tmpLiv.getStart());
                tmpLive->setDuration(tmpLiv.getDuration());

                list.add(dynamic_cast<Live *>(tmpLive));
                list.writeToFile();
                break;
            case '7':
                system("cls");
                list.displayCollection();
                std::cout << "Usun ze sledzonych: Wprowadz nazwe wideo ktore chcesz usunac... ";
//                std::getline(std::cin, name);
                std::cin >> name;
                list.removeFromCollection(name);
                list.writeToFile();
                break;
            case '8':
                system("cls");
                std::cout << "Filmy i seriale z najwyzszymi ocenami" << std::endl;
                list.recomendation();
                std::cout << "Nacisnij dowolny klawisz aby kontynuowac... ";
                getch();
                break;
            case '9':
                system("cls");
                list.displayList();
                std::cout << "Podaj nazwe wideo, ktore chcesz edytowac: ";
//                std::getline(std::cin, name);
                std::cin >> name;
                if (dynamic_cast<Series *>(list.getElement(name))) {
                    Series *tmpSeries;
                    tmpSeries = new Series();
                    tmpSer = Utils::editSeries(name);
                    tmpSeries->setName(tmpSer.getName());
                    tmpSeries->setRating(tmpSer.getRating());
                    tmpSeries->setEpisodesAmount(tmpSer.getEpisodesAmount());
                    tmpSeries->setEpisodes(tmpSer.getEpisodes());
                    list.List::modify(tmpSeries, name);
                    if (list.isInCollection(name)) {
                        list.modify(tmpSeries, name);
                    }
                } else if (dynamic_cast<Movie *>(list.getElement(name))) {
                    Movie *tmpMovie;
                    tmpMovie = new Movie();
                    tmpMov = Utils::editMovie(name);
                    tmpMovie->setName(tmpMov.getName());
                    tmpMovie->setRating(tmpMov.getRating());
                    tmpMovie->setDuration(tmpMov.getDuration());
                    list.List::modify(tmpMovie, name);
                    if (list.isInCollection(name)) {
                        list.modify(tmpMovie, name);
                    }
                } else if (dynamic_cast<Live *>(list.getElement(name))) {
                    Live *tmpLive;
                    tmpLive = new Live();
                    tmpLiv = Utils::createNewLive();
                    tmpLive->setName(tmpLiv.getName());
                    tmpLive->setStart(tmpLiv.getStart());
                    tmpLive->setDuration(tmpLiv.getDuration());
                    list.List::modify(tmpLive, name);
                    if (list.isInCollection(name)) {
                        list.modify(tmpLive, name);
                    }
                }
                list.writeToFile();
                getch();
            case 'a':
                system("cls");
                stats.countAverageRate(list.getList());
                std::cout << "Srednia ocena seriali: " << stats.getAverageRateSeries() << std::endl;
                std::cout << "Srednia ocena filmow: " << stats.getAverageRateMovie() << std::endl;
                std::cout << "Statystyki. Nacisnij dowolny klawisz aby kontynuowac... ";
                getch();
                break;
            case 'b':
                system("cls");
                std::cout << "Seriale z najwyzszymi ocenami" << std::endl;
                sorted = Utils::sort(list.getList());
                for (int i = 0; i < sorted.size(); ++i) {
                    dynamic_cast<Series *>(sorted[i])->display();
                }
                std::cout << "Posortowane. Nacisnij dowolny klawisz aby kontynuowac... ";
                getch();
                break;
            case 'q':
                break;
            default:
                system("cls");
                std::cout << "Opcja def: Nacisnij dowolny klawisz aby kontynuowac... ";
                getch();
                break;
        }
    }

    return 0;
}