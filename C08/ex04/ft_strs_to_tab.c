/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaint-p <tsaint-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 21:42:57 by tsaint-p          #+#    #+#             */
/*   Updated: 2023/03/02 18:24:53 by tsaint-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <stdlib.h>

char	*ft_strdup(char *src, int len)
{
	int		i;
	char	*dest;

	i = 0;
	dest = malloc(sizeof(char) * (len + 1));
	while (i < len)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

struct	s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	int					i;
	int					j;
	int					size;
	struct s_stock_str	*array;

	i = 0;
	array = malloc(sizeof(struct s_stock_str) * (ac + 1));
	if (!array)
		return (NULL);
	while (i < ac)
	{
		j = 0;
		size = 0;
		while (av[i][j])
		{
			size++;
			j++;
		}
		array[i].size = size;
		array[i].str = av[i];
		array[i].copy = ft_strdup(av[i], size);
		i++;
	}
	array[i].str = 0;
	return (array);
}
