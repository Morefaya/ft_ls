/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_ft.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 20:18:57 by jcazako           #+#    #+#             */
/*   Updated: 2016/02/23 21:02:01 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int	ascii_cmp(char *str1, char *str2)
{
	return (ft_strcmp(str1, str2));
}

int	mtime_cmp(time_t t1, time_t t2)
{
	return ((int)(t1 - t2));
}

int	atime_cmp(time_t t1, time_t t2)
{
	return ((int)(t1 - t2));
}

int	stime_cmp(time_t t1, time_t t2)
{
	return ((int)(t1 - t2));
}
