/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/06 20:19:34 by jcazako           #+#    #+#             */
/*   Updated: 2016/02/06 22:09:28 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_list	*get_data(t_list **list, DIR *f_dir)
{
	t_list			*lst_tmp;
	t_ls			content;
	struct dirent	*f_dirent;
	struct stat		*f_stat;

	while ((f_dirent = readdir(f_dir)))
	{
		if (!(content.name = ft_strdup(f_dirent->d_name)));
			return (NULL);
		if (!(lst_tmp = lst_new(&content, sizeof(content))))
		{
			free(content.name);
			return (NULL);
		}
		ft_lstadd(list, lst_tmp);
	}
}
