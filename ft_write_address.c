/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_address.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichoi <yichoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 19:12:01 by yichoi            #+#    #+#             */
/*   Updated: 2021/12/21 15:42:02 by yichoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	hexnu_count(unsigned long long n)
{
	int	count;

	count = 0;
	if (n == 0)
		count++;
	while (n)
	{
		n  /= 16;
		count++;
	}
	return (count);
}

static int      print_hex(unsigned long long n, int count)
{
	char    *hex_string;
	char    *hex_table;
	int             index;

	hex_table = "0123456789abcdef";
	count += 2;
	hex_string = (char *)malloc(sizeof(char) * (count + 1));
	if (!hex_string)
		return (0);
	hex_string[count] = '\0';
	hex_string[0] = '0';
	hex_string[1] = 'x';
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

int     ft_write_address(va_list ap)
{
	unsigned long long	address;
	int			count;
	int			len;

	address = va_arg(ap, long long);
	if (address == 0)
		return (write(1, "0x0", 3));
	count = hexnu_count(address);
	len = print_hex(address, count);
	return (len);
}
