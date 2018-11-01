#ifndef PROJEKT_LIST_H
#define PROJEKT_LIST_H

#include <vector>

template<class T>
class List {

private:
    std::vector<T *> list;

public:
    List() {}

    virtual ~List() {}

    const std::vector<T *> &getList() const {
        return list;
    }

    T *getElement(std::string name) {
        for (int i = 0; i < list.size(); ++i) {
            if (list[i]->getName() == name) {
                return list[i];
            }
        }
    }

    void displayList() {
        for (int i = 0; i < list.size(); ++i) {
            list[i]->display();
        }
    }

    void add(T *element) {
        list.push_back(element);
    }

    void remove(std::string name) {
        for (int i = 0; i < list.size(); ++i) {
            if (list[i]->getName() == name) {
                list.erase(list.begin() + i);
            }
        }
    }

    bool isElementInList(std::string name) {
        for (int i = 0; i < list.size(); ++i) {
            if (list[i]->getName() == name) {
                return true;
            }
        }
        return false;
    }
};


#endif //PROJEKT_LIST_H
