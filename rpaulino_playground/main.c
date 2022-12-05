#include "../prod/libft/includes/libft.h"
#include "../prod/minilibx/mlx.h"
#include <stdio.h>
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
}			t_data;

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

int	key_control(int key, t_data *img)
{
	img->old_player_x = img->player_x;
	img->old_player_y = img->player_y;
	if (key == 65363)
		img->player_x += 10;
	if (key == 65361)
		img->player_x -= 10;
	if (key == 65362)
		img->player_y -= 10;
	if (key == 65364)
		img->player_y += 10;
	draw(img);
	return (0);
}

void	draw(t_data *img)
{
    int i;
	int j;

	int matrix_height = 5;
	int matrix_width = 5;

	char matrix[5][5] =
	{{'1','1','1','0','0'}
	,{'1','0','0','0','1'}
	,{'1','0','0','0','1'}
	,{'1','1','1','1','0'}
	,{'1','0','0','0','1'}};

	int height = 0;
	int width = 0;

	j = 0;
	i = 0;
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
			if(this_point_is_in_a_circle(i,j,img->player_x, img->player_y, 50))
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
}

int main()
{
	t_data	img;

	img.screen_size = 1000;
	img.mlx = mlx_init();
	img.mlx_win = mlx_new_window(img.mlx, img.screen_size, img.screen_size, "2dMinirt");
	img.img = mlx_new_image(img.mlx, img.screen_size, img.screen_size);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	img.player_x = img.screen_size / 2;
	img.player_y = img.screen_size / 2;
	img.old_player_x = img.screen_size / 2;
	img.old_player_y = img.screen_size / 2;
	draw(&img);
	mlx_key_hook(img.mlx_win, key_control, &img);
	mlx_loop(img.mlx);
}