/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_lf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 16:49:47 by jcazako           #+#    #+#             */
/*   Updated: 2016/02/19 18:25:35 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	print_link(char *link)
{
	if (link)
	{
		ft_putstr(" -> ");
		ft_putstr(link);
	}
	ft_putchar('\n');
}

void	print_lf(t_list *lst)
{
	t_max	buff;

	fill_tmax(&buff, lst);
	ft_putstr("total ");
	ft_putnbr(get_nblock(lst));
	ft_putchar('\n');
	while (lst)
	{
		ft_putchar(((t_ls*)(lst->content))->type);
		ft_putendchar(((t_ls*)(lst->content))->rights, ' ');
		ft_putstr_right(ft_itoa(((t_ls*)(lst->content))->nb_hlink), buff.mx_hl);
		ft_putchar(' ');
		ft_putstr_left(((t_ls*)(lst->content))->u_name, buff.mx_un);
		ft_putchar(' ');
		ft_putstr_left(((t_ls*)(lst->content))->g_name, buff.mx_gn);
		ft_putchar(' ');
		ft_putstr_right(ft_itoa(((t_ls*)(lst->content))->size), buff.mx_sz);
		ft_putchar(' ');
		ft_putendchar(((t_ls*)(lst->content))->time, ' ');
		ft_putchar(' ');
		ft_putstr(((t_ls*)(lst->content))->name);
		print_link(((t_ls*)(lst->content))->link);
		lst = lst->next;
	}
}
