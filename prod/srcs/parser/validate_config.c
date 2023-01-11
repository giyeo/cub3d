/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_config.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjose-d <anjose-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 21:49:51 by rpaulino          #+#    #+#             */
/*   Updated: 2023/01/11 17:51:55 by anjose-d         ###   ########.fr       */
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

int	test_path(char *path)
{
	int		fd;
	char	*temp;
	char	*msg;

	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		temp = ft_strjoin(path, ": ");
		msg = ft_strjoin(temp, strerror(errno));
		throw_error(msg);
		free(temp);
		free(msg);
		return (-1);
	}
	close(fd);
	return (0);
}

int	assign_config(char *path, char type, t_config *config)
{
	if (type == 'N' && config->NO == NULL)
		config->NO = ft_strdup(path);
	else if (type == 'W' && config->WE == NULL)
		config->WE = ft_strdup(path);
	else if (type == 'S' && config->SO == NULL)
		config->SO = ft_strdup(path);
	else if (type == 'E' && config->EA == NULL)
		config->EA = ft_strdup(path);
	else
		return (ERR_CONFIG_TEXT_DUP);
		// throw_error("More Than one Texture");
	return (0);
}

int	parse_path(char *file_content, char type, t_config *config)
{
	char	*path;
	char	*trimmed_path;
	int		err_ret;

	err_ret = 0;
	path = ft_substr(file_content, 0, ft_str_find_idx(file_content, '\n'));
	trimmed_path = ft_strtrim(path, " ");
	err_ret = test_path(trimmed_path);
	if (!err_ret)
		err_ret = assign_config(trimmed_path, type, config);
	free(path);
	free(trimmed_path);
	return (err_ret);
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
		return (-1);
		//throw_error("File not Completed");
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

int	color_error_handling(char *line_content)
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
				return (ERR_INV_CHAR_COLOR);
				//throw_error("Invalid Char on Color");
		if (ft_isdigit(line_content[i]))
			has_digit = 1;
		if (line_content[i] == ',')
		{
			if (has_digit == 0)
				return (ERR_NOT_ENOUGH_DIGITS);
				//throw_error("Not enough digits");
			count_commas++;
			has_digit = 0;
		}
		i++;
	}
	if (has_digit == 0)
		return (ERR_NOT_ENOUGH_DIGITS);
		//throw_error("Not enough digits");
	if (count_commas != 2)
		return (ERR_INV_CHAR_COLOR);
		//throw_error("Only 2 commas allowed");
	return (0);
}

int	parse_line_content(char *line_content, char type, t_config *config)
{
	int	err_ret;

	err_ret = 0;
	if (type == 'F' || type == 'C')
	{
		err_ret = color_error_handling(line_content + 1);
		if (!err_ret)
			parse_color(line_content + 1, type, config);
	}
	else
		err_ret = parse_path(line_content + 2, type, config);
	return (err_ret);
}

int	check_invalid_char(char c)
{
	if (c == '1')
		return (1);
	if (c != 'N' && c != 'O' && c != 'S'
		&& c != 'W' && c != 'E' && c != 'A'
		&& c != 'F' && c != 'C' && c != ' '
		&& c != '\n' && c != '\r')
			return (ERR_INV_CHAR_IN_FILE);
		// throw_error("Not Allowed Char in .cub file");
	return (0);
}

int	validate_config(char **buffer, t_config *config)
{
	char	*line_content;
	int		line;
	int		column;
	int		type;
	int		err_ret;

	line = 0;
	err_ret = 0;
	while (buffer[line] != NULL && !err_ret)
	{
		line_content = buffer[line];
		column = 0;
		while (line_content[column] != '\0')
		{
			if (check_invalid_char(line_content[column]))
				return (ERR_INV_CHAR_IN_FILE);
			type = can_parse(line_content, column);
			if (type < 0)
				return (ERR_FILE_INCOMPLETE);
			else if (type != 0)
			{
				err_ret = parse_line_content(line_content + column, (char)type, config);
				break ;
			}
			column++;
		}
		line++;
	}
	throw_error("Map not found");
	return (err_ret);
}
