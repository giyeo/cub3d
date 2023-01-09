
#include "libft.h"

int	ft_mtx_biggest_strlen(char **mtx)
{
	int	i;
	int	len;
	int	biggest;

	i = 0;
	biggest = 0;
	while (mtx[i])
	{
		len = ft_strlen(mtx[i]);	
		if (len > biggest)
			biggest = len;
		i++;
	}
	return (biggest);
}

