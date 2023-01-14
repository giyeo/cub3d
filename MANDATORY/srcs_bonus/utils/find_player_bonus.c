/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjose-d <anjose-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 17:02:26 by anjose-d          #+#    #+#             */
/*   Updated: 2023/01/14 20:01:19 by anjose-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int	find_player(char **buffer, int first_line, t_config *config)
{
	int	line;
	int	col;

	line = first_line;
	while (buffer[line])
	{
		col = 0;
		while (buffer[line][col])
		{
			if (!is_one_of_these(buffer[line][col], "01 ") &&
				is_one_of_these(buffer[line][col], PLAYER_DIRECTIONS))
			{
				config->player_position[0] = line;
				config->player_position[1] = col;
				config->player_direction = buffer[line][col];
				break ;
			}
			col++;
		}
		line++;
	}
	if (config->player_position[0] == -1)
		return (-1);
	return (0);
}
