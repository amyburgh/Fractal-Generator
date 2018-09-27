/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amyburgh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 18:06:27 by amyburgh          #+#    #+#             */
/*   Updated: 2018/06/21 20:37:00 by amyburgh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstaddend(t_list **alst, t_list *new)
{
	t_list	*node;

	if (!new)
		return ;
	node = *alst;
	if (alst)
	{
		while (node->next)
			node = node->next;
		node->next = new;
	}
	else
		*alst = new;
}
