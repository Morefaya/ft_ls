/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 18:54:18 by jcazako           #+#    #+#             */
/*   Updated: 2016/02/19 17:19:59 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	*puterror(void)
{
	ft_putendl(strerror(errno));
	return (NULL);
}

int		get_nblock(t_list *lst)
{
	int		block;

	block = 0;
	while (lst)
	{
		block += ((t_ls*)(lst->content))->nb_blk;
		lst = lst->next;
	}
	return (block);
}
