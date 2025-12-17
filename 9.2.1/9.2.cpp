#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NONSTDC_NO_DEPRECATE
#include <stdio.h>
#include <conio.h>
#include <math.h>

#define Z_VAL 1

#define SQR(k) ((k)*(k))                  // Квадрат числа
#define ABS(k) (((k)<0)?-(k):(k))         // Модуль числа
#define MAX(a,b) (((a)>(b))?(a):(b))      // Максимум
#define MIN(a,b) (((a)<(b))?(a):(b))      // Мінімум

#define PRINTR(val) puts("Result w:"); \
                    printf(#val " = %f\n", (float)val)

void main()
{
    puts("Conditional compilation & Macros");

    float x, y, w;
    char ch;

#if Z_VAL != 1
    float z;
#endif

    do
    {
        // Початок блоку умовної компіляції
#if Z_VAL == 1
    // Гілка 1: z = 1 -> w = max((x-y)^2, |y-x|)
        puts("--- Mode: Z is fixed to 1 ---");
        puts("Calculating: max((x-y)^2, |y-x|)");

        puts("Input x:");
        scanf("%f", &x);
        puts("Input y:");
        scanf("%f", &y);

   
        float term1 = SQR(x - y);
        float term2 = ABS(y - x);
        w = MAX(term1, term2);

#else
    // Гілка 2: z != 1 -> w = min(x+y^2, z+x^2)
        puts("--- Mode: Z is NOT 1 ---");
        puts("Calculating: min(x+y^2, z+x^2)");

        puts("Input x:");
        scanf("%f", &x);
        puts("Input y:");
        scanf("%f", &y);
        puts("Input z (z != 1):");
        scanf("%f", &z);

        float term1 = x + SQR(y);
        float term2 = z + SQR(x);
        w = MIN(term1, term2);

#endif 

        PRINTR(w); // Виведення результату макросом

        puts("Repeat? y / n");
        ch = getch();
        printf("\n");

    } while (ch == 'y');
}