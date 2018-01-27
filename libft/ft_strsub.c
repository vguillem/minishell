/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguillem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 11:35:07 by vguillem          #+#    #+#             */
/*   Updated: 2018/01/02 09:18:11 by vguillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*tmp;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	tmp = ft_strnew(sizeof(char) * len);
	if (!tmp)
		return (NULL);
	while (len-- > 0)
		tmp[i++] = s[start++];
	return (tmp);
}
