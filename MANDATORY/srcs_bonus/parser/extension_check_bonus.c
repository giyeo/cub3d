/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extension_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjose-d <anjose-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 17:43:13 by anjose-d          #+#    #+#             */
/*   Updated: 2023/01/14 19:58:58 by anjose-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int	extension_check(char *file)
{
	int	file_len;
	int	ext_len;
	int	ret;

	file_len = ft_strlen(file);
	ext_len = ft_strlen(MAP_FILE_EXT);
	file += (file_len - ext_len);
	ret = ft_strncmp(file, MAP_FILE_EXT, ext_len);
	if (ret != 0)
		return (-1);
	return (0);
}
