/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjose-d <anjose-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 12:02:23 by rpaulino          #+#    #+#             */
/*   Updated: 2023/01/02 21:16:29 by anjose-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	img_init(t_img *img, t_config *config);

int	*load_textures(void *mlx)
{
	int	w;
	int	h;
	int		*addr;
	int		bpp;
	int		s_line;
	int		endian;
	int		color;

	void *img = mlx_xpm_file_to_image(mlx, "./textures/mine/1.xpm", &w, &h);
	if (!img)
	{
		ft_putendl_fd("No texture was found", 0);
		exit(0);
	}
	addr = (int32_t *)mlx_get_data_addr(img, &bpp, &s_line, &endian);

	return addr;
}

int	main(int argc, char *argv[])
{
	t_config	config;
	char		**buffer;
	int			fd;

	config_init(&config);
	fd = file_validate(argv[1], argc);
	buffer = read_file(fd, argv[1]);
	close(fd);
	parser_and_validate(buffer, &config);
	ft_destroy_matrix(buffer);
	config.texture_test = load_textures(config.conn_mlx.mlx_ptr);
	mlx_hook(config.conn_mlx.win_ptr, KeyPress, KeyPressMask, &key_pressed, &config);
	mlx_hook(config.conn_mlx.win_ptr, KeyRelease, KeyReleaseMask, &key_released, &config);
	mlx_hook(config.conn_mlx.win_ptr, DestroyNotify, NoEventMask, &end_game, &config);
	mlx_mouse_hook(config.conn_mlx.win_ptr, &mouse_handler, &config);
	mlx_loop_hook(config.conn_mlx.mlx_ptr, &load_game, &config);
	mlx_loop(config.conn_mlx.mlx_ptr);
	return (0);
}
