/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 15:49:40 by jcazako           #+#    #+#             */
/*   Updated: 2016/02/19 20:18:57 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_list	*get_adrlink(t_list *lst, int rang)
{
	while (rang--)
	{
		if (!lst)
			return (NULL);
		lst = lst->next;
	}
	return (lst);
}

int	main(int ac, char **av)
{
	t_list	*lst;

	if (ac != 2)
	{
		ft_putendl("too much arg");
		return (1);
	}
	if (!(lst = get_data(av[1])))
	{
		ft_putendl("error get_data");
		return (1);
	}
	sort(&lst);
	sort(&(lst->next->next));
	sort(&(lst->next->next->next->next));
	sort(&(lst->next->next->next->next->next->next));

	/*tri a partir du 2 maillon plutot*/
	print_lf(lst);
	/*utilise une maillon buffer tete de lecture*/
	return (0);
}
