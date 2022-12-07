#include "cub3d.h"

void	setup(t_data *img)
{
	img->screen_size = 900;
	img->player_radius = img->screen_size / 100;
	img->player_speed = 2;
	img->player_x = img->screen_size / 2;
	img->player_y = img->screen_size / 2;
	img->old_player_x = img->screen_size / 2;
	img->old_player_y = img->screen_size / 2;
	img->rotation_angle = PI / 2;
	img->rotation_speed = 2 * (PI / 180);
	img->walk_fb = 0;
	img->walk_lr = 0;
}

void	init(t_data *img)
{
	setup(img);
	img->mlx = mlx_init();
	img->mlx_win = mlx_new_window(img->mlx, img->screen_size, img->screen_size, "cub3d");
	img->img = mlx_new_image(img->mlx, img->screen_size, img->screen_size);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel, &img->line_length, &img->endian);
}

int main(void)
{
	t_data	img;

	init(&img);
	draw(&img);
	input(&img);
	mlx_loop(img.mlx);
	return(0);
}
