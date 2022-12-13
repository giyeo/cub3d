#ifndef TEST_MAIN_H
# define TEST_MAIN_H

#include "unity.h"
#include "cub3d.h"

extern char *g_str;

/* TESTES */
void	file_check_test_existance();
void	file_check_test_permission();

void	extension_check_test();
/* SRC FILES (ISSO VAI SAIR DAQUI) */
int		file_check(char *file);
int		extension_check(char *file);
/* TEST UTILS */
void	close_fd(int fd);
#endif