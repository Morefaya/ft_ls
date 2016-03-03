/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max_width.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/19 17:00:38 by jcazako           #+#    #+#             */
/*   Updated: 2016/03/03 14:51:39 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		max_w_hlink(t_list *lst)
{
	char	*buff;
	int		len;
	int		max;

	max = 0;
	while (lst)
	{
		if (!(buff = ft_itoa(((t_ls*)(lst->content))->nb_hlink)))
			return (-1);
		len = ft_strlen(buff);
		max = (len > max) ? len : max;
		free(buff);
		lst = lst->next;
	}
	return (max);
}

int		max_w_size(t_list *lst)
{
	char	*buff;
	int		len;
	int		max;

	max = 0;
	while (lst)
	{
		if (!(buff = ft_itoa(((t_ls*)(lst->content))->size)))
			return (-1);
		len = ft_strlen(buff);
		max = (len > max) ? len : max;
		free(buff);
		lst = lst->next;
	}
	return (max);
}

int		max_w_uname(t_list *lst)
{
	int		len;
	int		max;

	max = 0;
	while (lst)
	{
		len = ft_strlen(((t_ls*)(lst->content))->u_name);
		max = (len > max) ? len : max;
		lst = lst->next;
	}
	return (max);
}

int		max_w_gname(t_list *lst)
{
	int		len;
	int		max;

	max = 0;
	while (lst)
	{
		len = ft_strlen(((t_ls*)(lst->content))->g_name);
		max = (len > max) ? len : max;
		lst = lst->next;
	}
	return (max);
}

int		max_w_name(t_list *lst)
{
	int	len;
	int	max;

	max = 0;
	while (lst)
	{
		len = ft_strlen(((t_ls*)(lst->content))->name);
		max = (len > max) ? len : max;
		lst = lst->next;
	}
	return (max);
}
