/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_config.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjose-d <anjose-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 21:49:51 by rpaulino          #+#    #+#             */
/*   Updated: 2023/01/15 17:38:25 by anjose-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	loop_through_line(t_config *config, char *line, int *config_nbr);

int	validate_config(char **buffer, t_config *config, int map_line)
{
	int		line;
	int		err_ret;
	int		config_nbr;

	line = 0;
	err_ret = 0;
	config_nbr = 0;
	while (line < map_line || (buffer[line] != NULL && !err_ret))
	{
		if (line >= map_line)
			return (err_ret);
		err_ret = loop_through_line(config, buffer[line], &config_nbr);
		if (err_ret)
			return (err_ret);
		line++;
	}
	if (config_nbr != 6)
		return (ERR_CONFIG_MISSING);
	return (err_ret);
}

static int	can_parse(char *line_content, int i)
{
	char	current;
	char	next;
	char	after_next;

	current = line_content[i];
	next = line_content[i + 1];
	after_next = line_content[i + 2];
	if (next == '\0' || after_next == '\0')
		return (-1);
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

static int	config_check(char *config_line)
{
	int	ret;

	ret = 0;
	if (!config_line)
		return (0);
	ret = ft_strncmp(config_line, "NO", ft_strlen("NO") + 1);
	if (!ret)
		return (ret);
	ret = ft_strncmp(config_line, "SO", ft_strlen("SO") + 1);
	if (!ret)
		return (ret);
	ret = ft_strncmp(config_line, "WE", ft_strlen("WE") + 1);
	if (!ret)
		return (ret);
	ret = ft_strncmp(config_line, "EA", ft_strlen("EA") + 1);
	if (!ret)
		return (ret);
	ret = ft_strncmp(config_line, "F", ft_strlen("F") + 1);
	if (!ret)
		return (ret);
	ret = ft_strncmp(config_line, "C", ft_strlen("C") + 1);
	if (!ret)
		return (ret);
	return (ret);
}

static int	check_invalid_char(char *line_str, int *config_nbr)
{
	char	**config_line;
	int		ret;

	ret = 0;
	config_line = NULL;
	if (line_str)
	{
		config_line = ft_split(line_str, ' ');
		if (config_line)
			ret = config_check(config_line[0]);
	}
	if (!ret && *config_line)
		(*config_nbr)++;
	ft_destroy_matrix(config_line);
	return (ret);
}

static int	loop_through_line(t_config *config, char *line, int *config_nbr)
{
	int	column;
	int	err_ret;
	int	type;

	column = 0;
	err_ret = 0;
	while (ft_isspace(line[column]))
		column++;
	while (line[column] != '\0')
	{
		err_ret = check_invalid_char(line, config_nbr);
		if (err_ret && column == 0)
			return (ERR_INV_CHAR_IN_FILE);
		type = can_parse(line, column);
		if (type < 0)
			return (ERR_FILE_INCOMPLETE);
		else if (type != 0)
		{
			err_ret = parse_line_content(line + column,
					(char)type, config);
			break ;
		}
		column++;
	}
	return (err_ret);
}
