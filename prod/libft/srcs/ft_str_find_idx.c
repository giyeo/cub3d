/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_find_idx.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpaulino <rpaulino@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 00:08:14 by anjose-d          #+#    #+#             */
/*   Updated: 2022/12/08 00:53:54 by rpaulino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_str_find_idx(const char *str, int c)
{
	char	*ptr;
	int		i;
	int		len_s;

	len_s = 0;
	while (str[len_s])
		len_s++;
	ptr = (char *)str;
	i = 0;
	while (i < len_s + 1)
	{
		if (ptr[i] == (char)c)
			return (i);
		i++;
	}
	return (-1);
}
