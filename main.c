/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonkim <seonkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 16:21:52 by seonkim           #+#    #+#             */
/*   Updated: 2021/03/17 16:18:25 by hyeojung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"
#include <stdio.h>

void	process(void)
{
	int	i;
	int	j;

	i = g_max_row + 1;
	while (--i > g_max_row - g_max)
	{
		j = g_max_col + 1;
		while (--j > g_max_col - g_max)
			g_board[i][j] = g_fill;
	}
}

int 	main(int argc, char **argv)
{
	int	i;
	int	j;

	i = -1;
	if (argc < 3)
	{
		if (argc == 2)
			read_file(argv[1]);
		else
			read_file(NULL);
		dp();
		process();
		while (++i < g_row_size)
		{
			j = -1;
			while (++j < g_col_size)
				printf("%c ", g_board[i][j]);
			printf("\n");
		}
	}
	return (0);
}
