/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psalame <psalame@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 14:52:26 by psalame           #+#    #+#             */
/*   Updated: 2023/11/11 11:51:24 by psalame          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft.h"
# include <stdlib.h>

enum e_bool
{
	FALSE,
	TRUE
};

typedef struct s_pile
{
	int		*data;
	size_t	size;
}			t_pile;

void	add_pile_ele(t_pile *pile, int ele);
int		remove_pile_ele(t_pile *pile);
void	rotate_pile(t_pile *pile);
void	push(t_pile *pile_from, t_pile *pile_to);
void	swap(t_pile *pile);
t_pile	*create_pile(void);
size_t	get_largest_numer_pos(t_pile *pile);

#endif
