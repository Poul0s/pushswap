/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psalame <psalame@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 15:33:40 by psalame           #+#    #+#             */
/*   Updated: 2023/11/11 11:55:37 by psalame          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

e_bool	push(t_pile *pile_from, t_pile *pile_to)
{
	int	ele;

	if (pile_a == NULL || pile_b == NULL)
		return ;
	ele = pile_from->data[pile_from->size - 1];
	return (remove_pile_ele(pile_from) && add_pile_ele(pile_to, ele));
}
