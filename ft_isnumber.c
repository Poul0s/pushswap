/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isnumber.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psalame <psalame@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 02:17:41 by psalame           #+#    #+#             */
/*   Updated: 2023/11/18 02:22:08 by psalame          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

t_bool	ft_isnumber(const char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (FALSE);
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (str[i] == 0)
		return (FALSE);
	while (str[i])
		if (!ft_isdigit(str[i++]))
			return (FALSE);
	return (TRUE);
}
