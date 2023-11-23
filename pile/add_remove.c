/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_remove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psalame <psalame@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 18:09:25 by psalame           #+#    #+#             */
/*   Updated: 2023/11/23 13:04:25 by psalame          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	add_pile_ele(t_pile *pile, t_icost ele)
{
	pile->size++;
	pile->data[pile->size - 1] = ele;
}

void	remove_pile_ele(t_pile *pile)
{
	pile->size--;
}
