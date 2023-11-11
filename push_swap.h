/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psalame <psalame@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 14:52:26 by psalame           #+#    #+#             */
/*   Updated: 2023/11/12 00:17:26 by psalame          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft.h"
# include <stdlib.h>

typedef enum e_bool
{
	FALSE,
	TRUE,
}	t_bool;

typedef enum e_action
{
	sa,
	sb,
	ss,
	pa,
	pb,
	ra,
	rb,
	rr,
	rra,
	rrb,
	rrr,
}	t_action;

typedef struct s_pile
{
	int		*data;
	size_t	size;
}			t_pile;

t_bool	add_pile_ele(t_pile *pile, int ele);
t_bool	remove_pile_ele(t_pile *pile);
void	rotate_pile(t_pile *pile);
void	rotate_pile_revert(t_pile *pile);
t_bool	push(t_pile *pile_from, t_pile *pile_to);
void	swap(t_pile *pile);
t_pile	*create_pile(void);
size_t	get_largest_number_pos(t_pile *pile);

#endif
