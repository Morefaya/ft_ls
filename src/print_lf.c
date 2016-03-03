/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_lf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 16:49:47 by jcazako           #+#    #+#             */
/*   Updated: 2016/03/03 14:52:40 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	print_link(char *link)
{
	if (link)
	{
		ft_putstr(" -> ");
		ft_putstr(link);
	}
	ft_putchar('\n');
}

static void	print_time(time_t time)
{
	char	*str;

	if (!(str = get_time(time)))
		return ;
	ft_putendchar(str, ' ');
	free(str);
}

static void	puttime(t_list *lst, t_opt opt)
{
	if (opt.c)
		print_time(((t_ls*)(lst->content))->stime);
	else if (opt.u)
		print_time(((t_ls*)(lst->content))->atime);
	else
		print_time(((t_ls*)(lst->content))->mtime);
}

static void	putlf(t_list *lst, t_max buff, t_opt opt)
{
	ft_putchar(((t_ls*)(lst->content))->type);
	ft_putendchar(((t_ls*)(lst->content))->rights, ' ');
	ft_putstr_right(ft_itoa(((t_ls*)(lst->content))->nb_hlink), buff.mx_hl);
	ft_putchar(' ');
	if (!opt.g)
	{
		ft_putstr_left(((t_ls*)(lst->content))->u_name, buff.mx_un);
		ft_putstr("  ");
	}
	ft_putstr_left(((t_ls*)(lst->content))->g_name, buff.mx_gn);
	ft_putstr("  ");
	ft_putstr_right(ft_itoa(((t_ls*)(lst->content))->size), buff.mx_sz);
	ft_putchar(' ');
	puttime(lst, opt);
	ft_putstr(((t_ls*)(lst->content))->name);
	print_link(((t_ls*)(lst->content))->link);
}

void		print_lf(t_list *lst, t_opt opt)
{
	t_max	buff;

	if (!lst)
		return ;
	fill_tmax(&buff, lst);
	if (opt.lf_dir)
	{
		ft_putstr("total ");
		ft_putnbr(get_nblock(lst));
		ft_putchar('\n');
	}
	while (lst)
	{
		putlf(lst, buff, opt);
		lst = lst->next;
	}
}
