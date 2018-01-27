/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguillem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 13:03:52 by vguillem          #+#    #+#             */
/*   Updated: 2018/01/02 09:08:35 by vguillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	ft_lstdelone(t_list **alst, void (*dell)(void *, size_t))
{
	if (alst && dell)
	{
		dell((*alst)->content, (*alst)->content_size);
		free((*alst));
		(*alst) = NULL;
	}
}
