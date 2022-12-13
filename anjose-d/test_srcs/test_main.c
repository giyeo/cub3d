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
	
	ft_printf("\033[1;33m file_check_tests \033[0m\n");
	RUN_TEST(file_check_test_existance);
	RUN_TEST(file_check_test_permission);

	return (UNITY_END());
}
void	close_fd(int fd)
{
	if (fd > 0)
		close(fd);
}