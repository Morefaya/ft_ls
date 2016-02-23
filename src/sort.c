/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 18:57:09 by jcazako           #+#    #+#             */
/*   Updated: 2016/02/23 19:39:55 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static t_list	*split(t_list *lst)
{
	t_list	*aux;

	if (!lst)
		return (NULL);
	else if (!lst->next)
		return (NULL);
	else
	{
		aux = lst->next;
		lst->next = aux->next;
		aux->next = split(aux->next);
		return (aux);
	}
}

static t_list	*fusion(t_list *lst_g, t_list *lst_d, int (*f)(void*, void*))
{
	if (!lst_g)
		return (lst_d);
	else if (!lst_d)
		return (lst_g);
	else if (f(((t_ls*)(lst_g->content))->name,
		((t_ls*)(lst_d->content))->name) < 0)
	{
		lst_g->next = fusion(lst_g->next, lst_d, f);
		return (lst_g);
	}
	else
	{
		lst_d->next = fusion(lst_g, lst_d->next, f);
		return (lst_d);
	}
}

void			sort(t_list **lst, int (*f)(void*, void*))
{
	t_list *aux;

	if (*lst)
		if ((*lst)->next)
		{
			aux = split(*lst);
			sort(lst, f);
			sort(&aux, f);
			*lst = fusion(*lst, aux, f);
		}
}
