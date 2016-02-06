#include "ft_ls.h"

t_ls	*get_name(DIR *f_dir)
{
	static t_list	*list;
	struct dirent	*f_dirent;

	
	if ((f_dirent = readdir(f_dir)))
	{
		f_dirent->name;
	}
}
