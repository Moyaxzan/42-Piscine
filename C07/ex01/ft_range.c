/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaint-p <tsaint-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 15:08:15 by tsaint-p          #+#    #+#             */
/*   Updated: 2023/02/27 10:30:20 by tsaint-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*array;
	int	i;

	i = 0;
	array = NULL;
	if (max - min > 0)
	{
		array = malloc(sizeof(int) * (max - min));
		if (!array)
			return (NULL);
		while (min < max)
			array[i++] = min++;
	}
	return (array);
}
/*
#include <stdio.h>
int	main(void)
{
	int	*arr = ft_range(0, 1);
	int	i = 0;

	while (i < 1)
		printf("%d \n", arr[i++]);
	free(arr);
	return (0);
}*/
