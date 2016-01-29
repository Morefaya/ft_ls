#include "ft_ls.h"

int	main(int ac, char **av)
{
	DIR		*fd_o;
	struct dirent	*fd_r;
	
	if (ac != 2)
		return (1);
	if (!(fd_o = opendir(av[1])))
		return (1);
	while((fd_r = readdir(fd_o)))
	{
		ft_putstr(fd_r->d_name);
		ft_putstr("\t\t");
	}
	ft_putchar('\n');
	closedir(fd_o);
	return (0);
}
