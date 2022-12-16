#include "test_main.h"

void	validate_map_test_invalid_char_in_map()
{
	t_config	config;
	char		**buffer;
	int			ret;

	int	fd = file_check(INVALID_MAP);
	buffer = read_file(fd, INVALID_MAP);
	ret = validate_map(buffer, &config);
	TEST_ASSERT_EQUAL(-1, ret);
}

void	validate_map_test_valid_map()
{
	t_config	config;
	char		**buffer;
	int			ret;

	int	fd = file_check(SUBJECT_MAP);
	buffer = read_file(fd, SUBJECT_MAP);
	ret = validate_map(buffer, &config);
	TEST_ASSERT_EQUAL(0, ret);
}

void	validate_map_test_bottom_entrance_map()
{
	t_config	config;
	char		**buffer;
	int			ret;

	int	fd = file_check(ENTRANCE_BOTTOM_MAP);
	buffer = read_file(fd, ENTRANCE_BOTTOM_MAP);
	ret = validate_map(buffer, &config);
	TEST_ASSERT_EQUAL(-1, ret);
}

void	validate_map_test_top_entrance_map()
{
	t_config	config;
	char		**buffer;
	int			ret;

	int	fd = file_check(ENTRANCE_TOP_MAP);
	buffer = read_file(fd, ENTRANCE_TOP_MAP);
	ret = validate_map(buffer, &config);
	TEST_ASSERT_EQUAL(-1, ret);
}

void	validate_map_test_left_entrance_map()
{
	t_config	config;
	char		**buffer;
	int			ret;

	int	fd = file_check(ENTRANCE_LEFT_MAP);
	buffer = read_file(fd, ENTRANCE_LEFT_MAP);
	ret = validate_map(buffer, &config);
	TEST_ASSERT_EQUAL(-1, ret);
}

void	validate_map_test_right_entrance_map()
{
	t_config	config;
	char		**buffer;
	int			ret;

	int	fd = file_check(ENTRANCE_RIGHT_MAP);
	buffer = read_file(fd, ENTRANCE_RIGHT_MAP);
	ret = validate_map(buffer, &config);
	TEST_ASSERT_EQUAL(-1, ret);
}

void	validate_map_test_open_on_top_map()
{
	t_config	config;
	char		**buffer;
	int			ret;

	int	fd = file_check(OPEN_ON_TOP_MAP);
	buffer = read_file(fd, OPEN_ON_TOP_MAP);
	ret = validate_map(buffer, &config);
	TEST_ASSERT_EQUAL(-1, ret);
}

void	validate_map_test_open_on_bottom_map()
{
	t_config	config;
	char		**buffer;
	int			ret;

	int	fd = file_check(OPEN_ON_BOTTOM_MAP);
	buffer = read_file(fd, OPEN_ON_BOTTOM_MAP);
	ret = validate_map(buffer, &config);
	TEST_ASSERT_EQUAL(-1, ret);
}
