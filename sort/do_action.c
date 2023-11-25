/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_action.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psalame <psalame@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 03:18:10 by psalame           #+#    #+#             */
/*   Updated: 2023/11/25 16:56:05 by psalame          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	add_action(char *action, t_list **actions, t_pile *a, t_pile *b)
{
	t_list	*newele;

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

static char	*action_to_str(t_action action)
{
	if (action == sa)
		return (ft_strdup("sa"));
	if (action == sb)
		return (ft_strdup("sb"));
	if (action == pa)
		return (ft_strdup("pa"));
	if (action == pb)
		return (ft_strdup("pb"));
	if (action == ra)
		return (ft_strdup("ra"));
	if (action == rb)
		return (ft_strdup("rb"));
	if (action == rra)
		return (ft_strdup("rra"));
	if (action == rrb)
		return (ft_strdup("rrb"));
	if (action == rr)
		return (ft_strdup("rr"));
	if (action == rrr)
		return (ft_strdup("rrr"));
	return (NULL);
}

void	do_action(t_action action, t_list **actions, t_pile *a, t_pile *b)
{
	if (action == sa)
		swap(a);
	if (action == sb)
		swap(b);
	if (action == pa)
		push(b, a);
	if (action == pb)
		push(a, b);
	if (action == ra || action == rr)
		rotate_pile(a);
	if (action == rb || action == rr)
		rotate_pile(b);
	if (action == rra || action == rrr)
		rotate_pile_revert(a);
	if (action == rrb || action == rrr)
		rotate_pile_revert(b);
	add_action(action_to_str(action), actions, a, b);
}
