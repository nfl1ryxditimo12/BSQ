/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonkim <seonkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 04:06:49 by seonkim           #+#    #+#             */
/*   Updated: 2021/03/17 04:20:48 by seonkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	process(void)
{
	int i;
	int j;

	i = g_max_row + 1;
	while (--i > g_max_row - g_max)
	{
		j = g_max_col + 1;
		while (--j > g_max_col - g_max)
			g_board[i][j] = g_fill;
	}
}
