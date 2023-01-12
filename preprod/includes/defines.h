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
#define YELLOW_PIXEL 0xFFFF00
#define BLUE_PIXEL 0x0000FF
#define GREY_PIXEL 0xAAAAAA


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
# define MINIMAP_SCALE_FACTOR 0.2

# define WINDOW_WIDTH (1024)
# define WINDOW_HEIGHT (600)
# define RAY_RANGE (WINDOW_WIDTH * 2)
# define FOV_ANGLE (60 * (PI / 180))

#endif