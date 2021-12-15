/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichoi <yichoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 20:08:52 by yichoi            #+#    #+#             */
/*   Updated: 2021/12/15 19:11:39 by yichoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_write_string(const char *format, va_list ap)
{
	char	*string;

	string = va_arg(ap, char *);
	if (!string)
		return (write(1, "(null)", 6));
	return (write(1, string, ft_strlen(string)));
}
