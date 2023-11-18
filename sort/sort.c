/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psalame <psalame@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 02:24:23 by psalame           #+#    #+#             */
/*   Updated: 2023/11/18 03:41:35 by psalame          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static size_t	nb_to_separate(t_pile *pile)
{
	size_t	i;
	size_t	res;

	i = 0;
	res = 0;
	while (i < pile->size)
	{
		if (pile->rank[i] & 1 == 0)
			res++;
		i++;
	}
	return (res);
}

static t_bool	separate(t_pile *pile_a, t_pile *pile_b, t_list **actions)
{
	size_t	to_separate;
	size_t	separated;
	size_t	action;

	to_separate = nb_to_separate(pile_a);
	separated = 0;
	while (separated < to_separate)
	{
		if (pile_a->data[pile_a->size - 1] & 1 == 0)
		{
			push(pile_a, pile_b);
			separated++;
			if (!add_action("pb"))
				return (FALSE);
		}
		else
		{
			rotate_pile(pile_a);
			if (!add_action("ra"))
				return (FALSE);
		}
	}
	return (TRUE);
}

// https://medium.com/nerd-for-tech/push-swap-tutorial-fa746e6aba1e

t_list	*sort_pile(t_pile *pile_a, t_pile *pile_b)
{
	t_list	*actions;

	actions = NULL;
	while (!is_sort(pile_a, pile_b))
	{
		separate(pile_a, pile_b, &actions);
		// todo join
	}
	return (actions);
}
