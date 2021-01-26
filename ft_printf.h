/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyasuko <pyasuko@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 22:42:24 by pyasuko           #+#    #+#             */
/*   Updated: 2021/01/26 20:02:22 by pyasuko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct	s_flags
{
	int			type;
	int			width;
	int			dot;
	int			minus;
	int			star;
	int			null;
}				t_flags;

int				ft_printf(const char *input, ...);

int				ft_dot(char *string, int i, t_flags *flag, va_list args);
t_flags			ft_minus(t_flags flag);
t_flags			ft_width(t_flags flag, va_list args);
t_flags			ft_int(char c, t_flags flag);

int				ft_hex(unsigned int n, int flg, t_flags flag);

t_flags			ft_init_flag(void);

int				ft_p_int(int n, t_flags flag);

int				ft_p_func(t_flags flag, size_t str_len, char *p);
int				ft_pointer(unsigned long long n, t_flags flag);
char			*ft_str_tolower(char *p);

int				ft_str(char *string, va_list args);

int				ft_char(char c, t_flags flag);
int				ft_string(char *string, t_flags flag);

int				ft_pars_type(int c, t_flags flag, va_list args);
int				ft_percent(t_flags flag);
int				ft_check_flag(char *string, int i, t_flags *flag, va_list args);
int				ft_isflag(int c);
int				ft_istype(int c);

int				ft_u_int(unsigned int num, t_flags flag);

int				ft_print_width(int width, int str_len, int null);
int				ft_print_str(char *string, t_flags, int str_len);
int				ft_print_int(char *sub, int tmp, t_flags flag, size_t str_len);
int				ft_print_pointer(char *pointer, t_flags s_flags, size_t str_len);
int				ft_print_hex(char *hex, t_flags flag, size_t str_len);

size_t			ft_strlen(const char *str);
int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_tolower(int c);
char			*ft_strdup(const char *s1);
int				ft_putchar(char c);
void			ft_putstr(char const *s);
int				ft_putstr_len(char const *str, int len);
char			*ft_itoa(int n);
char			*ft_itoa_base(unsigned long long number, int base);
size_t			ft_strlcpy(char *dst, const char *src, size_t size);

#endif
