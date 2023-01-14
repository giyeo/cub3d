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

#include "cub3d_bonus.h"

void	load_textures(t_config *config)
{
	int	none;

	config->textures.img_no = mlx_xpm_file_to_image(
			config->conn_mlx.mlx_ptr, config->no, &none, &none);
	config->textures.img_so = mlx_xpm_file_to_image(
			config->conn_mlx.mlx_ptr, config->so, &none, &none);
	config->textures.img_we = mlx_xpm_file_to_image(
			config->conn_mlx.mlx_ptr, config->we, &none, &none);
	config->textures.img_ea = mlx_xpm_file_to_image(
			config->conn_mlx.mlx_ptr, config->ea, &none, &none);
	if (!config->textures.img_no || !config->textures.img_so
		|| !config->textures.img_we || !config->textures.img_ea)
	{
		throw_error("Texture not found");
		exit(1);
	}
	config->textures.no = (int32_t *)mlx_get_data_addr(
			config->textures.img_no, &none, &none, &none);
	config->textures.so = (int32_t *)mlx_get_data_addr(
			config->textures.img_so, &none, &none, &none);
	config->textures.we = (int32_t *)mlx_get_data_addr(
			config->textures.img_we, &none, &none, &none);
	config->textures.ea = (int32_t *)mlx_get_data_addr(
			config->textures.img_ea, &none, &none, &none);
}
