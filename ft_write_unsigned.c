/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichoi <yichoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 19:32:05 by yichoi            #+#    #+#             */
/*   Updated: 2021/12/16 21:00:47 by yichoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	nu_count(int n)
{
	int	count;

	count = 0;
	if (n == 0)
		count++;
	while (n)
	{
		n /= 10;
		count++;
	}
	return (count);
}

static int	print_num(unsigned int n, int count)
{
	char	*unsigned_string;
	int		index;

	unsigned_string = (char *)malloc(sizeof(char) * count + 1);
	if (!unsigned_string)
		return (0);
	unsigned_string[count] = '\0';
	index = count;
	while (n)
	{
		unsigned_string[--index] = n % 10;
		n /= 10;
	}
	write(1, unsigned_string, count);
	free(unsigned_string);
	return (count);
}

int	ft_write_unsigned(va_list ap)
{
	unsigned int		unsg_int;
	int					count;
	int					len;

	unsg_int = va_arg(ap, unsigned int);
	count = nu_count(unsg_int);
	len = print_num(unsg_int, count);
	return (len);
}
