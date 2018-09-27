/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amyburgh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 21:31:22 by amyburgh          #+#    #+#             */
/*   Updated: 2018/05/02 20:39:27 by amyburgh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (s1[i] && i < len)
	{
		j = 0;
		while (s2[j] && s1[i + j] == s2[j] && (i + j) < len)
			j++;
		if (!s2[j])
			return ((char *)s1 + i);
		i++;
	}
	return (NULL);
}
