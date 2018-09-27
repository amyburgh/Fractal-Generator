/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amyburgh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 21:01:56 by amyburgh          #+#    #+#             */
/*   Updated: 2018/06/21 20:38:31 by amyburgh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*fresh;

	fresh = (void *)malloc(size);
	if (!fresh)
		return (NULL);
	ft_bzero(fresh, size);
	return (fresh);
}
