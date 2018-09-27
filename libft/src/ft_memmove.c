/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amyburgh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 14:04:31 by amyburgh          #+#    #+#             */
/*   Updated: 2018/05/02 20:17:42 by amyburgh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	const char	*s1;
	char		*s2;

	s1 = (const char *)src;
	s2 = (char *)dst;
	if (s1 < s2)
	{
		s1 += n - 1;
		s2 += n - 1;
		while (n--)
			*s2-- = *s1--;
	}
	else
	{
		while (n--)
			*s2++ = *s1++;
	}
	return (dst);
}
