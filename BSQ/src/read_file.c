/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaint-p <tsaint-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 14:37:25 by elrichar          #+#    #+#             */
/*   Updated: 2023/03/01 20:14:25 by tsaint-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_get_map(char *path)
{
	char	*buffer;
	int		fd;
	int		i;
	char	tmp;

	i = 1;
	fd = open(path, O_RDONLY);
	if (fd == (-1))
		return (NULL);
	while (read(fd, &tmp, 1))
		i++;
	buffer = malloc(sizeof(char) * i);
	close(fd);
	if (buffer == NULL)
		return (NULL);
	fd = open(path, O_RDONLY);
	if (fd == (-1))
		return (NULL);
	i = 0;
	while (read(fd, &(buffer[i]), 1))
		i++;
	buffer[i] = '\0';
	close(fd);
	return (buffer);
}
