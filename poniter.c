#include <stdio.h>
#include <strings.h>

int main(void)
{
    int a = 42;
    int *b = &a;

    // printf("a = %d\n", ++a);
    // printf("a = %d\n", a);
    // printf("&a = %p\n", &a);
    // printf("b = %p\n", b);
    // printf("&b = %p\n", &b);
    // printf("*b = %d\n", *b);

    char str[100];
    char *ptr;
    char target[100] = "0123456789";
    char *p_t;

    ptr = NULL;
    ptr = target;
    
    while (*ptr)
    {
        // *ptr++
        // 1 -- *ptr read value inside address that ptr point to
        // 2 -- ++ =>>> ptr = ptr +1, increment value inside ptr 1,
        printf("before addr value in ptr = %p\n", ptr++);
        // printf("print value in *ptr++ = %c\n", ptr++);
        printf("after addr value in ptr  = %p\n", ptr);
        printf("address of ptr = %p\n\n", &ptr);
    }
}