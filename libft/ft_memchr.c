/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguillem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 14:33:55 by vguillem          #+#    #+#             */
/*   Updated: 2018/01/02 09:10:54 by vguillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char *tmp;

	tmp = (unsigned char *)s;
	while (n-- > 0)
	{
		if (*tmp == (unsigned char)c)
			return ((void *)tmp);
		tmp++;
	}
	return (NULL);
}
