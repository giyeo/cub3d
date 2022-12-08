/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpaulino <rpaulino@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 03:51:06 by rpaulino          #+#    #+#             */
/*   Updated: 2022/12/08 01:04:03 by rpaulino         ###   ########.fr       */
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
	char *line = ft_substr(file_content, 0, ft_str_find_idx(file_content, '\n'));
	int i = 0;
	int comma_index = 0;
	int start_index = 0;
	char *number_string;
	char *trimmed_number_string;
	int color[3];
	while(i < 3)
	{
		comma_index = ft_str_find_idx(line + start_index, ',');
		if(comma_index == -1)
			comma_index = ft_str_find_idx(line + start_index, '\0');
		number_string = ft_substr(line, start_index, comma_index);
		trimmed_number_string = ft_strtrim(number_string, " ");
		color[i++] = ft_atoi(trimmed_number_string);
		start_index += comma_index + 1;
		free(number_string);
		free(trimmed_number_string);
	}
	printf("%d %d %d\n", color[0], color[1], color[2]);
	free(line);
}

void	test_path(char *path)
{
	int		fd;

	fd = get_fd(path);
	python_log("OK");
	close(fd);
}

void	parse_path(char *file_content)
{
	char	*path;
	char	*trimmed_path;

	path = ft_substr(file_content, 0, ft_str_find_idx(file_content, '\n'));
	trimmed_path = ft_strtrim(path, " ");
	test_path(trimmed_path);
	
	free(trimmed_path);
	free(path);
}
