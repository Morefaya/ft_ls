#include "ft_ls.h"

static void	check_sitcky(char *rights, struct stat *f_stat)
{
	if (f_stat->st_mode & S_ISUID)
	{
		if (rights[2] == 'x')
			rights[2] = 'S';
		else
			rights[2] = 's';
	}
	if (f_stat->st_mode & S_ISGID)
	{
		if (rights[5] == 'x')
			rights[5] = 'S';
		else
			rights[5] = 's';
	}
	if (f_stat->st_mode & S_ISVTX)
	{
		if (rights[8] == 'x')
			rights[8] = 'T';
		else
			rights[8] = 't';
	}
}

static void	check_acl_extd(char *rights, )
{
	if (listxattr())
		rights[9] = '@';
	else if (acl_get_file())
		rights[9] = '+';
	else
		rights[9] = ' '
}

char		*get_rights(struct stat *f_stat)
{
	char	*rights;

	if (!(rights = ft_strnew(10)))
		return (NULL);
	rights[0] = (ft_stat->st_mode & S_IRUSR) ? 'r' : '-';
	rights[1] = (ft_stat->st_mode & S_IWUSR) ? 'w' : '-';
	rights[2] = (ft_stat->st_mode & S_IXUSR) ? 'x' : '-';
	rights[3] = (ft_stat->st_mode & S_IRGRP) ? 'r' : '-';
	rights[4] = (ft_stat->st_mode & S_IWGRP) ? 'w' : '-';
	rights[5] = (ft_stat->st_mode & S_IXGRP) ? 'x' : '-';
	rights[6] = (ft_stat->st_mode & S_IROTH) ? 'r' : '-';
	rights[7] = (ft_stat->st_mode & S_IWOTH) ? 'w' : '-';
	rights[8] = (ft_stat->st_mode & S_IXOTH) ? 'x' : '-';
	check_sticky(rights, f_stat);
	check_acl_extd(rights, );
	return (rights);
}
