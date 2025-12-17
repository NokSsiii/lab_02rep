#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <string>
#include <vector>
#include <fstream>

void showMenu();
int getIntInput(const std::string& prompt);

std::string getFileNameInput(const std::string& prompt);

char getCharInput(const std::string& prompt);
void showMessage(const std::string& msg);

std::string removeCharFromString(const std::string& source, char target);
std::vector<std::streampos> getLineOffsets(std::ifstream& file);
bool processFiles(const std::string& inputFile, const std::string& outputFile, char forbiddenChar);

#endif