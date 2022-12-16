/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjose-d <anjose-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 10:46:45 by anjose-d          #+#    #+#             */
/*   Updated: 2022/12/16 10:59:56 by anjose-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORS_H
# define ERRORS_H

enum e_errors
{
	ERR_OK = 0,
	ERR_NO_FD,						// can't get file descriptor
	ERR_INV_CHAR_IN_FILE,			// invalid char in .cub file		
	ERR_FILE_INCOMPLETE,			// file isn't complete (?)
	ERR_MAP_STARTS_ZERO,			// map started with 0
	ERR_MAP_INVALID_CHAR,			// invalid char in map
	ERR_MAP_INNEXIST,				// no map
	ERR_MAP_ENTRANCE,				// 0 on top or bottom of the map
	ERR_MAP_INVALID_WALLS,			// letter in the walls | 0 in the wall
	ERR_TOO_MNY_ARGS,				// too many arguments
	ERR_FILE_EXT_INVALID,			// invalid file extension
	ERR_CONFIG_MISSING,				// configuration missing
	ERR_CONFIG_COLOR_DUP,			// duplicate of colors
	ERR_CONFIG_TEXT_DUP				// more than one texture
};

#endif