#include "test_main.h"

void	validate_config_test()
{
	t_config	config;
	char		**buffer;

	int	fd = file_check(SUBJECT_MAP);
	buffer = read_file(fd, SUBJECT_MAP);
	validate_config(buffer, &config);

	// TEST_ASSERT_NOT_NULL(config.C);
}
// separar mapa de config
	//começa do final da matrix
	// linha tem APENAS
		// 1, 0, N, S, E, W
		// e não é '\0'
			// se sim
				// linha de mapa
				// veja a proxima linha
			// se não
				// separação entre mapa e config foi encontrada
	// 