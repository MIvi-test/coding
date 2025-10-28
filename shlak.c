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
        goto end;
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
            goto end;
        }
        str = r_str;
    }
    str[len] = '\0';
    *new_str = str;
    return;
end:
    printf("ошибка инициализации\n");
    return;
}

char compare(const char *str1, const char *str2)
{
    char flag = 1;
    short i = 0;
    for (; str1[i] != '\0' && str2[i] != '\0'; i++)
    {
        if (str1[i] != str2[i])
        {
            flag = 0;
        }
    }
    if (str1[i] == '\0' && str2[i] == '\0')
        return flag;
    else
        return 0;
}

void testing()
{
    char *test_cases[] = {
        "шлакоблок окунь",
        "папа папаха",
        "папа мама",
        "программа марафон",
        "компьютер термос",
        "телефон оникс",
        "солнце цель",
        "книга галактика",
        "окно ноутбук",
        "стол лодка",
        "море река",
        "небо облако",
        "город ода",
        "цветок ток",
        "дом мод",
        "лето торт",
        "зима маска",
        "весна нарцисс",
        "осень неньютоновская",
        "дождь жребий"};

    char *expected_results[] = {
        "шлакоблокунь",        // шлакоблок + окунь
        "папаха",              // папа + папаха
        "папамама",            // папа + мама
        "программарафон",      // программа + марафон
        "компьютермос",        // компьютер + термос
        "телефоникс",          // телефон + оникс
        "солнцель",            // солнце + цель
        "книгалактика",        // книга + галактика
        "окноутбук",           // окно + ноутбук
        "столодка",            // стол + лодка
        "морека",              // море + река
        "небоблако",           // небо + облако
        "города",              // город + ода
        "цветок",              // цветок + ток (полное перекрытие "ток")
        "домод",               // дом + мод
        "леторт",              // лето + торт
        "зимаска",             // зима + маска
        "веснарцисс",          // весна + нарцисс
        "осеньненьютоновская", // осень + неньютоновская
        "дождьжребий"          // дождь + жребий
    };

    short len = sizeof(test_cases) / sizeof(test_cases[0]);
    for (short i = 0; i < len; i++)
    {
        char *a = test_cases[i];
        short k = 0;
        char *str;
        searching(a);
        make_str(a, &str);
        if (str)
        {
            printf("test %d: ", i + 1);
            if (compare(str, expected_results[i]))
            {
                printf("OK\n");
            }
            else
            {
                printf("ERROR %s\n", str);
            }
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