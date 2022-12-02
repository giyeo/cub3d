#include "cube3d.h"

int	jump_to_next_line(char *file_content, int i)
{
	while(file_content[i] != '\n')
		i++;
	return i - 1;
}

void	is_new_line(char c, int *line, int *column)
{
	if(c == '\n')
	{
		*(line) += 1;
		*(column) = 0;
	}
}

void	check_char(char c)
{
	if(c != 'N' && c != 'O' && c != 'S'
	&& c != 'W' && c != 'E' && c != 'A'
	&& c != 'F' && c != 'C' && c != '1'
	&& c != '0' && c != ' ' && c != '\n'
	&& c != '\0'){
		printf("%c\n", c);
		throw_error("Not Allowed Char in .cub file");
	}
}

int	can_parse(char *file_content, int i)
{
	char current = file_content[i];
	char next = file_content[i + 1];
	char after_next = file_content[i + 2];

	if(next == '\0' || after_next == '\0')
		throw_error("File not Completed");
	if(((current == 'N' && next == 'O')
		|| (current == 'S' && next == 'O')
		|| (current == 'W' && next == 'E')
		|| (current == 'E' && next == 'A'))
		&& after_next == ' ')
		return (int)current;
	if(((current == 'F' || current == 'C')
		&& next == ' '))
		return (int)current;
	return 0;
}

int	map_started(char c)
{
	if(c == '0')
		throw_error("Map Started with 0");
	if(c == '1')
		return (1);
	else
		return (0);
}

void	parse_color(char *file_content)
{
	int i = 0;
	while(file_content[i] == ' ')
		i++;
	while(file_content[i] != '\n')
		i++;
}

void	parse_path(char *file_content)
{
	int i = 0;
	int start = 0;
	//tira da frente
	while(file_content[i] == ' ')
		i++;
	start = i;
	while(file_content[i] != '\n')
		i++;
	i--;
	//tira de tras
	while(file_content[i] == ' ')
		i--;
	i++;
	
	char *path;
	path = (char *)malloc(sizeof(char) * (i - start) + 1);
	strncpy(path, file_content + start, i - start);
	path[i - start] = '\0';

	int fd = get_fd(path);
	
	free(path);
	close(fd);
}

void	parse_info(char *file_content, char type)
{
	if(type == 'F' || type == 'C')
		parse_color(file_content + 1);
	else
		parse_path(file_content + 2);
}

int	parse_settings(char *file_content)
{
	int i = 0;
	int line = 0;
	int column = 0;
	//parse_variables();
	while(file_content[i] != '\0' && !map_started(file_content[i]))
	{
		//Verifica se atual char é valido e se deve começar a parsear um mapa.
		check_char(file_content[i]);
		//Verifica Quebras de linha
		is_new_line(file_content[i], &line, &column);
		//É executado caso o parse do mapa ainda não começou, identifica um tipo, e tenta parsear os valores.
		int type = can_parse(file_content, i);
		if(type != 0)
		{
			parse_info(file_content + i, (char)type);
			i = jump_to_next_line(file_content, i); //precisamos pegar as infos agora, e colocar dentro de uma variavel
		}
		//É executado caso o mapa tenha começado.
		column++;
		i++;
	}
	//volta para a primeira coluna da linha que começa o mapa.
	return i - (column - 1);
}

void	parse_file_content(char *file_content)
{
	//t_cdata *var;
	//var = (t_cdata *)malloc(sizeof(t_cdata));
	//faz o parsing do mapa a partir da primeira coluna da primeira linha que ele aparece.
	parse_map(file_content + parse_settings(file_content));
	//return var;
}