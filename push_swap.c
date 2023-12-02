/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psalame <psalame@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 14:52:10 by psalame           #+#    #+#             */
/*   Updated: 2023/12/02 14:52:47 by psalame          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_pile	*pile_a;
	t_pile	*pile_b;

	if (ac == 1)
		return (0);
	parse_arguments(&ac, av);
	if (ac == 1 || !check_arguments(ac - 1, av + 1))
	{
		ft_putendl_fd("Error", STDERR_FILENO);
		return (0);
	}
	pile_a = initialise_pile(av + 1, ac - 1, ac - 1);
	pile_b = initialise_pile(NULL, 0, ac - 1);
	if (pile_a == NULL || pile_b == NULL)
		ft_error(pile_a, pile_b, NULL);
	if (!is_sort(pile_a))
		sort_pile(pile_a, pile_b);
	free_pile(pile_a);
	free_pile(pile_b);
	return (0);
}
