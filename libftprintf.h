/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichoi <yichoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 15:30:08 by yichoi            #+#    #+#             */
/*   Updated: 2021/12/16 21:38:21 by yichoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIBFTPRINTF_H
# define FT_LIBFTPRINTF_H

#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>

# define ERR	-1

typedef int	(*FUNC_TYPE)(va_list);

int     ft_printf(const char *format_string, ...);
void    ft_format_specifier(int (*f[])(va_list));

int     ft_write_character(va_list ap);
int     ft_write_string(va_list ap);
int     ft_write_pointer_hex(va_list ap);
int		ft_write_decimal(va_list ap);
int		ft_write_integer(va_list ap);
int		ft_write_unsigned(va_list ap);
int		ft_write_lower_hex(va_list ap);
int		ft_write_upper_hex(va_list ap);
int		ft_write_percent(va_list ap);

size_t	ft_strlen(char *str);

#endif
