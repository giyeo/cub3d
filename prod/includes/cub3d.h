/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjose-d <anjose-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 19:54:39 by anjose-d          #+#    #+#             */
/*   Updated: 2023/01/13 22:11:31 by anjose-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

typedef struct s_config
{
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	int		f[3];
	int		c[3];
	char	**map;
	int		player_position[2];
	char	player_direction;
}			t_config;

/* PARSER */
int		file_validate(char *file, int argc);
int		file_check(char *file);
int		extension_check(char *file);
char	**read_file(int fd, char *file);
int		line_count(char *file);
int		parser_and_validate(char **buffer, t_config *config);
int		find_map_start(char **read_file);

/* UTILS */
int		throw_error(char *error);
int		throw_msg_error(int error);
int		only_these(char *str, char *needles);
void	config_init(t_config *config);
void	print_struct(t_config *config);
int		check_struct(t_config *config);
int		is_one_of_these(char c, char *these);
int		find_player(char **buffer, int first_line, t_config *config);
int		test_path(char *path);

/* VALIDATE */
int		validate_config(char **buffer, t_config *config, int map_line);
int		validate_map(char **buffer, t_config *config);

int		parse_line_content(char *line_content, char type, t_config *config);

void	parse_color(char *file_content, char type, t_config *config);

/* FREE */
void	free_config(t_config *config);

#endif