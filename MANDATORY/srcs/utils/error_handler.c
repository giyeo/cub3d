/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjose-d <anjose-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 17:33:23 by anjose-d          #+#    #+#             */
/*   Updated: 2023/01/13 20:39:48 by anjose-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	errors_init(char **errors);

int	throw_error(char *error)
{
	printf("Error\n%s.\n", error);
	return (-1);
}

int	throw_msg_error(int error)
{
	char	*errors[256];

	if (error > 0)
	{
		errors_init(&(*errors));
		return (throw_error(errors[error]));
	}
	return (-1);
}

void	errors_init(char **errors)
{
	errors[ERR_OK] = "Success";
	errors[ERR_NO_FD] = "Can't get file descriptor";
	errors[ERR_INV_CHAR_IN_FILE] = "Invalid char in .cub file";
	errors[ERR_FILE_INCOMPLETE] = "File isn't complete";
	errors[ERR_MAP_STARTS_ZERO] = "Map started with 0";
	errors[ERR_MAP_INVALID_CHAR] = "Invalid char in map";
	errors[ERR_MAP_INNEXIST] = "Map was not found";
	errors[ERR_MAP_ENTRANCE] = "0 on top or bottom of the map";
	errors[ERR_MAP_INVALID] = "Invalid map";
	errors[ERR_TOO_MNY_ARGS] = "Too many arguments";
	errors[ERR_FILE_EXT_INVALID] = "Invalid file extension";
	errors[ERR_CONFIG_MISSING] = "Configuration missing";
	errors[ERR_CONFIG_COLOR_DUP] = "Duplicate of colors";
	errors[ERR_CONFIG_TEXT_DUP] = "More than one texture";
	errors[ERR_INV_CHAR_COLOR] = "Invalid Char on Color";
	errors[ERR_NOT_ENOUGH_DIGITS] = "Not enough digits";
	errors[ERR_MORE_THAN_ONE_PLAYER] = "The map has more than one player";
}
