/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpaulino <rpaulino@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 03:38:39 by rpaulino          #+#    #+#             */
/*   Updated: 2022/12/03 04:04:48 by rpaulino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	int		f[3];
	int		c[3];
	char	*map;
}	t_cdata;

char	*ft_strjoin(char const *s1, char const *s2);
void	throw_error(char *error);
char	*get_data_from_file(int argc, char *argv);

int		get_fd(char *argv);

//parsing
void	parse_file_content(char *file_content);
void	is_new_line(char c, int *line, int *column);

void	is_valid_char(char c);
void	is_new_line(char c, int *line, int *column);
int		jump_to_next_line(char *file_content, int i);
void	parse_path(char *file_content);
void	parse_color(char *file_content);
#endif