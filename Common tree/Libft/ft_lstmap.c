/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swijnber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 16:59:24 by swijnber          #+#    #+#             */
/*   Updated: 2022/05/09 16:38:59 by swijnber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	delclear(t_list **lst, void (*del)(void *))
{
	void	*ptdr;

	if (del)
		ft_lstclear(lst, del);
	else
	{
		while (lst && *lst)
		{
			ptdr = (*lst)->next;
			free(*lst);
			*lst = ptdr;
		}
	}
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*rt;
	t_list	*new;

	if (!lst || !f)
		return (NULL);
	rt = ft_lstnew(f(lst->content));
	if (!rt)
		return (NULL);
	lst = lst->next;
	new = rt;
	while (lst)
	{
		new->next = ft_lstnew(f(lst->content));
		if (!new->next)
		{
			delclear(&rt, del);
			return (NULL);
		}
		new = new->next;
		lst = lst->next;
	}
	new->next = NULL;
	delclear(&lst, del);
	return (rt);
}
