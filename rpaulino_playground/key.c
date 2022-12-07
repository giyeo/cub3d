#include "cub3d.h"

int	key_pressed(int event, t_data *img)
{
	img->old_player_x = img->player_x;
    img->old_player_y = img->player_y;
	if (event == KEY_W)
	{
		//vars->player.walk_direction_fb = 1;
		img->player_y -= img->player_speed;
	}
	if (event == KEY_S)
	{
		//vars->player.walk_direction_fb = -1;
		img->player_y += img->player_speed;
	}
	if (event == KEY_D)
	{
		//vars->player.walk_direction_lr = 1;
		img->player_x += img->player_speed;
	}
	if (event == KEY_A)
	{
		//vars->player.walk_direction_lr = -1;
		img->player_x -= img->player_speed;
	}
	draw(img);
	return (0);
}

int	key_released(int event, t_data *img)
{
	printf("%d: released\n", event);
	// if (event == KEY_W)
	// if (event == KEY_S)
	// if (event == KEY_D)
	// if (event == KEY_A)
		
	return (0);
}

void	input(t_data *img)
{
	mlx_hook(img->mlx_win, 2, 1l << 0, key_pressed, img);
	mlx_hook(img->mlx_win, 3, 1l << 1, key_released, img);
	//mlx_hook(img->mlx_win, 33, 1l << 17, key_exit, img);
	mlx_loop_hook(img->mlx, draw, img);
}