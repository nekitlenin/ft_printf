/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyasuko <pyasuko@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 14:56:16 by pyasuko           #+#    #+#             */
/*   Updated: 2021/01/25 21:01:14 by pyasuko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_dot(char *string, int i, t_flags *flag, va_list args)
{
	if (string[++i] == '*')
	{
		flag->dot = va_arg(args, int);
		i++;
	}
	else
	{
		flag->dot = 0;
		while (ft_isdigit(string[i]))
			flag->dot = (flag->dot * 10) + (string[i++] - '0');
	}
	return (i);
}

t_flags	ft_minus(t_flags flag)
{
	flag.null = 0;
	flag.minus = 1;
	return (flag);
}

t_flags	ft_width(t_flags flag, va_list args)
{
	flag.width = va_arg(args, int);
	flag.star = 1;
	if (flag.width < 0)
	{
		flag.width *= -1;
		flag.minus = 1;
	}
	return (flag);
}

t_flags	ft_int(char c, t_flags flag)
{
	if (flag.star == 1)
		flag.width = 0;
	flag.width = (flag.width * 10) + (c - '0');
	return (flag);
}
