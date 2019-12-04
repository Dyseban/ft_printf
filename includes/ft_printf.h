/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgermai <thgermai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 11:15:05 by thgermai          #+#    #+#             */
/*   Updated: 2019/12/04 14:45:48 by thgermai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>

# define HEXADECIMAL "0123456789abcdef"
# define VALID_VALUE "cspdiuxX%"
# define VALID_FLAGS "-.0*"
# define LEFT 1
# define RIGHT 0

typedef struct	s_param
{
	int		specifier;
	int		width;
	int		precision;
	int		justify;
	char	fill;
}				t_param;

int			ft_printf(const char *str, ...);
int			next_arg_index(const char *str);
const char	*ft_refresh_str(const char *str);
int			define_type(char c);

t_param		*parcing_param(const char *str);

char		*pf_fill_char(va_list args, char *output, t_param *param);
char		*pf_fill_str(va_list args, char *output, t_param *param);
char		*pf_fill_add(va_list args, char *output, t_param *param);
char		*pf_fill_deci(va_list args, char *output, t_param *param);
char		*pf_fill_int(va_list args, char *output, t_param *param);
char		*pf_fill_unsi(va_list args, char *output, t_param *param);
char		*pf_fill_hexa(va_list args, char *output, t_param *param);
char		*pf_fill_hexa_caps(va_list args, char *output, t_param *param);
char		*pf_fill_modulo(va_list args, char *output, t_param *param);

char		*fill_width_left(char *str, t_param *param);
char		*fill_width_right(char *str, t_param *param);

#endif
