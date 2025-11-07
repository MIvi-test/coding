#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SPACE 32

void solution1(const char *str)
{
    int i = 0;
    char new_str[strlen(str) + 1];
    strcpy(new_str, str);
    strupr(new_str);
    while (str[i] != '\0')
    {
        if (str[i] == new_str[i])
        {
            char a = new_str[i];
            strlwr(&a);
            new_str[i] = a;
            printf("%c", a);
        }
        else
        {

            printf("%c", new_str[i]);
        }
        i++;
    }
    // return new_str;
}

void solution2(const char *str, char *return_str)
{
    strcpy(return_str, str);
    for (size_t i = 0; i < strlen(str); i++)
    {
        if (return_str[i] == 'A')
        {
            return_str[i] = 'X';
        }
    }
    return;
}

void solution3(const char *str, int start)
{
    int end = start;
    while (str[end] != '\0')
    {
        if (str[end] == SPACE)
        {

            solution3(str, end + 1);            
            for (int i = start; i < end; i++)
            {
                if (str[i] != '\n')
                    printf("%c", str[i]);
            }
            printf(" ");
            break;
        }
        end++;
    }
    return;
}

int readstr(char **return_str)
{
    char *str = (char *)calloc(sizeof(char) * 1, 1);
    int index = 0;
    printf("input string:\n");
    char a = ' ';
    do
    {
        scanf("%c", &a);
        char *new_str = (char *)realloc(str, sizeof(char) * (index + 1));
        if (new_str != NULL)
        {
            str = new_str;
            str[index] = a;
            index++;
        }
        else
        {
            printf("приплыли");
            return -1;
        }
    } while (a != '\n');
    char *s = (char *)realloc(str, index + 1);
    if (s != NULL)
    {
        str = s;
        str[index] = 32;
        index++;
        str[index] = '\0';
    }
    *return_str = str;
    return 0;
}

int main(void)
{
    char *str;
    readstr(&str);

    // solution1(str);
    char *sol2_str;
    solution2(str, sol2_str);
    printf("%s", sol2_str);
    printf()
    solution3(str, 0);
    return 1;
}