/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaint-p <tsaint-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 11:43:34 by tsaint-p          #+#    #+#             */
/*   Updated: 2023/03/01 15:50:04 by tsaint-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

void	fill_square(t_map *map)
{
	int	i;
	int	j;

	i = map->max_i;
	while (i > map->max_i - map->max_val)
	{
		j = map->max_j;
		while (j > map->max_j - map->max_val)
		{
			map->parsed[i][j] = map->foe[0];
			j--;
		}
		i--;
	}
}

void	write_map(t_map *map)
{
	int		i;
	int		j;

	fill_square(map);
	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{	
			write(1, &map->parsed[i][j], 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}
