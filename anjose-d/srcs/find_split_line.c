/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_split_line.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjose-d <anjose-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 17:27:10 by anjose-d          #+#    #+#             */
/*   Updated: 2022/12/14 18:35:40 by anjose-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	only_these(char *str, char *needles);

int	find_split_line(char **read_file)
{
	int	idx_line;
	int	mtx_size;

	mtx_size = ft_mtxlen(read_file);
	idx_line = mtx_size;
	while (read_file[idx_line - 1])
	{
		idx_line--;
		if (only_these(read_file[idx_line], ONLY_CHARS_MAP))
			break ;
	}
	return (idx_line);
}

int	only_these(char *str, char *needles)
{
	int	i;
	int	j;
	int	found;

	i = 0;
	if (str[i] == '\0')
		return (-1);
	while (str[i])
	{
		j = 0;
		found = 0;
		while (needles[j])
		{
			if (str[i] == needles[j])
			{
				found = 1;
				break ;
			}
			j++;
		}
		if (found == 0)
			return (-1);
		i++;
	}
}
