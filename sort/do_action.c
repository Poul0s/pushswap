/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_action.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psalame <psalame@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 03:18:10 by psalame           #+#    #+#             */
/*   Updated: 2023/11/19 12:34:33 by psalame          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_state(char *action, t_pile *pile_a, t_pile *pile_b)
{
	size_t	i;

	if (action == NULL)
		ft_putendl_fd("-----------------------------------\nInit a and b:", 1);
	else
		ft_printf("Exec %s:\n", action);
	i = pile_a->size;
	if (pile_b->size > pile_a->size)
		i = pile_b->size;
	while (i > 0)
	{
		if (i <= pile_a->size)
			ft_printf("%d (%d)", pile_a->data[i - 1], pile_a->rank[i - 1]);
		else
			ft_printf("     ");
		ft_printf(" ");
		if (i <= pile_b->size)
			ft_printf("%d (%d)", pile_b->data[i - 1], pile_b->rank[i - 1]);
		ft_putchar_fd('\n', 1);
		i--;
	}
	ft_putendl_fd("-     -\na     b\n-----------------------------------", 1);
}

t_bool	add_action(char *action, t_list **actions, t_pile *a, t_pile *b)
{
	t_list	*newele;

	if (action)
		action = ft_strdup(action);
	if (action == NULL)
		return (FALSE);
	newele = ft_lstnew(action);
	if (newele == NULL)
	{
		free(action);
		return (FALSE);
	}
	ft_lstadd_back(actions, newele);
	if (SHOW_DETAIL)
		print_state(action, a, b);
	if (STEP_BY_STEP)
		read(0, "", 1);
	return (TRUE);
}
