/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguillem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 15:05:47 by vguillem          #+#    #+#             */
/*   Updated: 2018/01/02 09:08:24 by vguillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*ltmp;

	while ((*alst))
	{
		ltmp = (*alst)->next;
		del((*alst)->content, (*alst)->content_size);
		free((*alst));
		(*alst) = ltmp;
	}
}
