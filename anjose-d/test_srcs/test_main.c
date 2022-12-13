#include "test_main.h"

char *g_str;

void	setUp()
{
	g_str = NULL;
}

void	tearDown()
{
	if(g_str)
		free(g_str);
}

int	main()
{
	UNITY_BEGIN();
	
	RUN_TEST(test1);
	RUN_TEST(coisa);

	return (UNITY_END());
}