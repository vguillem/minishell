/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguillem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 11:13:44 by vguillem          #+#    #+#             */
/*   Updated: 2018/01/02 09:16:41 by vguillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strmapi(char *s, char (*f)(unsigned int, char))
{
	char			*tmp;
	unsigned int	i;

	i = 0;
	tmp = NULL;
	if (!s)
		return (NULL);
	tmp = ft_strnew(sizeof(char) * ft_strlen(s));
	if (!tmp)
		return (NULL);
	while (s[i])
	{
		tmp[i] = f(i, s[i]);
		i++;
	}
	return (tmp);
}
