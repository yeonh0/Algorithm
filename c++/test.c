#include <stdio.h>

int multi(int a, int b) {
    return a * b;
}

int main() {
    int num1 = 5, num2 = 3, result;
    int (*fptr)(int, int) = NULL;
    fptr = multi;
    result = fptr(num1, num2);
    printf("Result : %d\n", result);

    return 0;
}
