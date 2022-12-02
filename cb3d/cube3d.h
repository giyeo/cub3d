#ifndef CUBE3D_H
# define CUBE3D_H

//# include "../../minilibx-linux/mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

# include <string.h> //Ilegal
//_____________________________
typedef struct cube_data
{
	char	*NO;
	char	*SO;
	char	*WE;
	char	*EA;

	int 	F[3];
	int		C[3];

	char	*map;

}	t_cdata;

char	*ft_strjoin(char const *s1, char const *s2);
void    throw_error(char *error);
char	*get_data_from_file(int argc, char *argv[]);

int		get_fd(char *argv);

//parsing
void	parse_file_content(char *file_content);
void	parse_map(char *map_content);
void	is_new_line(char c, int *line, int *column);
#endif