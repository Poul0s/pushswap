/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_remove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psalame <psalame@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 18:09:25 by psalame           #+#    #+#             */
/*   Updated: 2023/11/18 21:41:33 by psalame          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_bool	add_pile_ele(t_pile *pile, int ele, size_t rank)
{

	if (pile == NULL)
		return (FALSE);
	pile->size++;
	pile->data[pile->size - 1] = ele;
	pile->rank[pile->size - 1] = rank;
	return (TRUE);
}

t_bool	remove_pile_ele(t_pile *pile)
{
	if (pile == NULL || pile->size == 0)
		return (FALSE);
	pile->size--;
	return (TRUE);
}
