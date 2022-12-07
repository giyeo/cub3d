#include "cub3d.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	mlx_get_hex_trgb(int r, int g, int b)
{
	return ((r << 16) | (g << 8) | (b));
}

int	this_point_is_in_a_circle(int i, int j, int x_position, int y_position, int radius)
{
	if(((i - x_position) * (i - x_position)) + ((j - y_position) * (j - y_position)) < (radius * radius))
		return 1;
	return 0; 
}

int	draw(t_data *img)
{
	int matrix_height = 5;
	int matrix_width = 5;

	char matrix[5][5] =
	{{'1','1','1','0','0'}
	,{'1','0','0','0','1'}
	,{'1','0','0','0','1'}
	,{'1','1','1','1','0'}
	,{'1','0','0','0','1'}};

    int i = 0;
	int j = 0;
	int height = 0;
	int width = 0;

	//the collision detector should be here!
	while(height < matrix_height)
	{
		while(width < matrix_width)
		{
			//paint matriz squares 1 as white, 0 as black
			if(matrix[height][width] == '1')
				my_mlx_pixel_put(img, i, j, mlx_get_hex_trgb(255,255,255));
			else
				my_mlx_pixel_put(img, i, j, mlx_get_hex_trgb(0,0,0));
			//create horizontal grid lines
			if(i % (img->screen_size / matrix_width) == 0 && i != 0)
			{
				width++;
				my_mlx_pixel_put(img, i, j, mlx_get_hex_trgb(125,125,125));
			}
			//create vertical grid lines
			if(j % (img->screen_size / matrix_height) == 0 && j != 0)
				my_mlx_pixel_put(img, i, j, mlx_get_hex_trgb(125,125,125));
			//create a circle with player cordinates
			if(this_point_is_in_a_circle(i,j,img->player_x, img->player_y, img->player_radius))
			{
				//center of the circle collision
				if(matrix[height][width] != '1')
					my_mlx_pixel_put(img, i, j, mlx_get_hex_trgb(255,0,255));
				else
				{
					img->player_x = img->old_player_x;
					img->player_y = img->old_player_y;
				}
			}
			i++;
		}
		width = 0;
		i = 0;
		j++;
		if(j % (img->screen_size / matrix_height) == 0)
			height++;
	}
	mlx_put_image_to_window(img->mlx, img->mlx_win, img->img, 0, 0);
	return (0);
}
