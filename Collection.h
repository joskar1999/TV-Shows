#ifndef PROJEKT_COLLECTION_H
#define PROJEKT_COLLECTION_H


#include "List.h"
#include <vector>

template<class T>
class Collection : public List<T> {

private:
    std::vector<T *> collection;

public:
    Collection() {}

    virtual ~Collection() {}

    const std::vector<T> &getCollection() const {
        return collection;
    }

    void addToCollection(std::string name) {
        collection.push_back(getElement(name));
    }

    void removeFromCollection(std::string name) {
        for (int i = 0; i < collection.size(); ++i) {
            if (collection[i]->getName() == name) {
                collection.erase(collection.begin() + i);
            }
        }
    }

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
};


#endif //PROJEKT_COLLECTION_H
