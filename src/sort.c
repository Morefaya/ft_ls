/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/19 19:24:35 by jcazako           #+#    #+#             */
/*   Updated: 2016/02/19 22:42:10 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	inverse_link(t_list **lst)
{
	t_list *lst_tmp;
	lst_tmp = *lst;
}

t_list	*sort(t_list *lst)
{
	int	ret;

	while (lst)
	{
		if (lst->next)
		{
			ret = 0;
			if ((ret = ft_strcmp(((t_ls*)(lst->content))->name,
				((t_ls*)(lst->next->content))->name)))
				inverse_link(&lst);
		}
		lst = lst->next;
		lst = lst ? lst->next : lst;
		ft_putnbr(ret);
		ft_putchar(' ');
	}
	return (lst);
}
