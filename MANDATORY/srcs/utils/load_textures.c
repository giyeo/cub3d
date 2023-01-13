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
	int	no_use;

	config->textures.img_NO = mlx_xpm_file_to_image(
		config->conn_mlx.mlx_ptr,"./textures/mine/wall1.xpm", &no_use, &no_use);
	config->textures.img_SO = mlx_xpm_file_to_image(
		config->conn_mlx.mlx_ptr, "./textures/mine/wall2.xpm", &no_use, &no_use);
	config->textures.img_WE = mlx_xpm_file_to_image(
		config->conn_mlx.mlx_ptr, "./textures/mine/3.xpm", &no_use, &no_use);
	config->textures.img_EA = mlx_xpm_file_to_image(
		config->conn_mlx.mlx_ptr, "./textures/mine/4.xpm", &no_use, &no_use);
	if (!config->textures.img_NO || !config->textures.img_SO
	 || !config->textures.img_WE || !config->textures.img_EA)
	{
		throw_error("Texture not found");
		exit(1);
	}
	config->textures.NO = (int32_t *)mlx_get_data_addr(
		config->textures.img_NO, &no_use, &no_use, &no_use);
	config->textures.SO = (int32_t *)mlx_get_data_addr(
		config->textures.img_SO, &no_use, &no_use, &no_use);
	config->textures.WE = (int32_t *)mlx_get_data_addr(
		config->textures.img_WE, &no_use, &no_use, &no_use);
	config->textures.EA = (int32_t *)mlx_get_data_addr(
		config->textures.img_EA, &no_use, &no_use, &no_use);
}
