/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_action.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psalame <psalame@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 03:18:10 by psalame           #+#    #+#             */
/*   Updated: 2023/11/25 01:24:14 by psalame          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	add_action(char *action, t_list **actions, t_pile *a, t_pile *b)
{
	t_list	*newele;

	if (action)
		action = ft_strdup(action);
	if (action == NULL)
		ft_error(a, b, actions);
	newele = ft_lstnew(action);
	if (newele == NULL)
	{
		free(action);
		ft_error(a, b, actions);
	}
	ft_lstadd_back(actions, newele);
}

void	do_action(t_action action, t_list **actions, t_pile *a, t_pile *b)
{
	if (action == sa)
	{
		swap(a);
		add_action("sa", actions, a, b);
	}
	else if (action == sb)
	{
		swap(b);
		add_action("sb", actions, a, b);
	}
	else if (action == pa)
	{
		push(b, a);
		add_action("pa", actions, a, b);
	}
	else if (action == pb)
	{
		push(a, b);
		add_action("pb", actions, a, b);
	}
	else if (action == ra)
	{
		rotate_pile(a);
		add_action("ra", actions, a, b);
	}
	else if (action == rb)
	{
		rotate_pile(b);
		add_action("rb", actions, a, b);
	}
	else if (action == rra)
	{
		rotate_pile_revert(a);
		add_action("rra", actions, a, b);
	}
	else if (action == rrb)
	{
		rotate_pile_revert(b);
		add_action("rrb", actions, a, b);
	}
	else if (action == rr)
	{
		rotate_pile(a);
		rotate_pile(b);
		add_action("rr", actions, a, b);
	}
	else if (action == rrr)
	{
		rotate_pile_revert(a);
		rotate_pile_revert(b);
		add_action("rrr", actions, a, b);
	}
}
