#include <stdio.h>

void mb_float(long long N, int k)
{
    if (N == 0)
    {
        printf("ZeroDivisonError");
        return;
    }
    if (k < 0 || k > 100 || N > 1000000000)
    {
        printf("ValueError");
        return;
    }
    if (N < 0)
    {
        printf("-");
        N = -N;
    }
    int mas[k + 1];
    long ost = 1;

    for (int i = 0; i <= k; i++)
    {
        mas[i] = ost / N;
        ost = (ost % N) * 10;
    }

    printf("%d.", mas[0]);

    for (int n = 1; n < k; n++)
    {
        printf("%d", mas[n]);
    }
    printf("\n");
}

void testing();

int main()
{
    testing();
    return 0;
}

void testing()
{
    printf("первый тест\n");
    mb_float(1, 0);
    printf("второй тест\n");
    mb_float(2, 1);
    printf("третий тест\n");
    mb_float(3, 1);
    printf("четвертый тест\n");
    mb_float(1, 1);
    printf("пятый тест\n");
    mb_float(10, 2);
    printf("шестой тест\n");
    mb_float(12, 8);
    printf("седьмой тест\n");
    mb_float(-27, 6);
    printf("восьмой тест\n");
    mb_float(39, 80);
    printf("девятый тест\n");
    mb_float(0, 4);
    printf("десятый тест\n");
    mb_float(5, 2);
    printf("одиннадцатый тест\n");
    mb_float(7, 16);
    printf("двенадцатый тест\n");
    mb_float(10, 54);
    printf("тринадцатый тест\n");
    mb_float(14, 13);
    printf("четырнадцатый тест\n");
    mb_float(12345, 21);
    printf("пятнадцатый тест\n");
    mb_float(100, 45);
    printf("шестнадцатый тест\n");
    mb_float(4321413, 13);
    printf("семнадцатый тест\n");
    mb_float(654434, 10);
    printf("восемнадцатый тест\n");
    mb_float(1000, 3);
    printf("девятнадцатый тест\n");
    mb_float(1000000, 8);
    printf("двадцатый тест\n");
    mb_float(99999999, 99);
}