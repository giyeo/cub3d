/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_config.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjose-d <anjose-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 11:05:16 by anjose-d          #+#    #+#             */
/*   Updated: 2023/01/14 11:43:52 by anjose-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_config(t_config *config)
{
	if (config)
	{
		if (config->no)
			free(config->no);
		if (config->so)
			free(config->so);
		if (config->we)
			free(config->we);
		if (config->ea)
			free(config->ea);
		if (config->map)
			ft_destroy_matrix(config->map);
	}
}
