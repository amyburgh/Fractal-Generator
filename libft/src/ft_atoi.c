/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amyburgh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 23:22:15 by amyburgh          #+#    #+#             */
/*   Updated: 2018/06/21 20:22:20 by amyburgh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "macros.h"

int	ft_atoi(const char *str)
{
	long long	nb;
	int			flag;

	nb = 0;
	flag = 1;
	while (ALLSPACES(*str))
		str++;
	flag = (*str == '-') ? -1 : 1;
	str = (*str == '+' || *str == '-') ? str + 1 : str;
	while (IS_DIGIT(*str))
		nb = nb * 10 + (*str++ - 48);
	return ((int)(nb * flag));
}
