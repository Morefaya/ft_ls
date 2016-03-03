/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/24 18:16:15 by jcazako           #+#    #+#             */
/*   Updated: 2016/03/03 14:49:07 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int		get_colwidth(t_list *lst)
{
	int	width;

	width = max_w_name(lst);
	return (width + 8 - width % 8);
}

static t_list	*get_next_link(t_list *lst, int nb_col)
{
	while (nb_col--)
	{
		if (!lst)
			return (NULL);
		lst = lst->next;
	}
	return (lst);
}

static void		put_ls(t_list *lst, int nb_lgn, int max_w)
{
	while (lst)
	{
		ft_putstr_left(((t_ls*)(lst->content))->name, max_w);
		lst = get_next_link(lst, nb_lgn);
	}
}

static void		split_ls(t_list *lst, int nb_lgn, int max_w)
{
	int	i;

	i = 0;
	while (i < nb_lgn)
	{
		put_ls(lst, nb_lgn, max_w);
		lst = lst->next;
		i++;
		ft_putchar('\n');
	}
}

void			print_ls(t_list *lst)
{
	struct winsize	ws;
	int				nb_col;
	int				max_w;
	int				width;
	int				nb_lgn;

	if (!lst)
		return ;
	nb_col = 1;
	errno = 0;
	if ((ioctl(1, TIOCGWINSZ, &ws) == -1))
	{
		ft_putendl(strerror(errno));
		return ;
	}
	max_w = get_colwidth(lst);
	width = count_elem_list(lst);
	while (max_w * nb_col < ws.ws_col)
		nb_col++;
	nb_col--;
	nb_lgn = width / nb_col + 1;
	split_ls(lst, nb_lgn, max_w);
}
