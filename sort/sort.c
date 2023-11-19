/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psalame <psalame@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 02:24:23 by psalame           #+#    #+#             */
/*   Updated: 2023/11/19 12:44:21 by psalame          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static size_t	nb_to_separate(t_pile *pile, size_t bit_i)
{
	size_t	i;
	size_t	res;

	i = 0;
	res = 0;
	while (i < pile->size)
	{
		if (((pile->rank[i] >> bit_i) & 1) == 0)
			res++;
		i++;
	}
	return (res);
}

static t_bool	separate(t_pile *a, t_pile *b, t_list **actions, size_t i)
{
	size_t	to_separate;
	size_t	separated;

	to_separate = nb_to_separate(a, i);
	separated = 0;
	while (separated < to_separate)
	{
		if (((a->rank[a->size - 1] >> i) & 1) == 0)
		{
			push(a, b);
			separated++;
			if (!add_action("pb", actions, a, b))
				return (FALSE);
		}
		else
		{
			rotate_pile(a);
			if (!add_action("ra", actions, a, b))
				return (FALSE);
		}
	}
	return (TRUE);
}

// todo check if no need to push a
static t_bool	join(t_pile *pile_a, t_pile *pile_b, t_list **actions)
{
	while (pile_b->size != 0)
	{
		push(pile_b, pile_a);
		if (!add_action("pa", actions, pile_a, pile_b))
			return (FALSE);
	}
	return (TRUE);
}

static void	ft_putendl(void *str)
{
	ft_putendl_fd(str, 1);
}

t_bool	sort_pile(t_pile *pile_a, t_pile *pile_b)
{
	t_list	*actions;
	size_t	bit_i;

	actions = NULL;
	bit_i = 0;
	while (!is_sort(pile_a, pile_b))
	{
		if (!separate(pile_a, pile_b, &actions, bit_i))
			return (FALSE);
		if (!join(pile_a, pile_b, &actions))
			return (FALSE);
		bit_i++;
	}
	ft_lstiter(actions, &ft_putendl);
	ft_lstclear(&actions, &free);
	return (TRUE);
}
