/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psalame <psalame@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 18:17:04 by psalame           #+#    #+#             */
/*   Updated: 2023/11/12 00:19:02 by psalame          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_pile	*create_pile(void)
{
	t_pile	*pile;

	pile = malloc(sizeof(pile));
	if (pile == NULL)
		return (NULL);
	pile->data = NULL;
	pile->size = 0;
	return (pile);
}
