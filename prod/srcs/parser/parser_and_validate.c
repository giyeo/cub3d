/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_and_validate.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjose-d <anjose-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 12:09:44 by rpaulino          #+#    #+#             */
/*   Updated: 2023/01/11 21:25:57 by anjose-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_invalid_char_or_map_start(char c);

int	parser_and_validate(char **buffer, t_config *config)
{
	int line_start_map;
	int	ret;

	ret = validate_config(buffer, config);
	if (ret)
	{
		free_config(config);
		ft_destroy_matrix(buffer);
		if (ret < 0)
			return (-1);
		else
			return (throw_error("erro correspondente ao ret"));
		// deu erro
	}
	line_start_map = find_map_start(buffer);
	if (line_start_map < 0)
	{
		free_config(config);
		ft_destroy_matrix(buffer);
		return (-1);
	}
	check_struct(config, 0);
	validate_map(buffer + line_start_map, config);
	check_struct(config, 1);
	return (0);
}
