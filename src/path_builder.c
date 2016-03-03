/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_builder.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 14:44:07 by jcazako           #+#    #+#             */
/*   Updated: 2016/03/03 14:44:46 by jcazako          ###   ########.fr       */
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
		return (NULL);
	free(tmp_path);
	return (new_path);
}
