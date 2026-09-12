#pragma once
#include <string>
#include <iostream>

class Train {
private:
    std::string name_destination;
    int number_train;
    int hours_departure;
    int minutes_departure;

public:
    Train();

    Train(const std::string &name_destination, int number_train, int hours_departure, int minutes_departure);

    Train(const Train &other);

    ~Train();

    Train &operator=(const Train &other);


    friend std::istream &operator>>(std::istream &is, Train &train);

    friend std::ostream &operator<<(std::ostream &os, const Train &train);
};
