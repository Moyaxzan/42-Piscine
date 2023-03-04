/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jump.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaint-p <tsaint-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 14:48:22 by tsaint-p          #+#    #+#             */
/*   Updated: 2023/02/19 17:50:26 by tsaint-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef JUMP_H
# define JUMP_H
# include <unistd.h>

int		jump_col_down(int col, char **tab, int size);
int		jump_col_up(int col, char **tab, int size);
int		jump_row_right(int row, char **tab, int size);
int		jump_row_left(int row, char **tab, int size);

#endif
