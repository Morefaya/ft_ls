/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/13 13:38:00 by jcazako           #+#    #+#             */
/*   Updated: 2016/02/16 19:23:55 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <sys/ioctl.h>
#include <stdio.h>

int	main(int ac, char **av)
{
	DIR		*fd_o;
	struct dirent	*fd_r;
	struct stat	buff;
	char		*name;
	char		*path;

	errno = 0;
	if (ac != 2)
	{
		errno = E2BIG;
		ft_putendl(strerror(errno));
		return (1);
	}
	if (!(fd_o = opendir(av[1])))
		return (1);
	while ((fd_r = readdir(fd_o)))
	{
		if (!(path = path_builder(av[1], fd_r->d_name)))
			return (1);
		if (lstat(path, &buff) == -1)
		{
			ft_putendl(strerror(errno));
			return (1);
		}
		if (!(name = get_rights(&buff, path)))
		{
			ft_putendl("error get_rights");
			return (1);
		}
		ft_putstr(name);
		ft_putchar('\t');
		ft_putendl(path);
		free(path);
		free(name);
	}
	closedir(fd_o);
	return (0);
}
