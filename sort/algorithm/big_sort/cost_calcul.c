/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_calcul.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psalame <psalame@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 13:13:01 by psalame           #+#    #+#             */
/*   Updated: 2023/11/23 19:29:51 by psalame          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

unsigned int	calcul_go_top_cost(t_pile *pile, size_t i)
{
	unsigned int	cost;

	cost = 0;
	if (i < pile->size / 2)
		cost = i + 1;
	else
		cost = pile->size - i - 1;
	return (cost);
}

static ssize_t	get_better_cost(t_list *possibilities)
{
	ssize_t	best;

	best = -1;
	while (possibilities)
	{
		if (best == -1)
			best = (unsigned) possibilities->content;
		else
			best = MIN(best, ((unsigned) possibilities->content));
		possibilities = possibilities->next;
	}
	ft_lstclear(&possibilities, NULL);
	return (best);
}

ssize_t	calcul_better_place(t_pile *a, t_pile *b, size_t i)
{
	t_list	*possibilities;
	size_t	j;
	unsigned	costs[4];

	possibilities = NULL;
	j = 0;
	while (j < b->size)
	{
		if (j + 1 == b->size || b->data[j + 1].nb > a->data[i].nb) // mb bad condition
		{
			costs[0] = MAX(a->size - i - 1, b->size - j - 1);
			costs[1] = MAX(i + 1, j + 1);
			costs[2] = calcul_go_top_cost(a, i) + calcul_go_top_cost(b, j);
			costs[3] = MIN(MIN(costs[0], costs[1]), costs[2]);
			if (!ft_lstadd_back(&possibilities, ft_lstnew((void *) costs[3])))
				ft_lstclear(&possibilities, NULL);
			if (possibilities == NULL)
				return (-1);
		}
		j++;
	}
	return (get_better_cost(possibilities));
}

size_t	calcul_push_cost(t_pile *a, t_pile *b, t_list **actions)
{
	size_t			i;
	size_t			i_min;
	t_list			*possibilities;
	unsigned int	cost;
	
	i = 0;
	i_min = 0;
	while (i < a->size)
	{
		a->data[i].cost = calcul_better_place(a, b, i);
		if (a->data[i].cost == -1)
			ft_error(actions, a, b);
		if (a->data[i].cost < a->data[i_min].cost)
			i_min = i;
		i++;
	}
	return (i_min);
}
