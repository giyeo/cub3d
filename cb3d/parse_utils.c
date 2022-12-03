/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpaulino <rpaulino@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 03:51:06 by rpaulino          #+#    #+#             */
/*   Updated: 2022/12/03 05:00:05 by rpaulino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int	jump_to_next_line(char *file_content, int i)
{
	while (file_content[i] != '\n')
		i++;
	return (i - 1);
}

void	is_new_line(char c, int *line, int *column)
{
	if (c == '\n')
	{
		*(line) += 1;
		*(column) = 0;
	}
}

void	is_valid_char(char c)
{
	if (c != 'N' && c != 'O' && c != 'S'
		&& c != 'W' && c != 'E' && c != 'A'
		&& c != 'F' && c != 'C' && c != '1'
		&& c != '0' && c != ' ' && c != '\n')
		throw_error("Not Allowed Char in .cub file");
}

void	parse_color(char *file_content)
{
	int	i;

	i = 0;
	while (file_content[i] == ' ')
		i++;
	while (file_content[i] != '\n')
		i++;
}

void	parse_path(char *file_content)
{
	int		i;
	int		start;
	int		fd;
	char	*path;

	i = 0;
	start = 0;
	while (file_content[i] == ' ')
		i++;
	start = i;
	while (file_content[i] != '\n')
		i++;
	i--;
	while (file_content[i] == ' ')
		i--;
	i++;
	path = (char *)malloc(sizeof(char) * (i - start) + 1);
	strncpy(path, file_content + start, i - start);
	path[i - start] = '\0';
	fd = get_fd(path);
	python_log("OK");
	free(path);
	close(fd);
}
