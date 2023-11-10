/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_remove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psalame <psalame@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 18:09:25 by psalame           #+#    #+#             */
/*   Updated: 2023/11/10 18:15:41 by psalame          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	add_pile_ele(pile_t *pile, int ele)
{
	int		*newtab;
	size_t	i;

	if (pile == NULL)
		return ;
	newtab = malloc((pile->size + 1) * sizeof(int));
	i = 0;
	while (i < pile->size)
	{
		newtab[i] = pile->data[i];
		i++;
	}
	newtab[i] = ele;
	pile->size++;
	free(pile->data);
	pile->data = newtab;
}

int	remove_pile_ele(pile_t *pile)
{
	int		*newtab;
	size_t	i;
	int		removed_ele;

	pile->size--;
	newtab = malloc(pile->size * sizeof(int));
	i = 0;
	while (i < pile->size)
	{
		newtab[i] = pile->data[i];
		i++;
	}
	removed_ele = pile->data[i];
	free(pile->data);
	pile->data = newtab;
	return (removed_ele);
}
