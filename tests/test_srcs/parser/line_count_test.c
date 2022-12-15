#include "test_main.h"

void	line_count_test_no_breakline()
{
	TEST_ASSERT_EQUAL(22, line_count(SUBJECT_MAP));
}

void	line_count_test_breaklines()
{
	TEST_ASSERT_EQUAL(27, line_count(MANY_BLINES_MAP));
}