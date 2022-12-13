#include "test_main.h"

#define EXPECTED "asdf"

void	coisa()
{
	g_str = ft_strdup(EXPECTED);
	TEST_ASSERT_EQUAL_STRING(EXPECTED, g_str);
}