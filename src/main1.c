/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/13 13:38:00 by jcazako           #+#    #+#             */
/*   Updated: 2016/02/13 17:23:12 by jcazako          ###   ########.fr       */
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

	errno = 0;
	if (ac != 2)
	{
		errno = E2BIG;
		ft_putendl(strerror(errno));
		return (1);
	}
	if (!(fd_o = opendir(av[1])))
		return (1);
	fd_r = readdir(fd_o);
	if (lstat((const char*)(fd_r->d_name), &buff) == -1)
	{
		ft_putendl(strerror(errno));
		return (1);
	}
	if (!(name = get_time((time_t)(buff.st_mtime))))
	{
		ft_putendl("error get_gname");
		return (1);
	}
	ft_putendl(name);
	free(name);
	closedir(fd_o);
	return (0);
}
