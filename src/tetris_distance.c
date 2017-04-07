/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetri_distance.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rramirez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 19:25:23 by rramirez          #+#    #+#             */
/*   Updated: 2017/03/20 19:30:31 by rramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../includes/fillit.h"

void		ft_ydist(char **map, t_tetris *tstruct, int col)
{
	int	i;
	int	j;
	int	k;
	int	fp;

	i = 0;
	k = 0;
	while (map[i] != '\0')
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (map[i][j] != '.')
			{
				fp = j;
				tstruct->y_value[col][k++] = 0;
			}
			if (k != 0 && map[i][j] != '.')
				tstruct->y_value[col][k++] = j - fp;
			j++;
		}
		i++;
	}
	tstruct->y_value[col][4] = '\0';
}

void		ft_xdist(char **map, t_tetris *tstruct, int col)
{
	int	i;
	int	j;
	int	k;
	int	fp;

	i = 0;
	k = 0;
	while (map[i] != '\0')
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (map[i][j] != '.')
			{
				fp = i;
				tstruct->x_value[col][k++] = 0;
			}
			if (k != 0 && map[i][j] != '.')
				tstruct->x_value[col][k++] = i - fp;
			j++;
		}
		i++;
	}
	tstruct->x_value[col][4] = '\0';
}

void				ft_get_dim(t_tetris *tstruct, int col)
{
	int x;
	int	y;

	x = 0;
	tstruct->height[col] = 0;
	while (tstruct->x_value[col][x] != '\0')
	{
		if (tstruct->height[col] < tstruct->x_value[col][x])
			tstruct->height[col] = tstruct->x_value[col][x];
		x++;
	}
	y = 0;
	tstruct->width[col] = 0;
	while (tstruct->y_value[col][y] != '\0')
	{
		if (tstruct->width[col] < tstruct->y_value[col][y])
			tstruct->width[col] = tstruct->y_value[col][y]];
		y++;
	}
	tstruct->letter[col] = 'A' + col;
}

t_tetris			*ft_tet_distance(char **tet_cpy, t_tetris *tstruct)
{
	int	col;
	char 		**map;

	col = 0;
	while (col < g_num_tetris)
	{
		map = ft_strsplit(tet_cpy[col], '\n');
		ft_ydist(map, tstruct, col);
		ft_xdist(map, tstruct, col);
		ft_get_dim(tstruct, col);
		free(map);
		col++;
	}
}

t_tetris            *ft_create_struct(void)
{
	t_tetris *new_struct;
	int k;

	k = 0;
	if (!(new_struct = (t_tetris)malloc(sizeof(t_tetris))))
		return (0);
	if (!(new_struct->x_value = (int**)malloc(sizeof(int*) * g_num_tetris + 1)))
		return (0);
	if (!(new_struct->y_value = (int**)malloc(sizeof(int*) * g_num_tetris + 1)))
		return (0);
	while (k < g_num_tetris)
	{
		new_struct->x_value[k] = (int)malloc(sizeof(int) * 5);
		k++;
	}
	k = 0;
	while (k < g_num_tetris)
	{
		new_struct->y_value[k] = (int)malloc(sizeof(int) * 5);
		k++;
	}
	new_struct->height = (int)malloc(sizeof(int) * g_num_tetris + 1);
	new_struct->width = (int)malloc(sizeof(int) * g_num_tetris + 1);
	return (new_struct);
}









