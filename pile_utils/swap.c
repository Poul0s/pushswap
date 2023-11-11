/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psalame <psalame@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 14:57:28 by psalame           #+#    #+#             */
/*   Updated: 2023/11/11 11:34:25 by psalame          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_pile *pile)
{
	int	tmp;

	if (pile->size >= 2)
	{
		tmp = pile->data[pile->size - 1];
		pile->data[pile->size - 1] = pile->data[pile->size - 2];
		pile->data[pile->size - 2] = tmp;
	}
}
