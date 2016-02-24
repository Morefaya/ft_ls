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

static int		get_colwidth(t_list *lst)
{
	int	width;

	width = max_w_uname(lst)  + 1;
	return (width + 8 - width % 8);
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

static t_list	*split(t_list *lst, int ocr)
{
	t_list	*aux;
	int		i;

	i = 0;
	while (i <= ocr)
	{
		put_ls(get_next_link(lst, ocr));
		lst = lst->next;
		i++;
	}
}

void			print_ls(t_list *lst)
{
	struct winsize	ws;
	int				width;
	int				i;

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
	i--;
	ft_putnbr(i);
}
