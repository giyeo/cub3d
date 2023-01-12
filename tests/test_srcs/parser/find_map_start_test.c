/* find the line splitting map and game config */
#include "test_main.h"

void	find_map_start_test_subject_mapfile()
{
	int		fd;
	int		split_line;

	fd = open(SUBJECT_MAP, O_RDONLY);
	file_read = read_file(fd, SUBJECT_MAP);
	close_fd(fd);
	split_line = find_map_start(file_read);
	TEST_ASSERT_EQUAL(8, split_line);
}

void	find_map_start_test_doubleroom_mapfile()
{
	int		fd;
	int		split_line;

	fd = open(DOUBLE_ROOM_MAP, O_RDONLY);
	file_read = read_file(fd, DOUBLE_ROOM_MAP);
	close_fd(fd);
	split_line = find_map_start(file_read);
	TEST_ASSERT_EQUAL(8, split_line);
	// na validação da config vai pegar a outra sala e invalidar o mapa
}

void	find_map_start_test_doublehole_mapfile()
{
	int		fd;
	int		split_line;

	fd = open(DOUBLE_HOLE_MAP, O_RDONLY);
	file_read = read_file(fd, DOUBLE_HOLE_MAP);
	close_fd(fd);
	split_line = find_map_start(file_read);
	TEST_ASSERT_EQUAL(8, split_line);
}

void	find_map_start_test_many_blines_mapfile()
{
	int		fd;
	int		split_line;

	fd = open(MANY_BLINES_MAP, O_RDONLY);
	file_read = read_file(fd, MANY_BLINES_MAP);
	close_fd(fd);
	split_line = find_map_start(file_read);
	TEST_ASSERT_EQUAL(13, split_line);
}

void	find_map_start_test_invalid_mapfile()
{
	int		fd;
	int		split_line;

	fd = open(INVALID_MAP, O_RDONLY);
	file_read = read_file(fd, INVALID_MAP);
	close_fd(fd);
	split_line = find_map_start(file_read);
	TEST_ASSERT_EQUAL(8, split_line);
}

void	find_map_start_test_no_map()
{
	int		fd;
	int		split_line;

	fd = open(NO_MAP, O_RDONLY);
	file_read = read_file(fd, NO_MAP);
	close_fd(fd);
	split_line = find_map_start(file_read);
	TEST_ASSERT_EQUAL(-1, split_line);
}

