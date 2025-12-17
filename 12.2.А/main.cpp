#include <iostream>
#include <string>
#include "student.h"

using namespace std;

int main() {
    string filename;
    cout << "Enter file name: ";
    cin >> filename;

    int choice;
    do {
        cout << "\n--- MENU ---\n";
        cout << "1. Write in file\n";
        cout << "2. Enter surname\n";
        cout << "3. % vidminnukiv\n";
        cout << "4. Physics 5\n";
        cout << "0. Exit\n";
        cout << "Your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            createOrAppendFile(filename);
            break;
        case 2:
            printFileContent(filename);
            break;
        case 3: {
            double percent = calculateExcellentPercentage(filename);
            cout << "% vidminnukiv: " << percent << "%" << endl;
            break;
        }
        case 4:
            printStudentsWithPhysicsFive(filename);
            break;
        case 0:
            cout << "End off proccesing" << endl;
            break;
        default:
            cout << "Wrong choice" << endl;
        }

    } while (choice != 0);

    return 0;
}