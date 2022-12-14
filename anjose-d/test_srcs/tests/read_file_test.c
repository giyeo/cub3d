#include "test_main.h"

void	read_file_test_not_null()
{
	char	*file = "maps/subject.cub";
	int		fd;
	char	**file_read;

	fd = open(file, O_RDONLY);
	file_read = read_file(fd, file);
	close_fd(fd);
	TEST_ASSERT_NOT_NULL(file_read);
}

void	read_file_test_check_subject_lines()
{
	char	*file = "maps/subject.cub";
	int		fd;
	char	**file_read;

	fd = open(file, O_RDONLY);
	file_read = read_file(fd, file);
	close_fd(fd);
	TEST_ASSERT_NOT_NULL(file_read);
	TEST_ASSERT_EQUAL_STRING("NO ./path_to_the_north_texture", file_read[0]);
	TEST_ASSERT_EQUAL_STRING("SO ./path_to_the_south_texture", file_read[1]);
	TEST_ASSERT_EQUAL_STRING("WE ./path_to_the_west_texture", file_read[2]);
	TEST_ASSERT_EQUAL_STRING("EA ./path_to_the_east_texture", file_read[3]);
	TEST_ASSERT_EQUAL_STRING("\0", file_read[4]);
	TEST_ASSERT_EQUAL_STRING("F 220,100,0", file_read[5]);
	TEST_ASSERT_EQUAL_STRING("C 225,30,0", file_read[6]);
	TEST_ASSERT_EQUAL_STRING("\0", file_read[7]);
	TEST_ASSERT_EQUAL_STRING("1111111111111111111111111", file_read[8]);
	TEST_ASSERT_EQUAL_STRING("1000000000110000000000001", file_read[9]);
	TEST_ASSERT_EQUAL_STRING("1011000001110000000000001", file_read[10]);
	TEST_ASSERT_EQUAL_STRING("1001000000000000000000001", file_read[11]);
	TEST_ASSERT_EQUAL_STRING("111111111011000001110000000000001", file_read[12]);
	TEST_ASSERT_EQUAL_STRING("100000000011000001110111111111111", file_read[13]);
	TEST_ASSERT_EQUAL_STRING("11110111111111011100000010001", file_read[14]);
	TEST_ASSERT_EQUAL_STRING("11110111111111011101010010001", file_read[15]);
	TEST_ASSERT_EQUAL_STRING("11000000110101011100000010001", file_read[16]);
	TEST_ASSERT_EQUAL_STRING("10000000000000001100000010001", file_read[17]);
	TEST_ASSERT_EQUAL_STRING("10000000000000001101010010001", file_read[18]);
	TEST_ASSERT_EQUAL_STRING("11000001110101011111011110N0111", file_read[19]);
	TEST_ASSERT_EQUAL_STRING("11110111 1110101 101111010001", file_read[20]);
	TEST_ASSERT_EQUAL_STRING("11111111 1111111 111111111111", file_read[21]);
}

void	read_file_test_check_several_blines()
{
	char	*file = "maps/several_breaklines.cub";
	int		fd;
	char	**file_read;

	fd = open(file, O_RDONLY);
	file_read = read_file(fd, file);
	close_fd(fd);
	TEST_ASSERT_NOT_NULL(file_read);
	TEST_ASSERT_EQUAL_STRING("\0", file_read[0]);
	TEST_ASSERT_EQUAL_STRING("NO ./path_to_the_north_texture", file_read[1]);
	TEST_ASSERT_EQUAL_STRING("\0", file_read[2]);
	TEST_ASSERT_EQUAL_STRING("SO ./path_to_the_south_texture", file_read[3]);
	TEST_ASSERT_EQUAL_STRING("\0", file_read[4]);
	TEST_ASSERT_EQUAL_STRING("WE ./path_to_the_west_texture", file_read[5]);
	TEST_ASSERT_EQUAL_STRING("\0", file_read[6]);
	TEST_ASSERT_EQUAL_STRING("EA ./path_to_the_east_texture", file_read[7]);
	TEST_ASSERT_EQUAL_STRING("\0", file_read[8]);
	TEST_ASSERT_EQUAL_STRING("F 220,100,0", file_read[9]);
	TEST_ASSERT_EQUAL_STRING("\0", file_read[10]);
	TEST_ASSERT_EQUAL_STRING("C 225,30,0", file_read[11]);
	TEST_ASSERT_EQUAL_STRING("\0", file_read[12]);
	TEST_ASSERT_EQUAL_STRING("1111111111111111111111111", file_read[13]);
	TEST_ASSERT_EQUAL_STRING("1000000000110000000000001", file_read[14]);
	TEST_ASSERT_EQUAL_STRING("1011000001110000000000001", file_read[15]);
	TEST_ASSERT_EQUAL_STRING("1001000000000000000000001", file_read[16]);
	TEST_ASSERT_EQUAL_STRING("111111111011000001110000000000001", file_read[17]);
	TEST_ASSERT_EQUAL_STRING("100000000011000001110111111111111", file_read[18]);
	TEST_ASSERT_EQUAL_STRING("11110111111111011100000010001", file_read[19]);
	TEST_ASSERT_EQUAL_STRING("11110111111111011101010010001", file_read[20]);
	TEST_ASSERT_EQUAL_STRING("11000000110101011100000010001", file_read[21]);
	TEST_ASSERT_EQUAL_STRING("10000000000000001100000010001", file_read[22]);
	TEST_ASSERT_EQUAL_STRING("10000000000000001101010010001", file_read[23]);
	TEST_ASSERT_EQUAL_STRING("11000001110101011111011110N0111", file_read[24]);
	TEST_ASSERT_EQUAL_STRING("11110111 1110101 101111010001", file_read[25]);
	TEST_ASSERT_EQUAL_STRING("11111111 1111111 111111111111", file_read[26]);
}

void	read_file_test_invalid_map()
{
	char	*file = "maps/DOUBLE_ROOM_SIMPLE_MAP.cub";
	int		fd;
	char	**file_read;

	fd = open(file, O_RDONLY);
	file_read = read_file(fd, file);
	close_fd(fd);
	TEST_ASSERT_NOT_NULL(file_read);
	TEST_ASSERT_EQUAL_STRING("NO ./textures/texture1", file_read[0]);
	TEST_ASSERT_EQUAL_STRING("SO ./textures/texture2", file_read[1]);
	TEST_ASSERT_EQUAL_STRING("WE ./textures/texture3", file_read[2]);
	TEST_ASSERT_EQUAL_STRING("EA ./textures/texture4", file_read[3]);
	TEST_ASSERT_EQUAL_STRING("\0", file_read[4]);
	TEST_ASSERT_EQUAL_STRING("F 220,100,0", file_read[5]);
	TEST_ASSERT_EQUAL_STRING("C 225,30,0", file_read[6]);
	TEST_ASSERT_EQUAL_STRING("\0", file_read[7]);
	TEST_ASSERT_EQUAL_STRING("111111111111", file_read[8]);
	TEST_ASSERT_EQUAL_STRING("10N000000001", file_read[9]);
	TEST_ASSERT_EQUAL_STRING("100000000001", file_read[10]);
	TEST_ASSERT_EQUAL_STRING("111111111111", file_read[11]);
	TEST_ASSERT_EQUAL_STRING("\0", file_read[12]);
	TEST_ASSERT_EQUAL_STRING("111111111111", file_read[13]);
	TEST_ASSERT_EQUAL_STRING("100000000001", file_read[14]);
	TEST_ASSERT_EQUAL_STRING("100000000001", file_read[15]);
	TEST_ASSERT_EQUAL_STRING("111111111111", file_read[16]);
}