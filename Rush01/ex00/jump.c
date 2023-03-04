/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jump.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaint-p <tsaint-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 14:48:20 by tsaint-p          #+#    #+#             */
/*   Updated: 2023/02/19 21:43:48 by tsaint-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "jump.h"
#include <stdio.h>

int	jump_col_down(int col, char **tab, int size)
{
	int		i;
	int		jump;
	char	max;

	i = 1;
	max = 0;
	jump = 0;
	while (tab[i][col] != '0' && i < size - 1)
	{
		if (tab[i][col] > max)
		{
			max = tab[i][col];
			jump++;
		}
		i++;
	}
	if (jump + '0' > tab[0][col]
		|| (jump + '0' != tab[0][col] && i == size - 1))
		return (0);
	return (1);
}

int	jump_col_up(int col, char **tab, int size)
{
	int		i;
	int		jump;
	char	max;

	i = size - 2;
	jump = 0;
	max = 0;
	while (i > 0)
	{
		if (tab[i][col] > max)
		{
			max = tab[i][col];
			jump++;
		}
		i--;
	}
	if (jump + '0' != tab[size - 1][col])
		return (0);
	return (1);
}

int	jump_row_right(int row, char **tab, int size)
{
	int		i;
	int		jump;
	char	max;

	i = 1;
	max = 0;
	jump = 0;
	while (tab[row][i] != '0' && i < size - 1)
	{
		if (tab[row][i] > max)
		{
			max = tab[row][i];
			jump++;
		}
		i++;
	}
	if (jump + '0' > tab[row][0]
		|| (jump + '0' != tab[row][0] && i == size - 1))
		return (0);
	return (1);
}

int	jump_row_left(int row, char **tab, int size)
{
	int		i;
	int		jump;
	char	max;

	i = size - 2;
	jump = 0;
	max = 0;
	while (i > 0)
	{
		if (tab[row][i] > max)
		{
			max = tab[row][i];
			jump++;
		}
		i--;
	}
	if (jump + '0' != tab[row][size - 1])
		return (0);
	return (1);
}
