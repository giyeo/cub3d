/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjose-d <anjose-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 17:03:52 by anjose-d          #+#    #+#             */
/*   Updated: 2022/12/15 23:23:32 by anjose-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	map_has_entrance(char **buffer, int split_line);

int	validate_map(char **buffer, t_config *config)
{
	int	split_line;
	int	i;

	split_line = find_split_line(buffer) + 1;
	i = split_line;
	// checar se está circundado por 1
	if (map_has_entrance(buffer, split_line))
		return (-1);
	while (buffer[i])
	{
		// check invalid chars
		if(only_these(buffer[i], ONLY_CHARS_MAP))
			return (-2);
		i++;
	}
	return (0);
}

int	map_has_entrance(char **buffer, int split_line)
{
	// função para encontrar player
	// verificar 4 horizontes dos 0 (acima, abaixo, laterais)
		// deve ter 0 ou 1 (ou player position)
	return (0);
}