/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putxnbr_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psalame <psalame@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 23:51:09 by psalame           #+#    #+#             */
/*   Updated: 2023/11/21 17:12:27 by psalame          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

ssize_t	ft_putxnbr_fd(unsigned int nb, short maj, int fd)
{
	char	*str;
	int		len;

	if (maj)
		str = ft_ultoa_base(nb, FT_HEXA_BASE_MAJ);
	else
		str = ft_ultoa_base(nb, FT_HEXA_BASE);
	if (str == NULL)
		return (0);
	len = ft_putstr_fd(str, fd);
	free(str);
	return (len);
}
