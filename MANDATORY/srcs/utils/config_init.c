/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpaulino <rpaulino@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 21:45:47 by rpaulino          #+#    #+#             */
/*   Updated: 2023/01/13 21:49:51 by rpaulino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	config_init(t_config *config)
{
	config->NO = NULL;
	config->WE = NULL;
	config->SO = NULL;
	config->EA = NULL;
	config->map = NULL;
	config->F[0] = -1;
	config->C[0] = -1;
	config->player_position[0] = -1;
	config->player_position[1] = -1;
	config->player_direction = 'Z';
	config->conn_mlx.mlx_ptr = NULL;
	config->conn_mlx.win_ptr = NULL;
	config->img.addr = NULL;
	config->img.mlx_img = NULL;
	config->FOV = 60.0;
}
