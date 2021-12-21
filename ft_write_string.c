/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichoi <yichoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 20:08:52 by yichoi            #+#    #+#             */
/*   Updated: 2021/12/21 15:45:22 by yichoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_write_string(va_list ap)
{
	char	*string;

	string = va_arg(ap, char *);
	if (!string)
		return (write(1, "(null)", 6));
	return (write(1, string, pf_strlen(string)));
}
