/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psalame <psalame@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 14:52:26 by psalame           #+#    #+#             */
/*   Updated: 2023/11/10 18:18:25 by psalame          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft.h"
# include <stdlib.h>

typedef struct s_pile
{
	int		*data;
	size_t	size;
}			t_pile;

void	add_pile_ele(pile_t *pile, int ele);
int		remove_pile_ele(pile_t *pile);
void	rotate_pile(pile_t *pile);
void	push(pile_t *pile_from, pile_t *pile_to);
void	swap(pile_t *pile);
pile_t	*create_pile(void);

#endif
