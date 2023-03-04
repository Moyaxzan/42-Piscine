/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaint-p <tsaint-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 09:32:27 by tsaint-p          #+#    #+#             */
/*   Updated: 2023/02/28 16:12:22 by tsaint-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	is_base(char *str);
int	ft_strlen(char *str);

char	**alloc_num(long nbr, int len_base)
{
	char	**tab;
	int		cpt;

	cpt = 1;
	tab = malloc(sizeof(char *) * 2);
	if (!tab)
		return (NULL);
	if (nbr < 0)
		cpt++;
	while (nbr != 0)
	{
		nbr = nbr / len_base;
		cpt++;
	}
	tab[0] = malloc(sizeof(char) * cpt);
	tab[1] = malloc(sizeof(char) * cpt);
	return (tab);
}

int	size_num(char *str, char *base)
{
	int	i;
	int	j;
	int	not_end;

	i = 0;
	not_end = 1;
	if (str != 0x0)
	{
		while (not_end)
		{
			j = 0;
			while (base[j] != '\0' && str[i] != base[j])
				j++;
			if (base[j] == '\0')
				not_end = 0;
			i++;
		}
	}
	return (i);
}

void	rev_tab(char **tab, int i, int *j)
{
	if (tab[1][0] != '-')
		i--;
	while (*j <= i)
	{
		tab[1][*j] = tab[0][i - *j];
		*j = *j + 1;
	}
	tab[1][*j] = '\0';
}

char	*nbr_base(int nbr, char *base)
{
	int			i;
	int			j;
	char		**tab;
	long long	nb;

	i = 0;
	j = 0;
	nb = nbr;
	tab = alloc_num(nb, ft_strlen(base));
	if (nb < 0)
	{
		tab[1][0] = '-';
		nb = -nb;
		j++;
		i++;
	}
	while (nb != 0)
	{
		tab[0][i] = base[nb % ft_strlen(base)];
		nb = nb / ft_strlen(base);
		i++;
	}
	rev_tab(tab, i, &j);
	return (tab[1]);
}
