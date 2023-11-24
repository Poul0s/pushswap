/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   short_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psalame <psalame@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 14:43:47 by psalame           #+#    #+#             */
/*   Updated: 2023/11/24 18:25:29 by psalame          ###   ########.fr       */
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

void	short_sort(t_pile *pile_a, t_pile *pile_b, t_list **actions)
{
	if (pile_a->size == 2)
	{
		if (pile_a->data[1].nb > pile_a->data[0].nb)
			do_action(sa, actions, pile_a, pile_b);
	}
	else if (pile_a->size == 3)
		sort_three(pile_a, pile_b, actions);
	else
	{
		// todo
		return ;
	}
}
