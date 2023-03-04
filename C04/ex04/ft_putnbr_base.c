/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaint-p <tsaint-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 13:33:03 by tsaint-p          #+#    #+#             */
/*   Updated: 2023/02/21 09:14:59 by tsaint-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (str != 0x0)
	{
		while (str[i] != '\0')
			i++;
	}
	return (i);
}

int	is_base(char *str)
{
	int		i;
	int		j;
	char	passed[100];

	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		j = 0;
		if (str[i] == '+' || str[i] == '-' || str[i] <= ' ' || str [i] == 127)
			return (0);
		passed[i] = str[i];
		while (j < i && str[i] != passed[j])
			j++;
		if (j != i && i > 1)
			return (0);
		i++;
	}
	return (1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int			len_base;
	int			i;
	long int	l_nbr;
	char		revert_res[50];

	l_nbr = nbr;
	i = 0;
	len_base = ft_strlen(base);
	if (len_base >= 2 && is_base(base))
	{
		if (l_nbr < 0)
		{
			write(1, "-", 1);
			l_nbr = -l_nbr;
		}
		while (l_nbr != 0)
		{
			revert_res[i] = base[l_nbr % len_base];
			l_nbr = l_nbr / len_base;
			i++;
		}
		while (i >= 1)
			write(1, &revert_res[--i], 1);
	}
}
