#include <iostream>
#include <cmath>
#include <iomanip>
#include "dod.h"
#include "sum.h"
#include "var.h"

using namespace std;
using namespace nsDod;
using namespace nsSum;
using namespace nsVar;

int main() {

    cout << "Enter x_start: "; cin >> x_p;
    cout << "Enter x_end:   "; cin >> x_k;
    cout << "Enter dx:      "; cin >> dx;
    cout << "Enter eps:     "; cin >> e;
    cout << endl;

    // Table Header
    cout << string(58, '-') << endl;
    cout << "|" << setw(10) << "x"
        << "|" << setw(18) << "ln((1+x)/(1-x))"
        << "|" << setw(15) << "S (Sum)"
        << "|" << setw(10) << "n"
        << "|" << endl;
    cout << string(58, '-') << endl;

    cout << fixed << setprecision(5);

    x = x_p;
    while (x <= x_k + e / 2.0) {

        //|x| < 1
        if (fabs(x) >= 1) {
            cout << "|" << setw(10) << x
                << "|" << setw(45) << "out of domain (|x|<1) "
                << "|" << endl;
        }
        else {
            sum();

            double exactValue = log((1 + x) / (1 - x));

            cout << "|" << setw(10) << x
                << "|" << setw(18) << exactValue
                << "|" << setw(15) << s
                << "|" << setw(10) << n
                << "|" << endl;
        }

        x += dx;
    }
    cout << string(58, '-') << endl;

    cin.get(); cin.get();
    return 0;
}