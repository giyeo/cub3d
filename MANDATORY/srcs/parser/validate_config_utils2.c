/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_config_utils2.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjose-d <anjose-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 21:29:43 by anjose-d          #+#    #+#             */
/*   Updated: 2023/01/14 13:09:12 by anjose-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	assign_color(char type, t_config *config, int *color);
static int	get_number_trimmed(char *content, int start_idx, int comma_index);

void	parse_color(char *file_content, char type, t_config *config)
{
	int		i;
	int		comma_index;
	int		start_index;
	int		color[3];

	i = 0;
	start_index = 0;
	comma_index = 0;
	while (i < 3)
	{
		comma_index = ft_str_find_idx(file_content + start_index, ',');
		if (comma_index == -1)
			comma_index = ft_str_find_idx(file_content + start_index, '\0');
		color[i] = get_number_trimmed(file_content,
				start_index, comma_index);
		start_index += comma_index + 1;
		i++;
	}
	assign_color(type, config, color);
}

static int	get_number_trimmed(char *content, int start_idx, int comma_index)
{
	int		nbr;
	char	*number_string;
	char	*trimmed_number_string;

	nbr = 0;
	number_string = ft_substr(content, start_idx, comma_index);
	trimmed_number_string = ft_strtrim(number_string, " ");
	nbr = ft_atoi(trimmed_number_string);
	free(number_string);
	free(trimmed_number_string);
	return (nbr);
}

static void	assign_color(char type, t_config *config, int color[])
{
	if (type == 'F' && config->f[0] == -1)
	{
		config->f[0] = color[0];
		config->f[1] = color[1];
		config->f[2] = color[2];
	}
	else if (type == 'C' && config->c[0] == -1)
	{
		config->c[0] = color[0];
		config->c[1] = color[1];
		config->c[2] = color[2];
	}
}
