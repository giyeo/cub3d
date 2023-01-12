/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_mapping.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjose-d <anjose-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 23:55:22 by anjose-d          #+#    #+#             */
/*   Updated: 2023/01/11 23:24:31 by anjose-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	key_pressed(int keysym, t_config *config)
{
	if (keysym == ESC || keysym == Q)
		end_game(config);
	if (keysym == UP_ARROW || keysym == W)
		config->player.walk_direction = 1;
	if (keysym == DOWN_ARROW)
		config->player.walk_direction = -1;
	if (keysym == LEFT_ARROW)
		config->player.turn_direction = -1;
	if (keysym == RIGHT_ARROW || keysym == D)
		config->player.turn_direction = 1;
	if (keysym == 32)
		config->player.interact = 1;
	if (keysym == 101)
	{
		config->FOV -= 1;
		if(config->FOV == 19.0)
			config->FOV = 60.0;
	}
	return (0);
}

int	key_released(int keysym, t_config *config)
{
	if (keysym == UP_ARROW || keysym == W)
		config->player.walk_direction = 0;
	if (keysym == DOWN_ARROW || keysym == S)
		config->player.walk_direction = 0;
	if (keysym == LEFT_ARROW || keysym == A)
		config->player.turn_direction = 0;
	if (keysym == RIGHT_ARROW || keysym == D)
		config->player.turn_direction = 0;
	return (0);
}
