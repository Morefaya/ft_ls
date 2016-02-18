/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 18:54:18 by jcazako           #+#    #+#             */
/*   Updated: 2016/02/18 20:02:59 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int	max_width(t_list *lst)
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

int	get_nblock(t_list *lst)
{
	int	block;

	block = 0;
	while (lst)
	{
		block += ((t_ls*)(lst->content))->nb_blk;
		lst = lst->next;
	}
	return (block);
}
