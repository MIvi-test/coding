#include <stdio.h>
#include <float.h>

int main() {
    printf("Максимальное значение long double: %Le\n", LDBL_MAX);
    printf("Минимальное положительное значение long double: %Le\n", LDBL_MIN);
    
    return 0;
}
