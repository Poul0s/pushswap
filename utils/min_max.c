/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_max.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psalame <psalame@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 17:48:58 by psalame           #+#    #+#             */
/*   Updated: 2023/11/25 17:50:04 by psalame          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	min(size_t a, size_t b)
{
	if (a < b)
		return (a);
	else
		return (b);
}

size_t	max(size_t a, size_t b)
{
	if (a > b)
		return (a);
	else
		return (b);
}
