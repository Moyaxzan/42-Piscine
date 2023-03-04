/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaint-p <tsaint-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 14:25:11 by tsaint-p          #+#    #+#             */
/*   Updated: 2023/03/01 22:21:19 by tsaint-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

int	size_num(char *str)
{
	int	i;

	i = 0;
	if (str)
		while (str[i])
			i++;
	return (i);
}

int	is_in_base(char c, char *base)
{
	if (c == base[1] || c == base[2])
		return (1);
	return (0);
}

int	ft_atoi(char *str)
{
	int	i;
	int	nbr;
	int	end_num;

	i = 0;
	nbr = 0;
	end_num = i + size_num(&str[i]);
	while (i < end_num)
	{
		nbr = nbr * 10;
		nbr += (str[i] - '0');
		i++;
	}
	free(str);
	return (nbr);
}

int	check_base(t_map *map)
{
	int		i;
	int		len;

	i = 0;
	len = ft_strlen(map->parsed[0]) - 1;
	map->foe[3] = '\0';
	while (map->parsed[0][len - i] >= 32 && map->parsed[0][len - i] <= 126
		&& i < 3 && !is_in_base(map->parsed[0][len - i], map->foe))
	{
		map->foe[i] = map->parsed[0][len - i];
		i++;
	}
	if (i != 3 || map->parsed[0][len - i] < '0'
	|| map->parsed[0][len - i - 1] > '9')
		return (0);
	map->height = ft_atoi(fill_num(len, map->parsed, &i));
	return (1);
}

int	check_map(t_map *map)
{
	int		i;
	int		j;

	i = 1;
	if (!check_base(map))
		return (0);
	map->width = ft_strlen(map->parsed[1]);
	while (map->parsed[i] && i < map->height + 1)
	{
		j = 0;
		while (map->parsed[i][j] && is_in_base(map->parsed[i][j], map->foe)
			&& j < map->width)
			j++;
		if (j != map->width || map->parsed[i][j] != '\0')
			return (0);
		i++;
	}
	if (i != map->height + 1 || map->parsed[i])
		return (0);
	return (1);
}
