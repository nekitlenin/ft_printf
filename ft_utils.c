/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyasuko <pyasuko@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 19:05:34 by pyasuko           #+#    #+#             */
/*   Updated: 2021/01/26 19:37:54 by pyasuko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_width(int width, int str_len, int null)
{
	int len;

	len = 0;
	while (width - str_len > 0)
	{
		if (null)
			ft_putchar('0');
		else
			ft_putchar(' ');
		width--;
		len++;
	}
	return (len);
}

int	ft_print_str(char *string, t_flags flag, int str_len)
{
	int len;

	len = 0;
	if (flag.dot >= 0)
	{
		len += ft_print_width(flag.dot, str_len, 0);
		len += ft_putstr_len(string, flag.dot);
	}
	else
		len = ft_putstr_len(string, str_len);
	return (len);
}

int	ft_print_int(char *sub, int tmp, t_flags flag, size_t str_len)
{
	int len;

	len = 0;
	if (flag.dot >= 0 && tmp < 0)
		ft_putchar('-');
	if (flag.dot >= 0 && tmp == -2147483648)
	{
		len += ft_print_width(flag.dot - 1, str_len - 1, 1);
		len += ft_putstr_len(sub + 1, str_len);
	}
	else if (flag.dot >= 0)
	{
		len += ft_print_width(flag.dot - 1, str_len - 1, 1);
		len += ft_putstr_len(sub, str_len);
	}
	else
		len += ft_putstr_len(sub, str_len);
	return (len);
}

int	ft_print_pointer(char *pointer, t_flags flag, size_t str_len)
{
	int len;

	len = 0;
	len += ft_putstr_len("0x", 2);
	if (flag.dot >= 0)
	{
		len += ft_print_width(flag.dot, str_len, 1);
		len += ft_putstr_len(pointer, flag.dot);
	}
	else
		len += ft_putstr_len(pointer, str_len);
	return (len);
}

int	ft_print_hex(char *hex, t_flags flag, size_t str_len)
{
	int len;

	len = 0;
	if (flag.dot >= 0)
		len += ft_print_width(flag.dot - 1, str_len - 1, 1);
	len += ft_putstr_len(hex, str_len);
	return (len);
}
