/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpaulino <rpaulino@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 03:38:39 by rpaulino          #+#    #+#             */
/*   Updated: 2022/12/10 19:32:11 by rpaulino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

//# include "../../minilibx-linux/mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
#include <math.h>
#include "../prod/libft/includes/libft.h"
#include "../prod/minilibx/mlx.h"
# include <string.h> //Ilegal
//_____________________________
# define KEY_ESC 65307

# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100

# define KEY_UP 65362
# define KEY_DOWN 65364
# define KEY_LEFT 65361
# define KEY_RIGHT 65363

# define PI 3.14159265359

typedef struct	s_data {
	void	*mlx;
	void	*mlx_win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		screen_size;
	int		player_x;
	int		old_player_x;
	int		player_y;
	int		old_player_y;
	int		player_radius;
	int		player_speed;
	double	rotation_angle;
	double	rotation_speed;
	int		walk_fb;
	int		walk_lr;
	int		turn_dr;

}			t_data;

int		draw(t_data *img);
void	input(t_data *img);
int		update(t_data *img);
#endif