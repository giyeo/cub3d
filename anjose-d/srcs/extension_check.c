/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extension_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjose-d <anjose-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 17:43:13 by anjose-d          #+#    #+#             */
/*   Updated: 2022/12/13 18:20:26 by anjose-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	extension_check(char *file)
{
	int	file_len;
	int	ext_len;

	file_len = ft_strlen(file);
	ext_len = ft_strlen(MAP_FILE_EXT);
	file += (file_len - ext_len);
	int ret = ft_strncmp(file, MAP_FILE_EXT, ext_len);
	if (ret != 0)
		return (-1);
	return (0);
}