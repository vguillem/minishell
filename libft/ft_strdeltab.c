/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdeltab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguillem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 08:14:09 by vguillem          #+#    #+#             */
/*   Updated: 2018/01/27 07:54:28 by vguillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	ft_strdeltab(char ***ptr)
{
	int		i;
	char	**tab;

	i = 0;
	tab = *ptr;
	if (tab)
	{
		while (tab[i])
		{
			ft_strdel(&tab[i]);
			i++;
		}
	}
	ft_memdel((void **)ptr);
}
