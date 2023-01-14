/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjose-d <anjose-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 23:56:34 by anjose-d          #+#    #+#             */
/*   Updated: 2023/01/14 19:58:50 by anjose-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	free_imgs(t_config *config);

int	end_game(t_config *config)
{
	free_config(config);
	if (config->conn_mlx.mlx_ptr)
	{
		free_imgs(config);
		mlx_destroy_window(config->conn_mlx.mlx_ptr, config->conn_mlx.win_ptr);
		mlx_destroy_display(config->conn_mlx.mlx_ptr);
		free(config->conn_mlx.mlx_ptr);
		config->conn_mlx.mlx_ptr = NULL;
		config->conn_mlx.win_ptr = NULL;
	}
	exit (0);
}

void	free_imgs(t_config *config)
{
	void	*mlx_ptr;

	mlx_ptr = config->conn_mlx.mlx_ptr;
	if (config->img.mlx_img)
		mlx_destroy_image(mlx_ptr, config->img.mlx_img);
	if (config->textures.img_no)
		mlx_destroy_image(mlx_ptr, config->textures.img_no);
	if (config->textures.img_so)
		mlx_destroy_image(mlx_ptr, config->textures.img_so);
	if (config->textures.img_we)
		mlx_destroy_image(mlx_ptr, config->textures.img_we);
	if (config->textures.img_ea)
		mlx_destroy_image(mlx_ptr, config->textures.img_ea);
}
