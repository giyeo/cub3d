/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_mapping.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpaulino <rpaulino@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 23:55:22 by anjose-d          #+#    #+#             */
/*   Updated: 2023/01/12 10:42:49 by rpaulino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	key_pressed(int keysym, t_config *config)
{
	if (keysym == ESC || keysym == Q)
		end_game(config);
	if (keysym == UP_ARROW || keysym == W)
		config->player.walk_direction = 1;
	if (keysym == DOWN_ARROW || keysym == S)
		config->player.walk_direction = -1;
	if (keysym == LEFT_ARROW)
		config->player.turn_direction = -1;
	if (keysym == RIGHT_ARROW)
		config->player.turn_direction = 1;
	if (keysym == D)
		config->player.walk_side_direction = 1;
	if (keysym == A)
		config->player.walk_side_direction = -1;
	if (keysym == 32)
		config->player.interact = 1;
	if (keysym == 101)
		config->FOV -= 1;
	if (keysym == 117 && config->scale < 0.5)
		config->scale += 0.05;
	if (keysym == 121 && config->scale > 0.1)
		config->scale -= 0.05;
	return (0);
}

int	key_released(int keysym, t_config *config)
{
	if (keysym == UP_ARROW || keysym == W)
		config->player.walk_direction = 0;
	if (keysym == DOWN_ARROW || keysym == S)
		config->player.walk_direction = 0;
	if (keysym == LEFT_ARROW || keysym == RIGHT_ARROW)
		config->player.turn_direction = 0;
	if (keysym == A || keysym == D)
		config->player.walk_side_direction = 0;
	return (0);
}
