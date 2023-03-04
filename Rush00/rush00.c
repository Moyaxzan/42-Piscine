/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaint-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 18:03:13 by tsaint-p          #+#    #+#             */
/*   Updated: 2023/02/11 18:03:16 by tsaint-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	displayrush(int x, int y, int col, int line)
{
	if (col == 1 || col == x)
	{
		if (line == 1 || line == y)
			ft_putchar('o');
		else
			ft_putchar('|');
	}
	else if (line == 1 || line == y)
		ft_putchar('-');
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
