#ifndef PROJEKT_VIDEO_H
#define PROJEKT_VIDEO_H

#include <string>

class Video {

private:
    std::string name;

public:
    Video();

    virtual ~Video();

    const std::string &getName() const;

    void setName(const std::string &name);

    /**
     * Wyświetlanie informacji o danym obiekcie,
     * metoda do nadpisania w klasach pochodnych
     */
    virtual void display() = 0;

    virtual int getWeeklyDuration() = 0;
};


#endif //PROJEKT_VIDEO_H
