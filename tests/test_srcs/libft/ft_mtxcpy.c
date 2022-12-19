#include "test_main.h"

void	ft_mtxcpy_not_null()
{
	char	*file = "maps/DOUBLE_ROOM_SIMPLE_MAP.cub";
	int		fd;
	char 	**map;

	map = NULL;
	fd = open(DOUBLE_ROOM_MAP, O_RDONLY);
	file_read = read_file(fd, DOUBLE_ROOM_MAP);
	close_fd(fd);
	map = ft_mtxcpy(file_read);
	TEST_ASSERT_NOT_NULL(map);
	TEST_ASSERT_EQUAL_STRING("NO ../textures/texture1", map[0]);
	TEST_ASSERT_EQUAL_STRING("SO ../textures/texture2", map[1]);
	TEST_ASSERT_EQUAL_STRING("WE ../textures/texture3", map[2]);
	TEST_ASSERT_EQUAL_STRING("EA ../textures/texture4", map[3]);
	TEST_ASSERT_EQUAL_STRING("\0", map[4]);
	TEST_ASSERT_EQUAL_STRING("F 220,100,0", map[5]);
	TEST_ASSERT_EQUAL_STRING("C 225,30,0", map[6]);
	TEST_ASSERT_EQUAL_STRING("\0", map[7]);
	TEST_ASSERT_EQUAL_STRING("111111111111", map[8]);
	TEST_ASSERT_EQUAL_STRING("10N000000001", map[9]);
	TEST_ASSERT_EQUAL_STRING("100000000001", map[10]);
	TEST_ASSERT_EQUAL_STRING("111111111111", map[11]);
	TEST_ASSERT_EQUAL_STRING("\0", map[12]);
	TEST_ASSERT_EQUAL_STRING("111111111111", map[13]);
	TEST_ASSERT_EQUAL_STRING("100000000001", map[14]);
	TEST_ASSERT_EQUAL_STRING("100000000001", map[15]);
	TEST_ASSERT_EQUAL_STRING("111111111111", map[16]);
	ft_destroy_matrix(map);
}