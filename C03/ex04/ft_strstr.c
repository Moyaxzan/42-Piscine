/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaint-p <tsaint-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 19:47:16 by tsaint-p          #+#    #+#             */
/*   Updated: 2023/02/15 15:00:56 by tsaint-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (str != 0x0)
	{
		while (str[i] != '\0')
			i++;
	}
	return (i);
}

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	j;
	int	len_str;
	int	len_tf;

	i = 0;
	j = 0;
	len_str = ft_strlen(str);
	len_tf = ft_strlen(to_find);
	while (i < len_str && j != len_tf)
	{
		j = 0;
		while (str[i + j] == to_find[j] && j < len_tf && i + j < len_str)
			j++;
		i++;
	}
	if (j != len_tf)
		return (0x0);
	if (len_tf == 0)
		i++;
	return (&str[--i]);
}
