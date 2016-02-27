#include "ft_ls.h"
static void	init_opt(t_opt *opt)
{
	opt->l = 0;
	opt->R = 0;
	opt->a = 0;
	opt->r = 0;
	opt->t = 0;
	opt->A = 0;
	opt->u = 0;
	opt->c = 0;
	opt->g = 0;
	opt->one = 0;
	opt->S = 0;
}
static void	fill_opt(char a, t_opt *opt)
{
}

static void	pars_opt(char *str, t_opt *opt)
{
	int	i;

	i = 1;
	while (str[i])
	{
		if (!ft_strchr(OPT_CHARS, str[i]))
		{
			putillegal(str[i]);
			exit(1);
		}
		else
			fill_opt(str[i], opt);
		i++;
	}
}

static int	check_opt(int ac, char **av, t_opt *opt)
{
	int	i;

	i = 1;
	init_opt(opt);
	while (i < ac && av[i][0] == '-')
	{
		pars_opt(av[i], opt);
		i++;
	}
	return (i);
}

int		main(int ac, char **av)
{
	t_opt	opt;
	int	index;

	index = check_opt(av, &index, &opt);
	if (index == ac + 1)
		ft_ls(".", opt);
	while (index < ac)
	{
		ft_ls(av[index], opt);
		index++;
	}
	return (0);
}
