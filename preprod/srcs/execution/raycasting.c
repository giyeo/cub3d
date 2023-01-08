#include "cub3d.h"


int	find_color_wall(int side[2], double distances);

void	raycaster(t_config *config)
{
	double FOV;

	FOV = config->FOV * (PI / 180);
	
	double distances;
	double angle = normalize_angle(config->player.rotation_angle - (FOV / 2.0));
	double wallstrip;
	int y = 0;
	int x = 0;
	int non_wall_strip = 0;
	while(x < WINDOW_WIDTH)
	{
		//DISTANCE PLAYER TO WALL
		config->player.is_middle = 0;
		if(x == WINDOW_WIDTH / 2)
			config->player.is_middle = 1;
		distances =
		render_line(config,
			(config->player.x * TILE_SIZE),
			(config->player.y * TILE_SIZE),
			((config->player.x * TILE_SIZE) + cos(angle) * (RAY_RANGE )),
			((config->player.y * TILE_SIZE) + sin(angle) * (RAY_RANGE )),
			mlx_get_hex_trgb(0, 0, 0),
			0
		);
		//FISHBALL EFFECT FIX
		distances = distances * cos(angle - config->player.rotation_angle);
		//NEXT ANGLE
		angle += normalize_angle((FOV / WINDOW_WIDTH));
		//WALL HEIGHT
		wallstrip = (TILE_SIZE / distances) * (WINDOW_WIDTH / 2) / tan(FOV / 2);
		//NON WALL HEIGHT
		non_wall_strip = (WINDOW_HEIGHT - wallstrip) / 2.0;
		//COLOR
		int colorwall = BLACK_PIXEL;
		if (x != (WINDOW_WIDTH / 2))//faz a linha preta no meio
			colorwall = find_color_wall(config->side, distances);

		// if(x == WINDOW_WIDTH / 2)
		// 		printf("#ANGLE:%f @SIDE:[%d,%d] &Text_col:%d:%d gap (%d - %f) / 2 = %f, %d\n",
		// 		angle, config->side[0], config->side[1],
		// 		 config->texture_col[0], config->texture_col[1],
		// 		WINDOW_HEIGHT, wallstrip, (WINDOW_HEIGHT - wallstrip) / 2, non_wall_strip);
		while(y < WINDOW_HEIGHT)
		{
			if(non_wall_strip <= 0)
				img_pix_put(&config->img, x, y, colorwall);
			else if(y < non_wall_strip)
				img_pix_put(&config->img, x, y, mlx_get_hex_trgb(50, 50, 50));
			else if(y < non_wall_strip + wallstrip)
				img_pix_put(&config->img, x, y, colorwall);
			else
				img_pix_put(&config->img, x, y, mlx_get_hex_trgb(150, 150, 150));
			y++;
		}
		y = 0;
		x++;
	}
}

int	find_color_wall(int side[2], double distances)
{
	int total_dist = WINDOW_WIDTH * 1.42;
	int color;
	//as vezes fica bugado com 1, -1  1, 1    -1 -1, para arrumar preciso do angulo dps faço
	if(side[1] == 1)//norte
		return mlx_get_hex_trgb(0, 0, 125 - (distances * 125 / total_dist));//azul
	else if(side[1] == -1 )//sul
		return mlx_get_hex_trgb(0, 255 - (distances * 254 / total_dist), 0);//green
	else if(side[0] == 1)//oeste
		return mlx_get_hex_trgb(255 - (distances * 254 / total_dist), 0, 0);//red
	else if(side[0] == -1)//leste white
		return mlx_get_hex_trgb(255 - (distances * 254 / total_dist), 255 - (distances * 254 / total_dist), 255 - (distances * 254 / total_dist));
}
