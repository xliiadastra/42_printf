/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_decimal.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichoi <yichoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 19:32:05 by yichoi            #+#    #+#             */
/*   Updated: 2021/12/16 21:00:15 by yichoi           ###   ########.fr       */
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
	char	*dem_string;
	int		index;

	dem_string = (char *)malloc(sizeof(char) * count + 1);
	if (!dem_string)
		return (0);
	if (n < 0)
	{
		dem_string[0] = '-';
		n = -n;
	}
	dem_string[count] = '\0';
	index = count;
	while (n)
	{
		dem_string[--index] = n % 10;
		n /= 10;
	}
	write(1, dem_string, count);
	free(dem_string);
	return (count);
}

int	ft_write_decimal(va_list ap)
{
	int		decimal;
	int		count;
	int		len;

	decimal = va_arg(ap, int);
	if (decimal == -2147483648)
		return (write(1, "-2147483648", 11));
	count = nu_count(decimal);
	len = print_num(decimal, count);
	return (len);
}
