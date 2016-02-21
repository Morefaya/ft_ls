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
	t_list	*lst_tmp1;
	t_list	*lst_tmp2;

	lst_tmp1 = *lst;
	*lst = (*lst)->next;
	lst_tmp2 = (*lst)->next;
	(*lst)->next = lst_tmp1;
	lst_tmp1->next = lst_tmp2;

}

void	sort(t_list **lst)
{
	if ((*lst)->next)
		if ((ft_strcmp(((t_ls*)((*lst)->content))->name,
			((t_ls*)((*lst)->next->content))->name)) > 0)
		{
			inverse_link(lst);
		}
}
