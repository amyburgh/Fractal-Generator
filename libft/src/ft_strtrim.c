/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amyburgh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 23:25:00 by amyburgh          #+#    #+#             */
/*   Updated: 2018/05/24 19:20:46 by amyburgh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "macros.h"

char	*ft_strtrim(char const *s)
{
	const char	*end;

	if (!s)
		return (NULL);
	end = s + ft_strlen(s) - 1;
	while (SPACES1(*s))
		s++;
	if (!*s)
		return (ft_strnew(0));
	while (SPACES1(*end))
		end--;
	return (ft_strsub(s, 0, end - s + 1));
}
