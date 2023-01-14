/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   only_these.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjose-d <anjose-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 17:17:26 by anjose-d          #+#    #+#             */
/*   Updated: 2023/01/14 20:01:23 by anjose-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int	only_these(char *str, char *needles)
{
	int	i;
	int	j;
	int	found;

	i = 0;
	while (str[i])
	{
		j = 0;
		found = 0;
		while (needles[j])
		{
			if (str[i] == needles[j])
			{
				found = 1;
				break ;
			}
			j++;
		}
		if (found == 0)
			return (-1);
		i++;
	}
	return (0);
}
