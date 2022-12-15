#include "test_main.h"

char *g_str;

void	setUp()
{
	g_str = NULL;
}

void	tearDown()
{
	if(g_str)
		free(g_str);
}

int	main()
{
	UNITY_BEGIN();

	ft_printf("\033[1;33m file_check_tests \033[0m\n");
	RUN_TEST(file_check_test_existance);
	RUN_TEST(file_check_test_permission);

	ft_printf("\033[1;33m extension_check_tests \033[0m\n");
	RUN_TEST(extension_check_test);

	ft_printf("\033[1;33m read_file_tests \033[0m\n");
	RUN_TEST(line_count_test_no_breakline);
	RUN_TEST(line_count_test_breaklines);

	ft_printf("\033[1;33m read_file_tests \033[0m\n");
	RUN_TEST(read_file_test_not_null);
	RUN_TEST(read_file_test_check_subject_lines);
	RUN_TEST(read_file_test_check_several_blines);
	RUN_TEST(read_file_test_invalid_map);

	// verificar se quebra de linha está no meio do mapa (invalido)
		// esta validação será feita na validação da config
	ft_printf("\033[1;33m find_split_line_tests \033[0m\n");
	RUN_TEST(find_split_line_test_subject_mapfile);
	RUN_TEST(find_split_line_test_doubleroom_mapfile);
	RUN_TEST(find_split_line_test_doublehole_mapfile);
	RUN_TEST(find_split_line_test_many_blines_mapfile);

	return (UNITY_END());
}

void	close_fd(int fd)
{
	if (fd > 0)
		close(fd);
}