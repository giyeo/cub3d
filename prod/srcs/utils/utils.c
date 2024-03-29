/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjose-d <anjose-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 03:32:11 by rpaulino          #+#    #+#             */
/*   Updated: 2023/01/13 22:18:47 by anjose-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_struct(t_config *config)
{
	if (config->no == NULL || config->we == NULL
		|| config->so == NULL || config->ea == NULL
		|| config->f[0] == -1 || config->c[0] == -1)
		return (ERR_CONFIG_MISSING);
	if (config->map == NULL
		|| config->player_direction == 'Z'
		|| config->player_position[0] == -1)
		return (ERR_CONFIG_MISSING);
	return (0);
}

int	is_one_of_these(char c, char *these)
{
	int	i;

	i = 0;
	while (these[i])
	{
		if (c == these[i])
			return (1);
		i++;
	}
	return (0);
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
