#ifndef CUB3D_H
# define CUB3D_H

# include "libft.h"
# include <mlx.h>
# include <fcntl.h>
// open();
# include <stdio.h>
// perror();
# include <string.h>
// strerror();
# include <errno.h>

# define MAP_FILE_EXT ".cub"
# define ONLY_CHARS_MAP "01WNSE "

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
}			t_config;

/* PARSER */
int		file_check(char *file, int argc);
int		extension_check(char *file);
char	**read_file(int	fd, char *file);
int		line_count(char *file);
void	parser_and_validate(char **buffer, t_config *config);

/* UTILS */
void	throw_error(char *error);

/* VALIDATE*/
int		validate_config(char **buffer, t_config *config);
#endif