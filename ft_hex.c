/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyasuko <pyasuko@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 19:04:34 by pyasuko           #+#    #+#             */
/*   Updated: 2021/01/26 19:39:07 by pyasuko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_check_flag_hex(char *hex, t_flags flag)
{
	size_t	str_len;
	int		len;

	len = 0;
	str_len = ft_strlen(hex);
	if (flag.minus == 1)
		len += ft_print_hex(hex, flag, str_len);
	if (flag.dot >= 0 && (size_t)flag.dot < str_len)
		flag.dot = str_len;
	if (flag.dot >= 0)
	{
		flag.width -= flag.dot;
		len += ft_print_width(flag.width, 0, 0);
	}
	else
		len += ft_print_width(flag.width, str_len, flag.null);
	if (flag.minus == 0)
		len += ft_print_hex(hex, flag, str_len);
	return (len);
}

int			ft_hex(unsigned int n, int flg, t_flags flag)
{
	int		len;
	char	*hex;

	len = 0;
	if (flag.dot == 0 && n == 0)
	{
		len += ft_print_width(flag.width, 0, 0);
		return (len);
	}
	hex = ft_itoa_base((unsigned long long)n, 16);
	if (flg == 1)
		hex = ft_str_tolower(hex);
	len += ft_check_flag_hex(hex, flag);
	free(hex);
	return (len);
}
