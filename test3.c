#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	ft_putx(unsigned int u)
{
	char	a[8];
	int		i;
	int		count;

	count = 0;
	i = 8;
	if (u == 0 && ++count)
		write(1, "0", 1);
	while (u)
	{
		a[--i] = "0123456789abcdef"[u % 16];
		u /= 16;
		++count;
	}
	write(1, &a[i], 8 - i);
	return (count);
}

int main()
{
	int a = 3165135756;
	printf("%x", a);
	ft_putx(a);
}
