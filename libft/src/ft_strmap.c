/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amyburgh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 23:55:12 by amyburgh          #+#    #+#             */
/*   Updated: 2018/05/24 19:18:37 by amyburgh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*str;
	size_t	n;

	if (!s)
		return (NULL);
	n = ft_strlen(s);
	str = ft_strnew(n);
	if (!str)
		return (NULL);
	while (*s)
		*str++ = f(*s++);
	return (str - n);
}
