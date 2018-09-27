/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcasecmp.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amyburgh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 21:03:04 by amyburgh          #+#    #+#             */
/*   Updated: 2018/09/10 21:36:42 by amyburgh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcasecmp(const char *s1, const char *s2)
{
	unsigned char	*p1;
	unsigned char	*p2;
	int				res;

	p1 = (unsigned char*)s1;
	p2 = (unsigned char*)s2;
	if (p1 == p2)
		return (0);
	while (!(res = ft_tolower(*p1) - ft_tolower(*p2++)))
		if (*p1++ == '\0')
			break ;
	return (res);
}
