/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpaulino <rpaulino@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 03:32:11 by rpaulino          #+#    #+#             */
/*   Updated: 2022/12/20 11:56:24 by rpaulino         ###   ########.fr       */
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

void	init(t_config *config)
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
	while(config->map[i])
		printf("%s\n", config->map[i++]);
	printf("------END MAP------\n");
}