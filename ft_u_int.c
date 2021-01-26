/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_u_int.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyasuko <pyasuko@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 14:02:09 by pyasuko           #+#    #+#             */
/*   Updated: 2021/01/26 15:11:35 by pyasuko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_u_print(char *num_str, t_flags flag, size_t str_len)
{
	int	len;

	len = 0;
	if (flag.dot >= 0)
		len += ft_print_width(flag.dot - 1, str_len - 1, 1);
	len += ft_putstr_len(num_str, str_len);
	return (len);
}

static int	ft_check_flag_u_int(char *num_str, t_flags flag)
{
	int		len;
	size_t	str_len;

	len = 0;
	str_len = ft_strlen(num_str);
	if (flag.minus == 1)
		len += ft_u_print(num_str, flag, str_len);
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
		len += ft_u_print(num_str, flag, str_len);
	return (len);
}

int			ft_u_int(unsigned int num, t_flags flag)
{
	int		len;
	char	*num_str;

	len = 0;
	if (num == 0 && flag.dot == 0)
	{
		len += ft_print_width(flag.width, 0, 0);
		return (len);
	}
	num_str = ft_itoa_base(num, 10);
	len += ft_check_flag_u_int(num_str, flag);
	free(num_str);
	return (len);
}
