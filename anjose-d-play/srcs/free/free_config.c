/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_config.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjose-d <anjose-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 11:05:16 by anjose-d          #+#    #+#             */
/*   Updated: 2022/12/30 16:56:01 by anjose-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_img(t_config *config);

void	free_config(t_config *config)
{
	if (config)
	{
		if (config->NO)
			free(config->NO);
		if (config->SO)
			free(config->SO);
		if (config->WE)
			free(config->WE);
		if (config->EA)
			free(config->EA);
		if (config->map)
			ft_destroy_matrix(config->map);
		free_img(config);
	}
}

void	free_img(t_config *config)
{
	if (config->img.mlx_img)
		mlx_destroy_image(
			config->conn_mlx.mlx_ptr,
			config->img.mlx_img
		);
}
