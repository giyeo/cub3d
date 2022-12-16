#include "test_main.h"

void	validate_config_test_not_null()
{
	t_config	config;
	char		**buffer;

	int	fd = file_check(SUBJECT_MAP);
	buffer = read_file(fd, SUBJECT_MAP);
	validate_config(buffer, &config);

	TEST_ASSERT_NOT_NULL(config.NO);
	TEST_ASSERT_NOT_NULL(config.SO);
	TEST_ASSERT_NOT_NULL(config.WE);
	TEST_ASSERT_NOT_NULL(config.EA);
	TEST_ASSERT_NOT_NULL(config.map);
}

void	validate_config_test_values_check()
{
	t_config	config;
	char		**buffer;

	int	fd = file_check(SUBJECT_MAP);
	buffer = read_file(fd, SUBJECT_MAP);
	validate_config(buffer, &config);

	TEST_ASSERT_EQUAL_STRING("NO ../textures/texture1", config.NO);
	TEST_ASSERT_EQUAL_STRING("SO ../textures/texture2", config.SO);
	TEST_ASSERT_EQUAL_STRING("WE ../textures/texture3", config.WE);
	TEST_ASSERT_EQUAL_STRING("EA ../textures/texture4", config.EA);
	// TEST_ASSERT_EQUAL_STRING(config.map);
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