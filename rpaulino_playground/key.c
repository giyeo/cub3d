#include "cub3d.h"

int key_pressed(int event, t_data *img)
{
	if (event == KEY_W)
        img->walk_fb = 1;
	if (event == KEY_S)
        img->walk_fb = -1;
	if (event == KEY_D)
        img->walk_lr = 1;
	if (event == KEY_A)
        img->walk_lr = -1;
    if (event == KEY_RIGHT)
		img->rotation_angle += img->rotation_speed;
    if (event == KEY_LEFT)
		img->rotation_angle -= img->rotation_speed;
	return (0);
}

int key_released(int event, t_data *img)
{
	if (event == KEY_W)
        img->walk_fb = 0;
	if (event == KEY_S)
        img->walk_fb = 0;
	if (event == KEY_D)
        img->walk_lr = 0;
	if (event == KEY_A)
        img->walk_lr = 0;
	return (0);
}

void	input(t_data *img)
{
	mlx_hook(img->mlx_win, 2, 1l << 0, key_pressed, img);
	mlx_hook(img->mlx_win, 3, 1l << 1, key_released, img);
	//mlx_hook(img->mlx_win, 33, 1l << 17, key_exit, img);
	mlx_loop_hook(img->mlx, draw, img);
}
