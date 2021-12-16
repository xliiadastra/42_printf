/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_pointer_hex.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichoi <yichoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 19:12:01 by yichoi            #+#    #+#             */
/*   Updated: 2021/12/15 21:26:34 by yichoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	nu_count(unsigned long long n)
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

int	ft_write_pointer_hex(va_list ap, (*f)(char *))
{
	unsigned long long	address;
	char				*add_table;
	char				add_string[19];
	int					index;
	int					count;

	address = va_arg(ap, long long);
	add_table = "0123456789abcdef";
	add_string[0] = '0';
	add_string[1] = 'x';
	count = nu_count(address);
	add_string[count + 1] = '\0';
	index = 1 + count;
	while (count-- && index >= 2)
	{
		add_string[index--] = add_string[address % 16];
		address /= 16;
	}
	return (write(1, add_string, ft_strlen(add_string)));
}
*f