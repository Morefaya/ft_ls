/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/27 13:44:54 by jcazako           #+#    #+#             */
/*   Updated: 2016/02/29 23:12:55 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

p_sort		select_sort(t_opt opt)
{
	if (opt.u)
		return ((p_sort)atime_cmp);
	else if (opt.c)
		return ((p_sort)stime_cmp);
	else if (opt.t)
		return ((p_sort)mtime_cmp);
	else
		return ((p_sort)ascii_cmp);
}

static void	recursive(t_list *lst, char *dir_name, t_opt opt)
{
	char	*path;

	while (lst)
	{
		if (!(path = path_builder(dir_name,
			((t_ls*)(lst->content))->name)))
			return;
		if (((t_ls*)(lst->content))->type == 'd')
		{
			ft_putchar('\n');
			ft_putendchar(path, ':');
			ft_putchar('\n');
			ft_ls(path, opt);
		}
		free(path);
		lst = lst->next;
	}
}

int			ft_ls(char *dir_name, t_opt opt)
{
	t_list	*lst;
	p_sort	f_sort;

	if (!(lst = get_data(dir_name, opt)))
	{
		ft_putendl("error get_data");
		return (1);
	}
	f_sort = select_sort(opt);
	sort(&lst, (p_sort)f_sort, opt);
	print(lst, opt);
	if (opt.R)
	{
		recursive(lst, dir_name, opt);
	}
	ft_lstdel(&lst, (void(*)(void*, size_t))free_content);
	return (0);
}
