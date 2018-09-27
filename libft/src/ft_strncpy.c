/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amyburgh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 23:05:09 by amyburgh          #+#    #+#             */
/*   Updated: 2018/05/02 20:27:43 by amyburgh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strncpy(char *dst, const char *src, size_t n)
{
	char	*str;

	str = dst;
	while (n--)
	{
		if (!*src)
		{
			*str++ = '\0';
			continue ;
		}
		*str++ = *src++;
	}
	return (dst);
}
