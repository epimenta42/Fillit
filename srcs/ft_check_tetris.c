/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_tetris.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epimenta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 17:48:55 by epimenta          #+#    #+#             */
/*   Updated: 2016/12/06 17:49:01 by epimenta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_error(void)
{
	ft_putendl("error");
	exit(EXIT_FAILURE);
}

void	ft_check_form(t_tetris *list)
{
	int		i;
	int		j;
	int		k;

	while (list != NULL)
	{
		i = 0;
		k = 0;
		while (list->tetris[i] != NULL)
		{
			j = 0;
			while (list->tetris[i][j] != '\0')
			{
				if (list->tetris[i][j] != '.' && list->tetris[i][j] != '#')
					ft_error();
				if (list->tetris[i][j] == '#')
					k++;
				j++;
			}
			i++;
		}
		list = list->next;
		if (k != 4)
			ft_error();
	}
}

void	ft_check_motif(t_tetris *list)
{
	char	**motif;

	while (list != NULL)
	{
		motif = list->tetris;
		if (motif != NULL)
			if (!(ft_motif_sf(motif)))
				if (!(ft_motif(motif)))
					ft_error();
		list = list->next;
	}
}

char	**ft_param(char **motif, int *i, int *j)
{
	if (!motif)
		ft_error();
	*i = 0;
	while (motif[*i] != NULL)
	{
		*j = 0;
		while (motif[*i][*j] != '\0')
		{
			if (motif[*i][*j] == '#')
			{
				return (motif);
			}
			*j += 1;
		}
		*i += 1;
	}
	return (NULL);
}
