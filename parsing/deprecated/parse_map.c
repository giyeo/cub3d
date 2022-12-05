#include "cube3d.h"

void	check_map_char(char c)
{
	if (c != 'N' && c != 'S' && c != 'W' && c != 'E' && 
		c != '1' && c != '0' && c != ' ' && c != '\n' && c != '\0')
		throw_error("Not Allowed Char in .cub file, in MAP part");
}

int	is_player(char c)
{
	if(c == 'N' || c == 'E' || c == 'S' || c == 'W')
		return 1;
	return 0;
}

int	find_last_line(char *map_content)
{
	int line = 0;
	int line_with_number = 0;
	int i = 0;
	while(map_content[i] != '\0')
	{
		if (map_content[i] == '\n')
			line++;
		if (map_content[i] == '1' || map_content[i] == '0')
			line_with_number = line;
		i++;
	}
	return line_with_number;
}

void	parse_map(char *map_content)
{
	int i = 0;
	int line = 0;
	int column = 0;
	char current;
	char previous;
	char next;

	int last_line = find_last_line(map_content);
	if(last_line == 0)
		throw_error("no map");
	printf("%d\n", last_line);
	while(map_content[i] != '\0')
	{
		check_map_char(map_content[i]);
		is_new_line(map_content[i], &line, &column);

		if(line == 0 || line == last_line)
		{
			if(map_content[i] == '0')
				throw_error("top or bottom of the map has a 0");
		}
		else
		{
			current = map_content[i];
			previous = map_content[i - 1];
			//se o next dar algum erro, pega a last line e last column e da um jeito.
			next = map_content[i + 1];

			//Checa se tem letras nas paredes.
			if(is_player(current))
			{
				if((previous != '0' && previous != '1')
				|| (next != '0' && next != '1'))
					throw_error("Letter in the walls");
			}
			//checa se o 0 está em uma parede.
			if(current == '0')
			{
				if((previous == ' ' || next == ' ')
				|| (previous == '\n' || next == '\n')
				|| (next == '\0'))
					throw_error("0 in is the wall");
			}
		}
		i++;
		column++;
	}
	//aloca apenas o mapa para um ponteiro.
	//char *map;
	//strncpy(map, parse_map, i);
}
//não consigo checar em baixo/ em cima ainda
/*
1111
10N1
11

1
10N1
1111

SÓ TRABALHO EM UMA DIMENSÃO, NOT GOOD
*/