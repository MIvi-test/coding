#include <stdio.h>

void CHAR()
{
    unsigned char variable_1 = 1;
    while (variable_1 > 0)
    {
        variable_1 <<= 1;
    }
    printf("for unsighed char\nMAX = %d\nMIN = %d\n", --variable_1, 0);
    signed char variable_2 = 1;
    while (variable_2 > 0)
    {
        variable_2 <<= 1;
    }
    printf("for sighed char\nMAX = %d\nMIN = %d\n", ++variable_2, variable_2);
}

void SHORT()
{
    unsigned short variable_1 = 1;

    while (variable_1 > 0)
    {
        variable_1 <<= 1;
    }
    printf("for unsighed short\nMAX = %d\nMIN = %d\n", --variable_1, 0);
    signed short variable_2 = 1;
    while (variable_2 > 0)
    {
        variable_2 <<= 1;
    }
    printf("for sighed short\nMAX = %d\nMIN = %d\n", ++variable_2, variable_2);
}

void INT()
{
    unsigned int variable_1 = 1;
    while (variable_1 > 0)
    {
        variable_1 <<= 1;
    }
    {
        printf("for unsighed int\nMAX = %u\nMIN = %u\n", --variable_1, 0);
    }
    signed int variable_2 = 1;
    while (variable_2 > 0)
    {
        variable_2 <<= 1;
    }
    printf("for sighed int\nMAX = %u\nMIN = %d\n", ++variable_2, variable_2);
}

void LONG()
{
    unsigned long variable_1 = 1L;
    while (variable_1 > 0)
    {
        variable_1 <<= 1;
    }
    printf("for unsighed long\nMAX = %lli\nMIN = %lli\n", --variable_1, 0);
    signed long variable_2 = 1l;
    while (variable_2 > 0)
    {
        variable_2 <<= 1;
    }
    printf("for sighed long\nMAX = %li\nMIN = %li\n", ++variable_2, variable_2);
}

void LONG_LONG()
{
    unsigned long long variable_1 = 1LL;
    while (variable_1 > 0)
    {
        variable_1 <<= 1;
    }
    printf("for unsigned long long\nMAX = %llu\nMIN = %lli\n", --variable_1, 0);
    signed long long variable_2 = 1LL;
    while (variable_2 > 0)
    {
        variable_2 <<= 1;
    }
    printf("for signed long long\nMAX = %lli\nMIN = %lli\n", ++variable_2, variable_2);
}

void FLOAT()
{
    float F1 = 0.11f; // for нахождения предела
    float F0;
    while (F0 != F1)
    {
        F0 = F1;
        F1 += 1;
    } // создание самого большого значения типа float

    float H1 = 1.0f; // for нахождения предела
    float H0 = 10.0f;
    short count = 0;
    while (H1 < H0)
    {
        H0 = H1;
        H1 /= 2;
        count++;
    }
    float h1 = 1.0f; // for создания предела
    for (short i = 0; i < (count - 2); i++)
    {
        h1 /= 2;
    }

    printf("for float\nMAX = %f\nMIN_POS = %e\nMIN = %f\n", F1, h1, -1 * F1);
}

void DOUBLE()
{
    double F1 = 0.1f;
    double F0;
    short C = 0;
    while (F0 != F1)
    {
        F0 = F1;
        F1 *= 2;
        C++;
    }
    double f1 = 0.1f;

    for (int i = 0; i < (C - 2); i++)
    {
        f1 *= 2;
    }

    double H1 = 1.0f;
    double H0 = 10.0f;
    short count = 0;
    while (H1 < H0)
    {
        H0 = H1;
        H1 /= 2;
        count++;
    }
    double h1 = 1.0f;
    for (short i = 0; i < (count - 2); i++)
    {
        h1 /= 2;
    }

    printf("for double\nMAX = %e\nMIN_POS = %e\nMIN = %e\n", f1, h1, -1 * f1);
}

void LONG_DOUBLE()
{
    long double F1 = 0.1f;
    long double F0;
    int C = 0;
    while (F0 != F1)
    {
        F0 = F1;
        F1 *= 2;
        C++;
    }
    long double f1 = 0.1f;

    for (int i = 0; i < (C); i++)
    {
        f1 *= 2;
    }
    long double H1 = 1.0f;
    long double H0 = 10.0f;
    int count = 0;
    while (H1 < H0)
    {
        H0 = H1;
        H1 /= 2;
        count++;
    }
    long double h1 = 1.0f; // for создания предела
    for (int i = 0; i < (count); i++)
    {
        h1 /= 2;
    }

    printf("for long double\nMAX = %Le\nMIN_POS = %Le\nMIN = %Le\n", f1, h1, -1 * f1);
    // перепробовал модификаторы: Le, LLd, ld, L, LLe, Lf, llf, e
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
