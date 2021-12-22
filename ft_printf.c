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

static const char	g_option[9] = {'c', 's', 'p', 'd', 'i', 'u', 'x', 'X', '%'};
//static const char	g_flag[6] = "# +-0.";

//static int parse_flag()
//{
//	return ();
//}

void	parse_flag(t_flag_option *fo, flag_operations *fos, const char flag, int index)
{
	sibal;
}

static char	*to_find(FUNC_TYPE *operations, const char *format, va_list ap, ssize_t *count)
{
	int	i;
	int	n;
	int check;
	t_flag_option fo;
	flag_operations fos;

	i = 0;
	n = sizeof(g_flag) / sizeof(char);
	while (*format)
	{
		i = 0;
		check = 0;
		while (i < n)
		{
			if (g_flag[i] == *format)
			{

				check = 1;
				break ;
			}
			i++;
		}
		if (!check)
			break ;
		format++;
	}
//	count = parse_flag();
	i = 0;
	n = sizeof(g_option) / sizeof(char);
	while (i < n && *format)
	{
		if (g_option[i]  == *format)
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
//	const char		*option;
	ssize_t			count;
	FUNC_TYPE		operations[9];

	va_start(ap, format_string);
	ft_format_specifier(operations);
	count = 0;
//	option = "cspdiuxX%";
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
