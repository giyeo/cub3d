/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjose-d <anjose-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 17:09:48 by anjose-d          #+#    #+#             */
/*   Updated: 2022/12/14 21:31:38 by anjose-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <errno.h>

int	file_check(char *file, int argc)
{
	int	fd;

	if (argc != 2)
		throw_error("Too many arguments");
	fd = open(file, O_RDONLY);
	if (fd < 0)
		throw_error(strerror(errno));
	if (extension_check(file) == -1)
		throw_error("Invalid file extension. Expected a *.cub file");
	return (fd);
}
