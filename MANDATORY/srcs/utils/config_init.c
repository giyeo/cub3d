/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjose-d <anjose-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 21:45:47 by rpaulino          #+#    #+#             */
/*   Updated: 2023/01/14 12:36:25 by anjose-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	config_init(t_config *config)
{
	config->no = NULL;
	config->we = NULL;
	config->so = NULL;
	config->ea = NULL;
	config->map = NULL;
	config->f[0] = -1;
	config->f[1] = -1;
	config->f[2] = -1;
	config->c[0] = -1;
	config->c[1] = -1;
	config->c[2] = -1;
	config->player_position[0] = -1;
	config->player_position[1] = -1;
	config->player_direction = 'Z';
	config->conn_mlx.mlx_ptr = NULL;
	config->conn_mlx.win_ptr = NULL;
	config->img.addr = NULL;
	config->img.mlx_img = NULL;
	config->fov = 60.0;
}
