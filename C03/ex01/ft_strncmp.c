/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaint-p <tsaint-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 15:03:16 by tsaint-p          #+#    #+#             */
/*   Updated: 2023/02/16 14:53:27 by tsaint-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	int				diff;
	unsigned int	i;

	diff = 0;
	i = 0;
	if (n == 0)
		return (0);
	while (s2[i] != '\0' && s1[i] != '\0' && diff == 0 && i < n - 1)
	{
		diff = s1[i] - s2[i];
		i++;
	}
	if (diff == 0)
		diff = s1[i] - s2[i];
	return (diff);
}
