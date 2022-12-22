#ifndef TEST_MAIN_H
# define TEST_MAIN_H

#include "unity.h"
#include "cub3d.h"
#include "maps.h"

extern char		**file_read;
extern t_config	config;

/* TESTES */

// libft
void	ft_mtxcpy_not_null();

void	file_check_test_existance();
void	file_check_test_permission();

void	extension_check_test();

void	line_count_test_no_breakline();
void	line_count_test_breaklines();

void	read_file_test_not_null();
void	read_file_test_check_subject_lines();
void	read_file_test_check_several_blines();
void	read_file_test_invalid_map();

void	find_split_line_test_subject_mapfile();
void	find_split_line_test_doubleroom_mapfile();
void	find_split_line_test_doublehole_mapfile();
void	find_split_line_test_many_blines_mapfile();
void	find_split_line_test_invalid_mapfile();

void	validate_config_test_not_null();
void	validate_config_test_values_check();

void	validate_map_test_invalid_char_in_map();
void	validate_map_test_valid_map();
void	validate_map_test_bottom_entrance_map();
void	validate_map_test_top_entrance_map();
void	validate_map_test_left_entrance_map();
void	validate_map_test_right_entrance_map();
void	validate_map_test_open_on_top_map();
void	validate_map_test_open_on_bottom_map();
void	validate_map_test_double_hole_map();
void	validate_map_test_open_invalid_read_map();
void	validate_map_test_two_players_map();

/* SRC FILES (ISSO VAI SAIR DAQUI) */
int		find_split_line(char **read_file);

/* TEST UTILS */
void	close_fd(int fd);



#endif