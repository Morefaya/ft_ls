#include "ft_ls.h"

static t_list	*split(t_list *lst)
{
	t_list	*aux;

	if (!lst)
		return (NULL);
	else if (!lst->next)
		return (NULL);
	else
	{
		aux = lst->next;
		lst->next = aux->next;
		aux->next = split(aux->next);
		return (aux);
	}
}

static t_list	*fusion_ascii(t_list *lg, t_list *ld)
{
	if (!lg)
		return (ld);
	else if (!ld)
		return (lg);
	else if (ft_strcmp(((t_ls*)(lg->content))->name,
		 ((t_ls*)(ld->content))->name) < 0)
	{
		lg->next = fusion_ascii(lg->next, ld);
		return (lg);
	}
	else
	{
		ld->next = fusion_ascii(lg, ld->next);
		return (ld);
	}
}

void	sort_ascii(t_list **lst)
{
	t_list *aux;

	if (*lst)
		if ((*lst)->next)
		{
			aux = split(*lst);
			sort_ascii(lst);
			sort_ascii(&aux);
			*lst = fusion_ascii(*lst, aux);
		}
}
