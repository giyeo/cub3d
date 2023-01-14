/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_config_utils1.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjose-d <anjose-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 20:50:37 by anjose-d          #+#    #+#             */
/*   Updated: 2023/01/14 17:10:00 by anjose-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int		parse_path(char *file_content, char type, t_config *config);
static int		assign_config(char *path, char type, t_config *config);
static int		color_error_handling(char *line_content);
static int		line_check(char line_cont, int *has_digit, int *count_commas);

int	parse_line_content(char *line_content, char type, t_config *config)
{
	int		err_ret;
	int		color[3];
	char	rgb_type;
	char	**rgb_split;
	int		i;

	err_ret = 0;
	if (type == 'F' || type == 'C')
	{
		err_ret = color_error_handling(line_content + 1);
		if (!err_ret)
		{
			rgb_split = ft_split(line_content + 1, ',');
			i = 0;
			while (i < 3)
			{
				color[i] = -1;
				if (ft_is_numeric(ft_skip_space(rgb_split[i])))
					color[i] = atoi(rgb_split[i]);
				i++;
			}
			ft_destroy_matrix(rgb_split);
			rgb_type = ft_skip_space(line_content)[0];
			assign_color(config, color, rgb_type);
		}
	}
	else
		err_ret = parse_path(line_content + 2, type, config);
	return (err_ret);
}

static int	parse_path(char *file_content, char type, t_config *config)
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

static int	assign_config(char *path, char type, t_config *config)
{
	if (type == 'N' && config->no == NULL)
		config->no = ft_strdup(path);
	else if (type == 'W' && config->we == NULL)
		config->we = ft_strdup(path);
	else if (type == 'S' && config->so == NULL)
		config->so = ft_strdup(path);
	else if (type == 'E' && config->ea == NULL)
		config->ea = ft_strdup(path);
	else
		return (ERR_CONFIG_TEXT_DUP);
	return (0);
}

static int	color_error_handling(char *line_content)
{
	int	count_commas;
	int	has_digit;
	int	i;
	int	ret;

	count_commas = 0;
	has_digit = 0;
	i = 0;
	if (count_occur(line_content, ',') != 2)
		return (ERR_INV_CHAR_COLOR);
	while (line_content[i] != '\0')
	{
		ret = line_check(line_content[i], &has_digit, &count_commas);
		if (!ret)
			return (ret);
		i++;
	}
	if (has_digit == 0)
		return (ERR_NOT_ENOUGH_DIGITS);
	return (ret);
}

static int	line_check(char line_cont, int *has_digit, int *count_commas)
{
	if (!ft_isdigit(line_cont)
		&& line_cont != ' '
		&& line_cont != ',')
		return (ERR_INV_CHAR_COLOR);
	if (ft_isdigit(line_cont))
		*has_digit = 1;
	if (line_cont == ',')
	{
		if (*has_digit == 0)
			return (ERR_NOT_ENOUGH_DIGITS);
		*count_commas = (*count_commas) + 1;
		*has_digit = 0;
	}
	return (0);
}
