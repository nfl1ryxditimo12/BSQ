/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonkim <seonkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 13:55:40 by seonkim           #+#    #+#             */
/*   Updated: 2021/03/17 17:39:57 by hyeojung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"
#include <stdio.h>

void	g_arr_free(void)
{
	int i;

	i = 0;
	while (i < g_row_size + 1)
		free(g_board[i++]);
	free(g_board);
	i = 0;
	while (i < g_row_size)
		free(g_tab[i++]);
	free(g_tab);
}

void	print_error(char *error)
{
	while (*error)
		write(2, error++, 1);
	write(1, "\n", 1);
	exit(1);
}

int    board_valid(void)
{
	printf("board_valid\n");
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
