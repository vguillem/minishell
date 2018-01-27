/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realoc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguillem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 08:29:53 by vguillem          #+#    #+#             */
/*   Updated: 2018/01/02 09:15:06 by vguillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	*ft_realloc(void *s1, int sizes1, int sizes2)
{
	void	*tmp;

	if (!s1)
		return (NULL);
	tmp = (void *)ft_memalloc(sizes1 + sizes2);
	tmp = ft_memcpy(tmp, s1, sizes1);
	free(s1);
	return (tmp);
}
