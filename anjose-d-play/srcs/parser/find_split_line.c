/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_split_line.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjose-d <anjose-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 17:27:10 by anjose-d          #+#    #+#             */
/*   Updated: 2022/12/15 20:03:34 by anjose-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	find_split_line(char **read_file)
{
	int	idx_line;
	int	mtx_size;

	mtx_size = ft_mtxlen(read_file);
	idx_line = mtx_size;
	while (read_file[idx_line - 1] && idx_line)
	{
		idx_line--;
		if (read_file[idx_line][0] == 0)
			break ;
	}
	return (idx_line);
}
