/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetri_chk.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastro- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 15:24:45 by dcastro-          #+#    #+#             */
/*   Updated: 2017/04/07 18:57:34 by dcastro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"
#include "../libft/libft.h"

int		ft_check_read(int fd)
{
	char buff[21];
	int curr;
	int last;

	while ((curr = read(fd, buff, 21)))
	{
		buff[curr] = '\0';
		last = curr;
	}
	return ((last == 20) ? TRUE : FALSE);
}
