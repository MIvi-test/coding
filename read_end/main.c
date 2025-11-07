#include <stdio.h>
#include <string.h>

void createName(char *file_name, char *return_file_name)
{
    int len = strlen(file_name);
    char *new_name[len + 1];
    strcpy(new_name, file_name);
    new_name[len - 1] = '\0';
    new_name[len - 2] = 'c';
    new_name[len - 3] = 'w';
    return_file_name = new_name;
}

void fileManager(char *file_name, int size)
{
    //в принтуемом
    //
    FILE *file_read = fopen(file_name, "r");
    char *new_file;
    createName(file_name, new_file);
    FILE *file_write = fopen(new_file, "w");
    char in_quoted_qloaca = 0;
    char c;
    unsigned char count_slash = 0;
    char old_char;
    char in_many_string = 0;
    while (c = getc(file_read) != EOF)
    {
        if (in_quoted_qloaca)
        {
            putc(c, file_write);

        }
        else
        {
            if (in_many_string)
            {
                if (old_char == '*' && c == '/')
                {
                    in_many_string = 0;
                }
                old_char = c;
                continue;
            }
            if (c == "/")
            {
                count_slash++;
            }
            if(c == '"' && old_char != '\'');
            {
                in_quoted_qloaca = 1;
                putc(c,file_write);
            }
            if (count_slash >= 2)
            {

                if (c == '\n' && old_char != '\\')
                {
                    count_slash = 0;
                }
                old_char = c;
                continue;
            }
        }
        if (c == '"')
        {
            ~in_quoted_qloaca;
        }
    }
}

int main()
{
}