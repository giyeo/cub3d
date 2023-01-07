/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjose-d <anjose-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 03:32:11 by rpaulino          #+#    #+#             */
/*   Updated: 2023/01/07 19:17:30 by anjose-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_struct(t_config *config, int i)
{
	if(config->NO == NULL || config->WE == NULL
	|| config->SO == NULL || config->EA == NULL
	|| config->F[0] == -1 || config->C[0] == -1)
		throw_error("Configuration missing");
	if(i && (config->map == NULL
	|| config->player_direction == 'Z' 
	|| config->player_position[0] == -1))
		throw_error("Map configuration missing");
}

void	init_config(t_config *config)
{
	config->NO = NULL;
	config->WE = NULL;
	config->SO = NULL;
	config->EA = NULL;
	config->map = NULL;
	config->F[0] = -1;
	config->C[0] = -1;
	config->player_position[0] = -1;
	config->player_direction = 'Z';
}

void	throw_error(char *error)
{
	printf("Error\n%s.\n", error);
	//exit(1);
}

int		is_one_of_these(char c, char *these)
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

void	print_struct(t_config *config)
{
	printf("NO: %s\nEA: %s\nSO: %s\nWE: %s\nF: %d, %d, %d\nC: %d, %d, %d\n",
			config->NO, config->EA, config->SO, config->WE,
			config->F[0], config->F[1], config->F[2],
			config->C[0], config->C[1], config->C[2]);
	printf("Player Position X: %d, Y: %d.\nPlayer Direction: %c\n",
	config->player_position[0],
	config->player_position[1],
	config->player_direction);
	int i = 0;
	printf("------START MAP------\n");
	while(config->map && config->map[i])
		printf("%s\n", config->map[i++]);
	printf("------END MAP------\n");
}

int	map_has_wall_at(t_config *config, float x, float y)
{
	int	map_index_x;
	int	map_index_y;

	if (x < 0 || x >= config->window_width
		|| y < 0 || y >= config->window_height)
			return (1);
	map_index_x = floor(x / TILE_SIZE);
	map_index_y = floor(y / TILE_SIZE);
	if (config->map[map_index_y][map_index_x] != '0')
		return (1);
	return (0);
	
}

float	distance_between_points(float x1, float y1, float x2, float y2)
{
	float	distance;

	distance = sqrt(((x2 - x1) * (x2 - x1)) + ((y2 - y1) * (y2 - y1)));
	return (distance);
}
