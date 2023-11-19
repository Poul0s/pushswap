/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psalame <psalame@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 14:52:26 by psalame           #+#    #+#             */
/*   Updated: 2023/11/19 12:17:35 by psalame          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft.h"
# include <stdlib.h>
# ifndef SHOW_DETAIL
#  define SHOW_DETAIL 0
# endif
# ifndef STEP_BY_STEP
#  define STEP_BY_STEP SHOW_DETAIL
# endif

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
	size_t	*rank;
	size_t	size;
}			t_pile;

t_bool	add_pile_ele(t_pile *pile, int ele, size_t rank);
t_bool	remove_pile_ele(t_pile *pile);
void	rotate_pile(t_pile *pile);
void	rotate_pile_revert(t_pile *pile);
t_bool	push(t_pile *pile_from, t_pile *pile_to);
void	swap(t_pile *pile);
t_pile	*create_pile(void);
void	free_pile(t_pile *pile);
void	set_pile_rank(t_pile *pile);
t_pile	*initialise_pile(char **values, size_t size, size_t maxsize);
t_bool	ft_isnumber(const char *str);
t_bool	sort_pile(t_pile *pile_a, t_pile *pile_b);
t_bool	is_sort(t_pile *pile_a, t_pile *pile_b);
void	print_state(char *action, t_pile *pile_a, t_pile *pile_b);
t_bool	add_action(char *action, t_list **actions, t_pile *a, t_pile *b);

#endif
