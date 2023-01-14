/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_config_utils1.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjose-d <anjose-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 20:50:37 by anjose-d          #+#    #+#             */
/*   Updated: 2023/01/14 17:39:38 by anjose-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int		parse_path(char *file_content, char type, t_config *config);
static int		assign_config(char *path, char type, t_config *config);
static void		get_color(t_config *config, char *line_content);

int	parse_line_content(char *line_content, char type, t_config *config)
{
	int		err_ret;

	err_ret = 0;
	if (type == 'F' || type == 'C')
	{
		err_ret = color_error_handling(line_content + 1);
		if (!err_ret)
			get_color(config, line_content);
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

static void	get_color(t_config *config, char *line_content)
{
	char	**rgb_split;
	int		color[3];
	int		i;
	char	rgb_type;

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
