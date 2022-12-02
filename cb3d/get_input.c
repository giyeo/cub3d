#include "cube3d.h"

int get_fd(char *argv)
{
    int fd;

    fd = open(argv, O_RDONLY);
	if(fd == -1)
		throw_error("Can't get File descriptor");
	else
		printf("Success! fd:%d file:%s\n", fd, argv);
    return (fd);
}

char	*read_data(int fd)
{
	char    *buffer;
	char    *temp;
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

char	*get_data_from_file(int argc, char *argv[])
{
	int     fd;

	(void)argc;
	fd = get_fd(argv[1]);
	return (read_data(fd));
}