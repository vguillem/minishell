/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguillem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 15:47:43 by vguillem          #+#    #+#             */
/*   Updated: 2018/01/02 09:15:43 by vguillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strdup(const char *s)
{
	char	*ptr;
	int		i;

	i = -1;
	ptr = ft_memalloc((ft_strlen(s) + 1) * sizeof(char));
	if (ptr)
	{
		while (s[++i])
			ptr[i] = s[i];
		ptr[i] = s[i];
	}
	return (ptr);
}
