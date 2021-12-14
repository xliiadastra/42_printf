/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichoi <yichoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 15:29:11 by yichoi            #+#    #+#             */
/*   Updated: 2021/12/14 20:40:37 by yichoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_printf(const char *format_string, ...)
{
	va_list	ap;
	char	*option;
	int		count;
	int		n;
	int		(*func_type[9])(va_list);

	ft_format_specifier(func_type);
	count = 0;
	option = "cspdiuxX%";
	n = sizeof(option) / sizeof(char);
	va_start(ap, format_string);
	while (*format_string)
	{
		if (*format_string != '%')
			write(1, format_string, 1);
		else
			va_arg(ap, );
		format_string++;
		count++;
	}
	va_end(ap);
	return (count);
}
