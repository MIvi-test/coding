#include <stdio.h>
#include <string.h>

#define max(a, b) (a > b ? a : b)

int position_dot(char *p)
{
    int i = -1;
    int finded_index = -1;
    while (p[++i] != '\0')
    {
        if (p[i] == '.')
        {
            finded_index = i;
        } // very hard logic in code
    }
    return finded_index;
}
void fileManager(char *file_name)
{
    // в принтуемом
    // в многорострочном коменте
    // внутри строчного комента + перенос строки
    // иначе просто печать
    // смена флага для принта

    char *old_file;
    sprintf(old_file, "%s.c", file_name);
    FILE *file_read = fopen(old_file, "r");

    char *new_file;
    sprintf(new_file, "%s.wc", file_name);
    FILE *file_write = fopen(new_file, "w");

    char print = 0;                // флаг если переносили символ
    char in_quoted_qloaca = 0;     // флаг для принта
    char c;                        // для текущего символа
    char old_c = getc(file_read);  // для предыдущего символа
    unsigned char count_slash = 0; // чтобы понять, когда начинаеся строчный комент
    char in_many_string = 0;       // флаг для многострочного

    while (old_c != EOF)
    {
        c = getc(file_read);

        if (in_quoted_qloaca)
        {
            putc(old_c, file_write);
            print = 1;
        }

        else if (in_many_string)
        {
            if (old_c == '*' && c == '/')
            {
                in_many_string = 0;
                c = ' ';
            }
        }

        else if (count_slash)
        {
            if (c == '\n' && old_c != '\\')
            {
                count_slash = 0;
            }
        }

        else if (old_c == '/' && c == '/')
        {
            count_slash = 1;
        }

        else if (old_c == '/' && c == '*')
        {
            in_many_string = 1;
        }

        else
        {
            putc(old_c, file_write);
            print = 1;
        }

        old_c = c;

        if (c == '"' && print == 1) // выход из статуса клоаки
        {
            in_quoted_qloaca = !in_quoted_qloaca;
        }
        print = 0;
    }

    fclose(file_read);
    fclose(file_write);
}
void reader(char *project)
{
    FILE *p = fopen(project, "r");
    int N;
    fscanf(p, "%d\n", &N);
    char *filename;
    for (int i = 0; i < N; i++)
    {

        fscanf(p, "%s\n", filename);
        char *filename_without_extended;
        strncpy(filename_without_extended, filename, position_dot(filename));
        filename_without_extended[position_dot(filename)] = '\0';
        fileManager(filename_without_extended);
    }
}
int main()
{
    // fileManager("test.c", 10);
    reader("text.txt");
}