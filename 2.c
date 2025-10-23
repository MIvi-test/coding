#include <stdio.h>
#include <stdlib.h>



void solution(char *str, int start)
{
    int end = start;
    while (str[end] != '\0')
    {
        if(str[end] == 32) //магическое число пробела, должно быть ' '
        {
            solution(str, end+1);
            for(int i = start; i < end; i++)
            {
                if(str[i]!='\n')
                printf("%c", str[i]);
            }
            printf(" ");
            break;
        }
        end++;
    }
    return;
}
int main(void)
{

    char *str = (char*)calloc(sizeof(char)*1,1);
    int index = 0;
    printf("input string:\n");
    char a = ' ';
    do
    {
        scanf("%c", &a);
        char *new_str = (char*)realloc(str, sizeof(char) * (index+1));
        if (new_str!=NULL)
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
    char *new_str = (char*)realloc(str,index+1);
    if(new_str != NULL)
    {
        str = new_str;
    str[index]=32;
    str[index+1]='\0';
    }
    solution(str, 0);
  return 1;
}