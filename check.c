/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonkim <seonkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 13:55:40 by seonkim           #+#    #+#             */
/*   Updated: 2021/03/17 15:29:47 by hyeojung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	print_error(char *error)
{
	while (*error)
		write(2, error++, 1);
	write(1, "\n", 1);
	exit(1);
}

int    board_valid(void)
{
    int     i;
    int     j;
    char    c;

    i = -1;
    while (++i < g_row_size)
    {
		j = -1;
	    while (++j < g_col_size)
	    {
	        c = g_board[i][j];
			if (!(c == g_obstacle || c == g_blank))
				print_error(BOARD_ERR);
		}
		if (j != g_col_size)
			print_error(BOARD_ERR);
	}
	return (1);
}
