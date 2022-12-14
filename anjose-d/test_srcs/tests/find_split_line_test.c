/* find the line splitting map and game config */
#include "test_main.h"

void	find_split_line_test_subject_mapfile()
{
	int		fd;
	char	**file_read;
	int		split_line;

	fd = open(SUBJECT_MAP, O_RDONLY);
	file_read = read_file(fd, SUBJECT_MAP);
	close_fd(fd);
	split_line = find_split_line(file_read);
	TEST_ASSERT_EQUAL(7, split_line);
}

void	find_split_line_test_doubleroom_mapfile()
{
	int		fd;
	char	**file_read;
	int		split_line;

	fd = open(DOUBLE_ROOM_MAP, O_RDONLY);
	file_read = read_file(fd, DOUBLE_ROOM_MAP);
	close_fd(fd);
	split_line = find_split_line(file_read);
	TEST_ASSERT_EQUAL(12, split_line);
	// na validação da config vai pegar a outra sala e invalidar o mapa
}