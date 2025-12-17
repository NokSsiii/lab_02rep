#ifndef STUDENT_H
#define STUDENT_H

#include <string>

using namespace std;


enum Specialty {
    KN,
    SE,
    IA,
    TN,
    UNKNOWN
};

struct Student {
    string surname;
    int course;
    Specialty specialty;
    int gradePhysics;
    int gradeMath;
    int gradeInformatics;
};

string getSpecialtyStr(Specialty s);

void fillArray(Student* students, int size);

void printTable(const Student* students, int size);

double calculateExcellentPercentage(const Student* students, int size);

void printStudentsWithPhysicsFive(const Student* students, int size);

#endif