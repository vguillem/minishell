/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mutils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguillem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/14 08:43:51 by vguillem          #+#    #+#             */
/*   Updated: 2018/01/14 09:13:34 by vguillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_doubleslash(char *buf)
{
	int		i;

	i = ft_strlen(buf);
	if (i > 1 && buf[i - 1] == '/')
		buf[i - 1] = 0;
}

t_myenv	*ft_getenv(t_myenv *myenv, char *str)
{
	while (myenv && ft_strcmp(str, myenv->name) != 0)
		myenv = myenv->next;
	return (myenv);
}
