/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psalame <psalame@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 14:52:26 by psalame           #+#    #+#             */
/*   Updated: 2023/11/25 18:18:35 by psalame          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft.h"
# include <stdlib.h>

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

typedef struct s_stepcost
{
	char			a_direction;
	unsigned int	a_steps;
	char			b_direction;
	unsigned int	b_steps;
	unsigned int	cost;
}					t_stepcost;

typedef struct s_pile
{
	t_icost	*data;
	size_t	size;
}			t_pile;

size_t		min(size_t a, size_t b);
size_t		max(size_t a, size_t b);
void		parse_arguments(int *ac, char **av);
t_bool		check_arguments(int size, char **values);
void		add_pile_ele(t_pile *pile, t_icost ele);
void		remove_pile_ele(t_pile *pile);
void		rotate_pile(t_pile *pile);
void		rotate_pile_revert(t_pile *pile);
void		push(t_pile *pile_from, t_pile *pile_to);
void		swap(t_pile *pile);
t_pile		*create_pile(void);
void		free_pile(t_pile *pile);
t_pile		*initialise_pile(char **values, size_t size, size_t maxsize);
t_bool		ft_isint(const char *str);
void		short_sort(t_pile *pile_a, t_pile *pile_b, t_list **actions);
void		sort_three(t_pile *a, t_pile *b, t_list **actions);
void		sort_pile(t_pile *pile_a, t_pile *pile_b);
t_bool		is_sort(t_pile *pile);
void		add_action(char *action, t_list **actions, t_pile *a, t_pile *b);
void		do_action(t_action action, t_list **actions, t_pile *a, t_pile *b);
void		ft_error(t_pile *pile_a, t_pile *pile_b, t_list **actions);
t_bool		is_extreme_value(t_pile *pile, int value);
t_stepcost	calcul_better_place(t_pile *a, t_pile *b, size_t i);
t_stepcost	get_best_mouvment(t_pile *a, t_pile *b, size_t i, size_t j);
size_t		calcul_go_top_cost(t_pile *pile, size_t i);
size_t		calcul_push_cost(t_pile *a, t_pile *b);
void		big_sort(t_pile *pile_a, t_pile *pile_b, t_list **actions);
size_t		get_max_value_index(t_pile *pile);
size_t		get_max_value_below_index(t_pile *pile, int value_max);
size_t		get_min_value_after_index(t_pile *pile, int value_min);
size_t		get_min_value_index(t_pile *pile);
t_bool		is_cyclic_sort(t_pile *pile);
void		push_b_into_a_sorted(t_pile *a, t_pile *b, t_list **actions);

#endif
