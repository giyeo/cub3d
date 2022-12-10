#include "cub3d.h"

int matrix_height = 5;
int matrix_width = 5;

char matrix[5][5] =
{{'1','1','1','0','0'}
,{'1','0','0','0','1'}
,{'1','0','0','0','1'}
,{'1','1','1','0','0'}
,{'1','0','0','0','1'}};

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

int this_point_is_in_a_line(double i, double j, double ox, double oy, double rotation_angle)
{
    double bx; 
    double by;
	double slope_ab;

	if(oy - by == 0)
		return (0);
	bx = floor(ox + cos(rotation_angle) * 100.0);
	by = floor(oy + sin(rotation_angle) * 100.0);
	slope_ab = (ox - bx) / (oy - by);
	if (j - oy == slope_ab * (i - ox))
		return (1);
    return(0);
}

int update(t_data *img)
{
	img->old_player_x = img->player_x;
	img->old_player_y = img->player_y;

	if(img->walk_fb != 0)
	{
		img->player_y += img->walk_fb * img->player_speed;
	}
	if(img->walk_lr != 0)
	{
		img->player_x += img->walk_lr * img->player_speed;
	}
	if(img->turn_dr != 0)
	{
		img->rotation_angle += img->turn_dr * img->rotation_speed;
	}
		return (0);
}

int	draw(t_data *img)
{
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
				my_mlx_pixel_put(img, i, j, mlx_get_hex_trgb(125,125,125));
				width++;
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
            if(this_point_is_in_a_line(i, j, img->player_x, img->player_y, img->rotation_angle))
                my_mlx_pixel_put(img, i, j, mlx_get_hex_trgb(0,255,0));
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
