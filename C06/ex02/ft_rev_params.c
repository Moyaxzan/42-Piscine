/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaint-p <tsaint-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 15:53:46 by tsaint-p          #+#    #+#             */
/*   Updated: 2023/02/17 10:51:22 by tsaint-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char **argv)
{
	int	i;

	i = 0;
	argc = argc - 1;
	while (argc > 0)
	{
		i = 0;
		while (argv[argc][i])
			write(1, &argv[argc][i++], 1);
		write(1, "\n", 1);
		argc--;
	}
	return (0);
}
