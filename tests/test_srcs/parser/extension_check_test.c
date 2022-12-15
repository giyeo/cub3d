#include "test_main.h"

void	extension_check_test()
{
	TEST_ASSERT_EQUAL(-1, extension_check("asdf"));
	TEST_ASSERT_EQUAL(0, extension_check("asdf.cub"));
	TEST_ASSERT_EQUAL(-1, extension_check("asdf.cu"));
	TEST_ASSERT_EQUAL(-1, extension_check(".cuba"));
	TEST_ASSERT_EQUAL(-1, extension_check("a.cuba"));
}