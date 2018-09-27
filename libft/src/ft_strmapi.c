/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amyburgh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 16:15:24 by amyburgh          #+#    #+#             */
/*   Updated: 2018/05/24 19:19:07 by amyburgh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	index;
	size_t	n;
	char	*str;

	index = 0;
	if (!s)
		return (NULL);
	n = ft_strlen(s);
	str = ft_strnew(n);
	if (!str)
		return (NULL);
	while (*s)
		*str++ = f(index++, *s++);
	return (str - n);
}
