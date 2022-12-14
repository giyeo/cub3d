/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjose-d <anjose-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 18:37:12 by anjose-d          #+#    #+#             */
/*   Updated: 2022/12/14 00:55:41 by anjose-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// remover quando colocar no projeto principal
int		line_count(char *file);

char	**read_file(int	fd, char *file)
{
	char	**file_read;
	int		lcount;
	int		i;
	char	*line;
	
	file_read = NULL;
	lcount = line_count(file);
	file_read = malloc(sizeof(char **) * (lcount + 1));
	i = 0;
	while (i < lcount)
	{
		line = get_next_line(fd);
		if (line && line[0] != '\n')
		{
			if (line[ft_strlen(line) - 1] == '\n')
				line[ft_strlen(line) - 1] = '\0';
			file_read[i] = line;
			i++;
		}
		else if (line)
			free(line);
	}
	file_read[i] = '\0';
	return (file_read);
}
