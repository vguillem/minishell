/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguillem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 15:59:05 by vguillem          #+#    #+#             */
/*   Updated: 2018/01/02 09:08:56 by vguillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*ltmp;
	t_list	*nl;

	if (!(lst))
		return (NULL);
	if (!(nl = f(lst)))
		return (NULL);
	ltmp = nl;
	while (lst->next)
	{
		lst = lst->next;
		if (!(ltmp->next = f(lst)))
			return (NULL);
		ltmp = ltmp->next;
	}
	return (nl);
}
