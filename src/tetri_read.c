/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetri_read.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastro- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 18:09:51 by dcastro-          #+#    #+#             */
/*   Updated: 2017/03/18 21:29:14 by dcastro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"
#include "../libft/libft.h"

/* function here that checks the blocks and counts them. returns 1 if there's
 * 4 and 0 if there isnt
 */
char		**ft_array_to_alpha(char **tetris_array)
{
	int		i;
	int		j;
	char	c;

	c = 65;
	j = 0;
	i = 0;

	while (i < g_num_tetris && tetris_array[i] != '\0' )
	{
		j = 0;
		while (tetris_array[i][j] != '\0')
		{
			if (tetris_array[i][j] == '#')
				tetris_array[i][j] = c;
			j++;
		}
		tetris_array[i][j] = '\0';
		c++;
		i++;
	}
	return (tetris_array);
}
/*function that frees the array of tetris pieces*/
void		ft_tetris_destroy(char **tetris_array)
{
	int	i;

	i = 0;
	while (i < g_num_tetris)
	{
		free(tetris_array[i]);
		i++;
	}
	free(tetris_array);
}

/*function to create the individual array for each tetris piece*/
char		**ft_tetris_create(char **tetris_array, int fd)
{
	char	buff[1];
	int		num_lines;
	int		a;
	int		b;

	a = 0;
	b = 0;
	while (read(fd, buff, 1))
	{
		b = 0;
		num_lines = 0;
		while (num_lines != 4)
		{
			if (*buff == '\n')
				num_lines++;
			tetris_array[a][b] = *buff;
			b++;
			read(fd, buff, 1);
		}
		tetris_array[a][b] = '\0';
		a++;
	}
	return (tetris_array);
}
/* function that reads the file and stores it in an array*/
char		**ft_array_from_file(char *file)
{
	int		fd;
	int		i;
	char	**tetris_array;

	tetris_array = (char **)malloc(sizeof(char*) * g_num_tetris + 1);
	i = 0;
	while (i < g_num_tetris)
	{
		tetris_array[i] = (char*)malloc((sizeof(char) * 21));
		i++;
	}
	fd = open(file, O_RDONLY);
	tetris_array = ft_tetris_create(tetris_array, fd);
	close(fd);
	return (tetris_array);
}
