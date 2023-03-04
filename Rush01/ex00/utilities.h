/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaint-p <tsaint-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 15:10:20 by tsaint-p          #+#    #+#             */
/*   Updated: 2023/02/19 14:49:45 by tsaint-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILITIES_H
# define UTILITIES_H
# include <unistd.h>

int		absolute(int nb);
int		not_in_col(char value, char **tab, int index_col, int size);
int		not_in_row(char value, char **tab, int index_row, int size);

#endif