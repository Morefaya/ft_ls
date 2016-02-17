#include "ft_ls.h"

static void	check_sticky(char *rights, struct stat *f_stat)
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

static void	check_acl_extd(char *rights, struct dirent *f_drt)
{
	char	buff[1024];
	ssize_t	nb_xat;
	acl_t	p_acl;

	errno = 0;
	if ((nb_xat = listxattr(f_drt->d_name, buff, 1024, XATTR_NOFOLLOW)) == -1)
	{
		ft_putendl(strerror(errno));
		return;
	}
	rights[9] = (nb_xat) ? '@' : ' ';
	p_acl = acl_get_file(f_drt->d_name, ACL_TYPE_EXTENDED);
	rights[9] = (p_acl) ? '+' : ' ';
}

char		*get_rights(struct stat *f_stat, struct dirent *f_drt)
{
	char	*rights;

	if (!(rights = ft_strnew(10)))
		return (NULL);
	rights[0] = (f_stat->st_mode & S_IRUSR) ? 'r' : '-';
	rights[1] = (f_stat->st_mode & S_IWUSR) ? 'w' : '-';
	rights[2] = (f_stat->st_mode & S_IXUSR) ? 'x' : '-';
	rights[3] = (f_stat->st_mode & S_IRGRP) ? 'r' : '-';
	rights[4] = (f_stat->st_mode & S_IWGRP) ? 'w' : '-';
	rights[5] = (f_stat->st_mode & S_IXGRP) ? 'x' : '-';
	rights[6] = (f_stat->st_mode & S_IROTH) ? 'r' : '-';
	rights[7] = (f_stat->st_mode & S_IWOTH) ? 'w' : '-';
	rights[8] = (f_stat->st_mode & S_IXOTH) ? 'x' : '-';
	check_sticky(rights, f_stat);
	check_acl_extd(rights, f_drt);
	return (rights);
}