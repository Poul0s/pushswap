/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   short_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psalame <psalame@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 14:43:47 by psalame           #+#    #+#             */
/*   Updated: 2023/11/19 17:37:52 by psalame          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_bool	sort_three(t_pile *a, t_pile *b, t_list **actions)
{
	if (a->size == 2 && a->data[1] > a->data[0])
	{
		swap(a);
		return (add_action("sa", actions, a, b));
	}
	else if (a->size == 3)
	{
		while (!is_sort(a, b))
		{
			if (a->data[2] < a->data[1] && a->data[1] > a->data[0] && a->data[2] > a->data[0])
			{
				rotate_pile_revert(a);
				return (add_action("rra", actions, a, b));
			}
			if (a->data[2] > a->data[1] && a->data[0] > a->data[1] && a->data[2] > a->data[0])
			{
				rotate_pile(a);
				return (add_action("ra", actions, a, b));
			}
			swap(a);
			if (!add_action("sa", actions, a, b))
				return (FALSE);
		}
	}
	return (TRUE);
}

static t_bool	push_sort(t_pile *pile_a, t_pile *pile_b, t_list **actions)
{
	return (FALSE);
}

t_bool	short_sort(t_pile *pile_a, t_pile *pile_b, t_list **actions)
{
	t_pile	*tmp;
	t_bool	res;

	if (pile_a->size <= 3)
		return (sort_three(pile_a, pile_b, actions));
	else
	{
		while (pile_a->size > 3)
		{
			push(pile_a, pile_b);
			if (!add_action("pb", actions, pile_a, pile_b))
				return (FALSE);
		}
		tmp = initialise_pile(NULL, 0, pile_a->size);
		if (!tmp)
			return (FALSE);
		res = sort_three(pile_a, tmp, actions);
		free_pile(tmp);
		// if (res && pile_b->size == 2 && pile_b->data[0] < pile_b->data[1])
		// {
		// 	swap(pile_b);
		// 	res = add_action("sb", actions, pile_a, pile_b);
		// }
		push_sort(pile_a, pile_b, actions);
		// while (res && pile_b->size > 0) // doesnt push sorted
		// {
		// 	push(pile_b, pile_a);
		// 	res = add_action("pa", actions, pile_a, pile_b);
		// }
		return (res);
	}
}
