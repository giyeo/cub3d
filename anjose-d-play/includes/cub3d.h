#ifndef CUB3D_H
# define CUB3D_H

# include "libft.h"
# include "mlx.h"
# include <fcntl.h>
# include "errors.h"
# include "defines.h"
# include <X11/X.h>
// open();
# include <stdio.h>
// perror();
# include <string.h>
// strerror();
# include <errno.h>

typedef struct s_conn
{
	void	*mlx_ptr;
	void	*win_ptr;
}				t_conn;

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
	t_conn	conn_mlx;
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
void	check_struct(t_config *config, int i);
int		is_one_of_these(char c, char *these);
int		find_player(char **buffer, int first_line, t_config *config);

/* VALIDATE*/
int		validate_config(char **buffer, t_config *config);
int		validate_map(char **buffer, t_config *config);

/* FREE */
void	free_config(t_config *config);

/* MLX */
// hooks
int		key_mapping(int keysym, t_config *config);
int		end_game(t_config *config);
#endif
