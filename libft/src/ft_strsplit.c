/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amyburgh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 00:25:13 by amyburgh          #+#    #+#             */
/*   Updated: 2018/05/24 19:29:51 by amyburgh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "macros.h"
#include "libft.h"

static size_t	ft_wordcount_mod(const char *s, char c)
{
	size_t	count;
	size_t	state;

	count = 0;
	state = FALSE;
	while (*s)
	{
		if (*s == c)
			state = FALSE;
		else if (state == FALSE)
		{
			state = TRUE;
			count++;
		}
		s++;
	}
	return (count);
}

char			**ft_strsplit(char const *s, char c)
{
	size_t		i;
	char		**tab;
	char		*str;

	if (!s || !c)
		return (NULL);
	i = 0;
	tab = (char **)malloc(sizeof(char *) * (ft_wordcount_mod(s, c) + 1));
	if (!tab)
		return (NULL);
	while (*s)
	{
		while (*s == c)
			s++;
		str = (char *)s;
		while (*s && *s != c)
			s++;
		if (str != s)
		{
			tab[i] = ft_strndup(str, s - str);
			i++;
		}
	}
	tab[i] = NULL;
	return (tab);
}
