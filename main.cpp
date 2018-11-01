#include <iostream>
#include "Series.h"
#include "List.h"
#include "Collection.h"
#include "Movie.h"
#include "Live.h"

int main() {

    Series *ser, series;
    Movie *mov, movie;

    ser = &series;
    mov = &movie;

    ser->setName("chuj");
    ser->setRating(6.9);
    mov->setName("pizda");
    mov->setRating(9.0);
    mov->setDuration(120);

    List<Video> list;
    list.add(dynamic_cast<Series *>(ser));
    list.add(dynamic_cast<Movie *>(mov));
//    list.displayList();
//
//    Series *tmp = dynamic_cast<Series*>(list.getElement("chuj"));
//    std::cout << tmp->getRating();
    return 0;
}