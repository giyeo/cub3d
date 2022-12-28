/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtxcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjose-d <anjose-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 18:36:20 by anjose-d          #+#    #+#             */
/*   Updated: 2022/12/19 18:49:07 by anjose-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		**ft_mtxcpy(char **mtx_root)
{
	char	**mtx_ret;
	int		mtx_len;
	int		i;

	mtx_ret = NULL;
	mtx_len = ft_mtxlen(mtx_root);
	mtx_ret = malloc((mtx_len * sizeof(char **)) + 1);
	if (!mtx_ret)
		return (NULL);
	i = 0;
	while (i < mtx_len)
	{
		mtx_ret[i] = ft_strdup(mtx_root[i]);
		i++;
	}
	mtx_ret[i] = '\0';
	return (mtx_ret);
}
