/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguillem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 17:18:51 by vguillem          #+#    #+#             */
/*   Updated: 2018/01/02 09:16:48 by vguillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	char	*ptr;

	ptr = dest;
	while (*dest)
		dest++;
	while (*src && n-- > 0)
		*dest++ = *src++;
	*dest = '\0';
	return (ptr);
}
