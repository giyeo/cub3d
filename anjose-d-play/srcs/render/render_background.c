/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_background.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjose-d <anjose-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 11:52:13 by anjose-d          #+#    #+#             */
/*   Updated: 2023/01/04 18:02:32 by anjose-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	render_background(t_config *config, int color, t_img *img)
{
	int	i;
	int	j;

	if (config->conn_mlx.win_ptr == NULL)
		return (1);
	i = 0;
	while (i < config->window_height)
	{
		j = 0;
		while (j < config->window_height)
		{
			img_pix_put(config, j, i, color);
			j++;
		}
		i++;
	}
	return (0);
}
