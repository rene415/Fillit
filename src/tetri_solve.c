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
	// printf("y value: %i\n", y);
	// printf("k value: %i\n", k);
//	printf("map before check: \n");
//	print_map(solution_map);
	while (solution_map[i] != '\0')
	{
		j = 0;
		while (solution_map[i][j] != '\0' && count != 4)
		{
			while (solution_map[i][j] >= 'A' && solution_map[i][j] <= 'Z')
				j++;
			if (solution_map[i][j] == '.')
			{
				if ((i == (tstruct->x_value[tstruct->tet_value][h]) + y) && 
					(j == (tstruct->y_value[tstruct->tet_value][h]) + k))
				{
					count++;
					h++;
				}
			}
//			printf("count = %i i = %i, j = %i, x_value[h] = [%i], y_value[h] = [%i]\n", count, i, j, ((tstruct->x_value[tstruct->tet_value][h]) + y), (tstruct->y_value[tstruct->tet_value][h]) + k);
			j++;
		}
		i++;
	}
	return ((count == 4) ? 1 : 0);
}

int		ft_check_placement(char **solution_map, t_tetris *tstruct, int y, int k)
{
	int ret_val;

	ret_val = ft_get_count(tstruct, solution_map, y, k);
	// if (ret_val == 1)
	// 	printf("counting success!\n");
	// else
	// 	printf("fail\n");
	// printf("----------------------\n");
	return ((ret_val == 1) ? 1 : 0);
}

void	ft_place_piece(char **solution_map, t_tetris *tstruct, int y, int k)
{
	int i;
	int j;
	int h;

	i = 0;
	h = 0;
	// printf("entering placement\n");
	// printf("y value in placement: %i\n", y);
	// printf("k value in placement: %i\n", k);
	while (solution_map[i] != '\0')
	{
		j = 0;
		while (solution_map[i][j] != '\0')
		{
			if (solution_map[i][j] == '.')//fucking up here
			{
				if ((i == tstruct->x_value[tstruct->tet_value][h] + y) &&
					(j == tstruct->y_value[tstruct->tet_value][h] + k))
				{
					solution_map[i][j] = tstruct->letter[tstruct->tet_value];
					h++;
				}
			}
			j++;
		}
		i++;
	}
	// print_map(solution_map);
	// printf("----------------\n");
//	printf("not working yet\n");
}

int		ft_solve_tetris(t_tetris *tstruct, char **solution_map, int tet)
{
	int y;
	int k;

	y = 0;
	tstruct->tet_value = tet;
	// printf("tet value: %d\n", tstruct->tet_value);
	if (ft_check_spaces(solution_map))
		return (1);
//	if (tstruct->x_value[tstruct->tet_value][tet] == '\0')
//		return (1);
	while (solution_map[y] != '\0')
	{
		k = 0;
		while (solution_map[y][k] != '\0')
		{
	//		if (((tstruct->height[tet] + y)  > g_map_size) || 
//				((tstruct->width[tet] + k) > g_map_size))
	//			return (0);
			if (ft_check_placement(solution_map, tstruct, y, k))
			{
				ft_place_piece(solution_map, tstruct, y, k);
		//		break;
				if (ft_solve_tetris(tstruct, solution_map, ++tet))
					return (1);
				//ft_remove_tetri(tstruct, solution_map, --tet);
			}
	//		break;
			k++;
			//ft_remove_tetri(solution_map, --tet);
		}
//		break;
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
	// printf("starting solve\n");
	while (!flag)
	{
		g_map_size = map_size() + i;
		solution_map = create_map();
		// printf("g_map_size = %i\n", g_map_size);
		if (ft_solve_tetris(tstruct, solution_map, 0))
		{
			flag = 1;
			// printf("SOLVING success!~\n");
			print_map(solution_map);
		}
//		break;
		free(solution_map);
		i++;
	}
}
