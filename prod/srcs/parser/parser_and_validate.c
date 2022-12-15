#include "cub3d.h"

void	print_struct(t_config *config)
{
	printf(" NO: %s\n EA: %s\n SO: %s\n WE: %s\n F: %d, %d, %d\n C: %d, %d, %d\n",
			config->NO, config->EA, config->SO, config->WE,
			config->F[0], config->F[1], config->F[2],
			config->C[0], config->C[1], config->C[2]);
}
void	parser_and_validate(char **buffer, t_config *config)
{
	int map_start_line;

	map_start_line = validate_config(buffer, config);
	printf("%d\n", map_start_line);
	print_struct(config);
	// validate_map(map_start_line, buffer, config);
	ft_destroy_matrix(buffer);
	//Dei exit para não precisar fazer free da struct!
	exit(1);
}
