#include "test_main.h"

int fd;

void	file_check_test_existance()
{
	fd = file_check("asdf");
	TEST_ASSERT_EQUAL(-1, fd);
	close_fd(fd);

	fd = file_check(SUBJECT_MAP);
	TEST_ASSERT_EQUAL(3, fd);
	close_fd(fd);
}

void	file_check_test_permission()
{
	fd = file_check(NO_PERM_MAP);
	TEST_ASSERT_EQUAL(-1, fd);
	close_fd(fd);
}
