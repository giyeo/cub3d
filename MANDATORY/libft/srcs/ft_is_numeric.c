/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_numeric.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjose-d <anjose-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 20:20:24 by anjose-d          #+#    #+#             */
/*   Updated: 2023/01/14 17:08:34 by anjose-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_first_pos(char c);
static char		*skip_spc1(char *str);

int	ft_is_numeric(char *str)
{
	int	i;
	int	space_found;

	space_found = 0;
	if (str && check_first_pos(str[0]))
	{
		i = 1;
		str = skip_spc1(str);
		while (str[i])
		{
			if (!ft_isdigit(str[i]))
			{
				if (ft_isspace(str[i]))
					space_found++;
				else
					return (0);
			}
			else if (ft_isdigit(str[i]) && space_found)
				return (0);
			i++;
		}
	}
	else
		return (0);
	return (1);
}

static int	check_first_pos(char c)
{
	if (c == '+' || c == '-' || ft_isdigit(c))
		return (1);
	return (0);
}

static char 	*skip_spc1(char *str)
{
	char	*ret;

	if (!str)
		return (str);
	while (ft_isspace(*str))
		str++;
	ret = str;
	return (ret);
}
