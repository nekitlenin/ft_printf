/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyasuko <pyasuko@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 19:05:37 by pyasuko           #+#    #+#             */
/*   Updated: 2021/01/26 17:31:56 by pyasuko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_char(char c, t_flags flag)
{
	int len;

	len = 0;
	if (flag.minus == 1)
		ft_putchar(c);
	len = ft_print_width(flag.width, 1, 0);
	if (flag.minus == 0)
		ft_putchar(c);
	return (len + 1);
}

int	ft_string(char *string, t_flags flag)
{
	int		len;
	int		str_len;
	char	*sub;

	len = 0;
	if (!string)
		string = "(null)";
	str_len = ft_strlen(string);
	sub = ft_strdup(string);
	if (flag.dot >= 0 && (int)flag.dot > str_len)
		flag.dot = str_len;
	if (flag.minus == 1)
		len += ft_print_str(sub, flag, str_len);
	if (flag.dot >= 0)
		len += ft_print_width(flag.width, flag.dot, 0);
	else
		len += ft_print_width(flag.width, str_len, 0);
	if (flag.minus == 0)
		len += ft_print_str(sub, flag, str_len);
	free(sub);
	return (len);
}
