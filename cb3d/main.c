//map reader
#include "cube3d.h"

int main(int argc, char **argv)
{
	char *file_content = get_data_from_file(argc, argv);
	parse_file_content(file_content);
	printf("%s\n", file_content);
	free(file_content);
	/*
    PARSE_TEXTURES()
    {
		NO, SO, WE, EA
        Nessa ordem, pular todas os espaços / quebra de linhas, o primeiro
        caractere a se encontrar é especificamente NO, a proxima coisa,
        é um path, seguindo esse ciclo até o 4° Path.

        -Ao ler o buffer, pode retornar um número para a proxima func
        onde vai começar a fazer o parser de cores.
        
    }
    PARSE_COLORS()
    {
        Pular todas os espaços / quebra de linhas, primeiro char valido,
        F depois C, esses, seguidos de 2 números de 0 até 255 seguido por ','
        retornar um número para localização no buffer.
        
    }
    PARSE_MAP()
    {
        -Depois da parte de cima, depois de todo /n conta o número de espaços
        até encontrar o 1, se ele não aparecer, resetar.
        -marcar todos os espaços como 'X', espaço vazio mas considerado.
        -se for encontrado um espaço antes de um /n, marcar ele como 'X'
        -Sempre antes e depois (a menos que seja o último char)
        de um /n (ignorando os 'X', deve ter o número 1)
        -Quando encontrado o primeiro 1, todos devem ser 1 até o \n (ou X).
        -Quando achado o último 1, todos devem ser 1 até \n anterior (ou X).
        -será feita uma matrix baseada no buffer, nela será renderizada
        o raytracer
        
		não pode ter um 0 e espaço;
    }
    RAYTRACE(PARSED_TO_MATRIX_MAP)
	*/

}
