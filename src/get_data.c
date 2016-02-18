/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/06 20:19:34 by jcazako           #+#    #+#             */
/*   Updated: 2016/02/18 22:06:06 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		free_content(t_ls *adr_content)
{
	free(adr_content->name);
	free(adr_content->link);
	free(adr_content->u_name);
	free(adr_content->g_name);
	free(adr_content->rights);
	free(adr_content->time);
}

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

static t_list	*get_link(struct dirent *f_drt, struct stat *f_stat, char *path)
{
	t_ls			content;
	t_list			*lst;

	if (!f_stat || !f_drt)
		return (NULL);
	errno = 0;
	content.nb_hlink = (int)(f_stat->st_nlink);
	content.size = (int)(f_stat->st_size);
	content.nb_blk = (int)(f_stat->st_blocks);
	if (!(content.name = ft_strdup(f_drt->d_name))
		|| !(content.u_name = get_uname(f_stat->st_uid))
		|| !(content.g_name = get_gname(f_stat->st_gid))
		|| !(content.rights = get_rights(f_stat, path))
		|| !(content.type = get_type(f_stat))
		|| !(content.time = get_time(f_stat->st_mtime)))
		return (NULL);
	content.link = f_readlink(content, path);
	if (!(lst = ft_lstnew(&content, sizeof(content))))
	{
		free_content(&content);
		return (NULL);
	}
	return (lst);
}

static t_list	*mk_link(char *arg, struct dirent *f_drt)
{
	char			*path;
	t_list			*lst;
	struct stat		buff_stat;

	if (!(path = path_builder(arg, f_drt->d_name)))
		return (NULL);
	if (lstat(path, &buff_stat) == -1)
		return (puterror());
	if (!(lst = get_link(f_drt, &buff_stat, path)))
		return (NULL);
	return (lst);
}

t_list			*get_data(char *arg)
{
	DIR				*f_opn;
	struct dirent	*f_drt;
	t_list			*lst_tmp;
	t_list			*lst;

	errno = 0;
	lst = NULL;
	if (!(f_opn = opendir(arg)))
		return (puterror());
	while ((f_drt = readdir(f_opn)))
	{
		if (!(lst_tmp = mk_link(arg, f_drt)))
			return (NULL);
		ft_lstadd(&lst, lst_tmp);
	}
	closedir(f_opn);
	return (lst);
}
