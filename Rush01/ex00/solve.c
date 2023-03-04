/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaint-p <tsaint-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 14:59:15 by tsaint-p          #+#    #+#             */
/*   Updated: 2023/02/19 20:04:01 by tsaint-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solve.h"
#include "utilities.h"
#include "towerdoku.h"
#include "jump.h"
#include <stdio.h>

int	write_4(int row, int col, char **tab, int size)
{
	int	indicator;
	int	i;

	i = 0;
	indicator = 0;
	if (row == size - 1 || col == size - 1)
		indicator = 5;
	if (row == size - 1 || row == 0)
	{
		while (i < size - 2)
			tab[i][col] = '0' + absolute(i++ - indicator + 1);
		if (indicator == 0)
			indicator = 0;
		return (tab[i - --indicator][col] != '1');
	}
	else if (col == size - 1 || col == 0)
	{
		while (i < size - 2)
			tab[row][i] = '0' + absolute(i++ - indicator + 1);
		if (indicator == 0)
			indicator = 0;
		return (tab[row][i - --indicator] != '1');
	}
}

int	simple_cases(char **tab, int size)
{
	int	row;
	int	col;
	int	error;

	row = 0;
	col = 0;
	error = 0;
	while (row < size)
	{
		col = 0;
		while (col < size)
		{
			if (tab[row][col] == '4' &&
				(row == size - 1 || col == size - 1 || row == 0 || col == 0))
				error += write_4(row, col, tab, size);
			col++;
		}
		row++;
	}
	return (error);
}

int	check_views(int row, int col, char **tab, int size)
{
	int	results;

	results = 1;
	results *= jump_col_down(col, tab, size);
	results *= jump_row_right(row, tab, size);
	if (col == size - 2)
		results *= jump_row_left(row, tab, size);
	if (row == size - 2)
		results *= jump_col_up(col, tab, size);
	return (results);
}

int	backtrack(char **tab, int pos, int size)
{
	char	val;
	int		row;
	int		col;

	val = '1';
	row = pos / (size - 1) + 1;
	col = pos % (size - 1) + 1;
	if (col == (size - 1) && row == (size - 1))
		return (1);
	if (tab[row][col] != '0')
		return (backtrack(tab, pos + 1, size));
	while (val <= '4')
	{
		if (not_in_row(val, tab, row, 6) && not_in_col(val, tab, col, 6))
		{
			tab[row][col] = val;
			if (check_views (row, col, tab, size))
				if (backtrack(tab, pos + 1, size))
					return (1);
		}
		val++;
	}
	tab[row][col] = '0';
	return (0);
}
