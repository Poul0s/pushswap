/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   short_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psalame <psalame@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 14:43:47 by psalame           #+#    #+#             */
/*   Updated: 2023/11/25 18:26:05 by psalame          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_pile *a, t_pile *b, t_list **actions)
{
	if (!is_sort(a))
	{
		if (a->data[1].nb > a->data[0].nb)
		{
			if (a->data[2].nb < a->data[1].nb && a->data[2].nb > a->data[0].nb)
			{
				do_action(rra, actions, a, b);
			}
			else
			{
				do_action(sa, actions, a, b);
				if (a->data[2].nb > a->data[1].nb)
					do_action(ra, actions, a, b);
				else
					do_action(rra, actions, a, b);
			}
		}
		else
		{
			if (a->data[2].nb > a->data[0].nb)
				do_action(ra, actions, a, b);
			else
				do_action(sa, actions, a, b);
		}
	}
}

void	short_sort(t_pile *a, t_pile *b, t_list **actions)
{
	if (a->size == 2)
	{
		if (a->data[1].nb > a->data[0].nb)
			do_action(sa, actions, a, b);
	}
	else if (a->size == 3)
		sort_three(a, b, actions);
	else
	{
		while (a->size > 3)
			do_action(pb, actions, a, b);
		sort_three(a, b, actions);
		if (b->data[1].nb < b->data[0].nb)
			do_action(sb, actions, a, b);
		push_b_into_a_sorted(a, b, actions);
	}
}
