/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialise.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psalame <psalame@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 23:10:30 by psalame           #+#    #+#             */
/*   Updated: 2023/11/23 13:05:16 by psalame          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_pile	*initialise_pile(char **values, size_t size, size_t maxsize)
{
	t_pile	*pile;
	size_t	i;

	pile = create_pile();
	if (pile == NULL)
		return (NULL);
	pile->size = size;
	pile->data = malloc(maxsize * sizeof(t_icost));
	if (pile->data == NULL)
	{
		free_pile(pile);
		return (NULL);
	}
	i = size;
	while (i > 0)
	{
		pile->data[i - 1].nb = ft_atoi(values[i - 1]);
		i--;
	}
	return (pile);
}
