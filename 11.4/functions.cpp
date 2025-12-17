#include "functions.h"
#include <iostream>
#include <limits>

void showMenu() {
    std::cout << "\n----------- MENU ----------- \n";
    std::cout << "1. Run Task (Reverse lines & Remove char)\n";
    std::cout << "0. Exit\n";
    std::cout << "----------------------------\n";
}

int getIntInput(const std::string& prompt) {
    int value;
    while (true) {
        std::cout << prompt;
        if (std::cin >> value) {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return value;
        }
        else {
            std::cout << "Incorrect input. Please enter a number.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
}

std::string getFileNameInput(const std::string& prompt) {
    std::string name;
    while (true) {
        std::cout << prompt;
        std::getline(std::cin, name);

        if (!name.empty()) {
            if (name.length() < 4 || name.substr(name.length() - 4) != ".txt") {
                name += ".txt";
            }
            return name;
        }
        std::cout << "Filename cannot be empty.\n";
    }
}

char getCharInput(const std::string& prompt) {
    while (true) {
        std::cout << prompt;
        std::string input;
        std::getline(std::cin, input);
        if (input.length() == 1) {
            return input[0];
        }
        std::cout << "Please enter exactly one character.\n";
    }
}

void showMessage(const std::string& msg) {
    std::cout << ">> " << msg << std::endl;
}


std::string removeCharFromString(const std::string& source, char target) {
    std::string result;
    result.reserve(source.length());
    for (char c : source) {
        if (c != target) {
            result += c;
        }
    }
    return result;
}

std::vector<std::streampos> getLineOffsets(std::ifstream& file) {
    std::vector<std::streampos> offsets;

    // Скидаємо всі помилки та переходимо на початок
    file.clear();
    file.seekg(0, std::ios::beg);

    // Перший рядок завжди починається з 0
    offsets.push_back(file.tellg());

    std::string temp;
    // Читаємо файл рядок за рядком
    while (std::getline(file, temp)) {
        // Якщо після читання рядка ми НЕ в кінці файлу, значить, далі йде новий рядок
        // tellg() вказує на початок цього нового рядка
        if (!file.eof()) {
            offsets.push_back(file.tellg());
        }
    }
    return offsets;
}

bool processFiles(const std::string& inputPath, const std::string& outputPath, char forbiddenChar) {
    // Відкриваємо файл у бінарному режимі для точнішого позиціонування (хоча працюємо з текстом)
    // Це допомагає уникнути проблем з \r\n на Windows при seekg
    std::ifstream inFile(inputPath);
    if (!inFile.is_open()) return false;

    // Отримуємо "карту" рядків
    std::vector<std::streampos> offsets = getLineOffsets(inFile);

    std::ofstream outFile(outputPath);
    if (!outFile.is_open()) {
        inFile.close();
        return false;
    }

    std::string line;
    // Йдемо по вектору з кінця до початку (reverse iterator)
    for (auto it = offsets.rbegin(); it != offsets.rend(); ++it) {
        inFile.clear(); // Обов'язково очищуємо стан потоку (бо він був у EOF)
        inFile.seekg(*it); // Стрибаємо на початок конкретного рядка

        if (std::getline(inFile, line)) {
            // При зчитуванні останнього рядка може виникнути символ \r, прибираємо його
            if (!line.empty() && line.back() == '\r') {
                line.pop_back();
            }

            std::string processed = removeCharFromString(line, forbiddenChar);
            outFile << processed << std::endl;
        }
    }

    inFile.close();
    outFile.close();
    return true;
}