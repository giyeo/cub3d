#include "test_main.h"

void	read_file_test_not_null()
{
	char	*file = "maps/subject.cub";
	int		fd;
	char	**file_read;

	fd = open(file, O_RDONLY);
	file_read = read_file(fd);
	close_fd(fd);
	TEST_ASSERT_NOT_NULL(file_read);
}

