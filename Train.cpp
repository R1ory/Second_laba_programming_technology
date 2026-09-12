#include "Train.h"

Train::Train() {
    name_destination = "temp";
    number_train = 0;
    hours_departure = 0;
    minutes_departure = 0;
}

Train::Train(const std::string &name_destination, int number_train, int hours_departure, int minutes_departure) {
    this->name_destination = name_destination;
    this->number_train = number_train;
    hours_departure = hours_departure > 23 ? 23 : hours_departure < 0 ? 0 : hours_departure;
    this->hours_departure = hours_departure;
    minutes_departure = minutes_departure > 59 ? 59 : minutes_departure < 0 ? 0 : minutes_departure;
    this->minutes_departure = minutes_departure;
}

Train::Train(const Train &other) {
    name_destination = other.name_destination;
    number_train = other.number_train;
    hours_departure = other.hours_departure;
    minutes_departure = other.minutes_departure;
}

Train::~Train() {
}


Train &Train::operator=(const Train &other) {
    if (this == &other) {
        return *this;
    }
    name_destination = other.name_destination;
    number_train = other.number_train;
    hours_departure = other.hours_departure;
    minutes_departure = other.minutes_departure;
    return *this;
}

std::istream &operator>>(std::istream &is, Train &train) {
    std::cout << "Enter the destination: ";
    is >> train.name_destination;
    std::cout << "Enter the number of train: ";
    is >> train.number_train;
    std::cout << "Enter the hours departure: ";
    is >> train.hours_departure;
    train.hours_departure = train.hours_departure > 23 ? 23 : train.hours_departure < 0 ? 0 : train.hours_departure;
    std::cout << "Enter the minutes departure: ";
    is >> train.minutes_departure;
    train.minutes_departure = train.minutes_departure > 59
                                  ? 59
                                  : train.minutes_departure < 0
                                        ? 0
                                        : train.minutes_departure;

    return is;
}

std::ostream &operator<<(std::ostream &os, const Train &train) {
    os << "Destination: " << train.name_destination << std::endl;
    os << "Number Train: " << train.number_train << std::endl;
    os << "Time Departure: " << train.hours_departure << ":" << train.minutes_departure << std::endl;

    return os;
}
