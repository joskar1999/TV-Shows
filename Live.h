#ifndef PROJEKT_LIVE_H
#define PROJEKT_LIVE_H

#include "Video.h"

class Live : public Video {
private:
    std::string start;
    int duration;

public:
    Live();

    virtual ~Live();

    const std::string &getStart() const;

    void setStart(const std::string &start);

    int getDuration() const;

    void setDuration(int duration);

    void display() override;

    virtual int getWeeklyDuration();

    virtual std::string prepareFileText();
};


#endif //PROJEKT_LIVE_H
