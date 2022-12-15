#include <cub3d.h>

void	init(t_config *config)
{
	config->NO = NULL;
	config->WE = NULL;
	config->SO = NULL;
	config->EA = NULL;
	config->map = NULL;
	config->F[0] = -1;
	config->C[0] = -1;
}

int	main(int argc, char *argv[])
{
	void		*mlx;
	int			fd;
	char		**buffer;
	t_config	config;

	init(&config);
	fd = file_validate(argv[1], argc);
	buffer = read_file(fd, argv[1]);
	parser_and_validate(buffer, &config);
	// run (&config);

	(void)fd;
	(void)buffer;
	(void)config;
	(void)argc;
	(void)mlx;

	return (0);
}