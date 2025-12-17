#include <iostream>
#include "trains.h"

using namespace std;

int main() {

    string filename = getFileName();
    int choice;

    do {
        printMenu();
        choice = getMenuChoice();

        switch (choice) {
        case 1:
            createFile(filename);
            break;
        case 2: {
            Train t = inputTrainData();
            appendToFile(filename, t);
            break;
        }
        case 3:
            viewFile(filename);
            break;
        case 4: {
            string time = inputTime();
            // Функція повертає значення, Main відповідає за вивід (SRP)
            vector<Train> found = findTrainsAfterTime(filename, time);
            printTrainList(found);
            break;
        }
        case 0:
            cout << "Procces has fiin" << endl;
            break;
        default:
            cout << "Unknow command" << endl;
        }
    } while (choice != 0);

    return 0;
}