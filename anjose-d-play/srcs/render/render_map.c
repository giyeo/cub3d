/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjose-d <anjose-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 01:20:32 by anjose-d          #+#    #+#             */
/*   Updated: 2023/01/03 17:41:49 by anjose-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	render_map(t_config *config, int map_y, int map_x, int pixel_i, int pixel_j)
{
	if (config->map[map_y][map_x] == '1')
		img_pix_put(&config->img, pixel_i, pixel_j, WHITE_PIXEL);
	else
		img_pix_put(&config->img, pixel_i, pixel_j, BLACK_PIXEL);
}
