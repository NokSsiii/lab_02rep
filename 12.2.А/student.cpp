#include "student.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>

using namespace std;


string specialtyToString(Specialty s) {
    switch (s) {
    case COMPUTER_SCIENCE: return "Comp. Science";
    case INFORMATICS: return "Informatics";
    case MATH_ECONOMICS: return "Math & Econ";
    case PHYSICS_INFORMATICS: return "Phys & Inf";
    default: return "Unknown";
    }
}

Specialty intToSpecialty(int i) {
    if (i >= 0 && i <= 3) return static_cast<Specialty>(i);
    return UNKNOWN;
}

Student inputStudent() {
    Student s;
    cout << "  Surmane: ";
    cin >> s.surname;

    cout << "  Kurs: ";
    cin >> s.year;

    int specIndex;
    cout << "  Spetsialnist (0-KN, 1-INF, 2-MatEc, 3-FizInf): ";
    cin >> specIndex;
    s.specialty = intToSpecialty(specIndex);

    cout << "  Grade z physics: ";
    cin >> s.gradePhysics;
    cout << "  Grade z maths: ";
    cin >> s.gradeMath;
    cout << "  Grade z informatyky: ";
    cin >> s.gradeCS;

    return s;
}


void createOrAppendFile(const string& filename) {
    ofstream fout(filename, ios::binary | ios::app);
    if (!fout) {
        cerr << "Error with opening" << endl;
        return;
    }

    char choice;
    do {
        cout << "\n--- Dodavannya studenta ---\n";
        Student s = inputStudent();
        // Записуємо структуру як блок байтів
        fout.write(reinterpret_cast<char*>(&s), sizeof(Student));

        cout << "Dodaty shche? (y/n): ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');

    fout.close();
}

void printFileContent(const string& filename) {
    ifstream fin(filename, ios::binary);
    if (!fin) {
        cerr << "File ne znaydeno abo pomylka vidkryttya!" << endl;
        return;
    }

    cout << "\n=================================================================================\n";
    cout << "| # | "
        << left << setw(15) << "Surname" << " | "
        << setw(4) << "Kurs" << " | "
        << setw(15) << "Spetsialnist" << " | "
        << "Fiz | " << "Mat | " << "Inf |" << endl;
    cout << "---------------------------------------------------------------------------------\n";

    Student s;
    int index = 1;
    while (fin.read(reinterpret_cast<char*>(&s), sizeof(Student))) {
        cout << "| " << setw(2) << index++ << "| "
            << left << setw(15) << s.surname << " | "
            << setw(4) << s.year << " | "
            << setw(15) << specialtyToString(s.specialty) << " | "
            << setw(3) << s.gradePhysics << " | "
            << setw(3) << s.gradeMath << " | "
            << setw(3) << s.gradeCS << " |" << endl;
    }
    cout << "=================================================================================\n";

    fin.close();
}

double calculateExcellentPercentage(const string& filename) {
    ifstream fin(filename, ios::binary);
    if (!fin) return 0.0;

    Student s;
    int totalCount = 0;
    int excellentCount = 0;

    while (fin.read(reinterpret_cast<char*>(&s), sizeof(Student))) {
        totalCount++;
        if (s.gradePhysics == 5 && s.gradeMath == 5 && s.gradeCS == 5) {
            excellentCount++;
        }
    }
    fin.close();

    if (totalCount == 0) return 0.0;

    return (static_cast<double>(excellentCount) / totalCount) * 100.0;
}

void printStudentsWithPhysicsFive(const string& filename) {
    ifstream fin(filename, ios::binary);
    if (!fin) {
        cerr << "Error with file opening" << endl;
        return;
    }

    cout << "\nWith '5' z fizyky:" << endl;
    bool found = false;
    Student s;

    while (fin.read(reinterpret_cast<char*>(&s), sizeof(Student))) {
        if (s.gradePhysics == 5) {
            cout << "- " << s.surname << endl;
            found = true;
        }
    }

    if (!found) {
        cout << "No students" << endl;
    }
    fin.close();
}