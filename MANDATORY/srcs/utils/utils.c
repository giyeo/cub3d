/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpaulino <rpaulino@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 03:32:11 by rpaulino          #+#    #+#             */
/*   Updated: 2023/01/13 21:52:31 by rpaulino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_struct(t_config *config, int i)
{
	if (config->NO == NULL || config->WE == NULL
		|| config->SO == NULL || config->EA == NULL
		|| config->F[0] == -1 || config->C[0] == -1)
		throw_error("Configuration missing");
	if (i && (config->map == NULL
			|| config->player_direction == 'Z'
			|| config->player_position[0] == -1))
		throw_error("Map configuration missing");
}

void	throw_error(char *error)
{
	printf("Error\n%s.\n", error);
	//exit(1);
}

int	is_one_of_these(char c, char *these)
{
	int	i;

	i = 0;
	while (these[i])
	{
		if (c == these[i])
			return (1);
		i++;
	}
	return (0);
}

int	mlx_get_hex_trgb(int r, int g, int b)
{
	return ((r << 16) | (g << 8) | (b));
}

double	normalize_angle(double angle)
{
	angle = fmod(angle, TWO_PI);
	if (angle < 0)
		angle = TWO_PI + angle;
	return (angle);
}
