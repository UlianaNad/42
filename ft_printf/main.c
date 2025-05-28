#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "libftprintf.h"

void test_ft_putptr(void *ptr)
{
    int my_count;
    int real_count;

    printf("Testing pointer: %p\n", ptr);

    my_count = ft_putptr(ptr);
    write(1, "\n", 1);

    real_count = printf("%p\n", ptr);

    printf("ft_putptr returned: %d\n", my_count);
    printf("printf returned: %d\n", real_count);

    if (my_count == real_count)
        printf("Result: MATCH\n");
    else
        printf("Result: MISMATCH\n");
}

void test_libftprintf()
{
    int count_my, count_real;

    printf("\n--- Test libftprintf ---\n");

    count_my = libftprintf("Char: %c\nString: %s\nPointer: %p\nInt: %d\nUnsigned: %u\n"
                           "Hex lower: %x\nHex upper: %X\nPercent: %%\n",
                           'A', "Hello world", (void*)0x1234abcd, -1234, 4000000000u, 0xdeadbeef, 0xBEEF);
    printf("\n");

    count_real = printf("Char: %c\nString: %s\nPointer: %p\nInt: %d\nUnsigned: %u\n"
                        "Hex lower: %x\nHex upper: %X\nPercent: %%\n",
                        'A', "Hello world", (void*)0x1234abcd, -1234, 4000000000u, 0xdeadbeef, 0xBEEF);

    printf("libftprintf returned: %d\n", count_my);
    printf("printf returned: %d\n", count_real);

    if (count_my == count_real)
        printf("Result: MATCH\n");
    else
        printf("Result: MISMATCH\n");
}

int main(void)
{
    int x = 42;

    test_ft_putptr(NULL);
    test_ft_putptr(&x);
    test_ft_putptr((void*)0x0);
    test_ft_putptr((void*)0x7fff12345678);

    test_libftprintf();

    return 0;
}

