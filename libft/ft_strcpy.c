/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguillem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 16:20:40 by vguillem          #+#    #+#             */
/*   Updated: 2018/01/02 09:15:26 by vguillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strcpy(char *dest, const char *src)
{
	int		i;

	i = -1;
	while (src[++i])
		dest[i] = src[i];
	dest[i] = src[i];
	return (dest);
}
