/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psalame <psalame@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 02:01:00 by psalame           #+#    #+#             */
/*   Updated: 2023/12/03 18:54:40 by psalame          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_bool	check_arguments(int size, char **values)
{
	int	i;
	int	j;
	int	number;

	i = 0;
	while (i < size)
	{
		if (!ft_isint(values[i]))
			return (FALSE);
		j = i - 1;
		number = ft_atoi(values[i]);
		while (j >= 0)
			if (ft_atoi(values[j--]) == number)
				return (FALSE);
		i++;
	}
	return (TRUE);
}

static void	reduce_to_one_argument(int *ac, char **av)
{
	size_t	len;

	while (*ac > 2)
	{
		len = ft_strlen(av[*ac - 2]);
		av[*ac - 2][len] = ' ';
		*ac = *ac - 1;
	}
}

void	parse_arguments(int *ac, char **av)
{
	size_t	i;
	size_t	j;

	reduce_to_one_argument(ac, av);
	if (*ac == 2)
	{
		i = 0;
		j = 1;
		*ac = *ac - 1;
		while (av[1][i])
		{
			if (av[1][i] == ' ')
				av[1][i] = 0;
			else if (i == 0 || av[1][i - 1] == 0)
			{
				av[j++] = av[1] + i;
				*ac = *ac + 1;
			}
			i++;
		}
	}
}
