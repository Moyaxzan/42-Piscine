/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   towerdoku.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaint-p <tsaint-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 10:02:02 by tsaint-p          #+#    #+#             */
/*   Updated: 2023/02/19 21:52:13 by tsaint-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "towerdoku.h"
#include <stdlib.h>

int	basic_check(char *args)
{
	int	i;

	i = 0;
	while (args[i])
	{
		if (args[i] == ' ')
					i++;
		if ((args[i] >= '1' && args[i] <= '4') || (args[i] == ' '))
		{
			if ((i >= 0 && i <= 6) || (i >= 16 && i <= 22))
			{
				if (args[i] == args[i + 8]
					&& args[i] != '2' && args[i + 8] != '2')
					return (1);
			}
			i++;
		}
		else
			return (1);
	}
	if (i == 31)
		return (0);
	else
		return (1);
}

void	fill_grid(char **tab, int i, int j, char *povs)
{
	if (i == 0)
		tab[i][j] = povs[(j - 1) * 2];
	else if (i == 5)
		tab[i][j] = povs[(j + 3) * 2];
	else if (j == 0)
		tab[i][j] = povs[(i + 7) * 2];
	else if (j == 5)
		tab[i][j] = povs[(i + 11) * 2];
	else
		tab[i][j] = '0';
}

char	**init_grid(int size, char *povs)
{
	char	**tab;
	int		i;
	int		j;

	i = 0;
	j = 0;
	tab = malloc (sizeof(char *) * size);
	while (i < 6)
	{
		j = 0;
		tab[i] = malloc(sizeof(char) * size);
		while (j < 6)
		{
			if ((j == 0 || j == size - 1) && (i == 0 || i == size - 1))
				tab[i][j] = '0';
			else
				fill_grid(tab, i, j, povs);
			j++;
		}
		i++;
	}
	return (tab);
}

void	displaygrid(char **grid, int size)
{
	int	i;
	int	j;

	i = 1;
	j = 1;
	while (i < size - 1)
	{
		j = 1;
		while (j < size - 1)
		{
			write(1, &grid[i][j], 1);
			if (j != 4)
				write(1, " ", 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}
