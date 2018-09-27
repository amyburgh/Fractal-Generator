/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wordcount.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amyburgh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 00:50:21 by amyburgh          #+#    #+#             */
/*   Updated: 2018/05/24 19:33:02 by amyburgh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "macros.h"

size_t	ft_wordcount(const char *s)
{
	size_t	count;
	size_t	state;

	count = 0;
	state = FALSE;
	while (*s)
	{
		if (SPACES1(*s))
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
