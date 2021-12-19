/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_lower_hex.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichoi <yichoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 21:25:03 by yichoi            #+#    #+#             */
/*   Updated: 2021/12/16 21:51:16 by yichoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	hexnu_count(int n)
{
	int	count;

	count = 0;
	if (n == 0)
		count++;
	while (n)
	{
		n /= 16;
		count++;
	}
	return (count);
}

static int	print_hex(int n, int count)
{
	char	*hex_string;
	char	*hex_table;
	int		index;

	hex_table = "0123456789abcdef";
	hex_string = (char *)malloc(sizeof(char) * (count + 1));
	if (!hex_string)
		return (0);
	hex_string[count] = '\0';
	index = count;
	while (n)
	{
		hex_string[--index] = hex_table[n % 16];
		n /= 16;
	}
	write(1, hex_string, count);
	free(hex_string);
	return (count);
}

int	ft_write_lower_hex(va_list ap)
{
	int	lower_hex;
	int	count;
	int	len;

	lower_hex = va_arg(ap, int);
	count = hexnu_count(lower_hex);
	len = print_hex(lower_hex, count);
	return (len);
}
