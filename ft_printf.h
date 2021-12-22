/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichoi <yichoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 15:30:08 by yichoi            #+#    #+#             */
/*   Updated: 2021/12/21 15:44:58 by yichoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>

# define ERR	-1

typedef struct s_flag_option
{
	int flag;
	int type;
	size_t front;
	size_t back;
}	t_flag_option;

typedef enum
{
	hash = 1,
	space = 10,
	plus = 100,
	minus = 1000,
	number = 10000,
	dot = 100000
} flag_operations;

typedef int	(*FUNC_TYPE)(va_list);

int	ft_printf(const char *format_string, ...);
void	ft_format_specifier(int (*f[])(va_list));

int	ft_write_character(va_list ap);
int	ft_write_string(va_list ap);
int	ft_write_address(va_list ap);
int	ft_write_decimal(va_list ap);
int	ft_write_integer(va_list ap);
int	ft_write_unsigned(va_list ap);
int	ft_write_lower_hex(va_list ap);
int	ft_write_upper_hex(va_list ap);
int	ft_write_percent(va_list ap);

size_t	pf_strlen(char *str);

#endif
