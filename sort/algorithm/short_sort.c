/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   short_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psalame <psalame@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 14:43:47 by psalame           #+#    #+#             */
/*   Updated: 2023/11/23 18:44:11 by psalame          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_bool	sort_three(t_pile *a, t_pile *b, t_list **actions)
{
	if (a->size == 2 && a->data[1].nb > a->data[0].nb)
	{
		swap(a);
		return (add_action("sa", actions, a, b));
	}
	else if (a->size == 3)
	{
		while (!is_sort(a, b))
		{
			if (a->data[2].nb < a->data[1].nb && a->data[1].nb > a->data[0].nb && a->data[2].nb > a->data[0].nb)
			{
				rotate_pile_revert(a);
				add_action("rra", actions, a, b);
			}
			if (a->data[2].nb > a->data[1].nb && a->data[0].nb > a->data[1].nb && a->data[2].nb > a->data[0].nb)
			{
				rotate_pile(a);
				add_action("ra", actions, a, b);
			}
			swap(a);
			add_action("sa", actions, a, b);
		}
	}
	return (TRUE);
}

t_bool	short_sort(t_pile *pile_a, t_pile *pile_b, t_list **actions)
{
	t_pile	*tmp;
	t_bool	res;

	if (pile_a->size <= 3)
		return (sort_three(pile_a, pile_b, actions));
	else
	{
		// todo
		res = FALSE;
		return (res);
	}
}
