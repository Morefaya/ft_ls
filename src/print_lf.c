/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_lf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 16:49:47 by jcazako           #+#    #+#             */
/*   Updated: 2016/02/18 22:04:30 by jcazako          ###   ########.fr       */
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
	while (lst)
	{
		ft_putchar(((t_ls*)(lst->content))->type);
		ft_putstr(((t_ls*)(lst->content))->rights);
		ft_putchar(' ');
		ft_putstr_right(ft_itoa(((t_ls*)(lst->content))->nb_hlink), 8);
		ft_putchar(' ');
		ft_putstr(((t_ls*)(lst->content))->time);
		ft_putchar(' ');
		ft_putstr(((t_ls*)(lst->content))->name);
		print_link(((t_ls*)(lst->content))->link);
		lst = lst->next;
	}
}
