#include "cub3d.h"

int key_pressed(int event, t_data *img)
{
	if (event == 44)//44
        img->walk_fb = -1;
	if (event == 101)//101
        img->walk_fb = 1;
	if (event == 97)//97
        img->walk_lr = 1;
	if (event == 105)//105
        img->walk_lr = -1;
    if (event == KEY_RIGHT)
		img->turn_dr = 1;
    if (event == KEY_LEFT)
		img->turn_dr = -1;
	printf("%d\n", event);
	return (update(img));
}

int key_released(int event, t_data *img)
{
	if (event == 44)
        img->walk_fb = 0;
	if (event == 101)
        img->walk_fb = 0;
	if (event == 97)
        img->walk_lr = 0;
	if (event == 105)
        img->walk_lr = 0;
	if (event == KEY_RIGHT)
		img->turn_dr = 0;
    if (event == KEY_LEFT)
		img->turn_dr = 0;
	return (0);
}

void	input(t_data *img)
{
	mlx_hook(img->mlx_win, 2, 1l << 0, key_pressed, img);
	mlx_hook(img->mlx_win, 3, 1l << 1, key_released, img);
	//mlx_hook(img->mlx_win, 33, 1l << 17, key_exit, img);
	mlx_loop_hook(img->mlx, draw, img);
}
