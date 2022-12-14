/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpaulino <rpaulino@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 03:32:11 by rpaulino          #+#    #+#             */
/*   Updated: 2022/12/03 04:50:59 by rpaulino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	throw_error(char *error)
{
	printf("Error! %s\n", error);
	exit(1);
}

void	python_log(char *log)
{
	printf("%s ", log);
}