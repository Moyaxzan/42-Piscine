/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaint-p <tsaint-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 10:57:14 by tsaint-p          #+#    #+#             */
/*   Updated: 2023/03/01 22:50:56 by tsaint-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

int	get_value(char point, char *foe)
{
	if (point == foe[1])
		return (0);
	return (1);
}

int	min_neighbors(int **matrix, int i, int j)
{
	int	min;

	min = matrix[i][j - 1];
	if (matrix[i - 1][j] < min)
		min = matrix[i - 1][j];
	if (matrix[i - 1][j - 1] < min)
		min = matrix[i - 1][j - 1];
	return (min);
}

void	init_matrix(t_map *map)
{
	int	i;
	int	j;

	map->matrix = malloc(sizeof(int *) * (map->height + 1));
	i = 0;
	while (i < map->height)
	{
		j = 0;
		map->matrix[i] = malloc(sizeof(int) * map->width);
		while (j < map->width)
		{
			if (j == 0 || i == 0)
				map->matrix[i][j] = get_value(map->parsed[i][j], map->foe);
			else
			{
				map->matrix[i][j] = get_value(map->parsed[i][j], map->foe);
				if (map->matrix[i][j])
					map->matrix[i][j] += min_neighbors(map->matrix, i, j);
			}
			j++;
		}
		i++;
	}
}

void	find_max(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	map->max_i = 0;
	map->max_j = 0;
	map->max_val = map->matrix[0][0];
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (map->matrix[i][j] > map->max_val)
			{
				map->max_i = i;
				map->max_j = j;
				map->max_val = map->matrix[i][j];
			}
			j++;
		}
		i++;
	}
}

void	solve(t_map *map)
{
	map->parsed++;
	init_matrix(map);
	find_max(map);
}
