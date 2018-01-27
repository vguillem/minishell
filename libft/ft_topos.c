/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_topos.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguillem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/09 15:29:53 by vguillem          #+#    #+#             */
/*   Updated: 2018/01/02 09:18:45 by vguillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

unsigned long long	ft_topos(long long i)
{
	unsigned long long	j;

	if (i >= 0)
		j = i;
	else
		j = i * -1;
	return (j);
}
