/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaint-p <tsaint-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 17:28:57 by tsaint-p          #+#    #+#             */
/*   Updated: 2023/02/15 12:14:47 by tsaint-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	size_num(char *str)
{
	int	i;

	i = 0;
	if (str != 0x0)
	{
		while (str[i] >= '0' && str[i] <= '9')
			i++;
	}
	return (i);
}

int	ft_atoi(char *str)
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
	end_num = i + size_num(&str[i]);
	while (i < end_num)
	{
		nbr = nbr * 10;
		nbr += (str[i] - '0');
		i++;
	}
	return (nbr * sign);
}
