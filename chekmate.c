#include <stdio.h>

#define SIZE 8

int TABLE[SIZE][SIZE];

short position(int n)
{

    for (short i = 0; i < SIZE; i++) // по строчке
    {
        if (TABLE[n][i] != 0)
        {
            continue;
        }
        char flag = 1;
        for (short j = 0; j < n; j++) // по столбцу
        {
            if (TABLE[j][i] == 1)
            {
                flag = 0;
                break;
            }
            short k = n - j;
            if (i + k < SIZE && TABLE[j][i + k] == 1) // номер конечного столбца - номер текущего столбца = смещение по диагонали. Смещение + смещние по строке = позиция по диагонали
            {
                flag = 0;
                break;
            }
            if (i - k >= 0 && TABLE[j][i - k] == 1) // левая диагонали
            {
                flag = 0;
                break;
            }
        }
        if (flag)
        {
            return i;
        }
        // short k = n - i - 1; //диагональная часть
    }
    return -1;
}

int chakmate(int n)
{

    if (n == SIZE) // просто вывод получившегося, победа!
    {
        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j < SIZE; j++)
            {
                int A = TABLE[i][j];
                if (A == -1)
                {
                    A = 0;
                }
                printf_s("%d ", A); 
            }
            printf("\n");
        }
        return 1;
    }
    short pos = position(n);
    if (pos != -1)
    {
        TABLE[n][pos] = 1;
        chakmate(n + 1);
    }
    else
    {
        for (char i = 0; i < SIZE; i++)
        {
            TABLE[n][i] = 0; // очистка всех попыток для этого ферзя
        }
        for (char i = 0; i < SIZE; i++)
        {
            if (TABLE[n - 1][i] == 1)
            {
                TABLE[n - 1][i] = -1; // попытка n+1 ферзя неудачна
                break;
            }
        }
        chakmate(n - 1);
    }
}

int main()
{
    chakmate(0);
    int a;
    return 1;
}