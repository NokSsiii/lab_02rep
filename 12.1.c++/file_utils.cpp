#include "lab_25.h"
#include <iostream>
#include <fstream>
#include <limits>

using namespace std;

//функція запису
void CreateIntegerFile(const std::string& filename)
{
    ofstream fout(filename, ios::binary);
    if (!fout.is_open())
    {
        cerr << "Error: Could not open file for writing: " << filename << endl;
        return;
    }

    int number;
    char ch;
    do
    {
        cout << "Enter an integer: ";
        while (!(cin >> number))
        {
            cout << "Invalid input. Please enter an integer: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        //записуємо ціле число у бінарний файл
        fout.write(reinterpret_cast<const char*>(&number), sizeof(number));

        cout << "Continue? (y/n): ";
        cin >> ch;
        //очищення буфера вводу для наступного циклу
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    } while (ch == 'y' || ch == 'Y');
    cout << "File creation finished." << endl;
}

//функція фільтрації
void FilterCosValues(const std::string& sourceFilename, const std::string& destFilename)
{
    ifstream fin(sourceFilename, ios::binary);
    ofstream fout(destFilename, ios::binary);

    if (!fin.is_open())
    {
        cerr << "Error: Could not open source file: " << sourceFilename << endl;
        return;
    }
    if (!fout.is_open())
    {
        cerr << "Error: Could not open destination file: " << destFilename << endl;
        return;
    }

    int value;
    int count = 0;


    while (fin.read(reinterpret_cast<char*>(&value), sizeof(value)))
    {
        //перевірка умови: чи може ціле число бути значенням cos(x)
        if (value == -1 || value == 0 || value == 1)
        {
            fout.write(reinterpret_cast<const char*>(&value), sizeof(value));
            count++;
        }
    }
    cout << "Filtering finished. " << count << " components were written to " << destFilename << "." << endl;
}

//функції виводу
void PrintIntegerFile(const std::string& filename)
{
    ifstream fin(filename, ios::binary);
    if (!fin.is_open())
    {
        cerr << "Error: Could not open file for reading: " << filename << endl;
        return;
    }

    int value;
    int index = 0;
    cout << "--- Content of file: " << filename << " ---" << endl;
    while (fin.read(reinterpret_cast<char*>(&value), sizeof(value)))
    {
        cout << "[" << index++ << "]: " << value << endl;
    }
    cout << "-----------------------------------" << endl;
}