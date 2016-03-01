/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/27 13:29:48 by jcazako           #+#    #+#             */
/*   Updated: 2016/02/29 23:14:09 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		main(int ac, char **av)
{
	t_opt	opt;
	int		index;

	index = check_opt(ac, av, &opt);
	if (index == ac)
		ft_ls(".", opt);
	while (index < ac)
	{
		ft_putendchar(av[index], ':');
		ft_putchar('\n');
		ft_ls(av[index], opt);
		index++;
		if (index != ac)
			ft_putchar('\n');
	}
	return (0);
}
