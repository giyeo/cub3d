/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjose-d <anjose-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 20:41:18 by anjose-d          #+#    #+#             */
/*   Updated: 2023/01/13 20:41:30 by anjose-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	config_init(t_config *config)
{
	config->no = NULL;
	config->we = NULL;
	config->so = NULL;
	config->ea = NULL;
	config->map = NULL;
	config->f[0] = -1;
	config->c[0] = -1;
	config->player_position[0] = -1;
	config->player_position[1] = -1;
	config->player_direction = 'Z';
}
