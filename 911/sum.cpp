#include <cmath>
#include "dod.h"
#include "sum.h"
#include "var.h"

using namespace nsDod;
using namespace nsVar;

void nsSum::sum() {
    n = 0;
    a = 2 * x; // Перший член ряду для n=0: 2*x
    s = a;

    do {
        n++;
        dod(); // Обчислення наступного доданку
        s += a;
    } while (fabs(a) > e); // Продовжуємо, доки доданок більше точності eps
}