/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaint-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 17:57:11 by tsaint-p          #+#    #+#             */
/*   Updated: 2023/02/11 17:57:17 by tsaint-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	displayrush(int x, int y, int col, int line)
{
	if (col == 1 && line == 1)
		ft_putchar('/');
	else if (line == y && col == 1)
		ft_putchar('\\');
	else if (line == 1 && col == x)
		ft_putchar('\\');
	else if (line == y && col == x)
		ft_putchar('/');
	else if (line == 1 || col == 1 || col == x || line == y)
		ft_putchar('*');
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
