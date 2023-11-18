/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_action.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psalame <psalame@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 03:18:10 by psalame           #+#    #+#             */
/*   Updated: 2023/11/18 03:26:03 by psalame          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_bool	add_action(char *action, t_list **actions)
{
	t_list	*newele;

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
	return (TRUE);
}
