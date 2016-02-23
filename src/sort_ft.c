/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_ft.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 20:18:57 by jcazako           #+#    #+#             */
/*   Updated: 2016/02/23 21:02:01 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int	ascii_cmp(t_list *lst1, t_list *lst2)
{
	return (ft_strcmp(((t_ls*)(lst1->content))->name,
		((t_ls*)(lst2->content))->name));
}

int	mtime_cmp(t_list *lst1, t_list *lst2)
{
	return (((t_ls*)(lst1->content))->mtime - ((t_ls*)(lst2->content))->mtime);
}

int	atime_cmp(t_list *lst1, t_list *lst2)
{
	return (((t_ls*)(lst1->content))->atime - ((t_ls*)(lst2->content))->atime);
}

int	stime_cmp(t_list *lst1, t_list *lst2)
{
	return (((t_ls*)(lst1->content))->stime - ((t_ls*)(lst2->content))->stime);
}
