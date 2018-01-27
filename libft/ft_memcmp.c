/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguillem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 15:19:49 by vguillem          #+#    #+#             */
/*   Updated: 2018/01/02 09:10:16 by vguillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*tmps1;
	unsigned char	*tmps2;

	tmps1 = (unsigned char *)s1;
	tmps2 = (unsigned char *)s2;
	while (n > 0 && *tmps1 == *tmps2)
	{
		tmps1++;
		tmps2++;
		n--;
	}
	if (n == 0)
		return (0);
	return (*tmps1 - *tmps2);
}
