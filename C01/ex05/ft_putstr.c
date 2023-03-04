/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaint-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 19:30:55 by tsaint-p          #+#    #+#             */
/*   Updated: 2023/02/13 11:22:22 by tsaint-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str)
{
	int		i;
	char	c;

	if (str != 0x0)
	{
		i = 0;
		while (str[i] != '\0')
		{
			c = str[i];
			write(1, &c, 1);
			i++;
		}
	}
}
