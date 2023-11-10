/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psalame <psalame@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 18:17:04 by psalame           #+#    #+#             */
/*   Updated: 2023/11/10 18:18:04 by psalame          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

pile_t	*create_pile(void)
{
	pile_t	pile;

	pile = malloc(sizeof(pile));
	if (pile == NULL)
		return (NULL);
	pile->data = NULL;
	pile->size = 0;
	return (pile);
}
