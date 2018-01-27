/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguillem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 10:48:22 by vguillem          #+#    #+#             */
/*   Updated: 2018/01/02 09:10:44 by vguillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char		*tmpdest;
	const char	*tmpsrc;

	tmpdest = dest;
	tmpsrc = src;
	while (n-- > 0)
		*tmpdest++ = *tmpsrc++;
	return (dest);
}
