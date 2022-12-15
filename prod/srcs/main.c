#include <cub3d.h>

int	main(int argc, char *argv[])
{
	void		*mlx;
	int			fd;
	char		**buffer;
	t_config	config;

	fd = file_check(argv[1], argc);
	buffer = read_file(fd, argv[1]);
	//void parser(buffer, &config);
	// run (&config);

	(void)fd;
	(void)buffer;
	(void)config;
	(void)argc;
	(void)mlx;

	return (0);
}