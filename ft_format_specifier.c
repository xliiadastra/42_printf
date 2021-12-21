/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_specifier.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichoi <yichoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 19:28:49 by yichoi            #+#    #+#             */
/*   Updated: 2021/12/21 15:38:50 by yichoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_format_specifier(int (*f[])(va_list))
{
    f[0] = ft_write_character;
    f[1] = ft_write_string;
    f[2] = ft_write_address;
    f[3] = ft_write_decimal;
    f[4] = ft_write_integer;
    f[5] = ft_write_unsigned;
    f[6] = ft_write_lower_hex;
    f[7] = ft_write_upper_hex;
    f[8] = ft_write_percent;
}
