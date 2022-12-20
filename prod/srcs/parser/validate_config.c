/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_config.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpaulino <rpaulino@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 21:49:51 by rpaulino          #+#    #+#             */
/*   Updated: 2022/12/20 12:09:14 by rpaulino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	assign_color(char type, t_config *config, int *color)
{
	if (type == 'F' && config->F[0] == -1)
	{
		config->F[0] = color[0];
		config->F[1] = color[1];
		config->F[2] = color[2];
	}
	else if (type == 'C' && config->C[0] == -1)
	{
		config->C[0] = color[0];
		config->C[1] = color[1];
		config->C[2] = color[2];
	}
	else
		throw_error("Duplicate of Colors");
}

void	parse_color(char *file_content, char type, t_config *config)
{
	int		i;
	int		comma_index;
	int		start_index;
	char	*number_string;
	char	*trimmed_number_string;
	int		*color;

	i = 0;
	start_index = 0;
	comma_index = 0;
	color = (int *)(malloc(sizeof(int) * 3));
	while (i < 3)
	{
		comma_index = ft_str_find_idx(file_content + start_index, ',');
		if (comma_index == -1)
			comma_index = ft_str_find_idx(file_content + start_index, '\0');
		number_string = ft_substr(file_content, start_index, comma_index);
		trimmed_number_string = ft_strtrim(number_string, " ");
		color[i++] = ft_atoi(trimmed_number_string);
		start_index += comma_index + 1;
		free(number_string);
		free(trimmed_number_string);
	}
	assign_color(type, config, color);
	free(color);
}

void	test_path(char *path)
{
	int		fd;
	char	*temp;

	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		temp = ft_strjoin(path, ": ");
		throw_error(ft_strjoin(temp, strerror(errno)));
	}
	close(fd);
}

void	assign_config(char *path, char type, t_config *config)
{
	if (type == 'N' && config->NO == NULL)
		config->NO = path;
	else if (type == 'W' && config->WE == NULL)
		config->WE = path;
	else if (type == 'S' && config->SO == NULL)
		config->SO = path;
	else if (type == 'E' && config->EA == NULL)
		config->EA = path;
	else
		throw_error("More Than one Texture");
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

int	check_invalid_char_or_map_start(char c)
{
	if (c == '1')
		return (1);
	if (c != 'N' && c != 'O' && c != 'S'
		&& c != 'W' && c != 'E' && c != 'A'
		&& c != 'F' && c != 'C' && c != ' '
		&& c != '\n' && c != '\r')
		throw_error("Not Allowed Char in .cub file");
	return (0);
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

void	color_error_handling(char *line_content)
{
	int	count_commas;
	int	has_digit;
	int	i;

	count_commas = 0;
	has_digit = 0;
	i = 0;
	while (line_content[i] != '\0')
	{
		if (!ft_isdigit(line_content[i])
			&& line_content[i] != ' '
			&& line_content[i] != ',')
			throw_error("Invalid Char on Color");
		if (ft_isdigit(line_content[i]))
			has_digit = 1;
		if (line_content[i] == ',')
		{
			if (has_digit == 0)
				throw_error("Not enough digits");
			count_commas++;
			has_digit = 0;
		}
		i++;
	}
	if (has_digit == 0)
		throw_error("Not enough digits");
	if (count_commas != 2)
		throw_error("Only 2 commas allowed");
}

void	parse_line_content(char *line_content, char type, t_config *config)
{
	if (type == 'F' || type == 'C')
	{
		color_error_handling(line_content + 1);
		parse_color(line_content + 1, type, config);
	}
	else
		parse_path(line_content + 2, type, config);
}

void	validate_config(char **buffer, t_config *config)
{
	char	*line_content;
	int		line;
	int		column;
	int		type;

	line = 0;
	while (buffer[line] != NULL)
	{
		line_content = buffer[line];
		column = 0;
		while (line_content[column] != '\0')
		{
			if (check_invalid_char_or_map_start(line_content[column]))
				return ;
			type = can_parse(line_content, column);
			if (type != 0)
			{
				parse_line_content(line_content + column, (char)type, config);
				break ;
			}
			column++;
		}
		line++;
	}
	check_struct(config, 0);
}
