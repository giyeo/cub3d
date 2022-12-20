#include <cub3d.h>

int	main(int argc, char *argv[])
{
	t_config	config;
	char		**buffer;
	int			fd;

	init(&config);
	fd = file_validate(argv[1], argc);
	buffer = read_file(fd, argv[1]);
	close(fd);
	parser_and_validate(buffer, &config);
	ft_destroy_matrix(buffer);
	// run (&config);
	print_struct(&config);
	free_config(&config);
	return (0);
}