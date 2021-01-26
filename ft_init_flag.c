/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_flag.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyasuko <pyasuko@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 14:38:09 by pyasuko           #+#    #+#             */
/*   Updated: 2021/01/25 21:01:23 by pyasuko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flags	ft_init_flag(void)
{
	t_flags flag;

	flag.minus = 0;
	flag.null = 0;
	flag.width = 0;
	flag.type = 0;
	flag.star = 0;
	flag.dot = -1;
	return (flag);
}
