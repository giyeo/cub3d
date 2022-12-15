#include "cub3d.h"

void	print_struct(t_config *config)
{
	printf("NO: %s\nEA: %s\nSO: %s\nWE: %s\nF: %d, %d, %d\nC: %d, %d, %d\n",
			config->NO, config->EA, config->SO, config->WE,
			config->F[0], config->F[1], config->F[2],
			config->C[0], config->C[1], config->C[2]);
}

void	check_struct(t_config *config)
{
	print_struct(config);
	if(config->NO == NULL || config->WE == NULL
	|| config->SO == NULL || config->EA == NULL
	|| config->F[0] == -1 || config->C[0] == -1)
		throw_error("Configuration missing");
}

void	parser_and_validate(char **buffer, t_config *config)
{
	int map_start_line;

	map_start_line = validate_config(buffer, config);
	check_struct(config);
	printf("map_start_line: %d\n", map_start_line);
	// validate_map(map_start_line, buffer, config);
	ft_destroy_matrix(buffer);
	//Dei exit para não precisar fazer free da struct!
	exit(1);
}
