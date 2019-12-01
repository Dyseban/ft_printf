/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_address.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgermai <thgermai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 10:49:36 by thgermai          #+#    #+#             */
/*   Updated: 2019/12/01 17:33:06 by thgermai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_itoa_address(unsigned int n, char *base)
{
	char		*str;

	if (!(str = (char *)ft_calloc(sizeof(char), 2)))
		return (NULL);
	if (n < 0)
	{
		str[0] = '-';
		str[1] = '\0';
		str = ft_strjoin(str, ft_itoa_base(-n, base));
	}
	else if (n >= (unsigned int)ft_strlen(base))
	{
		free(str);
		str = ft_strjoin(ft_itoa_base(n / (unsigned int)ft_strlen(base), base),
			ft_itoa_base(n % (unsigned int)ft_strlen(base), base));
	}
	else if (n < (unsigned int)ft_strlen(base) && n >= 0)
	{
		str[0] = base[n];
		str[1] = '\0';
	}
	return (str);
}
