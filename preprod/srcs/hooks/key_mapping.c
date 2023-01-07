/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_mapping.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjose-d <anjose-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 23:55:22 by anjose-d          #+#    #+#             */
/*   Updated: 2023/01/03 22:12:10 by anjose-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	key_pressed(int keysym, t_config *config)
{
	if (keysym == ESC)
		end_game(config);
	if (keysym == UP_ARROW || keysym == W)
		config->player.walk_direction = 1;
	if (keysym == DOWN_ARROW || keysym == S)
		config->player.walk_direction = -1;
	if (keysym == LEFT_ARROW || keysym == A)
		config->player.turn_direction = -1;
	if (keysym == RIGHT_ARROW || keysym == D)
		config->player.turn_direction = 1;
	if (keysym == Q)
		config->player.interact = 1;
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

int mouse_handler(int button, int x, int y, t_config *config)
{

}