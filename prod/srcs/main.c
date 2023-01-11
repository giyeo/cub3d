/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjose-d <anjose-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 12:02:23 by rpaulino          #+#    #+#             */
/*   Updated: 2023/01/11 17:55:13 by anjose-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char *argv[])
{
	t_config	config;
	char		**buffer;
	int			fd;
	int			ret;

	config_init(&config);
	fd = file_validate(argv[1], argc);
	if (fd < 0)
		return (-1);
	buffer = read_file(fd, argv[1]);
	close(fd);
	ret = parser_and_validate(buffer, &config);
	if (ret)
		return (-1);
	ft_destroy_matrix(buffer);
	print_struct(&config);
	free_config(&config);
	return (0);
}
