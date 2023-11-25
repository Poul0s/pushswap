/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psalame <psalame@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 15:33:40 by psalame           #+#    #+#             */
/*   Updated: 2023/11/25 13:04:21 by psalame          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_pile *pile_from, t_pile *pile_to)
{
	t_icost	ele;

	if (pile_from == NULL || pile_to == NULL || pile_from->size == 0)
		return ;
	ele = pile_from->data[pile_from->size - 1];
	remove_pile_ele(pile_from);
	add_pile_ele(pile_to, ele);
}
