#include "ft_ls.h"

/*static t_list	*get_link(char *arg)
{
	t_list	*lst_tmp;
	t_arg	content;
	struct stat	f_stat;

	if (!arg)
		return (NULL);
	if (lstat(arg, &f_stat) == -1)
		return (puterror());
	if (!(content.arg = ft_strdup(arg)))
		return (NULL);
	content.mtime = f_stat.st_mtime;
	content.atime = f_stat.st_atime;
	content.stime = f_stat.st_ctime;
	if (!(lst_tmp = ft_lstnew(&content, sizeof(content))))
	{
		free(content.arg);
		return (NULL);
	}
	return (lst_tmp);
}*/

static t_list	*mk_arg(char *av)
{
	t_list		*lst;
	struct stat	f_stat;

	if (lstat(av, &f_stat) == -1)
	{
		puterror(av);
		return (NULL);
	}
	if (!(lst = get_link(av, &f_stat, av)))
		return (NULL);
	return (lst);
}

static void	get_arg(t_list **lst_f, t_list **lst_d, char *av)
{
	t_list	*lst_tmp;
	
	if (!(lst_tmp = mk_arg(av)))
		return;
	if (opendir(av))
		ft_lstadd(lst_d, lst_tmp);
	else if (errno == ENOTDIR)
		ft_lstadd(lst_f, lst_tmp);
	else
	{
		free_content(lst_tmp->content, lst_tmp->content_size);
		free(lst_tmp);
		puterror(av);
		return;
	}
}

void	split_arg(t_list **lst_f, t_list **lst_d, char **av, int n_av)
{
	int	i;

	i = 0;
	while (i < n_av)
	{
		get_arg(lst_f, lst_d, av[i]);
		i++;
	}
}
