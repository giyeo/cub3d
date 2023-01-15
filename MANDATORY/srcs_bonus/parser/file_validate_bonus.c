/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_validate_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjose-d <anjose-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 10:50:16 by anjose-d          #+#    #+#             */
/*   Updated: 2023/01/15 17:07:06 by anjose-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int	file_validate(char *file, int argc)
{
	int	fd;

	if (argc != 2)
		throw_error("Too many arguments");
	fd = file_check(file);
	if (fd < 0)
		return (throw_error("Error during .cub file validation"));
	if (extension_check(file) == -1)
		return (throw_error("Invalid file extension. Expected a *.cub file"));
	return (fd);
}
