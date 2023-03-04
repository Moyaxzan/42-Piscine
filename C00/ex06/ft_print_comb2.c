/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaint-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 15:50:44 by tsaint-p          #+#    #+#             */
/*   Updated: 2023/02/09 10:43:13 by tsaint-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_write_comb(int a, int b)
{
	char	a1;
	char	a2;
	char	b1;
	char	b2;

	a1 = '0' + (a / 10);
	a2 = '0' + (a % 10);
	b1 = '0' + (b / 10);
	b2 = '0' + (b % 10);
	write(1, &a1, 1);
	write(1, &a2, 1);
	write(1, " ", 1);
	write(1, &b1, 1);
	write(1, &b2, 1);
	if (a != 98 || b != 99)
		write(1, ", ", 2);
}

void	ft_print_comb2(void)
{
	int	a;
	int	b;

	a = 0;
	while (a <= 98)
	{
		b = a + 1;
		while (b <= 99)
		{
			ft_write_comb(a, b);
			b++;
		}
		a++;
	}
}
