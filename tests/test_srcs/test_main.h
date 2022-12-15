#ifndef TEST_MAIN_H
# define TEST_MAIN_H

#include "unity.h"
#include "cub3d.h"

/* maps */
// SIMPLE
#define SUBJECT_MAP "../maps_for_test/simple/subject.cub"
#define DOUBLE_ROOM_MAP "../maps_for_test/simple/DOUBLE_ROOM_SIMPLE_MAP.cub"
#define DOUBLE_HOLE_MAP "../maps_for_test/simple/BIG_ROOM_HOLES_SIMPLE_MAP.cub"
#define MANY_BLINES_MAP "../maps_for_test/simple/several_breaklines.cub"

// WRONG
#define NO_PERM_MAP "../maps_for_test/wrong/noperm.cub"

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
void	read_file_test_invalid_map();

void	find_split_line_test_subject_mapfile();
void	find_split_line_test_doubleroom_mapfile();
void	find_split_line_test_doublehole_mapfile();
void	find_split_line_test_many_blines_mapfile();


/* SRC FILES (ISSO VAI SAIR DAQUI) */
int		find_split_line(char **read_file);

/* TEST UTILS */
void	close_fd(int fd);



#endif