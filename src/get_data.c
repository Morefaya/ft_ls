/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/06 20:19:34 by jcazako           #+#    #+#             */
/*   Updated: 2016/03/03 19:14:39 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static char		*f_readlink(t_ls content, char *path)
{
	char	*link;

	if (!(link = ft_strnew(BUFF_SIZE)))
		return (NULL);
	if (content.type == 'l')
		if (readlink(path, link, BUFF_SIZE) > 0)
			return (link);
	free(link);
	return (NULL);
}

t_list			*get_link(char *d_name, struct stat *f_stat, char *path)
{
	t_ls			content;
	t_list			*lst;

	if (!f_stat || !d_name)
		return (NULL);
	errno = 0;
	content.nb_hlink = (int)(f_stat->st_nlink);
	content.size = (int)(f_stat->st_size);
	content.nb_blk = (int)(f_stat->st_blocks);
	time_asm(f_stat, &content);
	if (!(content.name = ft_strdup(d_name))
		|| !(content.u_name = get_uname(f_stat->st_uid))
		|| !(content.g_name = get_gname(f_stat->st_gid))
		|| !(content.rights = get_rights(f_stat, path))
		|| !(content.type = get_type(f_stat)))
		return (NULL);
	content.link = f_readlink(content, path);
	if (!(lst = ft_lstnew(&content, sizeof(content))))
	{
		free_content(&content, content.size);
		return (NULL);
	}
	return (lst);
}

static t_list	*mk_link(char *arg, char *d_name)
{
	char			*path;
	t_list			*lst;
	struct stat		buff_stat;

	if (!(path = path_builder(arg, d_name)))
		return (NULL);
	if (lstat(path, &buff_stat) == -1)
	{
		puterror(path);
		return (NULL);
	}
	if (!(lst = get_link(d_name, &buff_stat, path)))
		return (NULL);
	free(path);
	return (lst);
}

static void		d_link(struct dirent *f_drt, t_list **lst, char *arg, t_opt opt)
{
	t_list	*lst_tmp;

	if (opt.a)
	{
		if (!(lst_tmp = mk_link(arg, f_drt->d_name)))
			return ;
		ft_lstadd(lst, lst_tmp);
	}
	else if (opt.aa)
	{
		if (ft_strcmp(f_drt->d_name, ".")
			&& ft_strcmp(f_drt->d_name, ".."))
		{
			if (!(lst_tmp = mk_link(arg, f_drt->d_name)))
				return ;
			ft_lstadd(lst, lst_tmp);
		}
	}
	else if (*(f_drt->d_name) != '.')
	{
		if (!(lst_tmp = mk_link(arg, f_drt->d_name)))
			return ;
		ft_lstadd(lst, lst_tmp);
	}
}

t_list			*get_data(char *arg, t_opt opt)
{
	DIR				*f_opn;
	struct dirent	*f_drt;
	t_list			*lst;

	errno = 0;
	lst = NULL;
	if ((f_opn = opendir(arg)))
	{
		while ((f_drt = readdir(f_opn)))
			d_link(f_drt, &lst, arg, opt);
		closedir(f_opn);
	}
	return (lst);
}
