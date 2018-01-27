/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguillem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 19:17:04 by vguillem          #+#    #+#             */
/*   Updated: 2018/01/02 09:18:02 by vguillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strstr(const char *src, const char *x)
{
	int	i;
	int	y;

	i = 0;
	if (!*x)
		return ((char *)src);
	while (src[i])
	{
		y = 0;
		while (src[i + y] == x[y] || !x[y])
		{
			if (!x[y])
				return ((char *)src + i);
			y++;
		}
		i++;
	}
	return (NULL);
}
