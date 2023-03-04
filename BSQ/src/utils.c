/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaint-p <tsaint-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 19:02:24 by tsaint-p          #+#    #+#             */
/*   Updated: 2023/03/01 22:51:15 by tsaint-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

char	*stdin_read(void)
{
	char	buffer[1];
	int		fd;

	fd = open("./map.txt", O_CREAT | O_RDWR | O_TRUNC, 0666);
	while (read(0, buffer, 1))
		write(fd, buffer, 1);
	close(fd);
	return ("./map.txt");
}

char	*fill_num(int len, char **parsed, int *i)
{
	char	*num;

	num = malloc(sizeof(char) * (len - *i + 2));
	init_str(num, len - *i + 2);
	while (len - *i + 1)
	{
		num[*i - 3] = parsed[0][*i - 3];
		(*i)++;
	}
	num[*i - 3] = '\0';
	return (num);
}

void	free_tab(char **tab)
{
	int		k;

	k = 0;
	while (tab[k])
		free(tab[k++]);
	free(tab);
}

void	run(t_map *map, int *i, int argc, char	*map_path)
{
	char	*buff;
	char	**splited_tab;

	map = init_map();
	splited_tab = NULL;
	buff = NULL;
	buff = ft_get_map(map_path);
	if (buff)
	{
		splited_tab = malloc(sizeof(char *) * (count_words(buff) + 1));
		map->parsed = ft_split(buff, splited_tab);
		free(buff);
	}
	if (buff && map->parsed[1] && check_map(map))
	{
		solve(map);
		write_map(map);
		free_tab(splited_tab);
	}
	else
		write(1, "map error\n", 10);
	free_map(map);
	(*i)++;
	if (*i != argc - 1)
		write(1, "\n", 1);
}
