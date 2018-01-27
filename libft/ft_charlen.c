/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_charlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguillem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 08:13:17 by vguillem          #+#    #+#             */
/*   Updated: 2018/01/02 09:07:15 by vguillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int		ft_charlen(int str)
{
	if (str <= 0x7F)
		return (1);
	else if (str <= 0x7FF)
		return (2);
	else if (str <= 0xFFFF)
		return (3);
	else if (str <= 0x10FFFF)
		return (4);
	return (0);
}
