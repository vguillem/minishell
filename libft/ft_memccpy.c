/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguillem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 11:24:44 by vguillem          #+#    #+#             */
/*   Updated: 2018/01/02 09:09:48 by vguillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char		*tmpdest;
	const unsigned char	*tmpsrc;

	tmpdest = dest;
	tmpsrc = src;
	while (n > 0 && *tmpsrc != (unsigned char)c)
	{
		*tmpdest++ = *tmpsrc++;
		n--;
	}
	if (n > 0)
	{
		*tmpdest = *tmpsrc;
		return ((void *)++tmpdest);
	}
	else
		return (NULL);
}
