#include "cub3d.h"

void	config_init(t_config *config)
{
	time(&config->start_time);
	config->scale = MINIMAP_SCALE_FACTOR;
	config->NO = NULL;
	config->WE = NULL;
	config->SO = NULL;
	config->EA = NULL;
	config->map = NULL;
	config->F[0] = -1;
	config->C[0] = -1;
	config->player_position[0] = -1;
	config->player_position[1] = -1;
	config->player_direction = 'Z';
	config->conn_mlx.mlx_ptr = NULL;
	config->conn_mlx.win_ptr = NULL;
	config->img.addr = NULL;
	config->img.mlx_img = NULL;
	config->FOV = 60.0;
	config->ciclo = 0;
}
