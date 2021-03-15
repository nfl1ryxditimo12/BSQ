/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dp.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonkim <seonkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 16:34:41 by seonkim           #+#    #+#             */
/*   Updated: 2021/03/15 17:07:35 by seonkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	min(int x, int y)
{
	return (x < y ? x : y);
}

void	process(void)
{
	int max;
	int i;
	int j;

	max = 0;
	i = -1;
	while (++i < g_row_size)
	{
		j = -1;
		while (++j < g_col_size)
		{
			if (g_board[i][j] == g_obstacle)
				continue ;
			g_board[i][j] = min(min(g_board[i][j - 1], g_board[i - 1][j - 1]), g_board[i - 1][j]) + 1;
			if (max < g_board[i][j])
				max = g_board[i][j];
		}
	}
}
