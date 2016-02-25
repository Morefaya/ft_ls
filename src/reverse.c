/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 20:20:14 by jcazako           #+#    #+#             */
/*   Updated: 2016/02/25 21:51:11 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	ft_lstadd_back(t_list **lst, t_list *lst_new)
{
	t_list	*cur;

	cur = NULL;
	if (!lst)
		return;
	else if (!*lst)
		cur = *lst;
	else
	{
		while (cur->next)
			cur = cur->next;
		cur->next = lst_new;
		lst_new->next = NULL;
	}
}

void	rev_list(t_list **lst)
{
	t_list	*cur;
	t_list	*inv;

	cur = *lst;
	inv = NULL;

	if (!lst)
		return;
	else if (!*lst)
		return;
	else
	{
		while ((*lst)->next)
		{
			while (cur->next->next)
				cur = cur->next;
			ft_lstadd_back(&inv, cur->next);
			cur->next = NULL;
			cur = *lst;
		}
		ft_lstadd_back(&inv, *lst);
	}
	*lst = inv;
}
/*
void	rev_list(t_list **lst)
{
	t_list	*prev;
	t_list	*cur;
	t_list	*next;

	cur = *lst;
	while (cur->next)
	{
		next = cur->next;
		cur->next = prev;
		prev = cur;
		cur = next;
	}
	*lst = prev;
}*/
