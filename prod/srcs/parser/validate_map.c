/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjose-d <anjose-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 17:03:52 by anjose-d          #+#    #+#             */
/*   Updated: 2023/01/13 20:43:12 by anjose-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int		check_map(char **buffer, int first_line, t_config *config);
static int		check_surroundings(char **buffer, int line, int col);
static int		is_player(char **buffer, int line, int col, t_config *config);

int	validate_map(char **buffer, t_config *config)
{
	int	first_line;
	int	i;
	int	ret;

	first_line = 0;
	i = first_line;
	ret = check_map(buffer, first_line, config);
	if (ret)
		return (ret);
	while (buffer[i])
	{
		if (only_these(buffer[i], ONLY_CHARS_MAP))
			return (ERR_MAP_INVALID);
		i++;
	}
	config->map = ft_mtxcpy(buffer + first_line);
	ret = check_struct(config);
	return (ret);
}

static int	check_map(char **buffer, int first_line, t_config *config)
{
	int	line;
	int	ret;
	int	col;

	if (only_these(buffer[first_line], "1 ")
		|| only_these(buffer[ft_mtxlen(buffer) - 1], "1 "))
		return (ERR_MAP_INVALID);
	find_player(buffer, first_line, config);
	line = first_line + 1;
	while (buffer[line])
	{
		col = 0;
		while (buffer[line][col])
		{
			ret = is_player(buffer, line, col, config);
			if (ret)
				return (ret);
			if (is_one_of_these(buffer[line][col], "0NSWE")
			&& check_surroundings(buffer, line, col))
				return (ERR_MAP_INVALID);
			col++;
		}
		line++;
	}
	return (0);
}

static int	check_surroundings(char **buffer, int line, int col)
{
	if (col == 0
		|| ft_strlen(buffer[line - 1]) < (size_t)col
		|| ft_strlen(buffer[line + 1]) < (size_t)col)
		return (-1);
	if ((!is_one_of_these(buffer[line][col - 1], ONLY_CHARS_MAP)
		|| !is_one_of_these(buffer[line][col + 1], ONLY_CHARS_MAP)
		|| !is_one_of_these(buffer[line - 1][col], ONLY_CHARS_MAP)
		|| !is_one_of_these(buffer[line + 1][col], ONLY_CHARS_MAP)))
		return (-1);
	return (0);
}

static int	is_player(char **buffer, int line, int col, t_config *config)
{
	if (is_one_of_these(buffer[line][col], PLAYER_DIRECTIONS)
		&& (config->player_position[0] != line
		|| config->player_position[1] != col))
		return (ERR_MORE_THAN_ONE_PLAYER);
	return (0);
}
