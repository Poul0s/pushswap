/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_action.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psalame <psalame@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 03:18:10 by psalame           #+#    #+#             */
/*   Updated: 2023/11/23 13:07:57 by psalame          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_state(char *action, t_pile *pile_a, t_pile *pile_b)
{
	size_t	i;

	if (action == NULL)
		ft_putendl_fd("-----------------------------------\nInit a and b:", 1);
	else
		ft_printf("Exec %s:\n", action);
	if (pile_a != NULL)
		i = pile_a->size;
	else if (pile_a == NULL && pile_b != NULL)
		i = pile_b->size;
	if (pile_a && pile_b && pile_b->size > pile_a->size)
		i = pile_b->size;
	while (i > 0)
	{
		if (pile_a && i <= pile_a->size)
			ft_printf("%d", pile_a->data[i - 1].nb);
		else
			ft_printf(" ");
		ft_printf(" ");
		if (pile_b && i <= pile_b->size)
			ft_printf("%d", pile_b->data[i - 1].nb);
		ft_putchar_fd('\n', 1);
		i--;
	}
	ft_putendl_fd("- -\na b\n-----------------------------------", 1);
}

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
	if (SHOW_DETAIL)
		print_state(action, a, b);
	if (STEP_BY_STEP)
		read(0, "", 1);
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
}
