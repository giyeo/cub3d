/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpaulino <rpaulino@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 03:30:14 by rpaulino          #+#    #+#             */
/*   Updated: 2022/12/03 03:30:14 by rpaulino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int	main(int argc, char **argv)
{
	char	*file_content;

	file_content = get_data_from_file(argc, argv[1]);
	parse_file_content(file_content);
	printf("%s\n", file_content);
	free(file_content);
}
