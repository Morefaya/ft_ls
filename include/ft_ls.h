/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/06 21:28:40 by jcazako           #+#    #+#             */
/*   Updated: 2016/02/06 21:29:01 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include "libft.h"
# include <dirent.h>
# include <errno.h>

typedef struct	s_ls
{
	char		*name;
	int			nb_slink;
	char		type;
	char		*rights;
	char		*u_name;
	char		*g_name;
	size_t		size;
	char		*time;
}				t_ls;

#endif
