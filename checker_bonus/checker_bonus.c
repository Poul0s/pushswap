/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psalame <psalame@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 01:21:21 by psalame           #+#    #+#             */
/*   Updated: 2023/11/30 14:32:47 by psalame          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	exec_action(char *action, t_pile *a, t_pile *b);

void	check_result(t_pile *a, t_pile *b)
{
	char	*action;
	size_t	len;

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
	if (ac - 1 == 0)
		return (0);
	pile_a = initialise_pile(av + 1, ac - 1, ac - 1);
	pile_b = initialise_pile(NULL, 0, ac - 1);
	if (pile_a == NULL || pile_b == NULL)
	{
		ft_printf("%fError\n", STDERR_FILENO);
		return (EXIT_FAILURE);
	}
	check_result(pile_a, pile_b);
	return (0);
}
