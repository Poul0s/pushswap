/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_action_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psalame <psalame@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 12:50:53 by psalame           #+#    #+#             */
/*   Updated: 2023/11/28 16:31:43 by psalame          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	action_not_found(char *action, t_pile *a, t_pile *b)
{
	ft_printf("Error\n");
	free(action);
	close_next_line(0);
	free_pile(a);
	free_pile(b);
	exit(EXIT_SUCCESS);
}

static void	exec_swap(char *action, t_pile *a, t_pile *b)
{
	size_t	len;

	len = ft_strlen(action);
	if (ft_strncmp(action, "sa", max(len, 2)) == 0)
		swap(a);
	else if (ft_strncmp(action, "sb", max(len, 2)) == 0)
		swap(b);
	else if (ft_strncmp(action, "ss", max(len, 2)) == 0)
	{
		swap(b);
		swap(b);
	}
	else
		action_not_found(action, a, b);
}

static void	exec_rotate(char *action, t_pile *a, t_pile *b)
{
	size_t	len;

	len = ft_strlen(action);
	if (ft_strncmp(action, "ra", max(len, 2)) == 0)
		rotate_pile(a);
	else if (ft_strncmp(action, "rb", max(len, 2)) == 0)
		rotate_pile(b);
	else if (ft_strncmp(action, "rra", max(len, 3)) == 0)
		rotate_pile_revert(a);
	else if (ft_strncmp(action, "rrb", max(len, 3)) == 0)
		rotate_pile_revert(b);
	else if (ft_strncmp(action, "rr", max(len, 2)) == 0)
	{
		rotate_pile(a);
		rotate_pile(b);
	}
	else if (ft_strncmp(action, "rrr", max(len, 3)) == 0)
	{
		rotate_pile_revert(a);
		rotate_pile_revert(b);
	}
	else
		action_not_found(action, a, b);
}

void	exec_action(char *action, t_pile *a, t_pile *b)
{
	size_t	len;

	len = ft_strlen(action);
	if (action[0] == 's')
		exec_swap(action, a, b);
	else if (action[0] == 'r')
		exec_rotate(action, a, b);
	else if (ft_strncmp(action, "pa", max(len, 2)) == 0)
		push(b, a);
	else if (ft_strncmp(action, "pb", max(len, 2)) == 0)
		push(a, b);
	else
		action_not_found(action, a, b);
}
