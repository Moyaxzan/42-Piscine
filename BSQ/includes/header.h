/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaint-p <tsaint-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 16:12:21 by tsaint-p          #+#    #+#             */
/*   Updated: 2023/03/01 22:07:23 by tsaint-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>

typedef struct s_map
{
	char	**parsed;
	int		**matrix;
	char	*foe;
	int		width;
	int		height;
	int		max_i;
	int		max_j;
	int		max_val;
}	t_map;

int		ft_strlen(char *str);
char	*stdin_read(void);
char	*ft_get_map(char *path);
char	**ft_split(char *str, char **splited_tab);
int		check_map(t_map *map);
int		ft_strlen(char *str);
void	solve(t_map *map);
void	write_map(t_map *map);
void	init_str(char *str, int size);
t_map	*init_map(void);
void	free_map(t_map *map);
int		count_words(char *str);
char	*fill_num(int len, char **parsed, int *i);
void	run(t_map *map, int *i, int argc, char	*map_path);

#endif