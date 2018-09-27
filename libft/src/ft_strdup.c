/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amyburgh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 23:05:13 by amyburgh          #+#    #+#             */
/*   Updated: 2018/06/21 20:55:40 by amyburgh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*str_dup;
	char	*begin;

	str_dup = (char *)malloc(sizeof(*str_dup) * (ft_strlen(s1) + 1));
	if (!str_dup)
		return (NULL);
	begin = str_dup;
	while (*s1)
		*str_dup++ = *s1++;
	*str_dup = '\0';
	return (begin);
}
