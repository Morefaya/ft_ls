/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/27 15:53:57 by jcazako           #+#    #+#             */
/*   Updated: 2016/02/29 21:21:38 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void 		print_one(t_list *lst, t_opt opt)
{
	while (lst && opt.one)
		ft_putendl(((t_ls*)(lst->content))->name);
}

static void	(*select_print(t_opt opt))(t_list*, t_opt)
{
	if (opt.l || opt.g)
		return (print_lf);
	else if (opt.one)
		return (print_one);
	else
		return (print_ls);
}

void		print(t_list *lst, t_opt opt)
{
	void	(*f_print)(t_list*, t_opt);

	f_print = select_print(opt);
	f_print(lst, opt);
}
