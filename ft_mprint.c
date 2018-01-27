/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mprint.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguillem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 08:12:31 by vguillem          #+#    #+#             */
/*   Updated: 2018/01/07 13:09:54 by vguillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_mprintoneop(t_myenv *myenv, char *op)
{
	while (myenv && myenv->name && ft_strcmp(op, myenv->name) != 0)
		myenv = myenv->next;
	if (myenv)
	{
		ft_printf("%s=%s\n", myenv->name, myenv->data);
	}
}

void	ft_mprintenv(t_myenv *myenv)
{
	while (myenv)
	{
		if (myenv->name)
		{
			ft_printf("%s=", myenv->name);
			if (myenv->data)
				ft_printf("%s\n", myenv->data);
			else
				ft_putchar('\n');
		}
		myenv = myenv->next;
	}
}
