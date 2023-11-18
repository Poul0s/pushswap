/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_remove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psalame <psalame@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 18:09:25 by psalame           #+#    #+#             */
/*   Updated: 2023/11/12 00:16:08 by psalame          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_bool	add_pile_ele(t_pile *pile, int ele)
{
	int		*newtab;
	size_t	i;

	if (pile == NULL)
		return (FALSE);
	newtab = malloc((pile->size + 1) * sizeof(int));
	if (newtab == NULL)
		return (FALSE);
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
	return (TRUE);
}

t_bool	remove_pile_ele(t_pile *pile)
{
	int		*newtab;
	size_t	i;

	pile->size--;
	newtab = malloc(pile->size * sizeof(int));
	if (newtab == NULL)
		return (FALSE);
	i = 0;
	while (i < pile->size)
	{
		newtab[i] = pile->data[i];
		i++;
	}
	free(pile->data);
	pile->data = newtab;
	return (TRUE);
}
