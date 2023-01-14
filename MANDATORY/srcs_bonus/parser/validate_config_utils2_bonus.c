/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_config_utils2.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjose-d <anjose-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 21:29:43 by anjose-d          #+#    #+#             */
/*   Updated: 2023/01/14 19:59:23 by anjose-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	assign_color(t_config *config, int color[], char type)
{
	int	i;

	i = 0;
	if (type == 'F' && config->f[0] == -1)
	{
		while (i < 3)
		{
			config->f[i] = color[i];
			i++;
		}
	}
	else if (type == 'C' && config->c[0] == -1)
	{
		while (i < 3)
		{
			config->c[i] = color[i];
			i++;
		}
	}
	else
		throw_error("Duplicate of colors");
}

int	color_error_handling(char *line_content)
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

int	line_check(char line_cont, int *has_digit, int *count_commas)
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
