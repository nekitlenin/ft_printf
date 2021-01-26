/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyasuko <pyasuko@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 19:05:43 by pyasuko           #+#    #+#             */
/*   Updated: 2021/01/26 19:04:51 by pyasuko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_check_flag_int(char *num_str, int tmp, t_flags flag)
{
	int		len;
	size_t	str_len;

	len = 0;
	str_len = ft_strlen(num_str);
	if (flag.minus == 1)
		len += ft_print_int(num_str, tmp, flag, str_len);
	if (flag.dot >= 0 && (size_t)flag.dot < str_len)
		flag.dot = str_len;
	if (flag.dot >= 0)
	{
		flag.width -= flag.dot;
		len += ft_print_width(flag.width, 0, 0);
	}
	else if (flag.minus == 1 && flag.null == 1)
	{
		flag.null = 0;
		len += ft_print_width(flag.width, str_len, flag.null);
	}
	else
		len += ft_print_width(flag.width, str_len, flag.null);
	if (flag.minus == 0)
		len += ft_print_int(num_str, tmp, flag, str_len);
	return (len);
}

static int	ft_check_min(char **num_str, int tmp, t_flags flag)
{
	int len;

	len = 0;
	if (flag.null == 1 && flag.dot < 0 && tmp == -2147483648)
		len += ft_check_flag_int(*num_str + 1, tmp, flag);
	else
		len += ft_check_flag_int(*num_str, tmp, flag);
	return (len);
}

int			ft_p_int(int n, t_flags flag)
{
	int		len;
	int		tmp;
	char	*num_str;

	len = 0;
	tmp = n;
	if (n == 0 && flag.dot == 0)
	{
		len += ft_print_width(flag.width, 0, 0);
		return (len);
	}
	if (n < 0 && (flag.dot >= 0 || flag.null == 1))
	{
		if (flag.dot < 0 && flag.null == 1)
			ft_putchar('-');
		n *= -1;
		flag.width--;
		flag.null = 1;
		len++;
	}
	num_str = ft_itoa(n);
	len += ft_check_min(&num_str, tmp, flag);
	free(num_str);
	return (len);
}
