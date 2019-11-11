/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdirect <mdirect@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 13:10:30 by mdirect           #+#    #+#             */
/*   Updated: 2019/11/11 18:08:27 by mdirect          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "fillit.h"

/* We shorted code, but now it works correctly only with maps 5x5
 * i don't know, how to change this*/

void	ft_print_bit(uint64_t n, int y)
{
	int i;
	int tmp;

	i = y * (y + 1);
	while ((n & (1 << i)) == 0)
		i--;
	tmp = i;
	while (i > 0) {
		if ((n & (1 << i)) == 0)
			write(1, ".", 1);
		else if ((n & (1 << i)) != 0)
		{
			ft_putchar('#');
		}
		if ((i - 1) % y == 0)
			write(1, "\n", 1);
		i--;
	}
	i = tmp;
	while (i < (y * y + y))
	{
		write(1, ".", 1);
		i++;
//		if (i % y == 0)
//			write(1, "\n", 1);
	}
	write(1, "\n", 1);
}