#include "test_main.h"

void	file_check_test_existance()
{
	int	fd;

	fd = file_check("asdf");
	TEST_ASSERT_EQUAL(-1, fd);
	close_fd(fd);

	fd = file_check("maps/subject.cub");
	TEST_ASSERT_EQUAL(3, fd);
	close_fd(fd);
}

void	file_check_test_permission()
{
	TEST_ASSERT_EQUAL(-1, file_check("maps/noperm.cub"));
}
