#include <stdio.h>
#include <stdlib.h>

#define SIZE 32 * 2 + 2
#define SPACE 32

short right;
short left;
short join; // проще сделать так, чем посстоянно передавать из одной функции в другую

void searching(const char *str)
{
    short i = 0;
    while (str[i] != SPACE)
    {
        i++;
    }
    right = 1 + i;
    left = i;
    join = left;
    for (short left_now = 0; left_now < left; left_now++)
    {
        if (str[left_now] == str[right])
        {
            char flag = 1;
            for (short j = 0; j < left - left_now; j++)
            {
                if (str[j + right] == '\0' || str[j + right] == ' ' || str[j + right] == '\n')
                {
                    break;
                }
                if (str[j + left_now] != str[j + right])
                {
                    flag = 0;
                    break;
                }
            }
            if (flag)
            {
                join = left_now;
                break;
            }
        }
    }
    return;
}

void make_str(const char *old_str, char **new_str)
{
    char *str = (char *)malloc(1 * sizeof(char));
    if (!str)
    {
        goto A;
    }
    short len = 0;
    short k = 0;
    while (old_str[k] != '\n' && old_str[k] != '\0')
    {
        if (k == join)
        {
            k = right; // начало чтения второго слова
        }
        str[len] = old_str[k];
        len++;
        k++;
        char *r_str = realloc(str, len + 1);
        if (!r_str)
        {
            printf("HHAHAHAHHA");
            goto A;
        }
        str = r_str;
    }
    str[len] = '\0';
    *new_str = str;
    return;
A:
    printf("ошибка инициализации\n");
    return;
}

void testing()
{
    char *massive[] = {
        "shlakoblock ocktavius\0",
        "шлакоблок окунь\0",
        "папа папаха\n" // в конце должно быть либо \n или \0 или пробел
    };
    short len = sizeof(massive) / sizeof(massive[0]);
    for (short i = 0; i < len; i++)
    {
        char *a = massive[i];
        short k = 0;
        char *str;
        searching(a);
        make_str(a, &str);
        if (!str)
        {
            printf("%s\n", str);
        }
        else
        {
            return;
        }
    }
}

int main()
{
    // int N;
    // scanf("%d", &N);
    // getchar();

    // char words[N][SIZE];

    // for (int i = 0; i < N; i++)
    // {
    //     fgets(words[i], SIZE, stdin);
    // }

    // for (short n = 0; n < N; n++)
    // {
    //     searching(words[n]);
    //     char *str;
    //     make_str(words[n], &str);
    //     printf("%s\n", str);
    // }
    testing();
    return 0;
}