/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaint-p <tsaint-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 14:58:15 by tsaint-p          #+#    #+#             */
/*   Updated: 2023/02/19 20:54:01 by tsaint-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLVE_H
# define SOLVE_H
# include <unistd.h>
# include "utilities.h"

int		write_4(int row, int col, char **tab, int size);
int		simple_cases(char **tab, int size);
int		backtrack(char **tab, int pos, int size);

#endif