/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonkim <seonkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 16:21:52 by seonkim           #+#    #+#             */
/*   Updated: 2021/03/17 14:20:36 by hyeojung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"
#include <stdio.h>

int main(int argc, char **argv)
{
	int i = -1;
	int j;
	if (argc == 2)
	{
		read_file(argv[1]);
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
	else if (argc == 1)
	{
		read_file(NULL);
	}
	return (0);
}
