/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 18:54:18 by jcazako           #+#    #+#             */
/*   Updated: 2016/02/29 21:44:13 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	*puterror(void)
{
	ft_putendl(strerror(errno));
	return (NULL);
}

void	putillegal(char opt_chr)
{
	ft_putendl("ft_ls: illegal option --");
	ft_putchar(opt_chr);
	ft_putchar('\n');
	ft_putendl("usage: ft_ls [-lRartAucg1] [file ...]");
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

void	free_content(t_ls *adr_content, size_t size)
{
	free(adr_content->name);
	free(adr_content->link);
	free(adr_content->u_name);
	free(adr_content->g_name);
	free(adr_content->rights);
	ft_bzero(adr_content, size);
}

int		count_elem_list(t_list *lst)
{
	if (lst)
	{
		return (1 + count_elem_list(lst->next));
	}
	return (0);
}
