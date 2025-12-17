#include "trains.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <limits>
#include <string>
#include <vector>

using namespace std;

// --- Інтерфейс та Валідація ---

void printMenu() {
    cout << "\n=== MENU ===" << endl;
    cout << "1. Create file" << endl;
    cout << "2. Add train" << endl;
    cout << "3. Check all trains" << endl;
    cout << "4. Search trains after specific time" << endl;
    cout << "0. Exit" << endl;
    cout << "Your choice: ";
}

int getMenuChoice() {
    int choice;
    while (!(cin >> choice) || choice < 0 || choice > 4) {
        cout << "Error. Enter number from 0 to 4: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Очистка буфера після числа
    return choice;
}

string getFileName() {
    string name;
    cout << "Enter file name: ";
    getline(cin, name);
    return name;
}

string inputTime() {
    string time;
    bool valid = false;
    while (!valid) {
        cout << "Enter time (HH:MM): ";
        getline(cin, time);
        // Проста перевірка формату
        if (time.length() == 5 && time[2] == ':' &&
            isdigit(time[0]) && isdigit(time[1]) &&
            isdigit(time[3]) && isdigit(time[4])) {

            int h = stoi(time.substr(0, 2));
            int m = stoi(time.substr(3, 2));
            if (h >= 0 && h < 24 && m >= 0 && m < 60) {
                valid = true;
            }
        }

        if (!valid) cout << "Wrong time format\n";
    }
    return time;
}

// ОНОВЛЕНА ФУНКЦІЯ
Train inputTrainData() {
    Train t;

    // 1. Введення пункту призначення
    cout << "Enter destination: ";
    getline(cin, t.destination);

    // 2. Вибір типу поїзда через меню
    cout << "Select type of train:" << endl;
    cout << "1. Defoult" << endl;
    cout << "2. Express" << endl;
    cout << "3. Comfort" << endl;

    int typeChoice;
    bool validChoice = false;

    while (!validChoice) {
        cout << "Enter choice (1-4): ";
        if (cin >> typeChoice) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Очистка буфера

            switch (typeChoice) {
            case 1: t.type = "Defoult"; validChoice = true; break;
            case 2: t.type = "Express"; validChoice = true; break;
            case 3: t.type = "Comfort"; validChoice = true; break;
            default: cout << "Invalid option. ";
            }
        }
        else {
            cout << "Invalid input (must be a number). ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }

    // 3. Введення часу
    t.time = inputTime();
    return t;
}

// --- Робота з файлом ---

void createFile(const string& filename) {
    ofstream file(filename); // Відкриття без ios::app перезаписує файл
    if (!file) {
        cerr << "Error creating file" << endl;
    }
    else {
        cout << "Success" << endl;
    }
    file.close();
}

void appendToFile(const string& filename, const Train& train) {
    // Відкриваємо в режимі додавання (app)
    ofstream file(filename, ios::app);
    if (!file) {
        cerr << "Error! Cannot open the file" << endl;
        return;
    }
    // Записуємо через роздільник ';', щоб потім легко читати
    file << train.destination << ";" << train.type << ";" << train.time << endl;
    file.close();
    cout << "Record added." << endl;
}

void viewFile(const string& filename) {
    ifstream file(filename);
    if (!file) {
        cerr << "File not found or error opening." << endl;
        return;
    }

    string line;
    cout << "\n--- File Content ---" << endl;
    cout << left << setw(20) << "Destination" << setw(20) << "Type" << setw(10) << "Time" << endl;
    cout << "--------------------------------------------------" << endl;

    Train t;
    // Читаємо файл порядково і розбираємо рядок
    while (getline(file, t.destination, ';')) {
        getline(file, t.type, ';');
        getline(file, t.time); // Читаємо до кінця рядка (\n)

        cout << left << setw(20) << t.destination
            << setw(20) << t.type
            << setw(10) << t.time << endl;
    }
    file.close();
}

// --- Логіка пошуку ---

vector<Train> findTrainsAfterTime(const string& filename, const string& searchTime) {
    vector<Train> result;
    ifstream file(filename);
    if (!file) {
        cerr << "File not found." << endl;
        return result;
    }

    Train t;
    // Читаємо файл "на льоту", не зберігаючи все в масив
    while (getline(file, t.destination, ';')) {
        getline(file, t.type, ';');
        getline(file, t.time);

        // Порівняння рядків часу працює коректно для формату HH:MM
        if (t.time > searchTime) {
            result.push_back(t);
        }
    }
    file.close();
    return result;
}

void printTrainList(const vector<Train>& trains) {
    if (trains.empty()) {
        cout << "No trains found." << endl;
        return;
    }
    cout << "\n--- Search Results ---" << endl;
    for (const auto& t : trains) {
        cout << t.time << " - " << t.destination << " (" << t.type << ")" << endl;
    }
}