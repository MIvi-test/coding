#include <stdio.h>


#define SIZE_MASSIVE 10


int line(int massive[], int size, int wtf); // 123
int bin(int massive[], int size, int wtf);
int line_with_shield(int massive[], int size, int wtf);

int main()
{
    int mas[SIZE_MASSIVE] = {1,2,3,4,5,6,7,8,9.10};
    // printf("%d",line(mas, SIZE_MASSIVE, 2));
    // printf("%d",line_with_shield(mas, SIZE_MASSIVE, 5));
    printf("%d",bin(mas, SIZE_MASSIVE, 5));
    return 0;
}

int line(int massive[], int size, int wtf)
{
    int i = 0;
    while(i < size)
    {
        if(massive[i] == wtf)return i;
        i++;
    }

    return -1;
}
int line_with_shield(int massive[], int size, int wtf)
{
    int last = massive[size];
    massive[size] = wtf;
    int i = 0;
    while(massive[i] != wtf)
    {
        i++;
    }
    
    if(last != wtf)
    {
        massive[size] = last;
        return -1;
    }

}

int bin(int massive[], int size, int wtf)
{
    
    int left = 0;
    int right = size-1;
    int mid;
    int now;
    int count = 0;
    while(count < size)
    {
        now = massive[mid+1];
        if(now == wtf){return mid};
        if (now < wtf){left = mid;}
        else {right = mid;}
        mid = left + (right-left)/2;
        count++;
    }
    return -1
}

