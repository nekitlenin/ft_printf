/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_len.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyasuko <pyasuko@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 20:57:15 by pyasuko           #+#    #+#             */
/*   Updated: 2021/01/26 16:32:10 by pyasuko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_putstr_len(char const *str, int len)
{
	int i;

	i = 0;
	while (str[i] && i < len)
	{
		ft_putchar(str[i]);
		i++;
	}
	return (i);
}
