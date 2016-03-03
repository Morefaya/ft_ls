/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/29 19:22:02 by jcazako           #+#    #+#             */
/*   Updated: 2016/03/03 14:55:42 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	time_asm(struct stat *f_stat, t_ls *content)
{
	content->mtime = f_stat->st_mtime;
	content->atime = f_stat->st_atime;
	content->stime = f_stat->st_ctime;
}

void	fill_tmax(t_max *max, t_list *lst)
{
	max->mx_hl = max_w_hlink(lst);
	max->mx_sz = max_w_size(lst);
	max->mx_un = max_w_uname(lst);
	max->mx_gn = max_w_gname(lst);
}
