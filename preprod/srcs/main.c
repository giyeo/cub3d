/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjose-d <anjose-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 12:02:23 by rpaulino          #+#    #+#             */
/*   Updated: 2023/01/11 23:41:00 by anjose-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		mouse_handler(int button, int x, int y, t_config *config)
{
	return (0);
}

void	img_init(t_img *img, t_config *config);

void	load_textures(t_config *config, void *mlx)
{
	int	no_use;

	config->textures.img_NO = mlx_xpm_file_to_image(
		config->conn_mlx.mlx_ptr,"./textures/mine/1.xpm", &no_use, &no_use);
	config->textures.img_SO = mlx_xpm_file_to_image(
		config->conn_mlx.mlx_ptr, "./textures/mine/2.xpm", &no_use, &no_use);
	config->textures.img_WE = mlx_xpm_file_to_image(
		config->conn_mlx.mlx_ptr, "./textures/mine/3.xpm", &no_use, &no_use);
	config->textures.img_EA = mlx_xpm_file_to_image(
		config->conn_mlx.mlx_ptr, "./textures/mine/4.xpm", &no_use, &no_use);
	if (!config->textures.img_NO || !config->textures.img_SO
	 || !config->textures.img_WE || !config->textures.img_EA)
	{
		throw_error("Texture not found");
		exit(1);
	}
	config->textures.NO = (int32_t *)mlx_get_data_addr(
		config->textures.img_NO, &no_use, &no_use, &no_use);
	config->textures.SO = (int32_t *)mlx_get_data_addr(
		config->textures.img_SO, &no_use, &no_use, &no_use);
	config->textures.WE = (int32_t *)mlx_get_data_addr(
		config->textures.img_WE, &no_use, &no_use, &no_use);
	config->textures.EA = (int32_t *)mlx_get_data_addr(
		config->textures.img_EA, &no_use, &no_use, &no_use);
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
	mlx_hook(config.conn_mlx.win_ptr, KeyPress, KeyPressMask, &key_pressed, &config);
	mlx_hook(config.conn_mlx.win_ptr, KeyRelease, KeyReleaseMask, &key_released, &config);
	mlx_hook(config.conn_mlx.win_ptr, DestroyNotify, NoEventMask, &end_game, &config);
	mlx_mouse_hook(config.conn_mlx.win_ptr, &mouse_handler, &config);
	load_textures(&config, config.conn_mlx.mlx_ptr);
	mlx_loop_hook(config.conn_mlx.mlx_ptr, &load_game, &config);
	mlx_loop(config.conn_mlx.mlx_ptr);
	return (0);
}
