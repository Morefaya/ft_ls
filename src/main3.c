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
	int	index;
	t_list	*lst_f;
	t_list	*lst_d;
	p_sort	pt_arg;

	lst_f = NULL;
	lst_d = NULL;
	index = check_opt(ac, av, &opt);
	if (index == ac)
		ft_ls(".", opt);
	else
	{
		split_arg(&lst_f, &lst_d, av + index, ac - index);
		pt_arg = select_sort(opt);
		sort(&lst_f, pt_arg, opt);
		sort(&lst_d, pt_arg, opt);
		print(lst_f, opt);
		if (lst_f && lst_d)
			ft_putchar('\n');
		opt.lf_dir = 1;
		while (lst_d)
		{
			if (ac - index > 1)
			{
				ft_putendchar(((t_ls*)(lst_d->content))->name, ':');
				ft_putchar('\n');
			}
			ft_ls(((t_ls*)(lst_d->content))->name, opt);
			lst_d = lst_d->next;
			if (lst_d)
				ft_putchar('\n');
		}
	}
	return (0);
}
