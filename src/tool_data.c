/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/29 19:22:02 by jcazako           #+#    #+#             */
/*   Updated: 2016/02/29 20:36:01 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	time_asm(struct stat *f_stat, t_ls *content)
{
	content->mtime = f_stat->st_mtime;
	content->atime = f_stat->st_atime;
	content->stime = f_stat->st_ctime;
}
