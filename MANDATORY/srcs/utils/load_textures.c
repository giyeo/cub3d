/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpaulino <rpaulino@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 19:30:59 by rpaulino          #+#    #+#             */
/*   Updated: 2023/01/13 19:30:59 by rpaulino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	load_textures(t_config *config, void *mlx)
{
	int	none;

	config->textures.img_NO = mlx_xpm_file_to_image(
			config->conn_mlx.mlx_ptr, "./textures/mine/wall1.xpm", &none, &none);
	config->textures.img_SO = mlx_xpm_file_to_image(
			config->conn_mlx.mlx_ptr, "./textures/mine/wall2.xpm", &none, &none);
	config->textures.img_WE = mlx_xpm_file_to_image(
			config->conn_mlx.mlx_ptr, "./textures/mine/3.xpm", &none, &none);
	config->textures.img_EA = mlx_xpm_file_to_image(
			config->conn_mlx.mlx_ptr, "./textures/mine/4.xpm", &none, &none);
	if (!config->textures.img_NO || !config->textures.img_SO
		|| !config->textures.img_WE || !config->textures.img_EA)
	{
		throw_error("Texture not found");
		exit(1);
	}
	config->textures.NO = (int32_t *)mlx_get_data_addr(
			config->textures.img_NO, &none, &none, &none);
	config->textures.SO = (int32_t *)mlx_get_data_addr(
			config->textures.img_SO, &none, &none, &none);
	config->textures.WE = (int32_t *)mlx_get_data_addr(
			config->textures.img_WE, &none, &none, &none);
	config->textures.EA = (int32_t *)mlx_get_data_addr(
			config->textures.img_EA, &none, &none, &none);
}
