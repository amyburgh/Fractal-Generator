/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amyburgh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 00:34:16 by amyburgh          #+#    #+#             */
/*   Updated: 2018/05/29 00:40:31 by amyburgh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

char	*ft_strnjoin(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	char	*str;
	char	*begin;

	if (!s1 || !s2)
		return (NULL);
	if (!(str = ft_strnew(ft_strlen(s1) + n)))
		return (NULL);
	begin = str;
	i = 0;
	while (*s1)
		*str++ = *s1++;
	while (i < n)
		*str++ = s2[i++];
	return (begin);
}
