/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaint-p <tsaint-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 19:48:49 by tsaint-p          #+#    #+#             */
/*   Updated: 2023/02/27 10:38:37 by tsaint-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	is_separator(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (charset[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	count_words(char *str, char *charset)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (is_separator(str[i], charset) && str[i])
			i++;
		if (str[i])
			count++;
		while (!is_separator(str[i], charset) && str[i])
			i++;
	}
	return (count);
}

int	len_word(char *beg_word, char *charset)
{
	int	i;

	i = 0;
	while (!is_separator(beg_word[i], charset) && beg_word[i])
		i++;
	return (i);
}

char	*fill_word(char *beg_word, char *charset)
{
	int		len_wrd;
	int		i;
	char	*word;

	i = 0;
	len_wrd = len_word(beg_word, charset);
	word = malloc(sizeof(char) * len_wrd + 1);
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

char	**ft_split(char *str, char *charset)
{
	int		i;
	int		cpt;
	char	**splited_tab;

	i = 0;
	cpt = 0;
	splited_tab = malloc(sizeof(char *) * (count_words(str, charset) + 1));
	if (!splited_tab)
		return (NULL);
	while (str[i])
	{
		while (is_separator(str[i], charset) && str[i])
			i++;
		if (str[i])
			splited_tab[cpt++] = fill_word(&(str[i]), charset);
		if (!splited_tab[cpt - 1])
			return (NULL);
		while (!is_separator(str[i], charset) && str[i])
			i++;
	}
	splited_tab[cpt] = NULL;
	return (splited_tab);
}
/*
#include <stdio.h>
void    displaytab(char **tab)
{
    int    i;

    i = 0;
    while (tab[i])
    {
        printf("\n|%s|\n", tab[i]);
        i++;
    }
}

int    main(int ac, char **av)
{
	(void)ac;
    char    **tab;
    tab = ft_split(av[1], av[2]);
    displaytab(tab);
}*/
