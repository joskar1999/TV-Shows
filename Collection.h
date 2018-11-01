#ifndef PROJEKT_COLLECTION_H
#define PROJEKT_COLLECTION_H


#include "List.h"
#include <vector>

template<class T>
class Collection : public List<T> {

private:
    std::vector<T> collection;

public:
    Collection() {}

    virtual ~Collection() {}

    const std::vector<T> &getCollection() const {
        return collection;
    }

    void addToCollection(T element){

    }


};


#endif //PROJEKT_COLLECTION_H
