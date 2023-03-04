/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush03.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaint-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 19:01:11 by tsaint-p          #+#    #+#             */
/*   Updated: 2023/02/11 19:03:13 by tsaint-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	displayrush(int x, int y, int col, int line)
{
	if (col == 1 && line == 1)
		ft_putchar('A');
	else if (line == y && col == 1)
		ft_putchar('A');
	else if (line == 1 && col == x)
		ft_putchar('C');
	else if (line == y && col == x)
		ft_putchar('C');
	else if (line == 1 || col == 1 || col == x || line == y)
		ft_putchar('B');
	else
		ft_putchar(' ');
}

void	rush(int x, int y)
{
	int	col;
	int	line;

	line = 1;
	while (line <= y)
	{
		col = 1;
		while (col <= x)
		{
			displayrush(x, y, col, line);
			col++;
		}
		ft_putchar('\n');
		line++;
	}
}
