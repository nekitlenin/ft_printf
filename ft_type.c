/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyasuko <pyasuko@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 18:27:46 by pyasuko           #+#    #+#             */
/*   Updated: 2021/01/26 20:04:05 by pyasuko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_istype(int c)
{
	return ((c == 'c') || (c == 's') || (c == 'i') || (c == 'd') ||
			(c == 'x') || (c == 'X') || (c == 'p') || (c == 'u') || (c == '%'));
}

int	ft_isflag(int c)
{
	return ((c == '-') || (c == '*') || (c == '0') || (c == ' ') || (c == '.'));
}

int	ft_check_flag(char *string, int i, t_flags *flag, va_list args)
{
	while (string[i])
	{
		if (!ft_istype(string[i]) && !ft_isflag(string[i]) &&
			!ft_isdigit(string[i]))
			break ;
		if (string[i] == '0' && flag->width == 0 && flag->minus == 0)
			flag->null = 1;
		if (string[i] == '-')
			*flag = ft_minus(*flag);
		if (string[i] == '*')
			*flag = ft_width(*flag, args);
		if (string[i] == '.')
			i = ft_dot(string, i, flag, args);
		if (ft_isdigit(string[i]))
			*flag = ft_int(string[i], *flag);
		if (ft_istype(string[i]))
		{
			flag->type = string[i];
			break ;
		}
		i++;
	}
	return (i);
}

int	ft_percent(t_flags flag)
{
	int	len;

	len = 0;
	if (flag.minus == 1)
		len += ft_putchar('%');
	len += ft_print_width(flag.width, 1, flag.null);
	if (flag.minus == 0)
		len += ft_putchar('%');
	return (len);
}

int	ft_pars_type(int c, t_flags flag, va_list args)
{
	int len;

	len = 0;
	if (c == '%')
		len += ft_percent(flag);
	else if (c == 'c')
		len += ft_char(va_arg(args, int), flag);
	else if (c == 's')
		len += ft_string(va_arg(args, char *), flag);
	else if (c == 'p')
		len += ft_pointer(va_arg(args, unsigned long long int), flag);
	else if (c == 'd' || c == 'i')
		len += ft_p_int(va_arg(args, int), flag);
	else if (c == 'u')
		len += ft_u_int(va_arg(args, unsigned int), flag);
	else if (c == 'x')
		len += ft_hex(va_arg(args, unsigned int), 1, flag);
	else if (c == 'X')
		len += ft_hex(va_arg(args, unsigned int), 0, flag);
	return (len);
}
