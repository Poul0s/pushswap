/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psalame <psalame@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 14:55:04 by psalame           #+#    #+#             */
/*   Updated: 2023/11/18 23:05:53 by psalame          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_pile(t_pile *pile)
{
	int		tmp;
	size_t	rank_tmp;
	size_t	i;

	if (!pile || pile->size <= 1)
		return ;
	tmp = pile->data[pile->size - 1];
	rank_tmp = pile->rank[pile->size - 1];
	i = pile->size - 1;
	while (i > 0)
	{
		pile->data[i] = pile->data[i - 1];
		pile->rank[i] = pile->rank[i - 1];
		i--;
	}
	pile->data[0] = tmp;
	pile->rank[0] = rank_tmp;
}

void	rotate_pile_revert(t_pile *pile)
{
	int		tmp;
	ssize_t	rank_tmp;
	size_t	i;

	if (!pile || pile->size <= 1)
		return ;
	tmp = pile->data[0];
	rank_tmp = pile->data[0];
	i = 0;
	while (i < pile->size - 1)
	{
		pile->data[i] = pile->data[i + 1];
		pile->rank[i] = pile->rank[i + 1];
		i++;
	}
	pile->data[i] = tmp;
	pile->rank[i] = rank_tmp;
}
