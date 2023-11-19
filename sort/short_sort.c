/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   short_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psalame <psalame@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 14:43:47 by psalame           #+#    #+#             */
/*   Updated: 2023/11/19 14:59:38 by psalame          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_bool	sort_tree(t_pile *a, t_pile *b, t_list **actions)
{
	if (a->size == 2 && a->data[1] > a->data[0])
	{
		swap(a);
		return (add_action("sa", actions, a, b));
	}
	else if (a->size == 3)
	{
		if (a->data[2] > a->data[1] && a->data[0] > a->data[2])
		{
			swap(a);
			return (add_action("sa", actions, a, b));
		}
	}
	return (TRUE);
}

t_bool	short_sort(t_pile *pile_a, t_pile *pile_b, t_list **actions)
{
	
}