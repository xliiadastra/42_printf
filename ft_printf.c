/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichoi <yichoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 15:29:11 by yichoi            #+#    #+#             */
/*   Updated: 2021/12/15 17:58:21 by yichoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

//static int parse_flag()
//{
//	return ();
//}

static int	to_find(FUNC_TYPE *operations, const char *option, const char *format, va_list ap)
{
//	const char	*flag;
	int	i;
	int	count;
	int	n;

//	flag = "# +-0.";
//	count = parse_flag();
	i = 0;
	n = sizeof(option) / sizeof(char);
	while (i < n)
	{
		if (option[i]  == *format)
		{
			count = (*(operations[i]))(ap);
			break ;
		}
		i++;
	}
	return (count);
}

int	ft_printf(const char *format_string, ...)
{
	va_list			ap;
	const char		*option;
	ssize_t			count;
	FUNC_TYPE		operations[9];

	va_start(ap, format_string);
	ft_format_specifier(operations);
	count = 0;
	option = "cspdiuxX%";
	while (*format_string)
	{
		if (*format_string != '%')
			write(1, format_string, 1);
		else
			count += to_find(operations, option, format_string + 1, ap);
		format_string++;
		count++;
	}
	va_end(ap);
	return (count);
}
