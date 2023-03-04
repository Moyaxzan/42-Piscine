/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaint-p <tsaint-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 09:32:30 by tsaint-p          #+#    #+#             */
/*   Updated: 2023/02/28 16:17:15 by tsaint-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*nbr_base(int nbr, char *base);
int		size_num(char *str, char *base);

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	is_base(char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (ft_strlen(str) < 2)
		return (0);
	while (str[i])
	{
		if (str[i] == '+' || str[i] == '-' || str[i] < 32 || str[i] > 126)
			return (0);
		j = i + 1;
		while (str[j])
		{
			if (str[i] == str[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	get_num(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i] != c && base[i])
		i++;
	if (!base[i])
		return (-1);
	return (i);
}

int	ft_atoi_base(char *str, char *base)
{
	int	i;
	int	sign;
	int	nbr;
	int	end_num;

	i = 0;
	sign = 1;
	nbr = 0;
	while (str[i] == 32 || (9 <= str[i] && str[i] <= 13))
		i++;
	while (str[i] != '\0' && (str[i] == '+' || str[i] == '-'))
	{
		if (str[i] == '-')
			sign = -sign;
		i++;
	}
	end_num = i + size_num(&str[i], base) - 1;
	while (i < end_num)
	{
		nbr = nbr * ft_strlen(base);
		nbr += get_num(str[i], base);
		i++;
	}
	return (nbr * sign);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		atoied;
	char	*res;

	atoied = 0;
	if (!(is_base(base_from) && is_base(base_to)))
		return (NULL);
	atoied = ft_atoi_base(nbr, base_from);
	if (atoied == 0)
	{
		res = malloc(sizeof(char) * 2);
		if (!res)
			return (NULL);
		res[0] = base_to[0];
		res[1] = '\0';
	}
	else
		res = nbr_base(atoied, base_to);
	return (res);
}
/*
#include <stdio.h>
int	main(void)
{
	printf("%s \n", ft_convert_base("2147483648", "0123456789", "0123456789"));
	return (0);
}*/
