/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 15:49:40 by jcazako           #+#    #+#             */
/*   Updated: 2016/02/25 21:47:48 by jcazako          ###   ########.fr       */
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
	sort(&lst, (int (*)(void*, void*))ft_strcmp);
	rev_list(&lst);
	print_ls(lst);
	return (0);
}
