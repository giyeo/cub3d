/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_rect.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjose-d <anjose-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 17:52:01 by anjose-d          #+#    #+#             */
/*   Updated: 2022/12/29 21:56:37 by anjose-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	render_rect(t_conn conn_mlx, int x, int y, int rect_height, int rect_width, int color, t_img *img)
{
	int	i;
	int j;

	if (conn_mlx.win_ptr == NULL)
		return (1);
	i = y;
	while (i < y + rect_height)
	{
		j = x;
		while (j < x + rect_width)
		{
			img_pix_put(img, j, i, color);
			j++;
		}
		i++;
	}
	return (0);
}