/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_rect.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjose-d <anjose-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 17:52:01 by anjose-d          #+#    #+#             */
/*   Updated: 2023/01/04 17:56:59 by anjose-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	render_rect(t_config *config, int x, int y, int rect_height, int rect_width, int color)
{
	t_conn	*conn_mlx;
	t_img	*img;
	int		i;
	int		j;

	conn_mlx = &config->conn_mlx;
	if (conn_mlx->win_ptr == NULL)
		return (1);
	i = y;
	while (i < y + rect_height)
	{
		j = x;
		while (j < x + rect_width)
		{
			img_pix_put(config, j, i, color);
			j++;
		}
		i++;
	}
	return (0);
}