#include <stdio.h>
#include <locale.h>

#define SIZE 32 * 2 + 2
#define SPACE 32

void searching(char *str)
{
    short i = 0;
    while (str[i] != SPACE)
    {
        i++;
    }
    short right = i + 1;
    short left = i;
    short join = left;
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
    short k = 0;
    for (; k < join; k++)
    {
        printf("%c", str[k]);
    }
    for (k = right; str[k] != '\0'; k++)
    {
        printf("%c", str[k]);
    }

    return;
}

int main()
{
    int N;
    scanf("%d", &N);
    getchar();

    char words[N][SIZE];

    for (int i = 0; i < N; i++)
    {
        fgets(words[i], SIZE, stdin);
    }

    for (short n = 0; n < N; n++)
    {
        searching(words[n]);
    }
    return 0;
}