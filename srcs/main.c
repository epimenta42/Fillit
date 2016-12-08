/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epimenta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 17:50:36 by epimenta          #+#    #+#             */
/*   Updated: 2016/12/07 00:01:20 by epimenta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int argc, char **argv)
{
	char		*str;
	t_tetris	*list;
	t_map		*map;
	t_tetris	*s_list;

	if (argc == 2)
	{
		str = ft_open_file(argv);
		list = ft_init_tetris(str);
		ft_check_form(list);
		ft_check_motif(list);
		s_list = ft_define_list();
		ft_cut_motif_iter(list, &s_list);
		ft_init_h_w_motif(s_list);
		ft_list_letter(s_list);
		map = ft_resolve(s_list);
		ft_print_table(map);
		ft_dellist(&s_list);
		ft_delmap(&map);
		free(str);
		str = NULL;
	}
	else
		ft_putendl("usage: ./fillit use only one parameter");
	return (0);
}
