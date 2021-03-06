/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/27 13:44:54 by jcazako           #+#    #+#             */
/*   Updated: 2016/03/03 17:49:40 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_sort		select_sort(t_opt opt)
{
	if (opt.u && opt.t)
		return ((t_sort)atime_cmp);
	else if (opt.c && opt.t)
		return ((t_sort)stime_cmp);
	else if (opt.t)
		return ((t_sort)mtime_cmp);
	else
		return ((t_sort)ascii_cmp);
}

static void	recursive(t_list *lst, char *dir_name, t_opt opt)
{
	char	*path;

	while (lst)
	{
		if (!(path = path_builder(dir_name,
			((t_ls*)(lst->content))->name)))
			return ;
		if (((t_ls*)(lst->content))->type == 'd'
			&& ft_strcmp(((t_ls*)(lst->content))->name, ".")
			&& ft_strcmp(((t_ls*)(lst->content))->name, ".."))
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
	t_list		*lst;
	t_sort		f_sort;

	if (!(lst = get_data(dir_name, opt)))
	{
		puterror(dir_name);
		return (1);
	}
	f_sort = select_sort(opt);
	sort(&lst, (t_sort)f_sort, opt);
	print(lst, opt);
	if (opt.rr)
	{
		recursive(lst, dir_name, opt);
	}
	ft_lstdel(&lst, (void(*)(void*, size_t))free_content);
	return (0);
}
