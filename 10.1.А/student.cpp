#include "student.h"
#include <iostream>
#include <iomanip>

using namespace std;

string getSpecialtyStr(Specialty s) {
    switch (s) {
    case KN: return "Comp. Science";
    case SE: return "Software Eng.";
    case IA: return "Info. Analyt.";
    case TN: return "Telecom.";
    default: return "Unknown";
    }
}


void fillArray(Student* students, int size) {
    int specChoice;
    for (int i = 0; i < size; i++) {
        cout << "\nStudent #" << i + 1 << ":" << endl;

        cout << "Surname: ";
        cin >> students[i].surname;

        cout << "Year (Course): ";
        cin >> students[i].course;

        cout << "Specialty (0-CS, 1-SE, 2-IA, 3-TN): ";
        cin >> specChoice;

        //int в enum
        if (specChoice >= 0 && specChoice <= 3) {
            students[i].specialty = static_cast<Specialty>(specChoice);
        }
        else {
            students[i].specialty = UNKNOWN;
        }

        cout << "Grade in Physics: ";
        cin >> students[i].gradePhysics;

        cout << "Grade in Math: ";
        cin >> students[i].gradeMath;

        cout << "Grade in CS (Informatics): ";
        cin >> students[i].gradeInformatics;
    }
}


void printTable(const Student* students, int size) {
    cout << string(85, '-') << endl;
    cout << left << setw(4) << "No."
        << setw(15) << "Surname"
        << setw(6) << "Year"
        << setw(16) << "Specialty"
        << setw(10) << "Physics"
        << setw(10) << "Math"
        << setw(10) << "Comp.Sci" << endl;
    cout << string(85, '-') << endl;

    for (int i = 0; i < size; i++) {
        cout << left << setw(4) << i + 1
            << setw(15) << students[i].surname
            << setw(6) << students[i].course
            << setw(16) << getSpecialtyStr(students[i].specialty)
            << setw(10) << students[i].gradePhysics
            << setw(10) << students[i].gradeMath
            << setw(10) << students[i].gradeInformatics << endl;
    }
    cout << string(85, '-') << endl;
}

//обчислення відсотка
double calculateExcellentPercentage(const Student* students, int size) {
    if (size == 0) return 0.0;

    int countExcellent = 0;
    for (int i = 0; i < size; i++) {
        if (students[i].gradePhysics == 5 &&
            students[i].gradeMath == 5 &&
            students[i].gradeInformatics == 5) {
            countExcellent++;
        }
    }
    return (static_cast<double>(countExcellent) / size) * 100.0;
}

//пошуку студентів
void printStudentsWithPhysicsFive(const Student* students, int size) {
    cout << "\nStudents with grade '5' in Physics:" << endl;
    bool found = false;
    for (int i = 0; i < size; i++) {
        if (students[i].gradePhysics == 5) {
            cout << "- " << students[i].surname << endl;
            found = true;
        }
    }
    if (!found) {
        cout << "No such students found." << endl;
    }
}