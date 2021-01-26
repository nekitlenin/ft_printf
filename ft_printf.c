/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyasuko <pyasuko@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 20:09:54 by pyasuko           #+#    #+#             */
/*   Updated: 2021/01/26 13:37:48 by pyasuko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *input, ...)
{
	char	*string;
	va_list	args;
	int		input_len;

	input_len = 0;
	if (!(string = ft_strdup(input)))
		return (-1);
	va_start(args, input);
	input_len += ft_str(string, args);
	va_end(args);
	free(string);
	return (input_len);
}
