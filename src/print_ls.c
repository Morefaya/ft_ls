/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/24 18:16:15 by jcazako           #+#    #+#             */
/*   Updated: 2016/02/24 22:08:09 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int	get_colwidth(t_list *lst)
{
	int	width;

	width = max_w_uname(lst);
	return (width - width % 8);
}

static t_list	*get_next_link(t_list *lst, int ocr)
{
	while (ocr--)
	{
		if (!lst)
			return (NULL);
		lst = lst->next;
	}
	return (lst);
}

static void	put_ls(t_list *lst, int ocr, int max_w)
{
	t_list	*aux;

	aux = get_next_link(lst, ocr);
	if (!lst)
		return;
	ft_putstr_left(((t_ls*)(lst->content))->name, max_w);
	put_ls(aux, ocr, max_w);
}

static void	split_ls(t_list *lst, int ocr)
{
	int	i;
	int	max_w;

	i = 0;
	max_w = get_colwidth(lst);
	while (i < ocr)
	{
		put_ls(lst, ocr, max_w);
		lst = lst->next;
		i++;
		ft_putchar('\n');
	}
} 

void		print_ls(t_list *lst)
{
	struct winsize	ws;
	int		width;
	int		i;

	i = 1;
	errno = 0;
	if ((ioctl(1, TIOCGWINSZ, &ws) == -1))
	{
		ft_putendl(strerror(errno));
		return;
	}
	width = count_elem_list(lst) * get_colwidth(lst);
	while (((width / i) >= ws.ws_col))
		i++;
	split_ls(lst, i);
}
