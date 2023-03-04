/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaint-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 10:47:43 by tsaint-p          #+#    #+#             */
/*   Updated: 2023/02/09 15:28:20 by tsaint-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_it(char tab[], int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		write(1, &tab[i], 1);
		i++;
	}
	if (tab[0] != '9' - n + 1)
		write(1, ", ", 2);
}

int	ft_check_array(char tab[], int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		if (tab[i] > '9' - n + i + 1)
			return (0);
		i++;
	}
	return (1);
}

void	init_array(char arr[10], int n)
{
	char	a;
	int		k;

	a = '0';
	k = 0;
	while (a < '0' + n)
		arr[k++] = a++;
}

void	ft_print_combn(int n)
{
	char	tab[10];
	int		j;

	if (10 > n && n > 0)
	{
		init_array(tab, n);
		while (ft_check_array(tab, n))
		{
			ft_print_it(tab, n);
			j = 1;
			tab[n - 1]++;
			while (tab[n - j] > '9' - j + 1 && j < n)
			{
				tab[n - j - 1]++;
				j++;
			}
			while (j > 1)
			{
				tab[n - j + 1] = 1 + tab[n - j];
				j--;
			}
		}
	}
}
