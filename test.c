#include "libftprintf.h"

int	nu_count(unsigned long long n)
{
	int count;

	count = 0;
	if (n == 0)
		count++;
	while (n)
	{
		n /= 16;
		count++;
	}
	return count;
}

int main()
{
	unsigned long long	address;
	char				*add_table;
	char				add_string[19];
	int					index;
	int					count;

	//address = va_arg(ap, long long);
	address = 140732699335280;
	add_table = "0123456789abcdef";
	add_string[0] = '0';
	add_string[1] = 'x';
	count = nu_count(address);
	add_string[18] = '\0';
	index = 17;
	while (count-- && index >= 2)
	{
		add_string[index--] = add_string[address % 16];
		address /= 16;
	}
	write(1, add_string, ft_strlen(add_string));
}
