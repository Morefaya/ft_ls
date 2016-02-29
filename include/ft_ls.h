/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/06 21:28:40 by jcazako           #+#    #+#             */
/*   Updated: 2016/02/29 21:46:11 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include "libft.h"
# include <unistd.h>
# include <dirent.h>
# include <errno.h>
# include <sys/stat.h>
# include <pwd.h>
# include <grp.h>
# include <time.h>
# include <stdlib.h>
# include <sys/acl.h>
# include <sys/xattr.h>
# include <sys/ioctl.h>

# define BUFF_SIZE 1024
# define OPT_CHARS "larRtA1ugc"

typedef struct	s_ls
{
	char		*name;
	char		*link;
	int			nb_hlink;
	int			nb_blk;
	char		type;
	char		*rights;
	char		*u_name;
	char		*g_name;
	size_t		size;
	time_t		atime;
	time_t		mtime;
	time_t		stime;
}				t_ls;

typedef struct	s_max
{
	int			mx_hl;
	int			mx_sz;
	int			mx_un;
	int			mx_gn;
}				t_max;

typedef struct	s_opt
{
	int			l;
	int			R;
	int			a;
	int			r;
	int			t;
	int			A;
	int			u;
	int			c;
	int			g;
	int			one;
}				t_opt;


char			*get_uname(uid_t uid);
char			*get_gname(gid_t gid);
char			get_type(struct stat *f_stat);
char			*get_acl(char *path);

char			*get_rights(struct stat *f_stat, char *path);

char			*get_time(time_t time);

t_list			*get_data(char *arg, t_opt opt);

char			*path_builder(char *path, char *dir_name);

int				max_w_hlink(t_list *lst);
int				max_w_size(t_list *lst);
int				max_w_uname(t_list *lst);
int				max_w_gname(t_list *lst);
int				max_w_name(t_list *lst);
void			fill_tmax(t_max *max, t_list *lst);

int				get_nblock(t_list *lst);
void			*puterror(void);
void			putillegal(char opt_chr);
void			free_content(t_ls *adr_content, size_t size);
int				count_elem_list(t_list *lst);

void			print(t_list *lst, t_opt opt);

void			print_one(t_list *lst, t_opt opt);

void			print_ls(t_list* lst);

void			print_lf(t_list* lst, t_opt opt);

void			sort(t_list **lst, int (*f)(void*, void*));

int				ascii_cmp(char *str1, char *str2);
int				mtime_cmp(time_t t1, time_t t2);
int				atime_cmp(time_t t1, time_t t2);
int				stime_cmp(time_t t1, time_t t2);

void			time_asm(struct stat *f_stat, t_ls*content);

int				check_opt(int ac, char **av, t_opt *opt);

int				ft_ls(char *dir_name, t_opt opt);

#endif
