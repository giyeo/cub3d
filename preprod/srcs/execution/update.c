#include "cub3d.h"

void	collision_detected(t_config *config, double backup_x, double backup_y)
{
	char	**map = config->map;
	double	px = config->player.x;
	double	py = config->player.y;
	double player_square = 0.2;

	if (map[(int)(py + player_square)][(int)(px + player_square)] == '1'
	|| map[(int)(py + player_square)][(int)(px - player_square)] == '1'
	|| map[(int)(py - player_square)][(int)(px + player_square)] == '1'
	|| map[(int)(py - player_square)][(int)(px - player_square)] == '1')
	{
		config->player.x = backup_x;
		config->player.y = backup_y;
	}
}

void	turn_with_mouse(t_config *config)
{
	int x;
	int y;
	t_player *player = &config->player;

	mlx_mouse_get_pos(config->conn_mlx.mlx_ptr, config->conn_mlx.win_ptr, &x, &y);
	if(x < 50)
		player->rotation_angle += player->turn_speed * -1;
	if(x > WINDOW_WIDTH - 50)
		player->rotation_angle += player->turn_speed;
}

double	zoom_control(t_config *config)
{
	double turn_speed = config->player.turn_speed;

	if(config->FOV < 60.0 && config->FOV > 20.0)
		config->FOV -= 1;
	if(config->FOV == 20.0)
		return turn_speed /= 4;
	return turn_speed;
}

void	player_moviments(t_config *config, double turn_speed)
{
	double		move_step;
	t_player	*player;

	player = &config->player;
	player->rotation_angle += player->turn_direction * turn_speed;
	move_step = player->walk_direction * player->walk_speed;

	player->x += cos(player->rotation_angle) * move_step;
	player->y += sin(player->rotation_angle) * move_step;
}

void	update(t_config *config)
{
	t_player	*player;
	double		backup_y;
	double		backup_x;
	double  	turn_speed;

	player = &config->player;
	backup_y = player->y;
	backup_x = player->x;

	turn_with_mouse(config);
	turn_speed = zoom_control(config);
	player_moviments(config, turn_speed);
	collision_detected(config, backup_x, backup_y);
}
