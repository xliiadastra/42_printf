/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_integer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichoi <yichoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 19:32:05 by yichoi            #+#    #+#             */
/*   Updated: 2021/12/16 20:58:42 by yichoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	nu_count(int n)
{
	int	count;

	count = 0;
	if (n == 0 || n < 0)
		count++;
	while (n)
	{
		n /= 10;
		count++;
	}
	return (count);
}

static int	print_num(int n, int count)
{
	char	*int_string;
	int		index;

	int_string = (char *)malloc(sizeof(char) * count + 1);
	if (!int_string)
		return (0);
	if (n < 0)
	{
		int_string[0] = '-';
		n = -n;
	}
	int_string[count] = '\0';
	index = count;
	while (n)
	{
		int_string[--index] = n % 10;
		n /= 10;
	}
	write(1, int_string, count);
	free(int_string);
	return (count);
}

int	ft_write_integer(va_list ap)
{
	int		integer;
	int		count;
	int		len;

	integer = va_arg(ap, int);
	if (integer == -2147483648)
		return (write(1, "-2147483648", 11));
	count = nu_count(integer);
	len = print_num(integer, count);
	return (len);
}
