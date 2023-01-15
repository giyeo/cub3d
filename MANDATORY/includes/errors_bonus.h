/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjose-d <anjose-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 10:46:45 by anjose-d          #+#    #+#             */
/*   Updated: 2023/01/15 17:04:15 by anjose-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORS_BONUS_H
# define ERRORS_BONUS_H

enum e_errors
{
	ERR_OK = 0,
	ERR_NO_FD,
	ERR_INV_CHAR_IN_FILE,
	ERR_FILE_INCOMPLETE,
	ERR_MAP_STARTS_ZERO,
	ERR_MAP_INVALID_CHAR,
	ERR_MAP_INNEXIST,
	ERR_MAP_ENTRANCE,
	ERR_MAP_INVALID,
	ERR_TOO_MNY_ARGS,
	ERR_FILE_EXT_INVALID,
	ERR_CONFIG_MISSING,
	ERR_CONFIG_COLOR_DUP,
	ERR_CONFIG_TEXT_DUP,
	ERR_INV_CHAR_COLOR,
	ERR_NOT_ENOUGH_DIGITS,
	ERR_MAP_NOT_FOUND,
	ERR_MORE_THAN_ONE_PLAYER
};

#endif