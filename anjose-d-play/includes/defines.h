#ifndef DEFINES_H
# define DEFINES_H

# define MAP_FILE_EXT ".cub"
# define ONLY_CHARS_MAP "01WNSE "
# define PLAYER_DIRECTIONS "NSEW"

/* colors */
#define RED_PIXEL 0xFF0000
#define GREEN_PIXEL 0xFF00
#define WHITE_PIXEL 0xFFFFFF
#define BLACK_PIXEL 0x0


/* type identifiers */
# define TID_NORTH_TXT "NO"
# define TID_SOUTH_TXT "SO"
# define TID_WEST_TXT "WE"
# define TID_EAST_TXT "EA"
# define TID_FLOOR_CLR "F"
# define TID_CELLING_CLR "C"

/* KEYS */
# define Q 113
# define W 119
# define A 97
# define S 115
# define D 100
# define UP_ARROW 65362
# define DOWN_ARROW 65364
# define LEFT_ARROW 65361
# define RIGHT_ARROW 65363
# define ESC 65307

# define PI 3.141592653
# define TWO_PI 6.283185306

# define TILE_SIZE 64
# define MINIMAP_SCALE_FACTOR 1

// TIRAR DAQUI
#define MAP_NUM_ROWS 7
#define MAP_NUM_COLS 20
#define WINDOW_WIDTH (MAP_NUM_COLS * TILE_SIZE)
#define WINDOW_HEIGHT (MAP_NUM_ROWS * TILE_SIZE)
// # define WINDOW_WIDTH 800
// # define WINDOW_HEIGHT 600

# define FOV_ANGLE (60 * (PI / 180))
# define NUM_RAYS (WINDOW_WIDTH)


#endif