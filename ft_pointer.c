/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyasuko <pyasuko@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 20:07:44 by pyasuko           #+#    #+#             */
/*   Updated: 2021/01/26 20:03:36 by pyasuko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_p_func(t_flags flag, size_t str_len, char *p)
{
	int len;

	len = 0;
	if (flag.minus == 1)
	{
		len += ft_putstr_len("0x", 2);
		len += ft_print_str(p, flag, str_len);
	}
	len += ft_print_width(flag.width, str_len + 2, 0);
	if (flag.minus == 0)
	{
		len += ft_putstr_len("0x", 2);
		len += ft_print_str(p, flag, str_len);
	}
	return (len);
}

int		ft_pointer(unsigned long long n, t_flags flag)
{
	int		len;
	char	*p;
	size_t	str_len;

	len = 0;
	if (flag.dot == 0 && n == 0)
	{
		len += ft_putstr_len("0x", 2);
		return (len += ft_print_width(flag.width, 0, 1));
	}
	if (flag.dot >= 0 && n == 0)
		flag.width -= 1;
	p = ft_itoa_base(n, 16);
	p = ft_str_tolower(p);
	str_len = ft_strlen(p);
	if ((size_t)flag.dot < str_len)
		flag.dot = str_len;
	len += ft_p_func(flag, str_len, p);
	free(p);
	return (len);
}

char	*ft_str_tolower(char *p)
{
	int i;

	i = 0;
	while (p[i])
	{
		p[i] = ft_tolower(p[i]);
		i++;
	}
	return (p);
}
