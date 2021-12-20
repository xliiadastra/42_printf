#include "libftprintf.h"
#include <stdio.h>

int main()
{
	char	*name = "yichoi";
	int num = 84534654;
	ft_printf("hi my name is %s, %x, %p\n", name, num, &num);
	printf("hi my name is %s, %x, %p\n", name, num, &num);
}
