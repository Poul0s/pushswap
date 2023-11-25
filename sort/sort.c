/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psalame <psalame@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 02:24:23 by psalame           #+#    #+#             */
/*   Updated: 2023/11/25 00:59:41 by psalame          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_putendl(void *str)
{
	ft_putendl_fd(str, 1);
}

void	sort_pile(t_pile *pile_a, t_pile *pile_b)
{
	t_list	*actions;

	actions = NULL;
	if (!is_sort(pile_a))
	{
		if (pile_a->size <= 3)
			short_sort(pile_a, pile_b, &actions);
		else
			big_sort(pile_a, pile_b, &actions);
	}
	ft_lstiter(actions, &ft_putendl);
	ft_lstclear(&actions, &free);
}
