/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjose-d <anjose-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 18:37:12 by anjose-d          #+#    #+#             */
/*   Updated: 2023/01/14 19:59:17 by anjose-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static int		find_bline(char *str, int strsize);
static void		remove_bline(char **str, int lsize);

char	**read_file(int fd, char *file)
{
	char	**file_read;
	int		lcount;
	int		lsize;
	int		i;
	char	*line;

	file_read = NULL;
	lcount = line_count(file);
	file_read = malloc(sizeof(char **) * (lcount + 1));
	i = 0;
	while (i < lcount)
	{
		line = get_next_line(fd);
		lsize = ft_strlen(line);
		if (find_bline(line, lsize))
			remove_bline(&line, lsize);
		file_read[i] = line;
		i++;
	}
	file_read[i] = '\0';
	return (file_read);
}

static int	find_bline(char *str, int strsize)
{
	if (str[strsize - 1] == '\n' || str[strsize - 1] == '\r')
		return (1);
	return (0);
}

static void	remove_bline(char **str, int lsize)
{
	char	*line;

	line = *str;
	while (line && lsize > 0 && line[lsize - 1]
		&& find_bline(line, lsize))
	{
		line[lsize - 1] = '\0';
		lsize--;
	}
}
