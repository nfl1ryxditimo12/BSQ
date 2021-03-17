/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exception.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonkim <seonkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 17:31:50 by seonkim           #+#    #+#             */
/*   Updated: 2021/03/17 12:46:06 by seonkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

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

void	board_valid(void)
{
	int	i;
	int	j;
	char	c;

	i = -1;
	while (++i < g_row_size)
	{
		j = -1;
		while (++j < g_col_size)
		{
			c = g_board[i][j];
			if (!(c == g_obstacle || c == g_blank))
			{
				print_error(BOARD_ERR);
				exit(1);
			}
		}
	}
}
