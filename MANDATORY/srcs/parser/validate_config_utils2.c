/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_config_utils2.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjose-d <anjose-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 21:29:43 by anjose-d          #+#    #+#             */
/*   Updated: 2023/01/14 15:43:24 by anjose-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	assign_color(t_config *config, int color[], char type)
{
	int	i;

	i = 0;
	if (type == 'F' && config->f[0] == -1)
	{
		while (i < 3)
		{
			config->f[i] = color[i];
			i++;
		}
	}
	else if (type == 'C' && config->c[0] == -1)
	{
		while (i < 3)
		{
			config->c[i] = color[i];
			i++;
		}
	}
	else
		throw_error("Duplicate of colors");
}
