/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psalame <psalame@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 15:33:40 by psalame           #+#    #+#             */
/*   Updated: 2023/11/10 18:09:53 by psalame          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(pile_t *pile_from, pile_t *pile_to)
{
	if (pile_a == NULL || pile_b == NULL)
		return ;
	add_pile_ele(pile_b, remove_pile_ele(pile_from));
}
