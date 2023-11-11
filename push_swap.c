/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psalame <psalame@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 14:52:10 by psalame           #+#    #+#             */
/*   Updated: 2023/11/12 00:17:43 by psalame          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	show_actions(t_list *actions)
{
	while (actions != NULL)
	{
		ft_putendl_fd(actions->content, 1);
		actions = actions->next;
	}
}

static char	*do_action(t_pile *a, t_pile *b, t_action action)
{
	char	*res;

	res = NULL;
	if (action == pb)
	{
		if (push(a, b))
			res = ft_strdup("pb");
	}
	else if (action == sa)
	{
		swap(a);
		res = ft_strdup("sa");
	}
	else if (action == ra)
	{
		rotate_pile(a);
		res = ft_strdup("ra");
	}
	else if (action == rra)
	{
		rotate_pile_revert(a);
		res = ft_strdup("ra");
	}
	return (res);
}

static void	sort_pile(t_pile *pile_a, t_pile *pile_b)
{
	t_list	*actions;
	t_list	*current;
	size_t	pos;

	while (pile_a->size > 0)
	{
		pos = get_largest_number_pos(pile_a);
		if (pos == pile_a->size - 1)
			current = ft_lstnew(do_action(pile_a, pile_b, pb));
		else if (pos == pile_a-> size - 2)
			current = ft_lstnew(do_action(pile_a, pile_b, sa));
		else if (pos > pile_a->size / 2)
			current = ft_lstnew(do_action(pile_a, pile_b, ra));
		else
			current = ft_lstnew(do_action(pile_a, pile_b, rra));
		ft_lstadd_back(&actions, current);
		if (current == NULL || current->content == NULL)
		{
			ft_lstclear(&actions, &free);
			return ;
		}
	}
	show_actions(actions);
	ft_lstclear(&actions, &free);
}

int	main(int ac, char **av)
{
	t_pile	*pile_a;
	t_pile	*pile_b;
	size_t	i;

	if (ac == 1)
		return (0);
	pile_a = create_pile();
	pile_b = create_pile();
	if (pile_a == NULL || pile_b == NULL)
	{
		if (pile_a)
			free(pile_a);
		if (pile_b)
			free(pile_b);
		ft_putendl_fd("Error", 2);
		return (0);
	}
	i = ac - 1;
	while (i > 0)
		add_pile_ele(pile_a, ft_atoi(av[i++]));
	sort_pile(pile_a, pile_b);
	return (0);
}
