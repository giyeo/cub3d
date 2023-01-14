#include "test_main.h"

void	validate_config_test_not_null()
{
	int	fd = file_check(SUBJECT_MAP);
	file_read = read_file(fd, SUBJECT_MAP);
	config_init(&config);

	validate_config(file_read, &config, find_map_start(file_read));

	TEST_ASSERT_NOT_NULL(config.no);
	TEST_ASSERT_NOT_NULL(config.so);
	TEST_ASSERT_NOT_NULL(config.we);
	TEST_ASSERT_NOT_NULL(config.ea);
}

void	validate_config_test_values_check()
{

	int	fd = file_check(SUBJECT_MAP);
	file_read = read_file(fd, SUBJECT_MAP);
	config_init(&config);
	validate_config(file_read, &config, find_map_start(file_read));

	TEST_ASSERT_EQUAL_STRING("../textures/texture1", config.no);
	TEST_ASSERT_EQUAL_STRING("../textures/texture2", config.so);
	TEST_ASSERT_EQUAL_STRING("../textures/texture3", config.we);
	TEST_ASSERT_EQUAL_STRING("../textures/texture4", config.ea);
	TEST_ASSERT_EQUAL(220,config.f[0]);
	TEST_ASSERT_EQUAL(100,config.f[1]);
	TEST_ASSERT_EQUAL(0,config.f[2]);
	TEST_ASSERT_EQUAL(225,config.c[0]);
	TEST_ASSERT_EQUAL(30,config.c[1]);
	TEST_ASSERT_EQUAL(0,config.c[2]);
}

void	validate_config_test_rgb_wrong()
{
	int			ret;

	int	fd = file_check(WRONG_CONFIG1);
	file_read = read_file(fd, WRONG_CONFIG1);
	config_init(&config);
	ret = validate_config(file_read, &config, find_map_start(file_read));

	TEST_ASSERT_EQUAL(ERR_INV_CHAR_IN_FILE, ret);
}

void	validate_config_test_weird_rgb1()
{

	int	fd = file_check(WEIRD_RGB1);
	file_read = read_file(fd, WEIRD_RGB1);
	config_init(&config);
	int	start_line = find_map_start(file_read);
	int ret = validate_config(file_read, &config, start_line);

	TEST_ASSERT_EQUAL(0, ret);
	TEST_ASSERT_EQUAL_STRING("../textures/texture1", config.no);
	TEST_ASSERT_EQUAL_STRING("../textures/texture2", config.so);
	TEST_ASSERT_EQUAL_STRING("../textures/texture3", config.we);
	TEST_ASSERT_EQUAL_STRING("../textures/texture4", config.ea);
	TEST_ASSERT_EQUAL(220,config.f[0]);
	TEST_ASSERT_EQUAL(100,config.f[1]);
	TEST_ASSERT_EQUAL(0,config.f[2]);
	TEST_ASSERT_EQUAL(225,config.c[0]);
	TEST_ASSERT_EQUAL(30,config.c[1]);
	TEST_ASSERT_EQUAL(0,config.c[2]);
}

void	validate_config_test_weird_rgb2()
{

	int	fd = file_check(WEIRD_RGB2);
	file_read = read_file(fd, WEIRD_RGB2);
	config_init(&config);
	int	start_line = find_map_start(file_read);
	int ret = validate_config(file_read, &config, start_line);

	TEST_ASSERT_EQUAL(0, ret);
	TEST_ASSERT_EQUAL_STRING("../textures/texture1", config.no);
	TEST_ASSERT_EQUAL_STRING("../textures/texture2", config.so);
	TEST_ASSERT_EQUAL_STRING("../textures/texture3", config.we);
	TEST_ASSERT_EQUAL_STRING("../textures/texture4", config.ea);
	TEST_ASSERT_EQUAL(220,config.f[0]);
	TEST_ASSERT_EQUAL(100,config.f[1]);
	TEST_ASSERT_EQUAL(0,config.f[2]);
	TEST_ASSERT_EQUAL(225,config.c[0]);
	TEST_ASSERT_EQUAL(30,config.c[1]);
	TEST_ASSERT_EQUAL(0,config.c[2]);
}
