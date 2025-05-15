#include <stdio.h>

void swap(int *a, int *b)
{
    *a ^= *b; // a = a ^ b
    *b ^= *a; // b = b ^ a = a ^ b
    *a ^= *b; // a = a ^ b
}

int main()
{
    // int a = 10;
    // int b = 20;
    // printf("before swap: a = %d, b = %d\n", a, b);
    // swap(&a, &b);
    // printf("after swap: a = %d, b = %d\n", a, b);
    // return 0;
    // int i = 0xFFFFFFFF;
    // i = i << 32;
    // printf("i = %d\n", i);
    // return 0;

    int n = 10;
    for (int i = n - 1; i - sizeof(char) >= 0; i--)
        printf("i: 0x%x\n", i);
}
