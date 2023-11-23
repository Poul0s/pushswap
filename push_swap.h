/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psalame <psalame@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 14:52:26 by psalame           #+#    #+#             */
/*   Updated: 2023/11/23 19:04:35 by psalame          ###   ########.fr       */
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
# define MIN(a, b) (a * (a < b) + b * (a >= b))
# define MAX(a, b) (a * (a > b) + b * (a <= b))

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
	rra,
	rrb,
	rr,
	rrr,
}	t_action;

typedef struct s_icost
{
	int				nb;
	unsigned int	cost;
}					t_icost;

typedef struct s_pile
{
	t_icost	*data;
	size_t	size;
}			t_pile;

void	add_pile_ele(t_pile *pile, t_icost ele);
void	remove_pile_ele(t_pile *pile);
void	rotate_pile(t_pile *pile);
void	rotate_pile_revert(t_pile *pile);
void	push(t_pile *pile_from, t_pile *pile_to);
void	swap(t_pile *pile);
t_pile	*create_pile(void);
void	free_pile(t_pile *pile);
t_pile	*initialise_pile(char **values, size_t size, size_t maxsize);
t_bool	ft_isnumber(const char *str);
t_bool	short_sort(t_pile *pile_a, t_pile *pile_b, t_list **actions);
t_bool	sort_pile(t_pile *pile_a, t_pile *pile_b);
t_bool	is_sort(t_pile *pile);
void	print_state(char *action, t_pile *pile_a, t_pile *pile_b);
void	add_action(char *action, t_list **actions, t_pile *a, t_pile *b);
void	do_action(t_action action, t_list **actions, t_pile *a, t_pile *b);
void	ft_error(t_pile *pile_a, t_pile *pile_b, t_list **actions);

#endif
