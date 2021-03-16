/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dp.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeojung <hyeojung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 17:19:44 by hyeojung          #+#    #+#             */
/*   Updated: 2021/03/15 17:29:51 by hyeojung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int		**g_int_board;

int		min(int x, int y)
{
	return (x < y ? x : y);
}

void	fill_int_board(void)
{
	int		max;
	int		i;
	int		j;

	max = 0;
	i = -1;
	g_int_board = (int**)malloc(sizeof(int*) * g_row_size);
	while (++i < g_row_size)
	{
		j = -1;
		while (++j < g_col_size)
		{
			if (j == 0)
				g_int_board[i] = (int*)malloc(sizeof(int) * g_col_size);
			if (g_board[i][j] == g_blank)
				g_int_board[i][j] = min(min(g_int_board[i][j - 1], g_int_board[i - 1][j - 1]), g_board[i - 1][j]) + 1;
			max = (max < g_int_board[i][j]) ? g_int_board[i][j] : max;
		}
	}
}
