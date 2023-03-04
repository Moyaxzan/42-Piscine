/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaint-p <tsaint-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 16:09:56 by tsaint-p          #+#    #+#             */
/*   Updated: 2023/03/01 22:07:06 by tsaint-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

int	main(int argc, char **argv)
{
	int		i;
	t_map	**maps;
	char	**map_paths;

	i = 0;
	map_paths = &(argv[1]);
	if (argc == 1)
	{
		map_paths[0] = stdin_read();
		argc++;
	}
	maps = malloc(sizeof(t_map *) * argc);
	while (i < argc - 1)
		run(maps[i], &i, argc, map_paths[i]);
	free(maps);
	return (0);
}
