/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psalame <psalame@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 01:21:21 by psalame           #+#    #+#             */
/*   Updated: 2023/11/25 02:47:21 by psalame          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	exec_action(char *action, t_pile *a, t_pile *b)
{
	size_t	len;

	len = ft_strlen(action);
	if (ft_strncmp(action, "sa", MAX(len, 2)) == 0)
		swap(a);
	else if (ft_strncmp(action, "sb", MAX(len, 2)) == 0)
		swap(b);
	else if (ft_strncmp(action, "ss", MAX(len, 2)) == 0)
	{
		swap(b);
		swap(b);
	}
	else if (ft_strncmp(action, "pa", MAX(len, 2)) == 0)
		push(b, a);
	else if (ft_strncmp(action, "pb", MAX(len, 2)) == 0)
		push(a, b);
	else if (ft_strncmp(action, "ra", MAX(len, 2)) == 0)
		rotate_pile(a);
	else if (ft_strncmp(action, "rb", MAX(len, 2)) == 0)
		rotate_pile(b);
	else if (ft_strncmp(action, "rra", MAX(len, 3)) == 0)
		rotate_pile_revert(a);
	else if (ft_strncmp(action, "rrb", MAX(len, 3)) == 0)
		rotate_pile_revert(b);
	else if (ft_strncmp(action, "rr", MAX(len, 2)) == 0)
	{
		rotate_pile(a);
		rotate_pile(b);
	}
	else if (ft_strncmp(action, "rrr", MAX(len, 3)) == 0)
	{
		rotate_pile_revert(a);
		rotate_pile_revert(b);
	}
	else
	{
		ft_printf("Error\n");
		free(action);
		close_next_line(0);
		free_pile(a);
		free_pile(b);
		exit(EXIT_SUCCESS);
	}
}

void	check_result(t_pile *a, t_pile *b)
{
	char	*action;
	size_t		len;
	
	action = get_next_line(0);
	while (action)
	{
		len = ft_strlen(action);
		if (len != 0)
			action[len - 1] = 0;
		exec_action(action, a, b);
		free(action);
		action = get_next_line(0);
	}
	if (b->size != 0 || !is_sort(a))
		ft_printf("KO\n");
	else
		ft_printf("OK\n");
	free_pile(a);
	free_pile(b);
}

int	main(int ac, char **av)
{
	t_pile	*pile_a;
	t_pile	*pile_b;

	if (ac == 1)
		return (0);
	parse_arguments(&ac, av);
	if (!check_arguments(ac - 1, av + 1))
	{
		ft_putendl_fd("Error", STDERR_FILENO);
		return (0);
	}
	pile_a = initialise_pile(av + 1, ac - 1, ac - 1);
	pile_b = initialise_pile(NULL, 0, ac - 1);
	if (pile_a == NULL || pile_b == NULL)
	{
		ft_printf("%fError", STDERR_FILENO);
		return (EXIT_FAILURE);
	}
	check_result(pile_a, pile_b);
	return (0);
}
