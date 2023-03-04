/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaint-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 09:18:35 by tsaint-p          #+#    #+#             */
/*   Updated: 2023/02/12 10:31:50 by tsaint-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_rev_int_tab(int *tab, int size)
{
	int	tmp;
	int	cpt;

	tmp = 0;
	tmp++;
	if (tab != 0x0)
	{
		cpt = 0;
		while (cpt < size / 2)
		{
			tmp = tab[size - cpt - 1];
			tab[size - cpt - 1] = tab[cpt];
			tab[cpt] = tmp;
			cpt++;
		}
	}
}
