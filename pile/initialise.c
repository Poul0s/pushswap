/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialise.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psalame <psalame@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 23:10:30 by psalame           #+#    #+#             */
/*   Updated: 2023/11/18 21:13:45 by psalame          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_pile_rank(t_pile *pile)
{
	size_t	rank;
	size_t	i;
	size_t	j;

	i = 0;
	while (i < pile->size)
	{
		rank = 0;
		j = 0;
		while (j < pile->size)
			if (pile->data[j++] < pile->data[i])
				rank++;
		pile->rank[i] = rank;
		i++;
	}
}

t_pile	*initialise_pile(char **values, size_t size, size_t maxsize)
{
	t_pile	*pile;
	size_t	i;

	pile = create_pile();
	if (pile == NULL)
		return (NULL);
	pile->size = size;
	pile->data = malloc(maxsize * sizeof(int));
	pile->rank = malloc(maxsize * sizeof(size_t));
	if (pile->data == NULL || pile->rank == NULL)
	{
		free_pile(pile);
		return (NULL);
	}
	i = size;
	while (i > 0)
	{
		pile->data[i - 1] = ft_atoi(values[i - 1]);
		i--;
	}
	set_pile_rank(pile);
	return (pile);
}
