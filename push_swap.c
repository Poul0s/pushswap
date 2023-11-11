/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psalame <psalame@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 14:52:10 by psalame           #+#    #+#             */
/*   Updated: 2023/11/11 11:58:30 by psalame          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void show_actions(t_list *actions)
{
	while (actions != NULL)
	{
		ft_putendl_fd(actions->data, 1)
		actions = actions->next;
	}
}

static void	sort_pile(t_pile *pile_a, t_pile *pile_b)
{
	t_list	*actions;
	size_t	pos;

	while (pile_a->size > 0)
	{
		pos = get_largest_number_pos(pile_a);
		if (pos == pile_a->size - 1)
		{
			(void) 0;
			(void) 0;
		}
		else if (pos == pile_a-> size - 2)
		{
			(void) 0;
			(void) 0;
		}
		else if (pos > pile_a->size / 2)
		{
			(void) 0;
			(void) 0;
		}
		else
		{
			(void) 0;
			(void) 0;
		}
		
	}
	show_actions(actions);
}

int	main(int ac, char **av)
{
	t_pile	*pile_a;
	t_pile	*pile_b;
	size_t	i;

	if (ac == 1)
		return ;
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
