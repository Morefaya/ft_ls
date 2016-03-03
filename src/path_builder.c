/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_builder.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 14:44:07 by jcazako           #+#    #+#             */
/*   Updated: 2016/03/03 22:13:00 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	*path_builder(char *path, char *dir_name)
{
	char	*tmp_path;
	char	*new_path;

	if (!(tmp_path = ft_strjoin(path, "/")))
		return (NULL);
	if (!(new_path = ft_strjoin(tmp_path, dir_name)))
	{
		free(tmp_path);
		return (NULL);
	}
	free(tmp_path);
	return (new_path);
}
