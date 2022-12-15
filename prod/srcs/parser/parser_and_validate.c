#include "cub3d.h"

void	parser_and_validate(char **buffer, t_config *config)
{
	int map_start_line;

	map_start_line = validate_config(buffer, config);
	(void)(map_start_line);
	// validate_map(map_start_line, buffer, config);
	ft_destroy_matrix(buffer);
}
