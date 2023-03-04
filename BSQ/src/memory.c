/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaint-p <tsaint-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 16:11:15 by tsaint-p          #+#    #+#             */
/*   Updated: 2023/03/01 22:14:18 by tsaint-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

void	init_str(char *str, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		str[i] = '\0';
		i++;
	}
}

t_map	*init_map(void)
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	map->foe = malloc(sizeof(char) * 4);
	init_str(map->foe, 4);
	map->height = 0;
	map->width = 0;
	map->matrix = NULL;
	map->parsed = NULL;
	map->max_i = 0;
	map->max_j = 0;
	map->max_val = 0;
	return (map);
}

void	free_map(t_map *map)
{
	int	i;

	i = 0;
	if (map->foe)
		free(map->foe);
	while (i < map->height && map->matrix)
	{
		free(map->matrix[i]);
		i++;
	}
	i = 0;
	if (map->matrix)
		free(map->matrix);
	free(map);
}
