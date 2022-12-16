/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjose-d <anjose-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 17:03:52 by anjose-d          #+#    #+#             */
/*   Updated: 2022/12/16 17:16:23 by anjose-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_map(char **buffer, int first_line, t_config *config);
int	check_surroundings(char **buffer, int line, int col, int player_pos[2]);

int	validate_map(char **buffer, t_config *config)
{
	int	first_line;
	int	i;

	first_line = find_split_line(buffer) + 1;
	
	i = first_line;
	// checar se está circundado por 1
	if (check_map(buffer, first_line, config))
		return (-1);
	while (buffer[i])
	{
		// check invalid chars
		if(only_these(buffer[i], ONLY_CHARS_MAP))
			return (-1);
		i++;
	}
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
			if (buffer[line][i] == '0')
			{
				if (i == 0)				// canto esquerdo
					return (-1);
				else {
					if (check_surroundings(buffer, line, i, config->player_position))
						return (-1);
				}
			}
			i++;
		}
		line++;
	}
	return (0);
}

int	check_surroundings(char **buffer, int line, int col, int player_pos[2])
{
	if ((!is_one_of_these(buffer[line][col - 1], "01") && line != player_pos[0] && col != player_pos[1]) ||
	(!is_one_of_these(buffer[line][col + 1], "01") && line != player_pos[0] && col != player_pos[1])
	)
	{
		return (-1);
	}
	return (0);
}