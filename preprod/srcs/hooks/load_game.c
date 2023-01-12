/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpaulino <rpaulino@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 01:12:15 by anjose-d          #+#    #+#             */
/*   Updated: 2023/01/12 09:50:24 by rpaulino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	load_game(t_config *config)
{
	static int counter = 0;
	time_t now = time(NULL);
	config->ciclo++;
	if (config->ciclo > 100)
		config->ciclo = 0;
	update(config);
	raycaster(config);
	minimap(config);
	
	if(now - config->start_time > 0)
	{
		printf("FPS:%d\n", counter);
		counter = 0;
		time(&config->start_time);
	}
	
	mlx_put_image_to_window(config->conn_mlx.mlx_ptr,
		config->conn_mlx.win_ptr,
		config->img.mlx_img, 0, 0);
	counter++;
	return (0);
}
