/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_ft.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 20:18:57 by jcazako           #+#    #+#             */
/*   Updated: 2016/03/03 14:54:59 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int	ascii_cmp(t_ls *content_1, t_ls *content_2)
{
	return (ft_strcmp(content_1->name, content_2->name));
}

int	mtime_cmp(t_ls *content_1, t_ls *content_2)
{
	if (content_2->mtime > content_1->mtime)
		return (1);
	else if (content_1->mtime > content_2->mtime)
		return (-1);
	else
		return (ascii_cmp(content_1, content_2));
}

int	atime_cmp(t_ls *content_1, t_ls *content_2)
{
	if (content_2->atime > content_1->atime)
		return (1);
	else if (content_1->atime > content_2->atime)
		return (-1);
	else
		return (ascii_cmp(content_1, content_2));
}

int	stime_cmp(t_ls *content_1, t_ls *content_2)
{
	if (content_2->stime > content_1->stime)
		return (1);
	else if (content_1->stime > content_2->stime)
		return (-1);
	else
		return (ascii_cmp(content_1, content_2));
}
