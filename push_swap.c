/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psalame <psalame@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 14:52:10 by psalame           #+#    #+#             */
/*   Updated: 2023/11/24 13:58:53 by psalame          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// todo check doublon
static t_bool	check_values(int size, char **values)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (!ft_isnumber(values[i]))
			return (FALSE);
		i++;
	}
	return (TRUE);
}

int	main(int ac, char **av)
{
	t_pile	*pile_a;
	t_pile	*pile_b;

	if (ac == 1)
		return (0);
	if (!check_values(ac - 1, av + 1))
	{
		ft_putendl_fd("Error", STDERR_FILENO);
		return (0);
	}
	pile_a = initialise_pile(av + 1, ac - 1, ac - 1);
	pile_b = initialise_pile(NULL, 0, ac - 1);
	if (pile_a == NULL || pile_b == NULL)
		ft_error(pile_a, pile_b, NULL);
	if (SHOW_DETAIL)
		print_state(NULL, pile_a, pile_b);
	if (!is_sort(pile_a))
		sort_pile(pile_a, pile_b);
	free_pile(pile_a);
	free_pile(pile_b);
	return (0);
}
