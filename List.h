#ifndef PROJEKT_LIST_H
#define PROJEKT_LIST_H

#include <vector>
#include <fstream>

template<class T>
class List {

private:
    std::vector<T *> list;
    std::fstream file;

public:
    List() {
//        file.open("list.txt", std::fstream::in | std::fstream::out);
    }

    virtual ~List() {
//        file.close();
    }

    const std::vector<T *> &getList() const {
        return list;
    }

    /**
     * Pobranie obiektu o określonej nazwie
     * @param name - nazwa obiektu do pobrania
     * @return - metoda zwraca wskaźnik na poszukiwany obiekt
     */
    T *getElement(std::string name) {
        for (int i = 0; i < list.size(); ++i) {
            if (list[i]->getName() == name) {
                return list[i];
            }
        }
        return nullptr;
    }

    /**
     * Wyświetlenie wszystkich zapisanych Video
     */
    void displayList() {
        for (int i = 0; i < list.size(); ++i) {
            list[i]->display();
        }
    }

    /**
     * Dodanie pojedynczego elementu do listy
     * @param element - wskaźnik na dodawany obiekt
     */
    void add(T *element) {
        list.push_back(element);
    }

    /**
     * Ususwnaie określonego obiektu z listy
     * @param name - nazwa obiektu do usunięcia
     */
    void remove(std::string name) {
        for (int i = 0; i < list.size(); ++i) {
            if (list[i]->getName() == name) {
                list.erase(list.begin() + i);
            }
        }
    }

    /**
     * Sprawdzenie czy obiekt o podanej nazwie istnieje w liście
     * @param name - nazwa szukanego obiektu
     * @return - true jeśli obiekt isnieje na liście
     */
    bool isElementInList(std::string name) {
        for (int i = 0; i < list.size(); ++i) {
            if (list[i]->getName() == name) {
                return true;
            }
        }
        return false;
    }

    int getIndex(std::string name) {
        for (int i = 0; i < list.size(); ++i) {
            if (list[i]->getName() == name) {
                return i;
            }
        }
    }

    void modify(T *object, std::string name) {
        for (int i = 0; i < list.size(); ++i) {
            if (list[i]->getName() == name) {
                list[i] = object;
            }
        }
    }

    void writeToFile() {
        file.open("./list.txt", std::ios::in | std::ios::out | std::ios::trunc);
        for (int i = 0; i < list.size(); ++i) {
            file << list[i]->prepareFileText();
            std::cout << list[i]->prepareFileText();
        }
        file.close();
    }
};


#endif //PROJEKT_LIST_H
