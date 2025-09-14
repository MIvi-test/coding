#include <stdio.h>

void CHAR()
{
    unsigned char variable_1 = 1; 
    short count = 0; //счётчик длинны
    while (variable_1 > 0) {variable_1 <<= 1; count++;} //переполнение с подсчётом длинны
    long long number = 1; //предел значения
    count--;
    while (count > 0){number += 1<<count;--count;} //создание максимального значения путём смещения единицы
    {printf("для unsighed char\nMAX = %d\nMIN = %d\n",number, 0);}
    signed char variable_2 = 1;
    while (variable_2 > 0) {variable_2 <<= 1;} // переполнение, но так как это signed, то он по окончанию отрицателен
    printf("для sighed char\nMAX = %d\nMIN = %d\n", ~variable_2, variable_2); // ~ обращает в зеркальное значение
}

void SHORT()
{
    unsigned short variable_1 = 1; 
    short count = 0; //счётчик длинны
    while (variable_1 > 0) {variable_1 <<= 1; count++;} //переполнение с подсчётом длинны
    long long number = 1; //предел значения
    count--;
    while (count > 0){number += 1<<count;--count;} //создание максимального значения путём смещения единицы
    {printf("для unsighed short\nMAX = %d\nMIN = %d\n",number, 0);}
    signed short variable_2 = 1;
    while (variable_2 > 0) {variable_2 <<= 1;} // переполнение, но так как это signed, то он по окончанию отрицателен
    printf("для sighed short\nMAX = %d\nMIN = %d\n", ~variable_2, variable_2); // ~ обращает в зеркальное значение
}

void INT()
{
    unsigned int variable_1 = 1; 
    short count = 0; //счётчик длинны
    while (variable_1 > 0) {variable_1 <<= 1; count++;} //переполнение с подсчётом длинны
    unsigned int number = 1; //предел значения
    count-=1;number<<=count;number--;number<<=1;number++;
    
    {printf("для unsighed int\nMAX = %u\nMIN = %u\n",number, 0);}
    signed int variable_2 = 1;
    while (variable_2 > 0) {variable_2 <<= 1;} // переполнение, но так как это signed, то он по окончанию отрицателен
    printf("для sighed int\nMAX = %u\nMIN = %d\n", ~variable_2, variable_2); // ~ обращает в зеркальное значение
}

void LONG()
{
    unsigned long variable_1 = 1L; 
    short count = 0; //счётчик длинны
    while (variable_1 > 0) {variable_1 <<= 1; count++;} //переполнение с подсчётом длинны
    unsigned long number = 1; //предел значения
    count--;
    number<<=count;
    number--;number<<=1;number++;
    printf("для unsighed long\nMAX = %lli\nMIN = %lli\n",number, 0);

    signed long variable_2 = 1l;
    while (variable_2 > 0) {variable_2 <<= 1;} // переполнение, но так как это signed, то он по окончанию отрицателен
    printf("для sighed long\nMAX = %li\nMIN = %li\n", ~variable_2, variable_2); // ~ обращает в зеркальное значение
}

void LONG_LONG()
{
    unsigned long long variable_1 = 1LL;
    short count = 0;
    while (variable_1 > 0) {variable_1 <<= 1;count++;}
    unsigned long long number = 1;
    count--;
    number <<=count;
    number--; number <<=1; number++;
    printf("для unsigned long long\nMAX = %llu\nMIN = %lli\n", number, ~number);


    signed long long variable_2 = 1LL;
    while (variable_2 > 0) {variable_2 <<= 1;} // переполнение, но так как это signed, то он по окончанию отрицателен
    printf("для signed long long\nMAX = %lli\nMIN = %lli\n", ~variable_2, variable_2); // ~ обращает в зеркальное значение
}

void FLOAT()
{
    float F1 = 0.11f; // переменная для нахождения предела
    float F0;
    while (F0 != F1){F0 = F1;F1 += 1;} //создание самого большого значения типа float

    float H1 = 1.0f; //для нахождения предела
    float H0 = 10.0f;
    short count = 0;
    while (H1 < H0)
    {
        H0 = H1;
        H1 /=2;
        count++;
    }
    float h1 = 1.0f; //для создания предела
    for (short i = 0; i < (count-2);i++){h1/=2;}

    printf("для float\nMAX = %f\nMIN_POS = %e\nMIN = %f\n", F1,h1, -1*F1);
}

void DOUBLE()
{
    double F1 = 0.1f; // переменная для нахождения предела справа
    double F0;
    short C = 0;
    while (F0 != F1){F0 = F1;F1 *= 2;C++;} //создание самого большого значения типа float
    double f1 = 0.1f; //переменная для создания предельного значения

    for (int i = 0; i < (C-2);i++) { f1 *= 2;}

    double H1 = 1.0f; //для нахождения предела слева
    double H0 = 10.0f;
    short count = 0;
    while (H1 < H0)
    {
        H0 = H1;
        H1 /=2;
        count++;
    }
    double h1 = 1.0f; //для создания предела
    for (short i = 0; i < (count-2);i++){h1/=2;}

    printf("для double\nMAX = %e\nMIN_POS = %e\nMIN = %e\n", f1,h1, -1*f1);
}

void LONG_DOUBLE()
{
    long double F1 = 0.1f; // переменная для нахождения предела справа
    long double F0;
    int C = 0;
    while (F0 != F1){F0 = F1;F1 *= 2;C++;} //создание самого большого значения типа float
    long double f1 = 0.1f; //переменная для создания предельного значения

    // printf("\n%d\n", C);
    for (int i = 0; i < (C);i++) { f1 *= 2;}
    long double H1 = 1.0f; //для нахождения предела слева
    long double H0 = 10.0f;
    int count = 0;
    while (H1 < H0)
    {
        H0 = H1;
        H1 /=2;
        count++;
    }
    long double h1 = 1.0f; //для создания предела
    for (int i = 0; i < (count);i++){h1/=2;}

    printf("для long double\nMAX = %Le\nMIN_POS = %Le\nMIN = %Le\n", f1,h1, -1*f1);
}


int main()
{
    CHAR();

    SHORT();

    INT();

    LONG();

    LONG_LONG();

    FLOAT();

    DOUBLE();

    LONG_DOUBLE();
}