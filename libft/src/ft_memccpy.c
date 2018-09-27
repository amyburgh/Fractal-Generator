/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amyburgh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 13:37:28 by amyburgh          #+#    #+#             */
/*   Updated: 2018/05/02 20:16:28 by amyburgh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*str;

	str = (unsigned char *)dst;
	while (n--)
	{
		if (*(unsigned const char*)src == (unsigned char)c)
		{
			*str++ = *(unsigned const char*)src++;
			return (str);
		}
		*str++ = *(unsigned const char*)src++;
	}
	return (NULL);
}
