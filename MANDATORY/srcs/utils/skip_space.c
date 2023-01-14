/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skip_space.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjose-d <anjose-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 15:08:43 by anjose-d          #+#    #+#             */
/*   Updated: 2023/01/14 15:33:18 by anjose-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*ft_skip_space(char *str)
{
	char	*ret;

	if (!str)
		return (str);
	while (ft_isspace(*str))
		str++;
	ret = str;
	return (ret);
}
