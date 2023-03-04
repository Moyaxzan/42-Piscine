/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaint-p <tsaint-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 15:09:57 by tsaint-p          #+#    #+#             */
/*   Updated: 2023/02/19 14:49:34 by tsaint-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utilities.h"
#include <stdio.h>
#include <unistd.h>

int	absolute(int nb)
{
	if (nb < 0)
		return (nb * -1);
	return (nb);
}

int	not_in_col(char value, char **tab, int index_col, int size)
{
	int	i;

	i = 1;
	while (tab[i][index_col] != value && i < size - 2)
		i++;
	if (i == size - 2)
		return (1);
	return (0);
}

int	not_in_row(char value, char **tab, int index_row, int size)
{
	int	i;

	i = 1;
	while (tab[index_row][i] != value && i < size - 2)
		i++;
	if (i == size - 2)
		return (1);
	return (0);
}
