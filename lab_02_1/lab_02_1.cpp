// lab_02_01.cpp 
// Уршеджук Ілля 
// Лабораторна робота № 2.1 
// Лінійні програми. 
// Варіант 25 

#include <iostream>
#include <cmath>
#include <Windows.h>

using namespace std;

int main() 
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

	double alpha; // вхідний параметр
   
    cout << "Введіть значення: ";
    cin >> alpha;

	double z1 = 1 - 0.25 * pow(sin(2 * alpha), 2) + cos(2 * alpha); // обчислення за першою формулою
	// double z2 = pow(cos(alpha), 2) + pow(cos(alpha), 4); // обчислення за другою формулою

    cout << "z1 = " << z1 << endl;
	// cout << "z2 = " << z2 << endl // виведення результату

    return 0;
}

