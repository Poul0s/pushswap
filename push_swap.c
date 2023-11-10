/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psalame <psalame@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 14:52:10 by psalame           #+#    #+#             */
/*   Updated: 2023/11/10 18:25:02 by psalame          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	pile_t	*pile_a;
	pile_t	*pile_b;
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
		return ;
	}
	i = ac - 1;
	while (i > 0)
		add_pile_ele(pile_a, ft_atoi(av[i++]));
	show_sort_action(pile_a, pile_b);
	return (0);
}
