/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgermai <thgermai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 11:15:05 by thgermai          #+#    #+#             */
/*   Updated: 2019/12/01 10:33:25 by thgermai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>

# define HEXADECIMAL "0123456789ABCDEF"
# define VALID_VALUE "cspdiuxX%"

int			ft_printf(const char *str, ...);
int			nb_args(const char *str);
int			next_arg_index(const char *str);
int			ft_define_type(const char *str);
char		*fill_arg(char *output, va_list args, int type);

#endif
