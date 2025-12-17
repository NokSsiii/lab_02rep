#include <iostream>
#include <iomanip>
#include "student.h"

using namespace std;

int main() {
    int size;
    cout << "Enter the number of students: ";
    cin >> size;

    if (size <= 0) {
        cout << "The number of students must be positive!" << endl;
        return 1;
    }

    Student* students = new Student[size]; //пам'ять

    fillArray(students, size);

    cout << endl << "--- Student Academic Performance Table ---" << endl;
    printTable(students, size);

    double excPercent = calculateExcellentPercentage(students, size);
    cout << endl << "Percentage of 'excellent' students: "
        << fixed << setprecision(2) << excPercent << "%" << endl;

    printStudentsWithPhysicsFive(students, size);

    delete[] students;

    return 0;
}