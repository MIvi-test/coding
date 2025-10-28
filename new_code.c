#include <stdio.h>

int main()
{
    char *str = "Hellow world";
    FILE *f;
    int n;
    f = fopen("data.txt", "r");
    if(f == NULL)
    {
        perror("ошибка при открытии файла");
        return 1;
    }
    printf("1");
    return 0;

}