/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_and_validate.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjose-d <anjose-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 12:09:44 by rpaulino          #+#    #+#             */
/*   Updated: 2022/12/30 11:51:19 by anjose-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	parser_and_validate(char **buffer, t_config *config)
{
	int line_start_map;

	line_start_map = validate_config(buffer, config);
	check_struct(config, 0);
	validate_map(buffer + line_start_map, config);
	check_struct(config, 1);

	config->map_num_rows = ft_mtxlen(config->map);
	config->map_num_cols = ft_mtx_biggest_strlen(config->map);
}
