#ifndef TEST_MAIN_H
# define TEST_MAIN_H

#include "unity.h"
#include "cub3d.h"

extern char *g_str;

/* TESTES */
void	file_check_test_existance();
void	file_check_test_permission();

void	extension_check_test();

void	line_count_test_no_breakline();
void	line_count_test_breaklines();

void	read_file_test_not_null();
void	read_file_test_check_subject_lines();
void	read_file_test_check_several_blines();


/* SRC FILES (ISSO VAI SAIR DAQUI) */
int		file_check(char *file);
int		extension_check(char *file);
char	**read_file(int	fd, char *file);
int		line_count(char *file);

/* TEST UTILS */
void	close_fd(int fd);

#endif