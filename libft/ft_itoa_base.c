/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgermai <thgermai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 10:49:36 by thgermai          #+#    #+#             */
/*   Updated: 2019/12/01 12:45:12 by thgermai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_itoa_base(int n, char *base)
{
	char		*str;

	if (n == -2147483648)
		return (str = ft_strdup("-80000000"));
	if (!(str = (char *)ft_calloc(sizeof(char), 2)))
		return (NULL);
	if (n < 0)
	{
		str[0] = '-';
		str[1] = '\0';
		str = ft_strjoin(str, ft_itoa_base(-n, base));
	}
	else if (n >= (int)ft_strlen(base))
	{
		free(str);
		str = ft_strjoin(ft_itoa_base(n / ft_strlen(base), base),
			ft_itoa_base(n % ft_strlen(base), base));
	}
	else if (n < (int)ft_strlen(base) && n >= 0)
	{
		str[0] = base[n];
		str[1] = '\0';
	}
	return (str);
}
