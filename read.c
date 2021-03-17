/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonkim <seonkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 15:43:33 by seonkim           #+#    #+#             */
/*   Updated: 2021/03/18 00:08:19 by hyeojung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"
#include <stdio.h>

# define BUFFER_SIZE 1000000

char	**g_board;
int		g_row_size;
int		g_col_size;
char	g_blank;
char	g_obstacle;
char	g_fill;

char	*ft_bufcpy(char *dest, char *src, int n)
{
	char *d;

	d = dest;
	while (n--)
		*d++ = *src++;
	return (dest);
}

char	*get_value(int fd)
{
	char	buf[BUFFER_SIZE];
	char	*content;
	char	*tmp;
	int		len;
	int		size;

	if (!(content = malloc(sizeof(char))))
		return (NULL);
	*content = '\0';
	size = 0;
	while ((len = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		if (!(tmp = malloc((size + len + 1) * sizeof(char))))
			break ;
		tmp = ft_bufcpy(tmp, content, size);
		free(content);
		ft_bufcpy(tmp + size, buf, len);
		content = tmp;
		size += len;
		content[size] = '\0';
	}
	if (len)
		free(content);
	return ((len) ? NULL : content);
}

int		ft_atoi(char *str, int i)
{
	int	j;
	int	ret;

	j = -1;
	ret = 0;
	while (++j < i)
	{
		ret *= 10;
		ret += *str - '0';
	}
	return (ret);
}

char	*make_condition(char *cond)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = cond;
	while (!is_newline(*cond))
	{
		i++;
		cond++;
	}
	g_row_size = ft_atoi(tmp, i - 3);
	g_fill = *(cond - 1);
	g_obstacle = *(cond - 2);
	g_blank = *(cond - 3);
	printf("%d, %c, %c, %c\n", g_row_size, g_blank, g_obstacle, g_fill);
	cond++;
	return (cond);
}

void	read_file(char *file)
{
	int		fd;

	if (*file)
		fd = open(file, O_RDONLY);
	else
		fd = 0;
	if (fd == -1)
		print_error("Cannot open file\n");
	g_board = ft_split(make_condition(get_value(fd)));
	for (int i = 0; g_board[i]; i++)
	{
		for (int j = 0; g_board[i][j]; j++)
			printf("%c", g_board[i][j]);
		printf("\n");
	}
	board_valid();
	if (*file)
		close(fd);
}
