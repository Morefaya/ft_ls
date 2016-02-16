/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_time.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 19:18:31 by jcazako           #+#    #+#             */
/*   Updated: 2016/02/16 20:07:47 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static char	*puttime(time_t tm_file)
{
	char	*str_ctime;
	char	*str;

	if (!(str_ctime = ctime(&tm_file)))
		return (NULL);
	if (!(str = ft_strsub(str_ctime, 4, 12)))
		return (NULL);
	return (str);
}

static char	*putyear(time_t tm_file)
{
	char	*str_ctime;
	char	*str_1;
	char	*str_2;
	char	*str;

	if (!(str_ctime = ctime(&tm_file)))
		return (NULL);
	if (!(str_1 = ft_strsub(str_ctime, 4, 7))
		|| !(str_2 = ft_strsub(str_ctime, 19, 5)))
		return (NULL);
	if (!(str = ft_strjoin(str_1, str_2)))
		return (NULL);
	free(str_1);
	free(str_2);
	return (str);
}

char		*get_time(time_t tm_file)
{
	char		*str;
	char		*(*f)(time_t);
	time_t		tm_now;
	time_t		tm_diff;
	struct tm	*stm_diff;

	if (time(&tm_now) == -1)
		return (NULL);
	if ((tm_diff = tm_now - tm_file) < 0)
		return (NULL);
	if (!(stm_diff = localtime(&tm_diff)))
		return (NULL);
	if ((stm_diff->tm_mon >= 6) || (stm_diff->tm_year > 1970))
		f = putyear;
	else
		f = puttime;
	if (!(str = f(tm_file)))
		return (NULL);
	return (str);
}
