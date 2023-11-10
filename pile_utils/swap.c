/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psalame <psalame@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 14:57:28 by psalame           #+#    #+#             */
/*   Updated: 2023/11/10 15:22:32 by psalame          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(pile_t *pile)
{
	int	tmp;

	if (pile->size >= 2)
	{
		tmp = pile->data[pile->size - 1];
		pile->data[pile->size - 1] = pile->data[pile->size - 2];
		pile->data[pile->size - 2] = tmp;
	}
}
