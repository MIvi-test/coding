#include <stdio.h>

// реализуем шахматы и 8 ферзей
#define SIZE 4

int TABLE[SIZE][SIZE];
//нормально не чистит вертикали, норм в рекурсию не входит
void position(int n, int* pos)
{
    for (int i = 0; i < SIZE; i++)
    {
        if (TABLE[SIZE - n][i] == 0)
        {
            pos[0] = SIZE-n;
            pos[1] = i;
            return; //свободная позиция
        }
    }
    pos[0] = -1;
    pos[1] = -1;
    return;
}

void clean_table(int i, int j) // чистим все позиции под [i][j] и диагонали
{
    short count = 1;
    for(int n = i+1; n < SIZE;n++)
    {
        if(TABLE[n][j] == i+1)
        {
            TABLE[n][j] = 0;
        }
        if(((j+count <SIZE)) && (TABLE[n][j+count] == i+1))
        {
            TABLE[n][j+count] = 0;
        }
        if(((j-count <SIZE)) && (TABLE[n][j-count] == i+1))
        {
            TABLE[n][j-count] = 0;
        }
    }
    return;
}

int all_pos[SIZE];
char STATUS = 0;
int chakmate(int n)
{
    if (STATUS)
    {
        return 1;
    }
    if (n == 0) //просто вывод получившегося, победа!
    {
        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j < SIZE; j++)
            {
                printf_s("%d ", TABLE[i][j]);
            }
            printf("\n");
        }
        STATUS = 1;
        return 1;
    }
    else
    {

        int pos[2];
        position(n,pos);
        if (pos[0] != -1)
        {
            all_pos[SIZE-n] = pos[1];
            short count = 0;
            for (int j = SIZE - n; j < SIZE; j++) //j текушая строка для заполения
            {
                if(TABLE[j][pos[1]] == 0)
                {
                    TABLE[j][pos[1]] = SIZE - n + 1;
                } //первый ферзь ставиться и обозначается 1, а не ноль, чтобы не было ошибок, заполнение прямой
                if((pos[1]+count <SIZE) && (TABLE[j][count + pos[1]] == 0))
                {
                    TABLE[j][count+pos[1]] = SIZE-n+1;
                }
                if((pos[1] - count > 0) && (TABLE[j][count-pos[1]] == 0))
                {
                    TABLE[j][pos[1] - count] = SIZE-n+1;
                }
                count++;
            }
            int inner_res = chakmate(n-1);
            if (!inner_res)//написать проверку на возращения варианта, что невозможно отсюда поставить ферзя
            {
                clean_table(SIZE-n, all_pos[SIZE-n]);
                chakmate(n);
                return 1;
                 //повторно ставим на этой линии 
            }
        }
        else // не смогли поставить для текущего n ферзя и линия непригодна
        {
            for(char i = 0; i < SIZE; i++)
            {
                //чистим линию от попыток
                if(TABLE[n][i] == SIZE-n+1)
                {
                    TABLE[n][i] = 0;
                }
            }
            clean_table(SIZE-n+1,all_pos[SIZE-n+1]);
            chakmate(n+1);
            return 0;
        }
    }
}

int main()
{
    chakmate(SIZE);
    int a;
    return 1;
}