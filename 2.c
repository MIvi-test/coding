#include <stdio.h>

void main()
{
    int A[] = {1,1,1,1};
    int B[] = {2,2,2,2};
    printf("%zu\n", &A[0]);
    printf("%zu\n", &B[0]);
    printf("%zu\n", &A[6]);
    printf("%zu\n", &A[4]);

}