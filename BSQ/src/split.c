/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaint-p <tsaint-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 14:48:12 by tsaint-p          #+#    #+#             */
/*   Updated: 2023/03/01 22:33:08 by tsaint-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../includes/header.h"

int	count_words(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == '\n' && str[i])
			i++;
		if (str[i])
			count++;
		while (!(str[i] == '\n') && str[i])
			i++;
	}
	return (count);
}

int	len_word(char *beg_word)
{
	int	i;

	i = 0;
	while (!(beg_word[i] == '\n') && beg_word[i])
		i++;
	return (i);
}

char	*fill_word(char *beg_word)
{
	int		len_wrd;
	int		i;
	char	*word;

	i = 0;
	len_wrd = len_word(beg_word);
	word = malloc(sizeof(char) * (len_wrd + 1));
	init_str(word, len_wrd + 1);
	if (!word)
		return (NULL);
	while (beg_word[i] && i < len_wrd)
	{
		word[i] = beg_word[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split(char *str, char **splited_tab)
{
	int		i;
	int		cpt;

	i = 0;
	cpt = 0;
	if (!splited_tab || !str)
		return (NULL);
	while (str[i])
	{
		if (str[i] == '\n' && str[i])
			i++;
		if (str[i])
			splited_tab[cpt++] = fill_word(&(str[i]));
		if (!splited_tab[cpt - 1])
			return (NULL);
		while (!(str[i] == '\n') && str[i])
			i++;
	}
	splited_tab[cpt] = NULL;
	return (splited_tab);
}
