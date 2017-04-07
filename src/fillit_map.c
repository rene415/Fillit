/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastro- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 17:58:59 by dcastro-          #+#    #+#             */
/*   Updated: 2017/03/18 19:12:39 by dcastro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"
#include "../libft/libft.h"

int			map_size(void)
{
	int 	a;
	int		pieces;

	a = 2;
	pieces = (g_num_tetris * 4);
	while ((a * a) - pieces < 0)
		a++;
	return (a);
}

char		**create_map(void)
{
	char	**new_map;
	int		i;
	int		j;

	i = 0;
	j = 0;
	new_map = (char**)malloc(sizeof(char*) * (g_map_size + 1));
	while (i < g_map_size)
	{
		j = 0;
		while (j < g_map_size)
		{
			new_map[j] = ft_strnew((size_t)g_map_size);
			new_map[i][j] = '.';
			j++;
		}
		new_map[i][j] = '\0';
		i++;
	}
	new_map[i] = 0;
	return (new_map);
}

void	print_map(char **new_map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (new_map[i] != '\0')
	{
		j = 0;
		while (new_map[j] != '\0')
		{
			if (j != 0 && j == g_map_size)
				ft_putchar('\n');
			else
				ft_putchar(new_map[i][j]);
			j++;
		}
		i++;
	}
	ft_putchar('\n');
}
