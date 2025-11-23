#include <stdio.h>
#include <stdlib.h>

#define False 0
#define True 1


int pos(int x2, int y2, int type, int **positions, int size);

int **copy(int **massive, int size);

int mod(int n, int m);

int **append(int **massive, int *size, int *value);

int diff(int a, int b);

int *pop(int **massive, int *size);

int sum(int *massive, int size);

int **read_numbers(char *filename, int *N, int *L, int *K);

void writer(int **positions, int size);

void verification_file();

int main()
{
    int type = 1;
    int N, L, K;
    int **data = (int **)read_numbers("input.txt", &N, &L, &K);
    for (int start = 0; start < (N * N); start++)
    {
        int start_x = mod(start, N);
        int start_y = start / N;
        int **positions = copy(data, K);
        int figure = L;
        char flag = 1;
        int size = K;
        if(pos(start_x, start_y, type, positions, size) == 0)
        {
            continue;
        }
        while (flag)
        {
            for (int y = start_y; y < N; y++)
            {
                for (int x = start_x; x < N; x++)
                {
                    if (pos(x, y, type, positions, size))
                    {
                        int *t = (int *)malloc(sizeof(int) * 2);
                        t[0] = x;
                        t[1] = y;
                        figure--;
                        positions = append(positions, &size, t);
                    }
                    if (figure == 0)
                    {
                        writer(positions, size);
                        flag = 0;
                        break;
                    }
                }
                if (!flag)
                {
                    break;
                }
            }
            if(size <= K)
            {
                break;
            }
            int *old = pop(positions, &size);
            int sums = old[0] + old[1] * N + 1;
            start_x = mod(sums, N);
            start_y = sums / N;
            figure++;
        }
    }
    verification_file();
}

int **copy(int **massive, int size)
{
    int **new_massive = (int **)malloc(sizeof(int *) * size);
    if (!new_massive)
    {
        printf("HAHHAHAHAHHA");
        exit(-1);
    }
    for (int i = 0; i < size; i++)
    {
        *(new_massive++) = *(massive++);
    }
    new_massive -= size;
    return new_massive;
    
} // complite + tests

int mod(int n, int m)
{
    return n - m * (n / m);
} // compite + tests

int diff(int a, int b)
{
    if (a > b)
    {
        return a - b;
    }
    else
    {
        return b - a;
    }
}

int **append(int **massive, int *size, int *value)
{
    int **new_massive = (int **)malloc(sizeof(int *) * (*size + 1));
    if (!new_massive)
    {
        printf("HEHEHEHEHEHE");
        exit(-1);
    }
    for (int i = 0; i < *size; i++)
    {
        *(new_massive++) = *(massive++);
    }
    *new_massive = value;
    new_massive -= *size;
    (*size)++;
    return new_massive;
} // complite + tests

int *pop(int **massive, int *size)
{
    int *last_element = massive[--(*size)];
    int **new = (int **)malloc(sizeof(int *) * (*size));
    for (int i = 0; i < *size; i++)
    {
        *(new++) = *(massive++);
    }
    free(*massive);
    new -= *size;
    return last_element;
} // complite and tests

int sum(int *massive, int size)
{
    int result = 0;
    for (int i = 0; i < size; i++)
    {
        result += *(massive++);
    }
    return result;
} // complite and tests

int **read_numbers(char *filename, int *N, int *L, int *K)
{
    FILE *p = fopen(filename, "r");
    if (p == NULL)
    {
        perror("Error occured while opening data28.txt");
        return NULL;
    }
    fscanf(p, "%d %d %d", N, L, K);
    int **positions = (int **)malloc(sizeof(int *) * (*K));

    for (int i = 0; i < *K; i++)
    {
        int *t = malloc(sizeof(int) * 2);
        fscanf(p, "%d %d", &t[0], &t[1]);
        // printf("(%d, %d)\n", t[0], t[1]);
        positions[i] = t;
    }
    fclose(p);
    return positions;
}

void writer(int **positions, int size)
{
    FILE *fp = fopen("output.txt", "a");
    for (int n = 0; n < size; n++)
    {
        int t1 = positions[n][0];
        int t2 = positions[n][1];
        fprintf(fp, "(%d, %d) ", t1, t2);
    }
    fputc('\n', fp);
    fclose(fp);
}

void verification_file()
{
    FILE *p = fopen("output.txt", "r");
    if (p == NULL)
    {
        FILE *fp = fopen("output.txt", "w");
        fprintf(fp, "no solutions");
        fclose(fp);
    }
}

int pos(int x2, int y2, int type, int **positions, int size)
{
    for (int p = 0; p < size; p++)
    {
        int x1 = positions[p][0];
        int y1 = positions[p][1];
        switch (type)
        {
        case 1: // ферзь
            if ((x2 == x1) || (y1 == y2) || (diff(x1, x2) == diff(y1, y2)))
            {
                return False;
            }
            break;
        case 2: // конь
            if (((diff(x1, x2) == 1) && (diff(y2, y1) == 2)) ||
                ((diff(x1, x2) == 2) && (diff(y2, y1) == 1)))
            {
                return False;
            }
        case 3: // слон
            if (diff(x1, x2) == diff(y1, y2))
            {
                return False;
            }
        case 4: // ладья
            if ((x1 == x2) || (y1 == y2))
            {
                return False;
            }
        case 5: // король
            if (diff(x1, x2) < 2 && diff(y1, y2) < 2)
            {
                return False;
            }
        }
    }
    return True;
}