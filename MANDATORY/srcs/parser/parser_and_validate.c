/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_and_validate.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjose-d <anjose-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 12:09:44 by rpaulino          #+#    #+#             */
/*   Updated: 2023/01/14 00:43:24 by anjose-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	exit_free(t_config *config, char **buffer);

int	parser_and_validate(char **buffer, t_config *config)
{
	int	line_start_map;
	int	ret;

	line_start_map = find_map_start(buffer);
	if (line_start_map < 0)
	{
		exit_free(config, buffer);
		return (throw_msg_error(ERR_MAP_INNEXIST));
	}
	ret = validate_config(buffer, config, line_start_map);
	if (ret)
	{
		exit_free(config, buffer);
		return (throw_msg_error(ret));
	}
	ret = validate_map(buffer + line_start_map, config);
	if (ret)
	{
		exit_free(config, buffer);
		return (throw_msg_error(ret));
	}
	ft_destroy_matrix(buffer);
	config_populate(config);
	return (0);
}

static void	exit_free(t_config *config, char **buffer)
{
	free_config(config);
	if (buffer)
		ft_destroy_matrix(buffer);
}
