/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaint-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 10:35:43 by tsaint-p          #+#    #+#             */
/*   Updated: 2023/02/13 10:48:15 by tsaint-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *b;
	*b = *a;
	*a = tmp;
}

void	ft_sort_int_tab(int *tab, int size)
{
	int	min;
	int	imin;
	int	cpt1;
	int	cpt2;

	cpt1 = 0;
	while (cpt1 < size)
	{
		imin = cpt1;
		min = tab[cpt1];
		cpt2 = cpt1 + 1 ;
		while (cpt2 < size)
		{
			if (tab[cpt2] < min)
			{
				min = tab[cpt2];
				imin = cpt2;
			}
			cpt2++;
		}
		ft_swap(&tab[cpt1], &tab[imin]);
		cpt1++;
	}
}
