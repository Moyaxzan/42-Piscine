/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_memory.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taospa <taospa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 19:25:47 by tsaint-p          #+#    #+#             */
/*   Updated: 2023/03/04 14:31:38 by taospa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	base16[] = "0123456789abcdef";

int	is_printable(char c)
{
	if (c > 126 || c < 32)
		return (0);
	return (1);
}

void print_hex_addr(unsigned long add_int)
{
	char addr[17];
	int	i = 0;

	while (i < 16)
	{
		addr[i] = base16[add_int % 16];
		add_int = add_int / 16;
		i++;
	}
	while (--i)
	{
		write(1, &addr[i], 1);
	}
	write(1, ": ", 2);
}

#include <stdio.h>
void	print_hex_char(unsigned char *addr)
{
	int	i = 0;
	
	while (i < 16)
	{
		write(1, &(base16[addr[i] / 16]), 1);
		write(1, &base16[addr[i] % 16], 1);
		if (i % 2)
			write(1, " ", 1);
		i++;
	}
}

void	print_chars(unsigned char *addr)
{
	int	i = 0;

	while (i < 16)
	{
		if (is_printable(addr[i]))
			write(1, &addr[i], 1);
		else
			write(1, ".", 1);
		i++;
	}
}

void	print_memory(void *addr, unsigned int size)
{
	unsigned long	add_int = (unsigned long) addr;
	int				nb_lines;
	int				line;

	line = 0;
	nb_lines = 0;
	if (size < 16)
		nb_lines = 1;
	nb_lines += size / 16;
	while (line < nb_lines)
	{
		print_hex_addr(add_int + 16 * line);
		print_hex_char(addr + 16 * line);
		print_chars(addr + 16 * line);
		write(1, "\n", 1);
		line++;
	}	
}

int main(void)
{
	char	str[] = "oui je suis la hihihihi ^^";

	print_memory(str, 400);
	return (0);
}