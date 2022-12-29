/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjose-d <anjose-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 23:56:34 by anjose-d          #+#    #+#             */
/*   Updated: 2022/12/29 00:24:34 by anjose-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	end_game(t_config *config)
{
	if (config->conn_mlx.mlx_ptr)
	{
		mlx_destroy_window(config->conn_mlx.mlx_ptr, config->conn_mlx.win_ptr);
		mlx_destroy_display(config->conn_mlx.mlx_ptr);
		free(config->conn_mlx.mlx_ptr);
	}
	free_config(config);
	exit (0);
}