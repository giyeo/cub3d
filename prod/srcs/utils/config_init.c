#include "cub3d.h"

void	config_init(t_config *config)
{
	config->NO = NULL;
	config->SO = NULL;
	config->WE = NULL;
	config->EA = NULL;
	config->map = NULL;
	config->player_position[0] = -1;
	config->player_position[1] = -1;
	// config->errors[ERR_OK] = "Success";
	// config->errors[ERR_NO_FD] = "can't get file descriptor";
	// config->errors[ERR_INV_CHAR_IN_FILE] = "invalid char in .cub file";
	// config->errors[ERR_FILE_INCOMPLETE] = "file isn't complete";
	// config->errors[ERR_MAP_STARTS_ZERO] = "map started with 0";
	// config->errors[ERR_MAP_INVALID_CHAR] = "invalid char in map";
	// config->errors[ERR_MAP_INNEXIST] = "no map";
	// config->errors[ERR_MAP_ENTRANCE] = "0 on top or bottom of the map";
	// config->errors[ERR_MAP_INVALID_WALLS] = "letter in the walls | 0 in the wall";
	// config->errors[ERR_TOO_MNY_ARGS] = "too many arguments";
	// config->errors[ERR_FILE_EXT_INVALID] = "invalid file extension";
	// config->errors[ERR_CONFIG_MISSING] = "configuration missing";
	// config->errors[ERR_CONFIG_COLOR_DUP] = "duplicate of colors";
	// config->errors[ERR_CONFIG_TEXT_DUP] = "more than one texture";
}