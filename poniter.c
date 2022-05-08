#include <stdio.h>

int main(void)
{
    int a = 42;
    int *b = &a;

    printf("a = %d\n", a);
    printf("&a = %p\n", &a);
    printf("b = %p\n", b);
    printf("&b = %p\n", &b);
    printf("*b = %d\n", *b);
}