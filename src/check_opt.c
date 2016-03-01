/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_opt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/27 13:26:38 by jcazako           #+#    #+#             */
/*   Updated: 2016/02/27 15:46:58 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
}

static void	fill_opt_bon(char ch, t_opt *opt)
{
	if (ch == 'A' && !opt->a)
		opt->A = 1;
	if (ch == 'u' && !opt->t)
	{
		opt->u = 1;
		opt->c = 0;
	}
	if (ch == 'c' && !opt->t)
	{
		opt->c = 1;
		opt->u = 0;
	}
	if (ch == 'g')
	{
		opt->g = 1;
		opt->l = 0;
	}
	if (ch == '1')
	{
		opt->one = 1;
		opt->l = 0;
	}
}

static void	fill_opt_oba(char ch, t_opt *opt)
{
	if (ch == 'l' && !opt->g)
	{
		opt->l = 1;
		opt->one = 0;
	}
	if (ch == 'R')
		opt->R = 1;
	if (ch == 'a')
	{
		opt->a = 1;
		opt->A = 0;
	}
	if (ch == 'r')
		opt->r = 1;
	if (ch == 't')
	{
		opt->t = 1;
		opt->u = 0;
		opt->c = 0;
	}
	fill_opt_bon(ch, opt);
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
			fill_opt_oba(str[i], opt);
		i++;
	}
}

int			check_opt(int ac, char **av, t_opt *opt)
{
	int	i;

	init_opt(opt);
	i = 1;
	while (i < ac && av[i][0] == '-')
	{
		pars_opt(av[i], opt);
		i++;
	}
	return (i);
}
