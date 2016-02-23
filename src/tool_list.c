/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 18:54:18 by jcazako           #+#    #+#             */
/*   Updated: 2016/02/23 21:31:37 by jcazako          ###   ########.fr       */
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

void	free_content(t_ls *adr_content)
{
	free(adr_content->name);
	free(adr_content->link);
	free(adr_content->u_name);
	free(adr_content->g_name);
	free(adr_content->rights);
}
