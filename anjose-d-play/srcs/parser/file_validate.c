/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_validate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjose-d <anjose-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 10:50:16 by anjose-d          #+#    #+#             */
/*   Updated: 2022/12/15 10:55:04 by anjose-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	file_validate(char *file, int argc)
{
	int	fd;

	if (argc != 2)
		throw_error("Too many arguments");
	fd = file_check(file);
	if (fd < 0)
		throw_error(strerror(errno));
	if (extension_check(file) == -1)
		throw_error("Invalid file extension. Expected a *.cub file");
	return (fd);
}
