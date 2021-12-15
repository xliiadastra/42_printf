/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_specifier.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichoi <yichoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 19:28:49 by yichoi            #+#    #+#             */
/*   Updated: 2021/12/15 17:42:22 by yichoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_format_spcifier(*(f[])(va_list))
{
	*(f[0]) = ft_write_character;
	*(f[1]) = ft_write_string;
	*(f[2]) = ft_write_pointer_hex;
	*(f[3]) = ft_write_decimal;
	*(f[4]) = ft_write_integer;
	*(f[5]) = ft_write_unsigned;
	*(f[6]) = ft_write_lower_hex;
	*(f[7]) = ft_write_upper_hex;
	*(f[8]) = ft_write_percent;
}
