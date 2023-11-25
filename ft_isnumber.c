/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isnumber.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psalame <psalame@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 02:17:41 by psalame           #+#    #+#             */
/*   Updated: 2023/11/25 01:56:19 by psalame          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_bool	ft_isint(const char *str)
{
	size_t	i;
	int		number;

	i = 0;
	number = 0;
	if (!str)
		return (FALSE);
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (str[i] == 0)
		return (FALSE);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (FALSE);
		if (number * 10 + (str[i] - '0') < number)
			return (FALSE);
		number = number * 10 + (str[i] - '0');
		i++;
	}
	return (TRUE);
}
