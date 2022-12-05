/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpaulino <rpaulino@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 03:40:56 by rpaulino          #+#    #+#             */
/*   Updated: 2022/12/03 04:06:34 by rpaulino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int	can_parse(char *file_content, int i)
{
	char	current;
	char	next;
	char	after_next;

	current = file_content[i];
	next = file_content[i + 1];
	after_next = file_content[i + 2];
	if (next == '\0' || after_next == '\0')
		throw_error("File not Completed");
	if (((current == 'N' && next == 'O')
			|| (current == 'S' && next == 'O')
			|| (current == 'W' && next == 'E')
			|| (current == 'E' && next == 'A'))
		&& after_next == ' ')
		return ((int)current);
	if (((current == 'F' || current == 'C')
			&& next == ' '))
		return ((int)current);
	return (0);
}

void	parse_line_content(char *file_content, char type)
{
	if (type == 'F' || type == 'C')
		parse_color(file_content + 1);
	else
		parse_path(file_content + 2);
}

int	found_map_number(char c)
{
	if (c == '0')
		throw_error("Map Started with 0");
	if (c == '1')
		return (1);
	return (0);
}

int	parse_settings(char *file_content)
{
	int	i;
	int	line;
	int	column;
	int	type;

	i = 0;
	line = 0;
	column = 0;
	while (file_content[i] != '\0' && !found_map_number(file_content[i]))
	{
		is_valid_char(file_content[i]);
		is_new_line(file_content[i], &line, &column);
		type = can_parse(file_content, i);
		if (type != 0)
		{
			parse_line_content(file_content + i, (char)type);
			i = jump_to_next_line(file_content, i);
		}
		column++;
		i++;
	}
	return (i - (column - 1));
}

void	parse_file_content(char *file_content)
{
	parse_settings(file_content);
}
