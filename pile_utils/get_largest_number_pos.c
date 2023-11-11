/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_largest_number_pos.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psalame <psalame@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 11:42:43 by psalame           #+#    #+#             */
/*   Updated: 2023/11/11 11:43:01 by psalame          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	get_largest_numer_pos(t_pile *pile)
{
	size_t	i;
	size_t	pos;

	i = 1;
	pos = 0;
	while (i < pile->size)
	{
		if (pile->data[i] > pile->data[pos])
			pos = i;
		i++;
	}
	return (pos);
}
