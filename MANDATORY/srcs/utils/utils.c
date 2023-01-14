/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpaulino <rpaulino@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 03:32:11 by rpaulino          #+#    #+#             */
/*   Updated: 2023/01/14 16:52:45 by rpaulino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_struct(t_config *config)
{
	int	i;

	if (config->no == NULL || config->we == NULL
		|| config->so == NULL || config->ea == NULL
		|| config->f[0] == -1 || config->c[0] == -1)
		return (ERR_CONFIG_MISSING);
	if (config->map == NULL
		|| config->player_direction == 'Z'
		|| config->player_position[0] == -1
		|| config->player_position[1] == -1)
		return (ERR_CONFIG_MISSING);
	i = 0;
	while (i < 3)
	{
		if (config->f[i] < 0 || config->f[i] > 255
			|| config->c[i] < 0 || config->c[i] > 255)
			return (ERR_INV_CHAR_COLOR);
		i++;
	}
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

int	mlx_get_hex_trgb(int r, int g, int b)
{
	return ((r << 16) | (g << 8) | (b));
}

double	normalize_angle(double angle)
{
	angle = fmod(angle, TWO_PI);
	if (angle < 0)
		angle = TWO_PI + angle;
	return (angle);
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
