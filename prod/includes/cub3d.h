#ifndef CUB3D_H
# define CUB3D_H

# include "libft.h"
# include <mlx.h>
# include <fcntl.h>
# include "errors.h"
// open();
# include <stdio.h>
// perror();
# include <string.h>
// strerror();
# include <errno.h>

# define MAP_FILE_EXT ".cub"
# define ONLY_CHARS_MAP "01WNSE "
# define PLAYER_DIRECTIONS "NSEW"


/* type identifiers */
# define TID_NORTH_TXT "NO"
# define TID_SOUTH_TXT "SO"
# define TID_WEST_TXT "WE"
# define TID_EAST_TXT "EA"
# define TID_FLOOR_CLR "F"
# define TID_CELLING_CLR "C"

typedef struct	s_config
{
	char	*NO;
	char	*SO;
	char	*WE;
	char	*EA;
	int		F[3];
	int		C[3];
	char	**map;
	int		player_position[2];
	char	player_direction;
	char	*errors[255];
}			t_config;

/* PARSER */
int		file_validate(char *file, int argc);

int		file_check(char *file);
int		extension_check(char *file);
char	**read_file(int	fd, char *file);
int		line_count(char *file);
void	parser_and_validate(char **buffer, t_config *config);
int		find_split_line(char **read_file);

/* UTILS */
void	throw_error(char *error);
int		only_these(char *str, char *needles);
void	config_init(t_config *config);
int		is_one_of_these(char c, char *these);
int		find_player(char **buffer, int first_line, t_config *config);

/* VALIDATE*/
int		validate_config(char **buffer, t_config *config);
int		validate_map(char **buffer, t_config *config);

#endif