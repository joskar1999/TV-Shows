#ifndef PROJEKT_COLLECTION_H
#define PROJEKT_COLLECTION_H


#include "List.h"
#include "Movie.h"
#include "Utils.h"
#include <vector>
#include <fstream>

template<class T>
class Collection : public List<T> {

private:
    std::vector<T *> collection;
    std::fstream file;


public:
    Collection() {
        List::List();
        setCollection(Utils::readFromFile("collection.txt"));
    }

    virtual ~Collection() {}

    const std::vector<T> &getCollection() const {
        return collection;
    }

    void setCollection(const std::vector<T *> &collection) {
        Collection::collection = collection;
    }

    /**
     * Dodanie obiektu do puli śledzonych
     * element powinien istnieć w ogolnej liście
     * @param name - nazwa obiektu, który chcemy dodać
     */
    void addToCollection(std::string name) {
        collection.push_back(getElement(name));
    }

    /**
     * Usuwanie obiektu o podanej nazwie z puli śledzonych
     * @param name - obiekt do usunięcia
     */
    void removeFromCollection(std::string name) {
        for (int i = 0; i < collection.size(); ++i) {
            if (collection[i]->getName() == name) {
                collection.erase(collection.begin() + i);
            }
        }
    }

    /**
     * Wyświetlenie całej puli śledzonych
     */
    void displayCollection() {
        for (int i = 0; i < collection.size(); ++i) {
            collection[i]->display();
        }
    }

    int countWeeklyDuration() {
        int duration = 0;
        for (int i = 0; i < collection.size(); ++i) {
            duration += collection[i]->getWeeklyDuration();
        }
        return duration;
    }

    /**
     * Metoda wyświetla obiekty klasy Series i Movie,
     * które mają rating wyższy niż 7.5
     */
    void recomendation() {
        for (int i = 0; i < collection.size(); ++i) {
            if (dynamic_cast<Series *>(collection[i])) {
                if (dynamic_cast<Series *>(collection[i])->getRating() > 7.5) {
                    collection[i]->display();
                }
            } else if (dynamic_cast<Movie *>(collection[i])) {
                if (dynamic_cast<Movie *>(collection[i])->getRating() > 7.5) {
                    collection[i]->display();
                }
            }
        }
    }

    bool isInCollection(std::string name) {
        for (int i = 0; i < collection.size(); ++i) {
            if (collection[i]->getName() == name) {
                return true;
            }
        }
        return false;
    }

    void modify(T *object, std::string name) {
        for (int i = 0; i < collection.size(); ++i) {
            if (collection[i]->getName() == name) {
                collection[i] = object;
            }
        }
    }

    void writeToFile() {
        List::writeToFile();
        file.open("./collection.txt", std::ios::in | std::ios::out | std::ios::trunc);
        for (int i = 0; i < collection.size(); ++i) {
            file << collection[i]->prepareFileText();
            std::cout << collection[i]->prepareFileText();
        }
        file.close();
    }

    void operator+=(std::string name) {
        addToCollection(name);
    }

    void operator-=(std::string name) {
        removeFromCollection(name);
    }
};


#endif //PROJEKT_COLLECTION_H
