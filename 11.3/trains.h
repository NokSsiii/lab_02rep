#ifndef TRAINS_H
#define TRAINS_H

#include <string>
#include <vector>

using namespace std;

struct Train {
    string destination;
    string type;
    string time;
};

void printMenu();
int getMenuChoice();
string getFileName();
Train inputTrainData();
string inputTime();

void createFile(const string& filename);
void appendToFile(const string& filename, const Train& train);
void viewFile(const string& filename);

vector<Train> findTrainsAfterTime(const string& filename, const string& searchTime);

void printTrainList(const vector<Train>& trains);

#endif