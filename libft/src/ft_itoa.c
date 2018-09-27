/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amyburgh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 01:09:39 by amyburgh          #+#    #+#             */
/*   Updated: 2018/06/21 20:36:29 by amyburgh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "macros.h"
#include "libft.h"

char	*ft_itoa(int n)
{
	int		len;
	char	*str;

	if (!n)
		return (ft_strdup("0"));
	if (n == INT_MIN)
		return (ft_strdup(INT_MIN_STR));
	len = ft_digitcount(n);
	len = IS_NEG(n) ? len + 1 : len;
	str = ft_strnew(len);
	if (!str)
		return (NULL);
	if (IS_NEG(n))
	{
		str[0] = '-';
		n = ABS(n);
	}
	while (n)
	{
		str[--len] = n % 10 + '0';
		n /= 10;
	}
	return (str);
}
