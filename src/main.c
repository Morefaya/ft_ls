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
	DIR				*fd_o;
	struct dirent	*fd_r;
	struct winsize	ws;

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
	/*if ((ioctl(1, TIOCSETD, &line) == -1))
	{
		ft_putendl(strerror(errno));
		ft_putchar('@');
		return (1);
	}*/
	if ((ioctl(1, TIOCGWINSZ, &ws) == -1))
	{
		ft_putendl(strerror(errno));
		return (1);
	}
	printf("%d\n", ws.ws_col);
	/*while((fd_r = readdir(fd_o)))
	{
		ft_putstr(fd_r->d_name);
		ft_putchar('\n');
	}*/
	closedir(fd_o);
	return (0);
}
