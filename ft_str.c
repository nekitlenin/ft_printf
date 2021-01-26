/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyasuko <pyasuko@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 01:48:29 by pyasuko           #+#    #+#             */
/*   Updated: 2021/01/25 21:01:45 by pyasuko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_str(char *string, va_list args)
{
	size_t	len;
	size_t	i;
	t_flags	flag;

	len = 0;
	i = 0;
	while (string[i])
	{
		flag = ft_init_flag();
		if (string[i] == '%' && string[i + 1])
		{
			i++;
			i = ft_check_flag(string, i, &flag, args);
			if (ft_istype(string[i]))
				len += ft_pars_type((char)flag.type, flag, args);
		}
		else if (string[i] == '%' && string[i + 1] == '%')
			len += ft_putchar(string[i]);
		else
			len += ft_putchar(string[i]);
		i++;
	}
	return (len);
}
