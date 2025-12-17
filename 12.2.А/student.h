#ifndef STUDENT_H
#define STUDENT_H

#include <string>

enum Specialty {
    COMPUTER_SCIENCE,
    INFORMATICS,
    MATH_ECONOMICS,
    PHYSICS_INFORMATICS,
    UNKNOWN
};

struct Student {
    char surname[50];
    int year;
    Specialty specialty;
    int gradePhysics;
    int gradeMath;
    int gradeCS;
};

std::string specialtyToString(Specialty s);
Specialty intToSpecialty(int i);

void createOrAppendFile(const std::string& filename);
void printFileContent(const std::string& filename);

double calculateExcellentPercentage(const std::string& filename);
void printStudentsWithPhysicsFive(const std::string& filename);

#endif