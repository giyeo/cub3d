/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpaulino <rpaulino@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 03:19:02 by rpaulino          #+#    #+#             */
/*   Updated: 2022/12/03 04:05:12 by rpaulino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int	get_fd(char *argv)
{
	int	fd;

	printf("%s\n", argv);
	fd = open(argv, O_RDONLY);
	if (fd == -1)
		throw_error("ERROR: Can't get File descriptor");
	return (fd);
}

char	*read_data(int fd)
{
	char	*buffer;
	char	*temp;
	char	*temporary;
	size_t	n;

	temp = (char *)malloc(sizeof(char) + 1);
	buffer = strdup("");
	n = read(fd, temp, 1);
	temp[1] = '\0';
	while (n > 0)
	{
		temporary = ft_strjoin(buffer, temp);
		free(buffer);
		buffer = temporary;
		n = read(fd, temp, 1);
	}
	close(fd);
	free(temp);
	return (buffer);
}

char	*get_data_from_file(int argc, char *argv)
{
	int	fd;

	(void)argc;
	fd = get_fd(argv);
	return (read_data(fd));
}
