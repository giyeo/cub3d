/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjose-d <anjose-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 17:09:48 by anjose-d          #+#    #+#             */
/*   Updated: 2023/01/14 19:59:00 by anjose-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int	file_check(char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (-1);
	return (fd);
}
