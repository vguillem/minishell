/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_touppers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguillem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 15:11:25 by vguillem          #+#    #+#             */
/*   Updated: 2018/01/02 09:19:03 by vguillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_touppers(char *str)
{
	int		i;

	i = -1;
	while (str[++i])
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] = ft_toupper((int)(str[i]));
	}
	return (str);
}
