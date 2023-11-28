/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psalame <psalame@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 14:21:01 by psalame           #+#    #+#             */
/*   Updated: 2023/11/28 16:44:47 by psalame          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(t_pile *a, t_pile *b, t_list **actions)
{
	free_pile(a);
	free_pile(b);
	ft_lstclear(actions, &free);
	ft_printf("%fError\n", 2);
	exit(EXIT_FAILURE);
}
