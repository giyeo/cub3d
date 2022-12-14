#include "test_main.h"

void	line_count_test_no_breakline()
{
	char	*file = "maps/subject.cub";

	TEST_ASSERT_EQUAL(20, line_count(file));
}

void	line_count_test_breaklines()
{
	char	*file = "maps/several_breaklines.cub";

	TEST_ASSERT_EQUAL(20, line_count(file));
}