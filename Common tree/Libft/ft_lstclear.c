/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swijnber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 16:18:53 by swijnber          #+#    #+#             */
/*   Updated: 2022/05/05 13:43:55 by swijnber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	void	*ptdr;

	while (lst && del && *lst)
	{
		ptdr = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = ptdr;
	}
}
