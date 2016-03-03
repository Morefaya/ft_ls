/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 18:57:09 by jcazako           #+#    #+#             */
/*   Updated: 2016/03/03 16:21:34 by jcazako          ###   ########.fr       */
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

static t_list	*fusion(t_list *lst_g, t_list *lst_d, p_sort f, t_opt opt)
{
	int	signe;

	signe = (opt.r) ? -1 : 1;
	if (!lst_g)
		return (lst_d);
	else if (!lst_d)
		return (lst_g);
	else if (signe * f(lst_g->content,
		lst_d->content) < 0)
	{
		lst_g->next = fusion(lst_g->next, lst_d, f, opt);
		return (lst_g);
	}
	else
	{
		lst_d->next = fusion(lst_g, lst_d->next, f, opt);
		return (lst_d);
	}
}

void			sort(t_list **lst, p_sort f, t_opt opt)
{
	t_list *aux;

	if (*lst)
		if ((*lst)->next)
		{
			aux = split(*lst);
			sort(lst, f, opt);
			sort(&aux, f, opt);
			*lst = fusion(*lst, aux, f, opt);
		}
}
