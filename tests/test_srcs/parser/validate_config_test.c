#include "test_main.h"

void	validate_config_test_not_null()
{
	int	fd = file_check(SUBJECT_MAP);
	file_read = read_file(fd, SUBJECT_MAP);
	config_init(&config);
	validate_config(file_read, &config);

	TEST_ASSERT_NOT_NULL(config.NO);
	TEST_ASSERT_NOT_NULL(config.SO);
	TEST_ASSERT_NOT_NULL(config.WE);
	TEST_ASSERT_NOT_NULL(config.EA);
}

void	validate_config_test_values_check()
{

	int	fd = file_check(SUBJECT_MAP);
	file_read = read_file(fd, SUBJECT_MAP);
	config_init(&config);
	validate_config(file_read, &config);

	TEST_ASSERT_EQUAL_STRING("../textures/texture1", config.NO);
	TEST_ASSERT_EQUAL_STRING("../textures/texture2", config.SO);
	TEST_ASSERT_EQUAL_STRING("../textures/texture3", config.WE);
	TEST_ASSERT_EQUAL_STRING("../textures/texture4", config.EA);
	TEST_ASSERT_EQUAL(220,config.F[0]);
	TEST_ASSERT_EQUAL(100,config.F[1]);
	TEST_ASSERT_EQUAL(0,config.F[2]);
	TEST_ASSERT_EQUAL(225,config.C[0]);
	TEST_ASSERT_EQUAL(30,config.C[1]);
	TEST_ASSERT_EQUAL(0,config.C[2]);
	
}

void	validate_config_test_rgb_wrong()
{
	int			ret;

	int	fd = file_check(WRONG_CONFIG1);
	file_read = read_file(fd, WRONG_CONFIG1);
	config_init(&config);
	ret = validate_config(file_read, &config);

	TEST_ASSERT_EQUAL(ERR_FILE_INCOMPLETE, ret);
}
