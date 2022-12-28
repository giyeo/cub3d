/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjose-d <anjose-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 17:03:52 by anjose-d          #+#    #+#             */
/*   Updated: 2022/12/27 22:16:17 by anjose-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		check_map(char **buffer, int first_line, t_config *config);
int		check_surroundings(char **buffer, int line, int col);
void	is_player(char **buffer, int line, int col, t_config *config);

int	validate_map(char **buffer, t_config *config)
{
	int	first_line;
	int	i;
	first_line = find_split_line(buffer) + 1;
	i = first_line;
	// checar se está circundado por 1
	if (check_map(buffer, first_line, config))
		return (-1); // throw_error
	while (buffer[i])
	{
		// check invalid chars
		if(only_these(buffer[i], ONLY_CHARS_MAP))
			return (-1);  // throw_error
		i++;
	}
	config->map = ft_mtxcpy(buffer + first_line);
	return (0);
}

int	check_map(char **buffer, int first_line, t_config *config)
{
	int	line;
	// checking first line;
	if (only_these(buffer[first_line], "1 "))
		return (-1);
	// check line on the bottom;
	if (only_these(buffer[ft_mtxlen(buffer) - 1], "1 "))
		return (-1);
	find_player(buffer, first_line, config);
	line = first_line + 1;
	while (buffer[line])	// ja começa na segunda linha
	{
		int i = 0;
		while (buffer[line][i])
		{
			is_player(buffer, line, i, config);
			if (is_one_of_these(buffer[line][i], "0NSWE")
			&& check_surroundings(buffer, line, i))
					return (-1);
			i++;
		}
		line++;
	}
	return (0);
}

int	check_surroundings(char **buffer, int line, int col)
{
	// se posição atual 0 passa do tamanho da linha anterior
		// return -1
	if (col == 0
		|| strlen(buffer[line - 1]) < (size_t)col
		|| strlen(buffer[line + 1]) < (size_t)col)
		return (-1);
	if ((!is_one_of_these(buffer[line][col - 1], ONLY_CHARS_MAP)	// checa esquerda
		|| !is_one_of_these(buffer[line][col + 1], ONLY_CHARS_MAP)		// checa direita
		|| !is_one_of_these(buffer[line - 1][col], ONLY_CHARS_MAP)		// checa topo
		|| !is_one_of_these(buffer[line + 1][col], ONLY_CHARS_MAP)))		// checa bottom
		return (-1);
	return (0);
}

void	is_player(char **buffer, int line, int col, t_config *config)
{
	if (is_one_of_these(buffer[line][col], PLAYER_DIRECTIONS)
		&& (config->player_position[0] != line || config->player_position[1] != col))
			throw_error("The map has two players");
}