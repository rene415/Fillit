/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastro- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/14 16:53:02 by dcastro-          #+#    #+#             */
/*   Updated: 2017/03/18 18:47:25 by dcastro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <sys/uio.h>
# include <stdio.h>

# define CHK_BLOCK(x)			((x == '#') ? 1 : 0)
# define TRUE					1
# define FALSE					0

int						g_num_tetris;
int						g_map_size;

typedef struct			s_tetris
{
	int					**x_value;
	int					**y_value;
	int					*height;
	int					*width;
	char				*letter;
	int					tet_value;
}						t_tetris;

int						ft_check_read(int fd);

void					ft_ydist(char **map, t_tetris *tstruct, int col);
void					ft_xdist(char **map, t_tetris *tstruct, int col);
void					ft_get_dim(t_tetris *tstruct, int col);
t_tetris				*ft_tet_distance(char **tet_cpy, t_tetris *tstruct);
t_tetris				*ft_create_struct(void);

int						ft_file_read(int fd);
int						ft_block_chk(char **tet_arr);

int						map_size(void);
void					free_map(char **new_map);
char					**create_map(void);
void					print_map(char **new_map);

char					**ft_array_to_alpha(char **tetris_array);
void					ft_tetris_destroy(char **tetris_array);
char					**ft_tetris_create(char **tetris_array, int fd);
char					**ft_array_from_file(char *file);
int						*ft_make_indx_arr(char *tet_array);

void					ft_solve(char **tetris_array);
void					ft_place_piece(char **solution_map, t_tetris *tstruct, int y, int k);
int						ft_check_placement(char **solution_map, t_tetris *tstruct, int y, int k);
int						ft_solve_tetris(t_tetris *tstruct, char **solution_map, int tet);
int						ft_get_count(t_tetris *tstruct, char **solution_map, int y, int k);
int						ft_check_spaces(char **solution_map);
void					ft_remove_tetris(t_tetris *t_struct, char **solution_map);
#endif
