/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjose-d <anjose-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 23:24:50 by anjose-d          #+#    #+#             */
/*   Updated: 2023/01/11 23:24:50 by anjose-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	collision_detected(t_config *config, double backup_x, double backup_y)
{
	char	**map;
	double	px;
	double	py;
	double	player_square;

	map = config->map;
	px = config->player.x;
	py = config->player.y;
	player_square = 0.2;
	if (map[(int)(py + player_square)][(int)(px + player_square)] == '1'
	|| map[(int)(py + player_square)][(int)(px - player_square)] == '1'
	|| map[(int)(py - player_square)][(int)(px + player_square)] == '1'
	|| map[(int)(py - player_square)][(int)(px - player_square)] == '1')
	{
		config->player.x = backup_x;
		config->player.y = backup_y;
	}
}

void	player_moviments(t_config *config)
{
	double		move_step;
	double		move_side;
	t_player	*player;

	player = &config->player;
	player->rotation_angle += player->turn_direction * player->turn_speed;
	move_step = player->walk_direction * player->walk_speed;
	move_side = player->walk_side_direction * player->walk_speed;
	player->x += cos(player->rotation_angle) * move_step;
	player->y += sin(player->rotation_angle) * move_step;
	player->x += cos(player->rotation_angle + PI / 2) * move_side;
	player->y += sin(player->rotation_angle + PI / 2) * move_side;
}

void	update(t_config *config)
{
	t_player	*player;
	double		backup_y;
	double		backup_x;

	player = &config->player;
	backup_y = player->y;
	backup_x = player->x;
	player_moviments(config);
	collision_detected(config, backup_x, backup_y);
}
