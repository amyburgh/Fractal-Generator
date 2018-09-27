/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amyburgh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 23:22:41 by amyburgh          #+#    #+#             */
/*   Updated: 2018/05/02 20:38:38 by amyburgh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strstr(const char *s1, const char *s2)
{
	const char	*lrgstr;
	const char	*smlstr;

	if (!*s1 && !*s2)
		return ((char *)s1);
	while (*s1)
	{
		lrgstr = s1;
		smlstr = s2;
		while (*smlstr && *s1 && *smlstr == *s1)
		{
			smlstr++;
			s1++;
		}
		if (!*smlstr)
			return ((char *)lrgstr);
		s1 = lrgstr + 1;
	}
	return (NULL);
}
