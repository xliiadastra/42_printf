/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichoi <yichoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 15:29:11 by yichoi            #+#    #+#             */
/*   Updated: 2021/12/21 15:40:01 by yichoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*to_find(FUNC_TYPE *operations, const char *format, va_list ap, ssize_t *count)
{
	int	i;
	int	n;
	int check;
    const char		*option;

    i = 0;
    option = "cspdiuxX%";
    n = sizeof(operations) / sizeof(char);
    while (i < n && *format)
	{
		if (option[i] == *format)
		{
			*count = *count + (*(operations[i]))(ap);
			break ;
		}
		i++;
	}
	return ((char *)format);
}

int	ft_printf(const char *format_string, ...)
{
	va_list			ap;
	ssize_t			count;
	FUNC_TYPE		operations[9];

	va_start(ap, format_string);
	ft_format_specifier(operations);
	count = 0;
	while (*format_string)
	{
		if (*format_string != '%' && ++count)
			write(1, format_string++, 1);
		else
		{
			format_string = (const char *)to_find(operations, ++format_string, ap, &count);
			format_string++;
		}
	}
	va_end(ap);
	return (count);
}