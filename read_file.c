/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeojung <hyeojung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 17:53:56 by hyeojung          #+#    #+#             */
/*   Updated: 2021/03/17 18:01:18 by hyeojung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

char	**g_board;
int		g_row_size;
int		g_col_size;
char	g_blank;
char	g_obstacle;
char	g_fill;

char	*ft_strdup(char *str)
{
	char	*dest;
	int		i;
	
	i = 0;
	while (str[i])
		i++;
	dest = (char *)malloc(i + 1);
	i = -1;
	while (str[++i])
		dest[i] = str[i];
	dest[i] = 0;
	return (dest);
}

char	*get_value(int fd, char *c, int *i)
{
	char	*str;


}
