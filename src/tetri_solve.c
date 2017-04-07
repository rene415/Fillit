/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetris_solve.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rramirez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 14:54:45 by rramirez          #+#    #+#             */
/*   Updated: 2017/03/20 23:07:03 by rramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"
#include "../libft/libft.h"

int		ft_get_count(t_tetris *tstruct, char **solution_map, int y, int k)
{
	int	count;
	int i;
	int j;
	int h;

	count = 0;
	i = 0;
	h = 0;
	while (solution_map[i] != '\0')
	{
		j = 0;
		while (solution_map[i][j] != '\0')
		{
			if (solution_map[i][j] == '.') //fucking up here
			{
				if ((i == tstruct->x_value[tstruct->tet][h] + y) && 
					(j == tstruct->y_value[tstruct->tet][h] + k))
					count++;
			}
			j++;
			h++;
		}
		i++;
	}
	return ((count == 4) ? 1 : 0);
}

int		ft_check_placement(char **solution_map, t_tetris *tstruct, int y, int k)
{
	int count;

	count = ft_get_count(tstruct, solution_map, y, k);
//	printf("return value: %d\n", count);
	return ((count == 1) ? 1 : 0);
}

void	ft_place_piece(char **solution_map, t_tetris *tstruct, int y, int k)
{
//	tet = 0;
//	int i = 0;
//	tstruct->x_value[tet][i] = solution_map[tet][i];
//	printf("%c\n", solution_map[tet][i]);
	printf("not working yet\n");

}

int		ft_solve_tetris(t_tetris *tstruct, char **solution_map, int tet)
{
	int y;
	int k;

	y = 0;
//	printf("begin solve recursion\n");
	tstruct->tet = tet;
	while (solution_map[y] != '\0')
	{
		k = 0;
		while (solution_map[y][k] != '\0')
		{
	//		if (((tstruct->height[tet] + y)  > g_map_size) || 
//				((tstruct->width[tet] + k) > g_map_size))
	//			return (0);
	//		printf("tet value: %d\n", tet);
			if (ft_check_placement(solution_map, tstruct, y, k))
			{
				ft_place_piece(solution_map, tstruct, y, k);
				if (ft_solve_tetris(tstruct, solution_map, ++tet))
					return (1);
			}
			k++;
			//ft_remove_tetri(solution_map, --tet);
		}
		y++;
	}
	return(0);
}

void	ft_solve(char **tetris_array)
{
	int		flag;
	char	**solution_map;
	char	**tet_cpy;
	int		i;
	t_tetris *tstruct;
	
	flag = 0;
	tet_cpy = ft_array_to_alpha(tetris_array);
	tstruct = ft_create_struct();
	tstruct = ft_tet_distance(tet_cpy, tstruct);
	i = 0;
	printf("starting solve\n");
	while (!flag)
	{
		g_map_size = map_size() + i;
		solution_map = create_map();
		if (ft_solve_tetris(tstruct, solution_map, 0))
		{
			flag = 1;
			print_map(solution_map);
		}
//		free_map(solution_map);
		i++;
	}
}
