/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaint-p <tsaint-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 17:06:57 by tsaint-p          #+#    #+#             */
/*   Updated: 2023/02/24 20:56:04 by tsaint-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt_approx(int nb)
{
	int	res;

	res = 1;
	if (nb < 0)
		return (0);
	while (res * res <= nb && res < 46340)
		res++;
	return (--res);
}

int	ft_is_prime(int nb)
{
	int	i;
	int	sqrt;

	sqrt = ft_sqrt_approx(nb);
	i = 2;
	if (nb <= 1)
		return (0);
	while (i <= sqrt)
	{	
		if (nb % i == 0)
			return (0);
		i++;
	}
	return (1);
}

int	ft_find_next_prime(int nb)
{
	while (!ft_is_prime(nb))
		nb++;
	return (nb);
}
