/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtx_biggest_strlen.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjose-d <anjose-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 23:34:51 by anjose-d          #+#    #+#             */
/*   Updated: 2023/01/11 23:35:04 by anjose-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_mtx_biggest_strlen(char **mtx)
{
	int	i;
	int	len;
	int	biggest;

	i = 0;
	biggest = 0;
	while (mtx[i])
	{
		len = ft_strlen(mtx[i]);
		if (len > biggest)
			biggest = len;
		i++;
	}
	return (biggest);
}
