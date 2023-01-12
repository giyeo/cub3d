/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_map_start.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjose-d <anjose-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 17:27:10 by anjose-d          #+#    #+#             */
/*   Updated: 2023/01/11 21:05:27 by anjose-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_line(char *line);

int	find_map_start(char **read_file)
{
	int	map_start;

	map_start = 0;
	while (read_file[map_start] != NULL)
	{
		if (check_line(read_file[map_start]))
			break ;
		map_start++;
	}
	if (map_start == ft_mtxlen(read_file))
		return (-1);
	// e quando o mapa não é encontrado?
	// read_file == map_start?
	return (map_start);
}

int	check_line(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '1')
			return (1);
		if (ft_isspace(line[i]))
			i++;
		else
			break ;
	}
	return (0);
}
