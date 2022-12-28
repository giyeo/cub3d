#include "test_main.h"

char		**file_read;
t_config	config;

void	setUp()
{
	file_read = NULL;
	config_init(&config);
}

void	tearDown()
{
	ft_destroy_matrix(file_read);
	free_config(&config);
}

int	main()
{
	UNITY_BEGIN();

	ft_printf("\033[1;33m file_check_tests \033[0m\n");
	RUN_TEST(file_check_test_existance);
	RUN_TEST(file_check_test_permission);

	ft_printf("\033[1;33m extension_check_tests \033[0m\n");
	RUN_TEST(extension_check_test);

	ft_printf("\033[1;33m line_count_tests \033[0m\n");
	RUN_TEST(line_count_test_no_breakline);
	RUN_TEST(line_count_test_breaklines);

	ft_printf("\033[1;33m read_file_tests \033[0m\n");
	RUN_TEST(read_file_test_not_null);
	RUN_TEST(read_file_test_check_subject_lines);
	RUN_TEST(read_file_test_check_several_blines);
	RUN_TEST(read_file_test_invalid_map);

	// // verificar se quebra de linha está no meio do mapa (invalido)
	// 	// esta validação será feita na validação da config
	ft_printf("\033[1;33m find_split_line_tests \033[0m\n");
	RUN_TEST(find_split_line_test_subject_mapfile);
	RUN_TEST(find_split_line_test_doubleroom_mapfile);
	RUN_TEST(find_split_line_test_doublehole_mapfile);
	RUN_TEST(find_split_line_test_many_blines_mapfile);
	RUN_TEST(find_split_line_test_invalid_mapfile);

	ft_printf("\033[1;33m validate_config_tests \033[0m\n");
	//	validate_config function is breaking tests because of the 'throws'
	RUN_TEST(validate_config_test_not_null);
	RUN_TEST(validate_config_test_values_check);

	ft_printf("\033[1;33m validate_map_tests \033[0m\n");
	RUN_TEST(validate_map_test_invalid_char_in_map);
	RUN_TEST(validate_map_test_valid_map);
	RUN_TEST(validate_map_test_top_entrance_map);
	RUN_TEST(validate_map_test_bottom_entrance_map);
	RUN_TEST(validate_map_test_left_entrance_map);
	RUN_TEST(validate_map_test_right_entrance_map);
	RUN_TEST(validate_map_test_open_on_top_map);
	RUN_TEST(validate_map_test_open_on_bottom_map);
	RUN_TEST(validate_map_test_double_hole_map);
	RUN_TEST(validate_map_test_open_invalid_read_map); // invalid read
	RUN_TEST(validate_map_test_two_players_map);
	RUN_TEST(validate_map_test_glued_map);


	// ft_printf("\033[1;33m libft_tests \033[0m\n");
	// RUN_TEST(ft_mtxcpy_not_null);
	return (UNITY_END());
}

void	close_fd(int fd)
{
	if (fd > 0)
		close(fd);
}