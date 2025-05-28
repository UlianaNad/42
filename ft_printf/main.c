#include "ft_printf.h"
#include <stdio.h>

int main(void)
{
	int count1, count2;
	char *str = "Hello";
	int num = -42;
	unsigned int u_num = 4294967295;
	void *ptr = str;

	// %c
	count1 = ft_printf("My char: %c\n", 'A');
	count2 = printf("Real char: %c\n\n", 'A');

	// %s
	ft_printf("My string: %s\n", str);
	printf("Real string: %s\n\n", str);

	// %p
	ft_printf("My pointer: %p\n", ptr);
	printf("Real pointer: %p\n\n", ptr);

	// %d %i
	ft_printf("My int: %d\n", num);
	printf("Real int: %d\n\n", num);

	// %u
	ft_printf("My unsigned: %u\n", u_num);
	printf("Real unsigned: %u\n\n", u_num);

	// %x %X
	ft_printf("My hex lower: %x\n", 255);
	ft_printf("My hex upper: %X\n", 255);
	printf("Real hex lower: %x\n", 255);
	printf("Real hex upper: %X\n\n", 255);

	// %%
	ft_printf("My percent: %%\n");
	printf("Real percent: %%\n\n");

	// Check returned values
	printf("My printf returned: %d\n", count1);
	printf("Real printf returned: %d\n", count2);

	return (0);
}

