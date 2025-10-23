#include <stdio.h>


int main()
{
    int arr[10];
    scanf_s("%d %d %d %d %d %d %d %d %d %d", &arr[0], &arr[1], &arr[2], &arr[3], &arr[4], &arr[5], &arr[6], &arr[7], &arr[8], &arr[9]);
    // for sum
    int sum = 0;
    for(int i = 0; i < 10; i++)
    {
        sum += arr[i];
    }
    printf("sum = %d\n", sum);
    long long multi = 1;
    for(int i = 0; i < 10; i++)
    {
        multi *= arr[i];
    }
    printf("multi = %d\n", multi);
    int min = ~(1<<31);
        for(int i = 0; i < 10; i++)
    {
        if (arr[i] < min)
        {
            min = arr[i];
        }
    }
    printf("min = %d\n", min);

    int max = 0;
        for(int i = 0; i < 10; i++)
    {
        if (arr[i] > min)
        {
            max = arr[i];
        }
    }
    printf("max = %d\n", max);
    float a = sum%10;
    float avg = sum/10 + a/10;
    printf("avg = %0.01f\n", avg);
    float dist = 99999999999.1;
    int closer; // number, distance
    for(int i = 0; i < 10; i++)
    {
        float distance;
        if ((avg - arr[i]) < 0) 
        {
            distance =  -(avg - arr[i]);
        }
        else 
        {
            distance = avg - arr[i];
        }
        if (distance < dist)
        {
            closer = arr[i];
            dist = distance;
        }
    }
    printf("closer = %d", closer);
}
