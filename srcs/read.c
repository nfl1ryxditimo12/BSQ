/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonkim <seonkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 15:43:33 by seonkim           #+#    #+#             */
/*   Updated: 2021/03/17 03:34:48 by seonkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

char	**g_board;
int	g_row_size;
int	g_col_size;
char	g_blank;
char	g_obstacle;
char	g_fill;

char	*get_value(int fd, char *c, int *i)
{
	char	*str;

	if (!(str = malloc(1025)))
		exit(1);
	while (c[0] != '\n')
	{
		str[*i] = c[0];
		read(fd, c, 1);
		(*i)++;
	}
	if (c[0] == '\n')
		read(fd, c, 1);
	return (str);
}

int	make_condition(int fd)
{
	char	*cond;
	char	*tmp;
	char	c[1];
	int	i;
	int	j;

	i = -1;
	j = -1;
	tmp = get_value(fd, c, &i);
	cond = ft_strdup(tmp);
	free(tmp);
	g_fill = cond[i - 1];
	g_obstacle = cond[i - 2];
	g_blank = cond[i - 3];
	g_row_size = 0;
	while (++j < i - 3)
		if ('0' <= cond[j] && cond[j] <= '9')
			g_row_size = g_row_size * 10 + cond[j] - '0';
		else
		{
			print_error(COND_ERR);
			exit(1);
		}
	free(cond);
	return (1);
}

void	fill_board(int fd)
{
	char	*tmp;
	char	c[1];
	int	len;
	int	i;

	if (!(g_board = (char **)malloc(sizeof(char *) * (g_row_size + 1))))
		return ;
	i = -1;
	while (++i < g_row_size)
	{
		len = -1;
		tmp = get_value(fd, c, &len);
		g_col_size = len;
		g_board[i] = ft_strdup(tmp);
		free(tmp);
	}
	board_check();
}

void	read_file(char *file)
{
	int	fd;
	fd = open(file, O_RDONLY);
	if (fd == -1)
		print_error("Can not open file");
	make_condition(fd);
	fill_board(fd);
	board_valid();
	close(fd);
}
