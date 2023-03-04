/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   towerdoku.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaint-p <tsaint-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 10:01:59 by tsaint-p          #+#    #+#             */
/*   Updated: 2023/02/19 21:53:55 by tsaint-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOWERDOKU_H
# define TOWERDOKU_H
# include <unistd.h>

char	**init_grid(int size, char *povs);
void	displaygrid(char **grid, int size);
void	fill_grid(char **tab, int i, int j, char *povs);
int		basic_check(char *args);

#endif
