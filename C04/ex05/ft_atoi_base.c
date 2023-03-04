/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaint-p <tsaint-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 16:21:22 by tsaint-p          #+#    #+#             */
/*   Updated: 2023/02/21 09:48:44 by tsaint-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int	get_num(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i] != c)
		i++;
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
