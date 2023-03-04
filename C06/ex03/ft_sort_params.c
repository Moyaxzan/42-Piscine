/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaint-p <tsaint-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 16:06:19 by tsaint-p          #+#    #+#             */
/*   Updated: 2023/02/25 19:28:07 by tsaint-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strcomp(char *s1, char *s2)
{
	int	i;
	int	diff;

	diff = 0;
	i = 0;
	while (s2[i] != '\0' && s1[i] != '\0' && diff == 0)
	{
		diff = s1[i] - s2[i];
		i++;
	}
	if (diff == 0)
		diff = s1[i] - s2[i];
	return (diff);
}

void	ft_swap(char **tab, int a, int b)
{
	char	*tmp;

	tmp = tab[a];
	tab[a] = tab[b];
	tab[b] = tmp;
}

void	ft_sort_tab(char **tab, int size)
{
	char	*min;
	int		imin;
	int		cpt1;
	int		cpt2;

	cpt1 = 1;
	while (cpt1 < size)
	{
		imin = cpt1;
		min = tab[cpt1];
		cpt2 = cpt1 + 1 ;
		while (cpt2 < size)
		{
			if (ft_strcomp(min, tab[cpt2]) > 0)
			{
				min = tab[cpt2];
				imin = cpt2;
			}
			cpt2++;
		}
		ft_swap(tab, cpt1, imin);
		cpt1++;
	}
}

int	main(int argc, char **argv)
{
	int	i;
	int	j;

	j = 0;
	i = 1;
	ft_sort_tab(argv, argc);
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
			write(1, &argv[i][j++], 1);
		write(1, "\n", 1);
		i++;
	}
	return (0);
}
