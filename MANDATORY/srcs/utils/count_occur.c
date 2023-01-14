/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_occur.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjose-d <anjose-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 14:35:29 by anjose-d          #+#    #+#             */
/*   Updated: 2023/01/14 14:39:58 by anjose-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	count_occur(char *str, char c)
{
	int	i;
	int	occurs;

	i = 0;
	occurs = 0;
	while (str[i])
	{
		if (str[i] == c)
			occurs++;
		i++;
	}
	return (occurs);
}
