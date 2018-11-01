#include <iostream>
#include <conio.h>
#include "Series.h"
#include "List.h"
#include "Collection.h"
#include "Movie.h"
#include "Live.h"
#include "Utils.h"

int main() {

    char choice = 'c';
    std::string name;

    Series tmpSer, *serPtr;
    Movie tmpMov, *movPtr;
    Live tmpLiv, *livPtr;

    Series *ser, series;
    Series *ser2, series2;
    Series *ser3, series3;
    Series *ser4, series4;
    Series *ser5, series5;
    Movie *mov, movie;

    ser = &series;
    ser2 = &series2;
    ser3 = &series3;
    ser4 = &series4;
    ser5 = &series5;
    mov = &movie;

    ser->setName("chuj");
    ser->setRating(6.9);

    ser2->setName("chuj2");
    ser2->setRating(1.2);

    ser3->setName("chuj3");
    ser3->setRating(7.0);

    ser4->setName("chuj4");
    ser4->setRating(8.5);

    ser5->setName("chuj5");
    ser5->setRating(4.7);

    mov->setName("pizda");
    mov->setRating(9.0);
    mov->setDuration(120);

    Collection<Video> list;
    list.add(dynamic_cast<Series *>(ser));
    list.add(dynamic_cast<Series *>(ser2));
    list.add(dynamic_cast<Series *>(ser3));
    list.add(dynamic_cast<Series *>(ser4));
    list.add(dynamic_cast<Series *>(ser5));
    list.add(dynamic_cast<Movie *>(mov));

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
                std::cin >> name;
                list.addToCollection(name);
                break;
            case '4':
                system("cls");
                tmpSer = Utils::createNewSeries();
                serPtr = &tmpSer;
                list.add(dynamic_cast<Series *>(serPtr));
                break;
            case '5':
                system("cls");
                tmpMov = Utils::createNewMovie();
                movPtr = &tmpMov;
                list.add(dynamic_cast<Movie *>(movPtr));
                break;
            case '6':
                system("cls");
                tmpLiv = Utils::createNewLive();
                livPtr = &tmpLiv;
                list.add(dynamic_cast<Live *>(livPtr));
                break;
            case '7':
                system("cls");
                list.displayCollection();
                std::cout << "Usun ze sledzonych: Wprowadz nazwe wideo ktore chcesz usunac... ";
                std::cin >> name;
                list.removeFromCollection(name);
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