/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaint-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 14:55:44 by tsaint-p          #+#    #+#             */
/*   Updated: 2023/02/13 10:33:41 by tsaint-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr_non_printable(char *str)
{
	int				i;
	unsigned char	uchar;

	i = 0;
	while (str[i] != '\0' )
	{
		if (str [i] < 32 || str[i] > 126)
		{
			uchar = str[i];
			ft_putchar('\\');
			ft_putchar("0123456789abcdef"[uchar / 16]);
			ft_putchar("0123456789abcdef"[uchar % 16]);
		}
		else
			write(1, &str[i], 1);
		i++;
	}
}
