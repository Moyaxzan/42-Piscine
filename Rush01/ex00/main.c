/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaint-p <tsaint-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 09:59:37 by tsaint-p          #+#    #+#             */
/*   Updated: 2023/02/19 21:51:37 by tsaint-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "towerdoku.h"
#include "solve.h"
#include <stdio.h>
#define SIZE 6

int	main(int argc, char **argv)
{
	char	**tab;
	int		error;

	error = 0;
	if (argc == 2 && !(basic_check(argv[1])))
	{
		tab = init_grid(SIZE, argv[1]);
		error = simple_cases(tab, SIZE);
		error += backtrack(tab, 0, SIZE);
		if (tab[SIZE - 2][SIZE - 2] != '0')
			displaygrid(tab, SIZE);
		else
			write(1, "Error\n", 6);
	}
	else
		write(1, "Error\n", 6);
	return (error);
}
