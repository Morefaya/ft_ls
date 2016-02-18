/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 15:49:40 by jcazako           #+#    #+#             */
/*   Updated: 2016/02/18 16:45:42 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int	main(int ac, char **av)
{
	t_list	*lst;

	if (ac != 2)
	{
		ft_putendl("too much arg");
		return (1);
	}
	if (!(lst = get_data(av[1])))
	{
		ft_putendl("error get_data");
		return (1);
	}
	print_lf(lst);
	return (0);
}
