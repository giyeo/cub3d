/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_config.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjose-d <anjose-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 21:49:51 by rpaulino          #+#    #+#             */
/*   Updated: 2022/12/15 12:10:45 by anjose-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	assign_color(char type, t_config *config, int *color)
{
	if(type == 'F')
	{
		config->F[0] = color[0];
		config->F[1] = color[1];
		config->F[2] = color[2];
	}
	else
	{
		config->C[0] = color[0];
		config->C[1] = color[1];
		config->C[2] = color[2];
	}
}

void	parse_color(char *file_content, char type, t_config *config)
{
	char *line = ft_substr(file_content, 0, ft_str_find_idx(file_content, '\n'));
	int i = 0;
	int comma_index = 0;
	int start_index = 0;
	char *number_string;
	char *trimmed_number_string;
	int *color;

	color = (int *)(malloc(sizeof(int) * 3));
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
	assign_color(type, config, color);
	free(color);
	free(line);
}

void	test_path(char *path)
{
	int		fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		throw_error(strerror(errno));
	close(fd);
}

void	assign_config(char *path, char type, t_config *config)
{
	if(type == 'N')
		config->NO = path;
	if(type == 'W')
		config->WE = path;
	if(type == 'S')
		config->SO = path;
	if(type == 'E')
		config->EA = path;
}

void	parse_path(char *file_content, char type, t_config *config)
{
	char	*path;
	char	*trimmed_path;

	path = ft_substr(file_content, 0, ft_str_find_idx(file_content, '\n'));
	trimmed_path = ft_strtrim(path, " ");
	test_path(trimmed_path);
	
	assign_config(trimmed_path, type, config);
	free(path);
}

void	is_valid_char(char c)
{
	if (c != 'N' && c != 'O' && c != 'S'
		&& c != 'W' && c != 'E' && c != 'A'
		&& c != 'F' && c != 'C' && c != '1'
		&& c != '0' && c != ' ' && c != '\n'
		&& c != '\r')
			throw_error("Not Allowed Char in .cub file");
}

int	can_parse(char *line_content, int i)
{
	char	current;
	char	next;
	char	after_next;

	current = line_content[i];
	next = line_content[i + 1];
	after_next = line_content[i + 2];
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

void	parse_line_content(char *line_content, char type, t_config *config)
{
	//Impedir que venha mais de um tipo de variavel aqui.	
	if (type == 'F' || type == 'C')
		parse_color(line_content + 1, type, config);
	else
		parse_path(line_content + 2, type, config);
}

int	validate_config(char **buffer, t_config *config)
{	
	(void)config;
	int		line;
	int		column;
	int		type;
	char	*line_content;

	line = 0;
	while (buffer[line] != NULL)
	{
		line_content = buffer[line];
		column = 0;
		while (line_content[column] != '\0')
		{
			if(line_content[column] == '1')
				return (line);
			is_valid_char(line_content[column]);
			type = can_parse(line_content, column);
			if (type != 0)
			{
				parse_line_content(line_content + column, (char)type, config);
				break;
			}
			column++;
		}
		line++;
	}
	return (0);
}