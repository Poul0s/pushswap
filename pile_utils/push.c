/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psalame <psalame@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 15:33:40 by psalame           #+#    #+#             */
/*   Updated: 2023/11/12 00:16:49 by psalame          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_bool	push(t_pile *pile_from, t_pile *pile_to)
{
	int	ele;

	if (pile_from == NULL || pile_to == NULL)
		return (FALSE);
	ele = pile_from->data[pile_from->size - 1];
	return (remove_pile_ele(pile_from) && add_pile_ele(pile_to, ele));
}
