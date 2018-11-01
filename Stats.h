#ifndef PROJEKT_STATS_H
#define PROJEKT_STATS_H


class Stats {

private:
    double averageRate;

public:
    Stats();

    virtual ~Stats();

    double getAverageRate() const;

    void countAverageRate();
};


#endif //PROJEKT_STATS_H
