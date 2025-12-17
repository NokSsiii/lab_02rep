#include "lab_25.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
    //введення імен файлів
    string sourceFilename;
    cout << "Enter the name of the source file (e.g., source.bin): ";
    cin >> sourceFilename;

    string destFilename;
    cout << "Enter the name of the destination file (e.g., dest.bin): ";
    cin >> destFilename;

    //формування файлу даних
    cout << "\n--- 1. Creating Source File (" << sourceFilename << ") ---" << endl;
    CreateIntegerFile(sourceFilename);

    //виведення вмісту вихідного файлу
    cout << "\n--- Source File Content Check ---" << endl;
    PrintIntegerFile(sourceFilename);

    //фільтрація
    cout << "\n--- 2. Filtering data into Destination File (" << destFilename << ") ---" << endl;
    FilterCosValues(sourceFilename, destFilename);

    //вивід результатів
    cout << "\n--- 3. Final Result File Content (" << destFilename << ") ---" << endl;
    PrintIntegerFile(destFilename);

    return 0;
}