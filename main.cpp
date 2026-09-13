#include <iostream>
#include <algorithm>
#include "Train.h"

using namespace std;

void ExpandContainer(Train *trains, int &max_trains);

int main() {
    int max_trains = 256;
    Train *trains = new Train[max_trains];
    int current_amount_trains = 0;

    while (true) {
        cout << "1. Add new Train" << endl;
        cout << "2. Delete Train" << endl;
        cout << "3. Get Info about Train" << endl;
        cout << "4. Display the numbers of all trains" << endl;
        cout << "5. Exit" << endl;

        int action = -1;
        while (action < 0 || action > 5) {
            cout << "Enter your action: ";
            cin >> action;
        }

        switch (action) {
            case 1: {
                Train train;
                cin >> train;
                trains[current_amount_trains++] = train;
                if (current_amount_trains >= max_trains) {
                    ExpandContainer(trains, max_trains);
                }
                sort(trains, trains + current_amount_trains, [](const Train &a, const Train &b) {
                    return a.getNumberTrain() < b.getNumberTrain();
                });
                cout << "The train has been successfully added." << endl;
                break;
            }
            case 2: {
                cout << "Enter the train number to delete: ";
                int number_train_to_delete;
                cin >> number_train_to_delete;
                bool is_deleted = false;
                for (int i = 0; i < current_amount_trains; i++) {
                    if (is_deleted) {
                        trains[i] = trains[i + 1];
                    }
                    if (trains[i].getNumberTrain() == number_train_to_delete && !is_deleted) {
                        is_deleted = true;
                        if (i < current_amount_trains - 1) {
                            trains[i] = trains[i + 1];
                        }
                        current_amount_trains--;
                    }
                }
                if (is_deleted) {
                    cout << "The train has beed successfully removed." << endl;
                } else {
                    cout << "We couldn't find a train with that number." << endl;
                }

                break;
            }
            case 3: {
                cout << "Enter the train number: ";
                int number_train;
                cin >> number_train;
                bool is_find = false;
                for (int i = 0; i < current_amount_trains; i++) {
                    if (trains[i].getNumberTrain() == number_train) {
                        cout << trains[i];
                        is_find = true;
                        break;
                    }
                }
                if (!is_find) {
                    cout << "We couldn't find a train with that number." << endl;
                }
                break;
            }
            case 4: {
                for (int i = 0; i < current_amount_trains; i++) {
                    cout << trains[i].getNumberTrain() << "\t";
                }
                cout << endl;
                break;
            }
            case 5: {
                delete[] trains;
                return 0;
            }
            default: {
                cout << "Choose one of the available actions (1-5)" << endl;
            }
        }
    }
}

void ExpandContainer(Train *trains, int &max_trains) {
    Train *temp_trains = new Train[max_trains * 2];
    for (int i = 0; i < max_trains; i++) {
        temp_trains[i] = trains[i];
    }
    delete[] trains;
    trains = temp_trains;
    max_trains *= 2;
}
