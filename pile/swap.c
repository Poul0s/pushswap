/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psalame <psalame@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 14:57:28 by psalame           #+#    #+#             */
/*   Updated: 2023/11/18 21:07:36 by psalame          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_pile *pile)
{
	int		tmp;
	size_t	rank_tmp;

	if (pile->size >= 2)
	{
		tmp = pile->data[pile->size - 1];
		rank_tmp = pile->rank[pile->size - 1];
		pile->data[pile->size - 1] = pile->data[pile->size - 2];
		pile->rank[pile->size - 1] = pile->rank[pile->size - 2];
		pile->data[pile->size - 2] = tmp;
		pile->rank[pile->size - 2] = rank_tmp;
	}
}
